#include "Function.h"

void input(const char path[], classYear &a)
{
	//	load an entire new class from a .csv file;
	//	Nguyen Ho Huu Nghia

	ifstream fin(path);
	if (fin.good()) {
		//	ignore Class,
		fin.ignore(1000, ',');
		//	get Class Year
		char class_year[16];
		fin.getline(class_year, 16, ',');
		a.class_name = (string)class_year;
		//	ignore line 2
		fin.ignore(1000, '\n');
		fin.ignore(1000, '\n');

		student* cur;

		//	start reading students' info
		char temp_number[13], temp_username[8];
		int username;
		char full_name[101];
		while (fin.good()) {

			//	get ordinal number
			fin.getline(temp_number, 13, ',');

			//	get username(student_id)
			fin.getline(temp_username, 8, ',');
			username = atoi(temp_username);

			//	get fullname
			fin.getline(full_name, 101, '\n');

			if (a.head == NULL) {
				a.head = new student;
				a.head->id = username;
				a.head->full_name = (string)full_name;
				a.head->class_name = (string)class_year;
				a.head->next = NULL;
				a.head->generatePassword();
				cur = a.head;
			}
			else {
				cur->next = new student;
				cur = cur->next;
				cur->id = username;
				cur->full_name = (string)full_name;
				cur->class_name = (string)class_year;
				cur->generatePassword();
				cur->next = NULL;
			}
		}
	}
	fin.close();
}

void output(const char path[], classYear &a)
{
	ofstream fout;
	fout.open(path);

	student *cur = a.head;

	if (fout.good()) {
		fout << "Class," << a.class_name << "," << endl;
		fout << "No,Student ID,Student name" << endl;
		int count = 1;
		while (cur != NULL) {
			fout << count++ << ",";
			fout << cur->id << ",";
			fout << cur->full_name;
			fout << endl;
			cur = cur->next;
		}
	}

	fout.close();
}

void user::generateUsernameAndPassword() {
	//	generete default username and password for academic staff or lecturer
	//	Nguyen Ho Huu Nghia

	//	find the position of the last name
	int last_space_position;
	for (last_space_position = full_name.length() - 1; last_space_position >= 0; --last_space_position)
		if (full_name[last_space_position] == ' ')
			break;

	//	generate username
	int i;
	string username;
	username += tolower(full_name[0]);

	for (i = 1; i < last_space_position; ++i)
		if (full_name[i] == ' ')
			username += tolower(full_name[i + 1]);

	for (i = last_space_position + 1; i < full_name.length(); ++i)
		username += tolower(full_name[i]);

	//	generate password
	string password = username;
	for (i = phone.size() - 4; i < phone.size(); ++i)
		password += phone[i];
	//	passing the default username and password
	this->username = username;
	this->password = password;
}
void student::generatePassword() {
	//	generate default password for student
	//	by Nghia

	//	find the position of the last name
	int last_space_position;
	for (last_space_position = full_name.length() - 1; last_space_position >= 0; --last_space_position)
		if (full_name[last_space_position] == ' ')
			break;

	//	generate username
	int i;
	string short_name;
	short_name += tolower(full_name[0]);

	for (i = 1; i < last_space_position; ++i)
		if (full_name[i] == ' ')
			short_name += tolower(full_name[i + 1]);

	for (i = last_space_position + 1; i < full_name.length(); ++i)
		short_name += tolower(full_name[i]);

	//	generate password
	string password = short_name;
	for (i = phone.size() - 4; i < phone.size(); ++i)
		password += phone[i];
	
	//	passing the defalut password to the student
	this->password = password;
}

void viewListOfStudentsInAClass(const classList &a) {
	//	let user view the details of all students in a class
	//	Nguyen Ho Huu Nghia


	cout << "Enter the name of the class you want to view: ";
	string class_name;
	cin >> class_name;
	classYear* cur_class;
	cur_class = a.head;
	while (cur_class && cur_class->class_name.compare(class_name)) 
		cur_class = cur_class->next;
	if (!cur_class) {
		cout << "Class not found!\n";
		return;
	}
	if (!cur_class->class_name.compare(class_name)) {
		cout << "Class " << class_name << endl << endl;
		int count = 0;
		cout << setw(10) << "Number" << setw(12) << "Student ID" << setw(30) << "Full name" << setw(30) << "Email" << setw(12) << "Phone" << endl;
		student *cur_student = cur_class->head;
		while (cur_student) {
			cout << setw(10) << count++ << setw(12) << cur_student->id << setw(30) << cur_student->full_name << setw(30) << cur_student->email << setw(12) << cur_student->phone << endl;
			cur_student = cur_student->next;
		}
	}
}

