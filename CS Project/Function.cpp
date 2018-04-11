#include "Function.h"

// 1+2+5
void showMenu(classList class_list, courseList course_list, userList staff, userList lecturer) {

	//	Show the menu for all user
	//	By Nguyen Ho Huu Nghia

	bool check = true;
	while (check) {

		check = true;

		system("cls");
		cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
			<< "\t\t*********************************************************\n\n\n"
			<< "Enter the number corresponding to your role or enter \"4\" to exit:\n"
			<< "[1] Student\n"
			<< "[2] Academic Staff\n"
			<< "[3] Lecturer\n"
			<< "[4] Exit the program\n"
			<< "Your answer: ";

		int answer;
		cin >> answer;

		bool check_1 = true, check_2 = true, first_log_in = true;

		//	if the user is a student
		if (answer == 1) {

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

				//	first menu
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

						//	main menu
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
							check_2 = false;
						}
					}
				}
				else if (temp == 2) {
					cur_student->printInfo();
				}
				else if (temp == 3) {
					cur_student->changePassword();
				}
				else if (temp == 4) {
					check_1 = false;;
				}
			}
			continue;
		}

		//	if the user is an academic staff
		else if (answer == 2) {

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


				while (true) {
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
								while (true) {

									system("cls");
									cout << "\t\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
										<< "\t\t*********************************************************\n\n";

									cout << "Enter the number corresponding to the group of actions you want to take: \n"
										<< "[1] Import students of a class from a csv file\n"
										<< "[2] Add a new student to a class\n"
										<< "[3] Edit an existing student\n"
										<< "[4] Remove a student\n"
										<< "[5] Change students from class A to class B\n"
										<< "[6] Add a new empty class\n"
										<< "[7] View list of classes\n"
										<< "[8] View list of students in a class\n"
										<< "Your answer: ";

									char temp_2;
									cin >> temp_2;
									if (temp_2 == '1') {
										char path[1000];
										cout << "Enter the path of file: ";
										cin.ignore();
										cin.getline(path, 1000);
										classYear *cur_class = createNewNode(class_list.head);
										input(path, *cur_class);
									}
									else if (temp_2 == '2') {
										AddNewStudentToClass(class_list, )
									}
									else if (temp_2 == '3') {

									}
									else if (temp_2 == '3') {

									}
									else if (temp_2 == '4') {

									}
									else if (temp_2 == '5') {

									}
									else if (temp_2 == '6') {

									}
									else if (temp_2 == '7') {

									}
									else if (temp_2 == '8') {

									}
								}
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
								check_2 = false;
							}
						}
					}
					else if (temp == 2) {
						cur_user->printInfo();
					}
					else if (temp == 3) {
						cur_user->changePassword();
					}
					else if (temp == 4) {
						check_1 = false;
						break;
					}
				}
			}
		}


		//	if the user is a lecturer
		else if (answer == 3) {

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


				while (true) {
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
						cur_user->printInfo();
					}
					else if (temp == 3) {
						cur_user->changePassword();
					}
					else if (temp == 4) {
						check_1 = false;
						break;
					}
				}
			}
		}
		else if (answer>3)
			check = false;
	}
}

//	3
void user::printInfo() {
	cout << "Username: " << username << endl
		<< "Full name: " << full_name << endl
		<< "Email: " << email << endl
		<< "Phone: " << phone << endl
		<< "Password: " << password << endl;
}

//	3
void student::printInfo() {
	cout << "Student ID: " << id << endl
		<< "Class : " << class_name << endl
		<< "Full name: " << full_name << endl
		<< "Email: " << email << endl
		<< "Phone: " << phone << endl
		<< "Password: " << password << endl;
}

//	4
void student::changePassword()
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

//	4
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

//	6
void input(char path[], classYear &a)
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

void output(char path[], classYear &a)
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

//	7
void AddNewStudentToClass(classList L, classYear &a)
{
	// Vy Vy
	// Finished

	string classname;
	cout << "Which class you want to add new student? ";
	cin >> classname;

	classYear *cur = L.head;
	while (cur && cur->class_name.compare(classname)) {
		// if == return false 
		cur = cur->next;
	}
	if (!cur) {		//cur==NULL
		cout << "No class found.\n";
		return;
	}
	else if (!cur->class_name.compare(classname)) {	//return false
		student *add = a.head;
		cout << "Enter new student's ID: ";
		int newid;
		cin >> newid;
		//char full_name[101];
		if (newid < add->id) {
			student *tmp = new student;
			tmp->id = newid;
			tmp->class_name = classname;
			cout << "New student's name: ";
			cin.ignore(100, '\n');
			getline(cin, tmp->full_name);
			cout << "Phone number: ";
			getline(cin, tmp->phone);
			cout << "Email: ";
			getline(cin, tmp->email);
			tmp->next = add;
			a.head = tmp;
		}
		else {
			while (add->next && add->next->id < newid) {
				add = add->next;
			}
			if (!add->next) {
				add->next = new student;
				add->id = newid;
				add->class_name = classname;
				cout << "New student's name: ";
				cin.ignore(100, '\n');
				getline(cin, add->full_name);
				cout << "Phone number: ";
				getline(cin, add->phone);
				cout << "Email: ";
				getline(cin, add->email);
				add->next = NULL;
			}
			else {
				student *tmp = new student;
				tmp->id = newid;
				tmp->class_name = classname;
				cout << "New student's name: ";
				cin.ignore(100, '\n');
				getline(cin, tmp->full_name);
				cout << "Phone number: ";
				getline(cin, tmp->phone);
				cout << "Email: ";
				getline(cin, tmp->email);
				tmp->next = add->next;
				add->next = tmp;
			}
		}
	}
}

//	8
void EditStudent(classList L, classYear a)
{
	// Vy Vy
	// Finished

	string classname;
	cout << "Which class you want to edit an existing student? ";
	cin >> classname;

	classYear *cur = L.head;
	while (cur && cur->class_name.compare(classname)) {
		// if == return false 
		cur = cur->next;
	}
	if (!cur) {		//cur==NULL
		cout << "Sorry. No class found.\n";
		return;
	}
	else if (!cur->class_name.compare(classname)) {	//return false
		student *edit = a.head;
		cout << "Enter student ID: ";
		int newid;
		cin >> newid;
		while (edit && newid != edit->id) {
			edit = edit->next;
		}
		if (!edit) {
			cout << "Sorry. No student found.\n";
			return;
		}
		else {
			cout << "What info do you want to edit?\n";
			cout << "1. Phone number\n";
			cout << "2. Email\n";
			cout << "Please enter the appropriate number: ";
			int n;
			cin >> n;

			switch (n) {
			case 1: {
				cout << "Please enter new phone number: ";
				cin >> edit->phone;
				break;
			}
			default: {
				cout << "Please enter new email: ";
				cin >> edit->email;
			}
			}
		}
	}
}

//	10
void moveStudentsFromClassAToB(classList a) {

	//	By NT Tung

	bool t;
	if (t) return;
	string name;
	classYear *cur = a.head, *ca, *cb;
	bool input = false;
	do {
		cout << "Enter a class to transfer from :";
		cin >> name;
		cout << endl;
		while (cur->class_name != name && cur != NULL) {
			cur = cur->next;
		}
		if (cur != NULL) {
			ca = cur;
			input = true;
		}
	} while (!input);
	if (t) return;
	cur = a.head;
	input = false;
	do {
		cout << "Enter a class to transfer to :";
		cin >> name;
		cout << endl;
		while (cur->class_name != name && cur != NULL) {
			cur = cur->next;
		}
		if (cur != NULL) {
			cb = cur;
			if (cb != ca)
				input = true;
		}
	} while (!input);
	if (t) return;
	student *p = ca->head, *ini = ca->head;
	bool discont = false;
	bool trans;
	while (!discont&&p->next != NULL) {
		cout << "Transfer this student out ? not 0 =YES, 0=NO :";
		cout << p->next->id;
		cout << endl;
		cout << p->next->full_name;
		cout << endl;
		cout << p->next->class_name;
		cout << endl;
		cout << p->next->password;
		cout << endl;
		cout << p->next->email;
		cout << endl;
		cout << p->next->phone;
		cout << endl;
		cin >> trans;
		cout << endl;
		if (trans) {
			student *tmp = p->next;
			p->next = p->next->next;
			tmp->next = cb->head;
			cb->head = tmp;
		}
		else p = p->next;
		cout << "Discontinue or not ? not 0 = YES, 0 = NO :";
		cin >> discont;
		if (discont) break;
	}
	cout << "Transfer this student out ? not 0 =YES, 0=NO :";
	cout << ini->id;
	cout << endl;
	cout << ini->full_name;
	cout << endl;
	cout << ini->class_name;
	cout << endl;
	cout << ini->password;
	cout << endl;
	cout << ini->email;
	cout << endl;
	cout << ini->phone;
	cout << endl;
	cin >> trans;
	cout << endl;
	if (trans) {
		ca->head = ini->next;
		ini->next = cb->head;
		cb->head = ini;
	}
	return;
}