void viewListOfClass(const classList L)
{
	//Nguyen Vo Duc Loc

	classYear *cur = L.head;

	while (cur != NULL)
	{
		cout << cur->class_name << endl;
		cur = cur->next;
	}
}

void classList:: addEmptyClass()
{
	//insert a new empty class into classList
	//Nguyen Vo Duc Loc

	string name;
	cout << "pls enter the name for the class: ";
	getline(cin, name);

	if (head == NULL)
	{
		head = new classYear;
		head->class_name = name;
		head->next = NULL;
		head->head = NULL;
	}
	else
	{
		classYear *cur = head;

		while (cur->next != NULL)
			cur = cur->next;

		cur->next = new classYear;
		cur = cur->next;
		cur->class_name = name;
		cur->head = NULL;
	}
}

void student:: changePassword()
{
	//Nguyen Vo Duc Loc

	string pass, newPass;

	cout << "pls enter your previous password: ";
	getline(cin, pass);

	if (pass != password)
	{
		cout << "wrong password";
		system("pause");
		return;
	}

	cout << "pls enter your new password: ";
	getline(cin, pass);
	cout << "pls enter again your new password: ";
	getline(cin, newPass);

	if (newPass == pass)
	{
		password = newPass;
		cout << "your password is changed successfully";
	}
	else
		cout << "unsucessfully";

	system("pause");
}

void user::changePassword()
{
	//Nguyen Vo Duc Loc

	string pass, newPass;

	cout << "pls enter your previous password: ";
	getline(cin, pass);

	if (pass != password)
	{
		cout << "wrong password";
		system("pause");
		return;
	}

	cout << "pls enter your new password: ";
	getline(cin, pass);
	cout << "pls enter again your new password: ";
	cin >> newPass;

	if (newPass == pass)
	{
		password = newPass;
		cout << "your password is changed successfully";
	}
	else
		cout << "unsucessfully";

	system("pause");
}

void importCourse(string path, courseList& a) {
	//	import courses from a .csv file
	//	Nguyen Ho Huu Nghia

	ifstream fin(path);
	fin.ignore(10000, '\n');

	a.head = NULL;
	if (fin.good()) {

		course* cur;

		//	start reading students' info
		string course_code, course_name, lecturer_username, temp_course_year, temp_semester, temp_day, temp_month, temp_year;
		int course_year, semester, day, month, year;

		while (fin.good()) {

			getline(fin, course_code, ',');
			getline(fin, course_name, ',');
			getline(fin, lecturer_username, ',');
			getline(fin, temp_course_year, ',');
			course_year = stoi(temp_course_year);
			getline(fin, temp_semester, ',');
			semester = stoi(temp_semester);
			getline(fin, temp_day, '/');
			day = stoi(temp_day);
			getline(fin, temp_month, '/');
			month = stoi(temp_month);
			getline(fin, temp_year, ',');
			year = stoi(temp_year);


			if (a.head == NULL) {
				a.head = new course;
				a.head->course_code = course_code;
				a.head->course_name = course_name;
				a.head->lecturer_username = lecturer_username;
				a.head->start_date.day = day;
				a.head->start_date.month = month;
				a.head->start_date.day = day;
				getline(fin, temp_day, '/');
				day = stoi(temp_day);
				getline(fin, temp_month, '/');
				month = stoi(temp_month);
				getline(fin, temp_year, ',');
				year = stoi(temp_year);
				a.head->end_date.day = day;
				a.head->end_date.month = month;
				a.head->end_date.year = year;
				a.head->next = NULL;
				cur = a.head;
			}
			else {
				cur->next = new course;
				cur = cur->next;
				cur->course_code = course_code;
				cur->course_name = course_name;
				cur->lecturer_username = lecturer_username;
				cur->start_date.day = day;
				cur->start_date.month = month;
				cur->start_date.day = day;
				getline(fin, temp_day, '/');
				day = stoi(temp_day);
				getline(fin, temp_month, '/');
				month = stoi(temp_month);
				getline(fin, temp_year, ',');
				year = stoi(temp_year);
				cur->end_date.day = day;
				cur->end_date.month = month;
				cur->end_date.year = year;
				cur->next = NULL;
			}
		}
	}
	fin.close();
}

void editExistingCourse(courseList &a) {
	//	edit the details about an existing course
	//	by Nguyen Ho Huu Nghia

	while(true){
		int temp;
		cout << "Enter the code of the course you want to edit: ";
		string course_code;
		cin >> course_code;

		//	traverse the course list until the course is found or
		//	there is no course left
		course* cur = a.head;
		while (cur && course_code.compare(cur->course_code))
			cur = cur->next;

		//	if there is no course left
		if (!cur){
			cout << "Course not found";
		}
		//	if the course is found
		else {
			while(true){
				cout << "Enter the number of the action you want to take:\n"
					<< "1. Edit the course code\n"
					<< "2. Edit the course name\n"
					<< "3. Edit the lecturer username\n"
					<< "4. Edit the year the course takes place\n"
					<< "5. Edit the semester the course takes place\n";
				cin >> temp;
				switch (temp) {
				case 1:
					cout << "Enter the new course code: ";
					cin >> cur->course_code;
					break;
				case 2:
					cout << "Enter the new course name: ";
					cin >> cur->course_name;
					break;
				case 3:
					cout << "Enter the new lecturer username: ";
					cin >> cur->lecturer_username;
					break;
				case 4:
					cout << "Enter the new year: ";
					cin >> cur->year;
					break;
				case 5:
					cout << "Enter the new semester: ";
					cin >> cur->semester;
					break;
				}
				system("cls");
				cout << "The new information has been added.\n"
					<< "Do you want to edit any other information about this course?\nEnter 0 for \"no\" and 1 for \"yes\"\n";
				if (temp == 0)
					break;
			}
		}
		cout << "Do you want to edit another course?\n"
			<< "Enter 1 if you do and 0 if you don't:\n";
		cin >> temp;
		if (temp == 0)
			break;
	}
}