//	11
void classList::addEmptyClass()
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

//	12
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

//	13
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

//	14
void importCourses(string path, courseList& a) {
	//	import courses from a .csv file
	//	Nguyen Ho Huu Nghia

	ifstream fin(path);
	fin.ignore(10000, '\n');

	a.head = NULL;
	if (fin.good()) {

		course* cur;

		//	start reading students' info
		string buffer;

		while (fin.good()) {

			if (a.head == NULL) {
				a.head = new course;
				getline(fin, a.head->course_code, ',');
				getline(fin, a.head->course_name, ',');
				getline(fin, a.head->lecturer_username, ',');
				getline(fin, a.head->year, ',');
				getline(fin, buffer, ',');
				a.head->semester = stoi(buffer);

				getline(fin, buffer, '-');
				a.head->start_date.day = stoi(buffer);
				getline(fin, buffer, '-');
				a.head->start_date.month = stoi(buffer);
				getline(fin, buffer, ',');
				a.head->start_date.day = stoi(buffer);

				getline(fin, buffer, '-');
				a.head->end_date.day = stoi(buffer);
				getline(fin, buffer, '-');
				a.head->end_date.month = stoi(buffer);
				getline(fin, buffer, ',');
				a.head->end_date.year = stoi(buffer);
				getline(fin, a.head->room, '\n');
				a.head->next = NULL;
				cur = a.head;
			}

			else {
				cur->next = new course;
				cur = cur->next;
				getline(fin, cur->course_code, ',');
				getline(fin, cur->course_name, ',');
				getline(fin, cur->lecturer_username, ',');
				getline(fin, cur->year, ',');
				getline(fin, buffer, ',');
				cur->semester = stoi(buffer);

				getline(fin, buffer, '-');
				cur->start_date.day = stoi(buffer);
				getline(fin, buffer, '-');
				cur->start_date.month = stoi(buffer);
				getline(fin, buffer, ',');
				cur->start_date.day = stoi(buffer);

				getline(fin, buffer, '-');
				cur->end_date.day = stoi(buffer);
				getline(fin, buffer, '-');
				cur->end_date.month = stoi(buffer);
				getline(fin, buffer, ',');
				cur->end_date.year = stoi(buffer);

				getline(fin, cur->room, '\n');
				cur->next = NULL;
			}
		}
	}
	fin.close();
}

//	15
void courseList::addNewCourse()
{
	//Nguyen Vo Duc Loc
	//add a new empty course to List

	string name, code;

	cin.get();
	cout << "pls enter your course name: ";
	getline(cin, name);

	cout << "pls enter your course code: ";
	cin >> code;

	course *cur = head;
	if (head == NULL)
	{
		head = new course;
		head->course_name = name;
		head->course_code = code;
		head->next = NULL;
		cout << "you add a new course successfully" << endl;
		return;
	}
	else
		while (cur->next != NULL)
			cur = cur->next;
	cur->next = new course;
	cur = cur->next;
	cur->next = NULL;
	cur->course_name = name;
	cur->course_code = code;
	cout << "you add a new course successfully" << endl;
}

//	16
void editExistingCourse(courseList &a) {
	//	edit the details about an existing course
	//	by Nguyen Ho Huu Nghia

	while (true) {
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
		if (!cur) {
			cout << "Course not found";
		}
		//	if the course is found
		else {
			while (true) {
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
					cin.ignore();
					getline(cin, cur->course_name);
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

//	17
void removeAcourse(courseList b)
{
	// Vy Vy
	// Finished but haven't checked
	
	course* cur = b.head;
	course* del;
	string code;
	cout << "Enter the course's code you want to remove: ";
	getline(cin, code, '\n');

	if (b.head || code == b.head->course_code) {		//1st course
		del = b.head;
		b.head = b.head->next;
		delete del;
		return;
	}

	while (cur->next || cur->next->course_code != code)
		cur = cur->next;

	if (cur->next) {
		del = cur->next;
		cur->next = del->next;
		delete del;
	}
	else if (!cur->next) {
		cout << "Sorry, the course you want to delete doesn't exist.\n";
	}
}

//	18
void viewCourseList(course* a) {

	//	By NT Tung

	cout << "List of courses" << endl;
	while (a != NULL) {
		cout << "Course code : " << a->course_code << " Course name : " << a->course_name << endl;
		a = a->next;
	}
}

void gotoxy(int x, int y)
{
	//	Don't mind this function, it's for experimental purpose for later UI

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//	19
void importCoursesSchedulesOfAClass(courseList course_list, classYear* cur_class, string path) {
	
	//	import all courses' schedules of a single class from a .csv file
	//	By Nguyen Ho Huu Nghia

	//	open the file
	ifstream fin;
	fin.open(path);

	//	check if file is succesfully opened
	if (!fin.is_open()) {
		cout << "File at the following address is not loaded: \n"
			<< path <<endl;
		fin.close();
	}
	else{


		//	ignore the 1st line containing the name of columns
		fin.ignore(10000, '\n');


		cur_class->head_course_code = new courseCode;
		cur_class->head_course_code->next = NULL;
		char buffer[5];
		
		getline(fin, cur_class->head_course_code->course_code, ',');

		//	find the corresponding course in the course list
		course *cur_course = course_list.head, *pre_course=cur_course;
		while (cur_course->course_code != cur_class->head_course_code->course_code && cur_course != NULL) {
			pre_course = cur_course;
			cur_course = cur_course->next;
		}

		//	if the course doesn't exist, add a new one
		if (cur_course == NULL) {
			pre_course->next = new course;
			cur_course = pre_course->next;
		}
		
		getline(fin, cur_course->course_name, ',');
		getline(fin, cur_course->lecturer_username, ',');


		schedule* cur_schedule = createNewNode(cur_course->head_schedule);
		


		getline(fin, cur_schedule->year, ',');

		fin.getline(buffer, 2, ',');
		cur_schedule->semester = atoi(buffer);

		//	start date
		fin.getline(buffer, 3, '-');
		cur_schedule->start_date.day = atoi(buffer);
		fin.getline(buffer, 3, '-');
		cur_schedule->start_date.month = atoi(buffer);
		fin.getline(buffer, 5, ',');
		cur_schedule->start_date.year = atoi(buffer);

		//	end date
		fin.getline(buffer, 3, '-');
		cur_schedule->end_date.day = atoi(buffer);
		fin.getline(buffer, 3, '-');
		cur_schedule->end_date.month = atoi(buffer);
		fin.getline(buffer, 5, ',');
		cur_schedule->end_date.year = atoi(buffer);

		fin.getline(buffer, 2, ',');
		switch (atoi(buffer)) {
		case 1:
			cur_schedule->course_session.session_day = sunday;
			break;
		case 2:
			cur_schedule->course_session.session_day = monday;
			break;
		case 3:
			cur_schedule->course_session.session_day = tuesday;
			break;
		case 4:
			cur_schedule->course_session.session_day = wednesday;
			break;
		case 5:
			cur_schedule->course_session.session_day = thursday;
			break;
		case 6:
			cur_schedule->course_session.session_day = friday;
			break;
		case 7:
			cur_schedule->course_session.session_day = saturday;
			break;
		}
		//	Start time
		fin.getline(buffer, 3, ':');
		cur_schedule->course_session.start.hour = atoi(buffer);
		fin.getline(buffer, 3, ',');
		cur_schedule->course_session.start.minute = atoi(buffer);

		//	End time
		fin.getline(buffer, 3, ':');
		cur_schedule->course_session.end.hour = atoi(buffer);
		fin.getline(buffer, 3, ',');
		cur_schedule->course_session.end.minute = atoi(buffer);

		//	Get room
		getline(fin, cur_schedule->room, '\n');

		/*
		cur_class.head_course->course_code = course_code;
		cur_class.head_course->course_name = course_name;
		cur_class.head_course->lecturer_username = lecturer_username;
		cur_class.head_course->year = year;
		cur_class.head_course->semester = semester;
		cur_class.head_course->start_date = start_date;
		cur_class.head_course->end_date = end_date;
		cur_class.head_course->course_session = course_session;
		cur_class.head_course->room = room;
		*/

		courseCode* cur_course_code = cur_class->head_course_code;


		while (fin.good()) {

			//	create a new course code 
			cur_course_code->next = new courseCode;
			cur_course_code = cur_course_code->next;

			getline(fin, cur_course_code->course_code, ',');

			//	find the corresponding course in the course list
			course *cur_course = course_list.head, *pre_course = cur_course;
			while (cur_course->course_code != cur_course_code->course_code && cur_course != NULL) {
				pre_course = cur_course;
				cur_course = cur_course->next;
			}

			//	if the course doesn't exist, add a new one
			if (cur_course == NULL) {
				pre_course->next = new course;
				cur_course = pre_course->next;
			}

			getline(fin, cur_course->course_name, ',');
			getline(fin, cur_course->lecturer_username, ',');

			schedule* cur_schedule = createNewNode(cur_course->head_schedule);


			getline(fin, cur_schedule->year, ',');

			fin.getline(buffer, 2, ',');
			cur_schedule->semester = atoi(buffer);

			//	start date
			fin.getline(buffer, 3, '-');
			cur_schedule->start_date.day = atoi(buffer);
			fin.getline(buffer, 3, '-');
			cur_schedule->start_date.month = atoi(buffer);
			fin.getline(buffer, 5, ',');
			cur_schedule->start_date.year = atoi(buffer);

			//	end date
			fin.getline(buffer, 3, '-');
			cur_schedule->end_date.day = atoi(buffer);
			fin.getline(buffer, 3, '-');
			cur_schedule->end_date.month = atoi(buffer);
			fin.getline(buffer, 5, ',');
			cur_schedule->end_date.year = atoi(buffer);

			fin.getline(buffer, 2, ',');
			switch (atoi(buffer)) {
			case 1:
				cur_schedule->course_session.session_day = sunday;
				break;
			case 2:
				cur_schedule->course_session.session_day = monday;
				break;
			case 3:
				cur_schedule->course_session.session_day = tuesday;
				break;
			case 4:
				cur_schedule->course_session.session_day = wednesday;
				break;
			case 5:
				cur_schedule->course_session.session_day = thursday;
				break;
			case 6:
				cur_schedule->course_session.session_day = friday;
				break;
			case 7:
				cur_schedule->course_session.session_day = saturday;
				break;
			}
			//	Start time
			fin.getline(buffer, 3, ':');
			cur_schedule->course_session.start.hour = atoi(buffer);
			fin.getline(buffer, 3, ',');
			cur_schedule->course_session.start.minute = atoi(buffer);

			//	End time
			fin.getline(buffer, 3, ':');
			cur_schedule->course_session.end.hour = atoi(buffer);
			fin.getline(buffer, 3, ',');
			cur_schedule->course_session.end.minute = atoi(buffer);

			//	Get room
			getline(fin, cur_schedule->room, '\n');

		}
		fin.close();
	}

}

//	20
void addACourseSchedule(courseList course_list, classList class_list) {
	
	//	add a new course at the end of the course list and let the user type in its schedule
	//	by Nguyen Ho Huu Nghia

	string class_name;
	cout << "Enter the name of the class: ";
	cin >> class_name;

	//	find the class in the class list
	classYear* cur_class = class_list.head;
	if (class_list.head->class_name != class_name){
		while (cur_class->next != NULL && cur_class->class_name != class_name)
			cur_class = cur_class->next;
		if (cur_class->next == NULL) {
			cout << "Class not found.\n";
			return;
		}
		else {
			cur_class = cur_class->next;
		}
	}
	
	char buffer[100];
	courseCode* cur_course_code = createNewNode(cur_class->head_course_code);

	system("cls");
	cout << "Enter the course code: ";
	cin >> cur_course_code->course_code;
	
	course *cur_course = course_list.head;
	if (course_list.head == NULL) {
		cout << "Course does not exist. Do you want to add it?\n"
			<<"[Y]Yes\n[N]No\n"
			<<"Your answer: ";
		char a;
		cin >> a;
		if (a == 'N')
			return;
		else {
			cur_course = new course;
		}
	}
	else {
		while (cur_course->next && cur_course->next->course_code!=cur_course_code->course_code)
			cur_course = cur_course->next;
		if (!cur_course->next) {
			cout << "Course does not exist. Do you want to add it?\n"
				<< "[Y]Yes\n[N]No\n"
				<< "Your answer: ";
			char a;
			cin >> a;
			if (a == 'N')
				return;
			else {
				cur_course->next = new course;
				cur_course = cur_course->next;
			}
		}
		else {
			cur_course = cur_course->next;
		}
	}

	schedule *cur_schedule = createNewNode(cur_course->head_schedule);


	/*
	system("cls");
	cout << "Enter the course name: ";
	cin.ignore();
	cin.getline(buffer, 100, '\n');
	cur_course->course_name = buffer;

	system("cls");
	cout << "Enter the course lecturer username: ";
	cin.getline(buffer, 100, '\n');
	cur_course->lecturer_username = buffer;
	*/


	system("cls");
	cout << "Enter the year in which the course take place: ";
	cin.ignore();
	getline(cin, cur_course->year, '\n');
	system("cls");
	cout << "Enter the semester in which the course take place: ";
	cin >> cur_course->semester;
	system("cls");

	cout << "Enter the start date in the format of dd-mm-yyyy: ";
	cin.ignore();
	cin.getline(buffer, 3, '-');
	cur_schedule->start_date.day = atoi(buffer);
	cin.getline(buffer, 3, '-');
	cur_schedule->start_date.month = atoi(buffer);
	cin.getline(buffer, 5, '\n');
	cur_schedule->start_date.year = atoi(buffer);

	system("cls");
	cout << "Enter the end date in the format of dd-mm-yyyy: ";
	cin.getline(buffer, 3, '-');
	cur_schedule->end_date.day = atoi(buffer);
	cin.getline(buffer, 3, '-');
	cur_schedule->end_date.month = atoi(buffer);
	cin.getline(buffer, 5, '\n');
	cur_schedule->end_date.year = atoi(buffer);

	system("cls");
	cout << "Enter the day of the week in which the session take place:\n"
		<< "[1] Sunday\n"
		<< "[2] Monday\n"
		<< "[3] Tuesday\n"
		<< "[4] Wednesday\n"
		<< "[5] Thursday\n"
		<< "[6] Friday\n"
		<< "[7] Saturday\n";
	int temp;
	cin >> temp;
	switch (temp) {
	case 1:
		cur_schedule->course_session.session_day = sunday;
		break;
	case 2:
		cur_schedule->course_session.session_day = monday;
		break;
	case 3:
		cur_schedule->course_session.session_day = tuesday;
		break;
	case 4:
		cur_schedule->course_session.session_day = wednesday;
		break;
	case 5:
		cur_schedule->course_session.session_day = thursday;
		break;
	case 6:
		cur_schedule->course_session.session_day = friday;
		break;
	case 7:
		cur_schedule->course_session.session_day = saturday;
		break;
	}

	system("cls");
	cout << "Enter the start time of the session in the format hh:mm : ";
	cin.get();
	cin.getline(buffer, 3, ':');
	cur_schedule->course_session.start.hour = atoi(buffer);
	cin.getline(buffer, 3, '\n');
	cur_schedule->course_session.start.minute = atoi(buffer);

	system("cls");
	cout << "Enter the end time of the session in the format hh:mm : ";
	cin.getline(buffer, 3, ':');
	cur_schedule->course_session.end.hour = atoi(buffer);
	cin.getline(buffer, 3, '\n');
	cur_schedule->course_session.end.minute = atoi(buffer);

	system("cls");
	cout << "Enter the name of the room in which the session takes place: ";
	cin >> cur_schedule->room;
}

bool exit() {
	bool t;
	cout << "Do you want to exit ? not 0 =YES, 0=NO : ";
	cin >> t;
	return t;
}

//	25
void viewAttendance(courseList course_list, presence* head_presence)
{
	// Haven't checked
	// Vy Vy

	string code;
	cout << "Enter code of the course you want to check attendance: ";
	cin >> code;
	course* cur = course_list.head;

	while (cur && cur->course_code != code) {
		cur = cur->next;
	}
	if (!cur)
		cout << "Sorry, the course you enter doesn't exist.\n";
	else {
		presence* student_presence = head_presence;
		while (student_presence) {
			cout << setw(17) << "Monday" << setw(5 + 7) << "Tuesday" << setw(5 + 9) << "Wednesday";
			cout << setw(5 + 7) << "Thurday" << setw(5 + 6) << "Friday" << setw(5 + 8) << "Saturday";
			cout << endl;
			cout << student_presence->id << setw(5);
			cout << student_presence->attendance[0] << setw(5 + 6);
			cout << student_presence->attendance[1] << setw(5 + 7);
			cout << student_presence->attendance[2] << setw(5 + 9);
			cout << student_presence->attendance[3] << setw(5 + 7);
			cout << student_presence->attendance[4] << setw(5 + 6);
			cout << student_presence->attendance[5];
			cout << endl;
			student_presence = student_presence->next;
		}

void moveStudentsFromClassAToB(classList a) {

	//	By NT Tung

	bool t;
	if (t) return;
	string name;
	classYear *cur = a.head, *ca, *cb;
	bool input = false;
	do {
		cout << "Enter a class to transfer from :";
		cin >> name;
		cout << endl;
		while (cur->class_name != name && cur != NULL) {
			cur = cur->next;
		}
		if (cur != NULL) {
			ca = cur;
			input = true;
		}
	} while (!input);
	if (t) return;
	cur = a.head;
	input = false;
	do {
		cout << "Enter a class to transfer to :";
		cin >> name;
		cout << endl;
		while (cur->class_name != name && cur != NULL) {
			cur = cur->next;
		}
		if (cur != NULL) {
			cb = cur;
			if (cb != ca)
				input = true;
		}
	} while (!input);
	if (t) return;
	student *p = ca->head, *ini = ca->head;
	bool discont = false;
	bool trans;
	while (!discont&&p->next != NULL) {
		cout << "Transfer this student out ? not 0 =YES, 0=NO :";
		cout << p->next->id;
		cout << endl;
		cout << p->next->full_name;
		cout << endl;
		cout << p->next->class_name;
		cout << endl;
		cout << p->next->password;
		cout << endl;
		cout << p->next->email;
		cout << endl;
		cout << p->next->phone;
		cout << endl;
		cin >> trans;
		cout << endl;
		if (trans) {
			student *tmp = p->next;
			p->next = p->next->next;
			tmp->next = cb->head;
			cb->head = tmp;
		}
		else p = p->next;
		cout << "Discontinue or not ? not 0 = YES, 0 = NO :";
		cin >> discont;
		if (discont) break;
	}
	cout << "Transfer this student out ? not 0 =YES, 0=NO :";
	cout << ini->id;
	cout << endl;
	cout << ini->full_name;
	cout << endl;
	cout << ini->class_name;
	cout << endl;
	cout << ini->password;
	cout << endl;
	cout << ini->email;
	cout << endl;
	cout << ini->phone;
	cout << endl;
	cin >> trans;
	cout << endl;
	if (trans) {
		ca->head = ini->next;
		ini->next = cb->head;
		cb->head = ini;
	}
	return;
}
void exportPresence(string path, course a) {

	//	By NT Tung

	ofstream fout;
	fout.open(path);
	presence *cur = a.head_presence;
	fout << a.course_code << endl;
	while (cur != NULL) {
		fout << cur->id << endl;
		cur = cur->next;
	}
}

//	26
course* searchCourse(string a, course *b) {

	//	By NT Tung

	while (b != NULL) {
		if (b->course_code == a) return b;
		b = b->next;
	}
	return NULL;
}

//	26
void viewScore(course* a) {

	//	By NT Tung

	presence* cur = a->head_presence;
	cout << "Scoreboard of " << a->course_code << endl;
	while (cur != NULL) {
		cout << "ID : " << cur->id << " Midterm : " << cur->midterm << " Lab : " << cur->lab << " Final : " << cur->final << endl;
		cur = cur->next;
	}
}