//	Don't mind this function, it's for experimental purpose for later UI
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showMenu(classList class_list, courseList course_list, userList staff, userList lecturer) {

	//	Show the menu for a student
	//	By Nguyen Ho Huu Nghia

	bool check = true;
	while(check){

		system("cls");
		cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
			<< "\t\t*********************************************************\n\n\n" 
			<< "Enter the number corresponding to your role:\n"
			<< "[1] Student\n"
			<< "[2] Academic Staff\n"
			<< "[3] Lecturer\n\n"
			<< "Your answer: ";
		
		int answer;
		cin >> answer;

		//	if the user is a student
		if(answer==1){

			bool check_1 = true, check_2 = true;
			while (check_1) {
				int temp;
				student* cur_student = class_list.head->head;


				system("cls");
				cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
					<< "\t\t*********************************************************\n\n\n"
					<< "LOG IN\n"
					<< "Username: ";
				string username, password;
				cin >> username;
				cout << "Password: ";
				cin >> password;


				//	Check if there is any student matching the log in info
				while (true) {
					while (cur_student && (username.compare(to_string(cur_student->id)) || password.compare(cur_student->password)))
						cur_student = cur_student->next;

					//	if there is a user
					if (!username.compare(to_string(cur_student->id)))
						break;

					system("cls");
					cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
						<< "\t\t*********************************************************\n\n"
						<< "The username and password match no student\n"
						<< "LOG IN\n"
						<< "Username: ";
					getline(cin, username);
					cout << "Password: ";
					getline(cin, password);
				}


				system("cls");
				cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
					<< "\t\t*********************************************************\n\n";

				cout << "Enter the number corresponding to the action you want to take: \n"
					<< "[1] Show main menu\n"
					<< "[2] Show my information\n"
					<< "[3] Change password\n"
					<< "[4] Log out\n"
					<< "Your answer: ";

				cin >> temp;

				if (temp == 1) {
					int temp_1;

					while (check_2) {

						system("cls");
						cout << "\t\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
							<< "\t\t*********************************************************\n\n";

						cout << "Enter the number corresponding to the action you want to take: \n"
							<< "[1] Check-in\n"
							<< "[2] View check-in result\n"
							<< "[3] View my scores\n"
							<< "[4] View schedules\n"
							<< "[5] Back to the previous menu\n"
							<< "Your answer: ";

						cin >> temp_1;

						if (temp_1 == 1) {

						}
						else if (temp_1 == 2) {

						}
						else if (temp_1 == 3) {

						}
						else if (temp_1 == 4) {

						}
						else if (temp_1 == 5) {
							break;
						}
					}
				}
				else if (temp == 2) {

				}
				else if (temp == 3) {

				}
				else if (temp == 4) {
					break;
				}
				system("cls");
				cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
					<< "\t\t*********************************************************\n\n";

				cout << "Enter the number corresponding to the action you want to take: \n"
					<< "[1] Show main menu\n"
					<< "[2] Show my information\n"
					<< "[3] Change password\n"
					<< "[4] Log out\n"
					<< "Your answer: ";

				cin >> temp;
			}
			continue;
		}

		//	if the user is an academic staff
		else if (answer == 2) {
			bool check_1 = true, check_2 = true;
			while (check_1) {
				int temp;
				user* cur_user = staff.head;


				system("cls");
				cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
					<< "\t\t*********************************************************\n\n\n"
					<< "LOG IN\n"
					<< "Username: ";
				string username, password;
				cin >> username;
				cout << "Password: ";
				cin >> password;


				//	Check if there is any staff matching the log in info
				while (true) {
					while (cur_user && (username.compare(cur_user->username) || password.compare(cur_user->password)))
						cur_user = cur_user->next;

					//	if there is a staff that match the log in info
					if (!username.compare(cur_user->username))
						break;

					//	if there is none then repeat
					system("cls");
					cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
						<< "\t\t*********************************************************\n\n"
						<< "The username and password match no academic staff\n"
						<< "LOG IN\n"
						<< "Username: ";
					getline(cin, username);
					cout << "Password: ";
					getline(cin, password);
				}


				system("cls");
				cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
					<< "\t\t*********************************************************\n\n";

				cout << "Enter the number corresponding to the action you want to take: \n"
					<< "[1] Show main menu\n"
					<< "[2] Show my information\n"
					<< "[3] Change password\n"
					<< "[4] Log out\n"
					<< "Your answer: ";

				cin >> temp;

				if (temp == 1) {
					int temp_1;

					while (check_2) {

						system("cls");
						cout << "\t\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
							<< "\t\t*********************************************************\n\n";

						cout << "Enter the number corresponding to the group of actions you want to take: \n"
							<< "[1] Classes and students\n"
							<< "[2] Courses\n"
							<< "[3] Schedules\n"
							<< "[4] Attendance\n"
							<< "[5] Scoreboard\n"
							<< "[6] Back to the previous menu\n"
							<< "Your answer: ";

						cin >> temp_1;

						if (temp_1 == 1) {

						}
						else if (temp_1 == 2) {

						}
						else if (temp_1 == 3) {

						}
						else if (temp_1 == 4) {

						}
						else if (temp_1 == 5) {

						}
						else if (temp_1 == 6) {
							break;
						}
					}
				}
				else if (temp == 2) {

				}
				else if (temp == 3) {

				}
				else if (temp == 4) {
					break;
				}
				system("cls");
				cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
					<< "\t\t*********************************************************\n\n";

				cout << "Enter the number corresponding to the action you want to take: \n"
					<< "[1] Show main menu\n"
					<< "[2] Show my information\n"
					<< "[3] Change password\n"
					<< "[4] Log out\n"
					<< "Your answer: ";

				cin >> temp;
			}
			continue;
		}
		else if(answer==3) {
			bool check_1 = true, check_2 = true;
			while (check_1) {
				int temp;
				user* cur_user = lecturer.head;


				system("cls");
				cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
					<< "\t\t*********************************************************\n\n\n"
					<< "LOG IN\n"
					<< "Username: ";
				string username, password;
				cin >> username;
				cout << "Password: ";
				cin >> password;


				//	Check if there is any lecturer matching the log in info
				while (true) {
					while (cur_user && (username.compare(cur_user->username) || password.compare(cur_user->password)))
						cur_user = cur_user->next;

					//	if there is a lecturer matching the log in info
					if (!username.compare(cur_user->username))
						break;

					//	if there is none then repeat
					system("cls");
					cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
						<< "\t\t*********************************************************\n\n"
						<< "The username and password match no lecturer\n"
						<< "LOG IN\n"
						<< "Username: ";
					getline(cin, username);
					cout << "Password: ";
					getline(cin, password);
				}


				system("cls");
				cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
					<< "\t\t*********************************************************\n\n";

				cout << "Enter the number corresponding to the action you want to take: \n"
					<< "[1] Show main menu\n"
					<< "[2] Show my information\n"
					<< "[3] Change password\n"
					<< "[4] Log out\n"
					<< "Your answer: ";

				cin >> temp;

				if (temp == 1) {
					int temp_1;

					while (check_2) {

						system("cls");
						cout << "\t\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
							<< "\t\t*********************************************************\n\n";

						cout << "Enter the number corresponding to the action you want to take: \n"
							<< "[1] Import scoreboard of a course(midterm, final, lab, bonus)\n"
							<< "[2] Edit grade of a student\n"
							<< "[3] View a scoreboard\n"
							<< "[4] Back to the previous menu\n"
							<< "Your answer: ";

						cin >> temp_1;

						if (temp_1 == 1) {

						}
						else if (temp_1 == 2) {

						}
						else if (temp_1 == 3) {

						}
						else if (temp_1 == 4) {
							break;
						}
					}
				}
				else if (temp == 2) {

				}
				else if (temp == 3) {

				}
				else if (temp == 4) {
					break;
				}
				system("cls");
				cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
					<< "\t\t*********************************************************\n\n";

				cout << "Enter the number corresponding to the action you want to take: \n"
					<< "[1] Show main menu\n"
					<< "[2] Show my information\n"
					<< "[3] Change password\n"
					<< "[4] Log out\n"
					<< "Your answer: ";

				cin >> temp;
			}
			continue;
		}
	}
}