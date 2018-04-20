#include "Function.h"

// 1+2+5
void showMenu(classList &class_list, courseList &course_list, userList &staff, userList &lecturer, studentList_t &student_list) {
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
				char temp;

				student* cur_student = student_list.head;


				system("cls");
				cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
					<< "\t\t*********************************************************\n\n\n"
					<< "LOG IN\n"
					<< "Username: ";
				string password;
				string str_username;
				cin >> str_username;
				if (isNumber(str_username) == false) 
					while(isNumber(str_username)==false){
						system("cls");
						cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
							<< "\t\t*********************************************************\n\n"
							<< "The username of a student must be a number.\n"
							<< "LOG IN\n"
							<< "Username: ";
						cin >> str_username;
					}
				int username = stoi(str_username);
				cout << "Password: ";
				inputPassword(password);


				//	Check if there is any student matching the log in info
				while (true) {
					cur_student = student_list.head;
					while (cur_student && (username != cur_student->id || password != cur_student->password))
						cur_student = cur_student->next;

					//	if there is no staff that matches the log in info
					if (!cur_student) {
						password = "";
						system("cls");
						cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
							<< "\t\t*********************************************************\n\n"
							<< "The username and password match no student\n"
							<< "Do you want to go back to the previous menu? You can exit the program from there. Otherwise you can try to retype the password.\n"
							<< "[y]Yes\n[n]No\n";
						char go_back_after_wrong_pass;
						cin.ignore();
						cin.get(go_back_after_wrong_pass);
						if (go_back_after_wrong_pass == 'y' || go_back_after_wrong_pass == 'Y') {
							check_1 = false;
							break;
						}
						else {
							system("cls");
							cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
								<< "\t\t*********************************************************\n\n"
								<< "The username and password match no student\n"
								<< "LOG IN\n"
								<< "Username: ";
							cin >> str_username;
							username = stoi(str_username);
							cout << "Password: ";
							inputPassword(password);
							continue;
						}
					}
					else break;
				}

				if (check_1 == false)
					break;

				while (true) {
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
					cin.ignore();
					cin.get(temp);

					if (temp == '1') {

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
							cout << "---------------------------------------------------------\n\n";

							if (temp_1 == 1) {
								checkIn(cur_student, course_list);
							}
							else if (temp_1 == 2) {
								viewCheckInResult(cur_student, course_list);
							}
							else if (temp_1 == 3) {
								viewMyScore(course_list);
							}
							else if (temp_1 == 4) {
								viewListOfSchedules(course_list, class_list);
							}
							else if (temp_1 == 5) {
								break;
							}
							system("pause");
						}
					}
					else if (temp == '2') {
						cout << "---------------------------------------------------------\n\n";
						cur_student->printInfo();
						system("pause");
					}
					else if (temp == '3') {
						cout << "---------------------------------------------------------\n\n";
						cur_student->changePassword();
						system("pause");
					}
					else if (temp == '4') {
						check_1 = false;
						break;
					}
				}
			}
			continue;
		}

		//	if the user is an academic staff
		else if (answer == 2) {

			while (check_1) {
				char temp;
				user* cur_user = staff.head;


				system("cls");
				cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
					<< "\t\t*********************************************************\n\n\n"
					<< "LOG IN\n"
					<< "Username: ";
				string username, password;
				cin >> username;
				cout << "Password: ";
				inputPassword(password);


				//	Check if there is any staff matching the log in info
				while (true) {
					cur_user = staff.head;
					while (cur_user && (username != cur_user->username || password != cur_user->password))
						cur_user = cur_user->next;

					//	if there is no staff that matches the log in info
					if (!cur_user) {
						password = "";
						system("cls");
						cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
							<< "\t\t*********************************************************\n\n"
							<< "The username and password match no academic staff\n"
							<< "Do you want to go back to the previous menu? You can exit the program from there. Otherwise you can try to retype the password.\n"
							<< "[y]Yes\n[n]No\n";
						char go_back_after_wrong_pass;
						cin.ignore();
						cin.get(go_back_after_wrong_pass);
						if (go_back_after_wrong_pass == 'y' || go_back_after_wrong_pass == 'Y') {
							check_1 = false;
							break;
						}
						else {
							system("cls");
							cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
								<< "\t\t*********************************************************\n\n"
								<< "The username and password match no academic staff\n"
								<< "LOG IN\n"
								<< "Username: ";
							cin >> username;
							cout << "Password: ";
							inputPassword(password);
							continue;
						}
					}
					else break;
				}

				if (check_1 == false)
					break;


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

					if (temp == '1') {
						char temp_1;

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

							cin.ignore();
							cin.get(temp_1);

							if (temp_1 == '1') {
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
										<< "[9] Back to the previous menu\n"
										<< "Your answer: ";

									char temp_2;
									cin >> temp_2;
									cout << "---------------------------------------------------------\n\n";
									if (temp_2 == '1') {
										input(class_list, student_list);
									}
									else if (temp_2 == '2') {
										AddNewStudentToClass(class_list);
									}
									else if (temp_2 == '3') {
										EditStudent(class_list);
									}
									else if (temp_2 == '4') {
										removeAcourse(course_list);
									}
									else if (temp_2 == '5') {
										moveStudentsFromClassAToB(class_list);
									}
									else if (temp_2 == '6') {
										class_list.addEmptyClass();
									}
									else if (temp_2 == '7') {
										viewListOfClass(class_list);
									}
									else if (temp_2 == '8') {
										viewListOfStudentsInAClass(class_list);
									}
									else
										break;

									system("pause");
								}
							}
							else if (temp_1 == '2') {
								while (true) {

									system("cls");
									cout << "\t\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
										<< "\t\t*********************************************************\n\n";

									cout << "Enter the number corresponding to the group of actions you want to take: \n"
										<< "[1] Import courses from a csv file\n"
										<< "[2] Add a new course\n"
										<< "[3] Edit an existing course\n"
										<< "[4] Remove a course\n"
										<< "[5] View list of courses\n"
										<< "[6] Back to the previous menu\n"
										<< "Your answer: ";

									char temp_2;
									cin >> temp_2;
									cout << "---------------------------------------------------------\n\n";
									if (temp_2 == '1') {
										importCourses(course_list, student_list);
									}
									else if (temp_2 == '2') {
										course_list.addNewCourse();
									}
									else if (temp_2 == '3') {
										editExistingCourse(course_list);
									}
									else if (temp_2 == '4') {
										removeAcourse(course_list);
									}
									else if (temp_2 == '5') {
										viewCourseList(course_list);
									}
									else
										break;
									system("pause");
								}
							}
							else if (temp_1 == '3') {
								while (true) {

									system("cls");
									cout << "\t\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
										<< "\t\t*********************************************************\n\n";

									cout << "Enter the number corresponding to the group of actions you want to take: \n"
										<< "[1] Import courses schedules from a .csv file\n"
										<< "[2] Add a course\'s schedule\n"
										<< "[3] Edit a course\'s schedule\n"
										<< "[4] Remove a course\'s schedule\n"
										<< "[5] View list of schedules\n"
										<< "[6] Back to the previous menu\n"
										<< "Your answer: ";

									char temp_2;
									cin >> temp_2;
									cout << "---------------------------------------------------------\n\n";
									if (temp_2 == '1') {
										importCoursesSchedulesOfAClass(course_list, class_list);
									}
									else if (temp_2 == '2') {
										addACourseSchedule(course_list, class_list);
									}
									else if (temp_2 == '3') {
										editCourseSchedule(course_list);
									}
									else if (temp_2 == '4') {
										removeCourseSchedule(course_list);
									}
									else if (temp_2 == '5') {
										viewListOfSchedules(course_list, class_list);
									}
									else
										break;
									system("pause");
								}
							}
							else if (temp_1 == '4') {
								while (true) {

									system("cls");
									cout << "\t\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
										<< "\t\t*********************************************************\n\n";

									cout << "Enter the number corresponding to the group of actions you want to take: \n"
										<< "[1] Search and view attendance list of a course\n"
										<< "[2] Export attendance list to a csv file\n"
										<< "[3] Back to the previous menu\n"
										<< "Your answer: ";

									char temp_2;
									cin >> temp_2;
									cout << "---------------------------------------------------------\n\n";
									if (temp_2 == '1') {
										viewAttendance(course_list);
									}
									else if (temp_2 == '2') {
										//exportPresence()
									}
									else
										break;
									system("pause");
								}
							}
							else if (temp_1 == '5') {
								while (true) {

									system("cls");
									cout << "\t\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
										<< "\t\t*********************************************************\n\n";

									cout << "Enter the number corresponding to the group of actions you want to take: \n"
										<< "[1] Search and view scoreboard of a course.\n"
										<< "[2] Export a scoreboard to a csv file.\n"
										<< "[3] Back to the previous menu.\n"
										<< "Your answer: ";

									char temp_2;
									cin >> temp_2;
									cout << "---------------------------------------------------------\n\n";
									if (temp_2 == '1') {
										cout << "Enter the name of the course: ";
										string course_name;
										getline(cin, course_name, '\n');
										viewScore(searchCourse(course_name, course_list.head));
									}
									else if (temp_2 == '2') {
										//exportScoreboardToCsv(course_list);
									}
									else
										break;
									system("pause");
								}
							}
							else if (temp_1 == '6') {
								check_2 = false;
							}
							else if (temp_1 == 6) {
								break;
							}
						}
					else if (temp == '2') {
						cout << "---------------------------------------------------------\n\n";
						cur_user->printInfo();
						system("pause");
					}
					else if (temp == '3') {
						cout << "---------------------------------------------------------\n\n";
						cur_user->changePassword();
						system("pause");
					}
					else if (temp == '4') {
						check_1 = false;
						break;
					}
					}
				}
			}

		}
			//	if the user is a lecturer
		else if (answer == 3) {

			while (check_1) {
				char temp;
				user* cur_user = lecturer.head;


				system("cls");
				cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
					<< "\t\t*********************************************************\n\n\n"
					<< "LOG IN\n"
					<< "Username: ";
				string username, password;
				cin >> username;
				cout << "Password: ";
				inputPassword(password);


				//	Check if there is any lecturer matching the log in info
				while (true) {
					cur_user = staff.head;
					while (cur_user && (username != cur_user->username || password != cur_user->password))
						cur_user = cur_user->next;

					//	if there is no staff that matches the log in info
					if (!cur_user) {
						password = "";
						system("cls");
						cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
							<< "\t\t*********************************************************\n\n"
							<< "The username and password match no lecturer\n"
							<< "Do you want to go back to the previous menu? You can exit the program from there. Otherwise you can try to retype the password.\n"
							<< "[y]Yes\n[n]No\n";
						char go_back_after_wrong_pass;
						cin.ignore();
						cin.get(go_back_after_wrong_pass);
						if (go_back_after_wrong_pass == 'y' || go_back_after_wrong_pass == 'Y') {
							check_1 = false;
							break;
						}
						else {
							system("cls");
							cout << "\t\t\t\tSTUDENT MANAGEMENT PROGRAM\n"
								<< "\t\t*********************************************************\n\n"
								<< "The username and password match no lecturer\n"
								<< "LOG IN\n"
								<< "Username: ";
							cin >> username;
							cout << "Password: ";
							inputPassword(password);
							continue;
						}
					}
					else break;
				}

				if (check_1 == false)
					break;


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

					cin.ignore();
					cin.get(temp);

					if (temp == '1') {
						char temp_1;

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

							cin.get(temp_1);
							cout << "---------------------------------------------------------\n\n";

							if (temp_1 == '1') {

							}
							else if (temp_1 == '2') {
								editGrade(course_list);
							}
							else if (temp_1 == '3') {
								//viewScore
							}
							else if (temp_1 == '4') {
								break;
							}
							system("pause");
						}
					}
					else if (temp == '2') {
						cout << "---------------------------------------------------------\n\n";
						cur_user->printInfo();
						system("pause");
					}
					else if (temp == '3') {
						cout << "---------------------------------------------------------\n\n";
						cur_user->changePassword();
						system("pause");
					}
					else if (temp == '4') {
						check_1 = false;
						break;
					}
				}
			}
		}
		else if (answer > 3){
			check = false;
		}
	}
}

void importUsers(userList &staff, string path) {
	//import staffs list from a csv file
	//By Nguyen Ho Huu Nghia

	ifstream fin(path);
	fin.ignore(1000, '\n');
	staff.head = new user;
	user* cur_user = staff.head;
	string buffer;
	getline(fin, buffer, ',');
	if (buffer.empty()) {
		getline(fin, staff.head->full_name, ',');
		getline(fin, staff.head->email, ',');
		getline(fin, staff.head->phone, ',');
		getline(fin, staff.head->password, '\n');
		staff.head->generateUsernameAndPassword();
		while (fin.good()) {
			cur_user->next = new user;
			cur_user = cur_user->next;
			fin.ignore(10, ',');
			getline(fin, cur_user->full_name,',');
			getline(fin, cur_user->email, ',');
			getline(fin, cur_user->phone, ',');
			getline(fin, cur_user->password, '\n');
			cur_user->generateUsernameAndPassword();
		}
	}
	else {
		staff.head->username = buffer;
		getline(fin, staff.head->full_name, ',');
		getline(fin, staff.head->email, ',');
		getline(fin, staff.head->phone, ',');
		getline(fin, staff.head->password, '\n');
		while (fin.good()) {
			cur_user->next = new user;
			cur_user = cur_user->next;
			fin.ignore(10, ',');
			getline(fin, cur_user->username,',');
			getline(fin, cur_user->full_name,',');
			getline(fin, cur_user->email, ',');
			getline(fin, cur_user->phone, ',');
			getline(fin, cur_user->password, '\n');
		}
	}
	fin.close();
}
//	3
void user::printInfo() {
	cout << "Username: " << username << endl
		<< "Full name: " << full_name << endl
		<< "Email: " << email << endl
		<< "Phone: " << phone << endl;
}

//	3
void student::printInfo() {
	cout << "Student ID: " << id << endl
		<< "Class : " << class_name << endl
		<< "Full name: " << full_name << endl
		<< "Email: " << email << endl
		<< "Phone: " << phone << endl;
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

	cin.ignore(50, '\n');

	cout << "pls enter your previous password: ";
	inputPassword(pass);

	if (pass != password)
	{
		cout << "wrong password";
		system("pause");
		return;
	}

	pass = "";
	cout << "\npls enter your new password: ";
	inputPassword(pass);
	cout << "\npls enter again your new password: ";
	inputPassword(newPass);

	if (newPass == pass)
	{
		password = newPass;
		cout << "\nyour password is changed successfully";
	}
	else
	{
		cout << "\n" << newPass << "\n" << pass;
		cout << "\nunsucessfully";
	}
}

// ghi de password
void saveNewPasswordForStaff(char path[], userList staff)
{

	//Vy Vy

	ofstream fout;
	fout.open(path);

	user *newstaff = staff.head;

	if (fout.good()) {
		fout << "Username,Full name,Email,Mobile phone,Password\n";
		while (newstaff) {
			fout << newstaff->username << "," << newstaff->full_name << "," << newstaff->email << "," << newstaff->phone << "," << newstaff->password;
			fout << endl;
			newstaff = newstaff->next;
		}
	}

	fout.close();
}

// ghi de password
void saveNewPasswordForLecturer(char path[], userList lecturer)
{
	//Vy Vy

	ofstream fout;
	fout.open(path);

	user *newstaff = lecturer.head;

	if (fout.good()) {
		fout << "Username,Full name,Email,Mobile phone,Password\n";
		while (newstaff) {
			fout << newstaff->username << "," << newstaff->full_name << "," << newstaff->email << "," << newstaff->phone << "," << newstaff->password;
			fout << endl;
			newstaff = newstaff->next;
		}
	}

	fout.close();
}

	// ghi de password
void saveNewPasswordForStaff(char path[], userList staff)
	{

		//Vy Vy

		ofstream fout;
		fout.open(path);

		user *newstaff = staff.head;

		if (fout.good()) {
			fout << "Username,Full name,Email,Mobile phone,Password\n";
			while (newstaff) {
				fout << newstaff->username << "," << newstaff->full_name << "," << newstaff->email << "," << newstaff->phone << "," << newstaff->password;
				if(newstaff->next!=NULL)
					fout << endl;
				newstaff = newstaff->next;
			}
		}

		fout.close();
	}

	// ghi de password
void saveNewPasswordForLecturer(char path[], userList lecturer)
	{
		//Vy Vy

		ofstream fout;
		fout.open(path);

		user *newstaff = lecturer.head;

		if (fout.good()) {
			fout << "Username,Full name,Email,Mobile phone,Password\n";
			while (newstaff) {
				fout << newstaff->username << "," << newstaff->full_name << "," << newstaff->email << "," << newstaff->phone << "," << newstaff->password;
				if(newstaff->next!=NULL)
					fout << endl;
				newstaff = newstaff->next;
			}
		}

		fout.close();
	}

//	6
void input(char path[], classYear &a, studentList_t &student_list)
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
				if(a.head->password.empty()==true)
					a.head->generatePassword();
				student* cur_student = NULL;
				addIfNotAdded(student_list.head, a.head->id, cur_student);
				if(cur_student!=NULL)
					*cur_student = *a.head;
				cur = a.head;
			}
			else {
				cur->next = new student;
				cur = cur->next;
				cur->id = username;
				cur->full_name = (string)full_name;
				cur->class_name = (string)class_year;
				if(cur->password.empty()==true)
					cur->generatePassword();
				student* cur_student = NULL;
				addIfNotAdded(student_list.head, cur->id, cur_student);
				if (cur_student != NULL)
					*cur_student = *cur;
				cur->next = NULL;
			}
		}
	}
	fin.close();
}

// 6
void input(classList &class_list, studentList_t &student_list)
{
	//	load an entire new class from a .csv file;
	//	Nguyen Ho Huu Nghia
	//	For the users
	//	Haven't checked

	string path;
	cout << "Enter the path of the file: ";
	getline(cin, path, '\n');

	string class_name;
	cout << "Enter the name of the class: ";
	if (class_list.head->class_name == class_name) {
		cout << "The class already existed.\n";
	}
	else {
		classYear* cur_class = class_list.head;
		while (cur_class->next && cur_class->next->class_name != cur_class->class_name)
			cur_class = cur_class->next;
		if (cur_class->next == NULL) {
			cur_class->next = new classYear;
			cur_class = cur_class->next;
			ifstream fin(path);
			if (fin.good()) {
				//	ignore Class,
				fin.ignore(1000, ',');
				//	get Class Year
				char class_year[16];
				fin.getline(class_year, 16, ',');
				cur_class->class_name = (string)class_year;
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

					if (cur_class->head == NULL) {
						cur_class->head = new student;
						cur_class->head->id = username;
						cur_class->head->full_name = (string)full_name;
						cur_class->head->class_name = (string)class_year;
						cur_class->head->next = NULL;
						if(cur_class->head->password.empty()==true)
							cur_class->head->generatePassword();
						student* cur_student = NULL;
						addIfNotAdded(student_list.head, cur_class->head->id, cur_student);
						if(cur_student!=NULL)
							*cur_student = *cur_class->head;
						cur = cur_class->head;
					}
					else {
						cur->next = new student;
						cur = cur->next;
						cur->id = username;
						cur->full_name = (string)full_name;
						cur->class_name = (string)class_year;
						if (cur->password.empty() == true)
							cur->generatePassword();
						student* cur_student = NULL;
						addIfNotAdded(student_list.head, cur->id, cur_student);
						if (cur_student != NULL)
							*cur_student = *cur;
						cur->next = NULL;
					}
				}
			}
			fin.close();

		}
		else
			cout << "The class already existed.\n";
	}

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
void AddNewStudentToClass(classList L)
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
		student *add = cur->head;
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
			tmp->generatePassword();
			tmp->next = add;
			cur->head = tmp;
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
				add->generatePassword();
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
				tmp->generatePassword();
				tmp->next = add->next;
				add->next = tmp;
			}
		}
	}
}

//	8
void EditStudent(classList L)
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
		student *edit = cur->head;
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
//9
void removeAStudent(classList &class_list)
{
	// Vy Vy

	string classname;
	cout << "Enter name of the class you want to remove a student: ";
	cin >> classname;
	
	classYear *cur = class_list.head;
	while (cur && cur->class_name!=classname) {
		cur = cur->next;
	}
	if (!cur) {
		cout << "Sorry, the class you entered doesn't exist.\n";
		return;
	}
	else {
		int newid;
		cout << "Enter the ID of the student you want to remove: ";
		cin >> newid;
		student *del = cur->head;

		// Check first student
		if (del->id == newid) {
			cur->head = cur->head->next;
			delete del;
			return;
		}

		while (del->next && del->next->id != newid) {
			del = del->next;
		}
		if (!del->next) {
			cout << "Sorry, the ID you entered doesn't exist.\n";
			return;
		}
		else {
			student *tmp = del->next;
			del->next = tmp->next;
			delete tmp;
			return;
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
	//	generete default username and password and email for academic staff or lecturer
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

	//	passing the default username and password and email;
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
	int temp_id = this->id;
	vector <int> temp;
	for (int i = 0; i < 4; ++i) {
		temp.push_back(temp_id % 10);
		temp_id /= 10;
	}
	this->email = short_name;
	for (int i = 0; i < 4; ++i) {
		password += to_string(temp.back());
		this->email += to_string(temp.back());
		temp.pop_back();
	}
	//	passing the default password to the student
	this->password = password;
	this->email += "@apcs.vn";
}

//	14
void importCourses(string path, courseList& a, studentList_t &student_list) {
	//	import courses from a .csv file
	//	Nguyen Ho Huu Nghia

	ifstream fin(path), fin1;
	fin.ignore(10000, '\n');

	a.head = NULL;
	if (fin.good()) {

		course* cur;

		//	start reading students' info
		string buffer;

		while (fin.good()) {
			string class_name, file_name;

			if (a.head == NULL) {
				a.head = new course;
				getline(fin, a.head->course_code, ',');
				getline(fin, a.head->course_name, ',');
				getline(fin, a.head->lecturer_username, ',');

				getline(fin, buffer, '\n');
				stringstream classes(buffer);

				while (classes.good()) {
					classes >> class_name;
					file_name = class_name + "-" + a.head->course_code + ".csv";
					fin1.open(file_name);
					
					if(fin1.good()){

						fin1.ignore(1000, '\n');

						fin1.ignore(1000, '\n');
						int student_id;

						while (fin1.good() &&!fin.eof()) {
							fin1.ignore(1000, ',');

							string buffer_student_id;
							getline(fin1, buffer_student_id, ',');
							student_id= stoi(buffer_student_id);

							presence* cur_presence = NULL;
							addIfNotAdded(a.head->head_presence, student_id, cur_presence);
							
							student* cur_student = NULL;
							addIfNotAdded(student_list.head, student_id, cur_student);
							if(cur_student==NULL)
								fin1.ignore(1000, '\n');
							else {
								getline(fin1, cur_student->full_name, '\n');
								cur_student->generatePassword();
							}
						}
					}
					fin1.close();
				}


				a.head->next = NULL;
				cur = a.head;
			}

			else {
				cur->next=new course;
				cur = cur->next;
				getline(fin, cur->course_code, ',');
				getline(fin, cur->course_name, ',');
				getline(fin, cur->lecturer_username, ',');

				getline(fin, buffer, '\n');
				stringstream classes(buffer);

				while (classes.good()) {
					classes >> class_name;
					file_name = class_name + "-" + cur->course_code + ".csv";
					fin1.open(file_name);

					if (fin1.good()) {

						fin1.ignore(1000, '\n');

						fin1.ignore(1000, '\n');
						int student_id;

						while (fin1.good() && !fin.eof()) {
							fin1.ignore(1000, ',');

							string buffer_student_id;
							getline(fin1, buffer_student_id, ',');
							student_id = stoi(buffer_student_id);

							presence* cur_presence = NULL;
							addIfNotAdded(cur->head_presence, student_id, cur_presence);

							student* cur_student = NULL;
							addIfNotAdded(student_list.head, student_id, cur_student);
							if (cur_student == NULL)
								fin1.ignore(1000, '\n');
							else {
								getline(fin1, cur_student->full_name, '\n');
								cur_student->generatePassword();
							}
						}
					}
					fin1.close();
				}


				cur->next = NULL;
			}
		}
	}
	fin.close();
}

//	14
//	For the users
void importCourses(courseList& a, studentList_t &student_list) {
	//	import courses from a .csv file
	//	Nguyen Ho Huu Nghia

	cout << "Enter the path of the .csv file: ";
	string path;
	getline(cin, path, '\n');

	ifstream fin(path), fin1;
	fin.ignore(10000, '\n');

	a.head = NULL;
	if (fin.good()) {

		course* cur;

		//	start reading students' info
		string buffer;

		while (fin.good()) {
			string class_name, file_name;

			if (a.head == NULL) {
				a.head = new course;
				getline(fin, a.head->course_code, ',');
				getline(fin, a.head->course_name, ',');
				getline(fin, a.head->lecturer_username, ',');

				getline(fin, buffer, '\n');
				stringstream classes(buffer);

				while (classes.good()) {
					classes >> class_name;
					file_name = class_name + "-" + a.head->course_code + ".csv";
					fin1.open(file_name);

					if (fin1.good()) {

						fin1.ignore(1000, '\n');

						fin1.ignore(1000, '\n');
						int student_id;

						while (fin1.good() && !fin.eof()) {
							fin1.ignore(1000, ',');

							string buffer_student_id;
							getline(fin1, buffer_student_id, ',');
							student_id = stoi(buffer_student_id);

							presence* cur_presence = NULL;
							addIfNotAdded(a.head->head_presence, student_id, cur_presence);

							student* cur_student = NULL;
							addIfNotAdded(student_list.head, student_id, cur_student);
							if (cur_student == NULL)
								fin1.ignore(1000, '\n');
							else {
								getline(fin1, cur_student->full_name, '\n');
								cur_student->generatePassword();
							}
						}
					}
					fin1.close();
				}


				a.head->next = NULL;
				cur = a.head;
			}

			else {
				cur->next = new course;
				cur = cur->next;
				getline(fin, cur->course_code, ',');
				getline(fin, cur->course_name, ',');
				getline(fin, cur->lecturer_username, ',');

				getline(fin, buffer, '\n');
				stringstream classes(buffer);

				while (classes.good()) {
					classes >> class_name;
					file_name = class_name + "-" + cur->course_code + ".csv";
					fin1.open(file_name);

					if (fin1.good()) {

						fin1.ignore(1000, '\n');

						fin1.ignore(1000, '\n');
						int student_id;

						while (fin1.good() && !fin.eof()) {
							fin1.ignore(1000, ',');

							string buffer_student_id;
							getline(fin1, buffer_student_id, ',');
							student_id = stoi(buffer_student_id);

							presence* cur_presence = NULL;
							addIfNotAdded(cur->head_presence, student_id, cur_presence);

							student* cur_student = NULL;
							addIfNotAdded(student_list.head, student_id, cur_student);
							if (cur_student == NULL)
								fin1.ignore(1000, '\n');
							else {
								getline(fin1, cur_student->full_name, '\n');
								cur_student->generatePassword();
							}
						}
					}
					fin1.close();
				}


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
void viewCourseList(courseList a) {

	//	By NT Tung

	course* cur = a.head;
	cout << "List of courses" << endl;
	while (cur != NULL) {
		cout << "Course code : " << cur->course_code << endl << " Course name : " << cur->course_name << endl << endl;
		cur = cur->next;
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
//	This version is for importing courses' schedule without asking for the class and path
//	For the developers
void importCoursesSchedulesOfAClass(courseList &course_list, classList &class_list, string path, string class_name) {

	//	import all courses' schedules of a single class from a .csv file
	//	By Nguyen Ho Huu Nghia

	//	open the file
	ifstream fin;
	fin.open(path);

	//	check if file is succesfully opened
	if (!fin.is_open()) {
		cout << "File at the following address is not loaded: \n"
			<< path << endl;
		fin.close();
	}
	else {

		classYear *cur_class = class_list.head;

		//	find the class from the class name
		if (class_name != class_list.head->class_name) {
			while (cur_class->next && cur_class->next->class_name != class_name)
				cur_class = cur_class->next;
			if (!cur_class->next) {
				cur_class->next = new classYear;
				cur_class = cur_class->next;
				cur_class->next = NULL;
				cur_class->class_name = class_name;
			}
			else
				cur_class = cur_class->next;
		}

		//	ignore the 1st line containing the name of columns
		fin.ignore(10000, '\n');

		courseCode* cur_course_code=cur_class->head_course_code;
		char buffer[100];

		while (fin.good()) {

			//	get the course code
			fin.getline(buffer, 100, ',');

			//	if the course code doesn't exist then create a new course code 
			if(cur_class->head_course_code!=NULL){
				cur_course_code = cur_class->head_course_code;
				if (cur_class->head_course_code->course_code != (string)buffer) {
					while (cur_course_code->next && cur_course_code->course_code != (string)buffer)
						cur_course_code = cur_course_code->next;
					if (cur_course_code->next == NULL) {
						cur_course_code->next = new courseCode;
						cur_course_code = cur_course_code->next;
					}
					else
						cur_course_code = cur_course_code->next;
				}
			}
			else {
				cur_class->head_course_code = new courseCode;
				cur_course_code = cur_class->head_course_code;
			}
			cur_course_code->course_code = buffer;


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

			schedule* cur_schedule = findSchedule(cur_course->head_schedule, cur_class->class_name);

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

			string file_name;
			ifstream fin1;
			file_name = cur_class->class_name + "-" + cur_course->course_code + ".csv";
			fin1.open(file_name); 
			int weeks = weeksBetweenTwoDates(cur_schedule->start_date, cur_schedule->end_date);
			string temp_attendance = "";
			while (weeks > 0) {
				temp_attendance += " ";
				weeks--;
			}
			if (fin1.good()) {

				fin1.ignore(1000, '\n');
				fin1.ignore(1000, '\n');

				while (fin1.good()) {
					fin1.ignore(1000, ',');

					string buffer_student_id;
					getline(fin1, buffer_student_id, ',');
					int student_id = stoi(buffer_student_id);

					presence* cur_presence = findNode(cur_course->head_presence, student_id);
					
					if (cur_presence->attendance.length() == 0)
						cur_presence->attendance = temp_attendance;
					fin1.ignore(1000, '\n');
				}
			}
			fin1.close();

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

//	19
//	This version asks the user what is the class and the file path
//	For the users
void importCoursesSchedulesOfAClass(courseList &course_list, classList &class_list) {

	//	import all courses' schedules of a single class from a .csv file
	//	By Nguyen Ho Huu Nghia
	cout << "Enter the path of the file: ";
	string path;
	cin.ignore();
	getline(cin, path, '\n');

	//	open the file
	ifstream fin;
	fin.open(path);

	string class_name;
	cout << "Enter the name of the class: ";
	getline(cin, class_name, '\n');


	//	check if file is succesfully opened
	if (!fin.is_open()) {
		cout << "File at the following address is not loaded: \n"
			<< path << endl;
		fin.close();
	}
	else {

		classYear *cur_class = class_list.head;

		//	find the class from the class name
		if (class_name != class_list.head->class_name) {
			while (cur_class->next && cur_class->next->class_name != class_name)
				cur_class = cur_class->next;
			if (!cur_class->next) {
				cur_class->next = new classYear;
				cur_class = cur_class->next;
				cur_class->next = NULL;
				cur_class->class_name = class_name;
			}
			else
				cur_class = cur_class->next;
		}

		//	ignore the 1st line containing the name of columns
		fin.ignore(10000, '\n');

		courseCode* cur_course_code = cur_class->head_course_code;
		char buffer[100];

		while (fin.good()) {

			//	get the course code
			fin.getline(buffer, 100, ',');

			//	if the course code doesn't exist then create a new course code 
			if (cur_class->head_course_code != NULL) {
				cur_course_code = cur_class->head_course_code;
				if (cur_class->head_course_code->course_code != (string)buffer) {
					while (cur_course_code->next && cur_course_code->course_code != (string)buffer)
						cur_course_code = cur_course_code->next;
					if (cur_course_code->next == NULL) {
						cur_course_code->next = new courseCode;
						cur_course_code = cur_course_code->next;
					}
					else
						cur_course_code = cur_course_code->next;
				}
			}
			else {
				cur_class->head_course_code = new courseCode;
				cur_course_code = cur_class->head_course_code;
			}
			cur_course_code->course_code = buffer;


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
			cur_schedule->class_name = cur_class->class_name;
			/*if (cur_course->head_schedule == NULL) {
			cur_course->head_schedule = new schedule;
			cur_schedule = cur_course->head_schedule;
			cur_schedule->class_name = cur_class->class_name;
			}
			else {
			cur_schedule = cur_course->head_schedule;
			while (cur_schedule && cur_schedule->class_name != cur_class->class_name)
			cur_schedule = cur_schedule->next;
			if (!cur_schedule) {
			cur_schedule->next = new schedule;
			cur_schedule = cur_schedule->next;
			cur_schedule->class_name = cur_class->class_name;
			}
			}*/

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

			string file_name;
			ifstream fin1;
			file_name = cur_class->class_name + "-" + cur_course->course_code + ".csv";
			fin1.open(file_name);
			int weeks = weeksBetweenTwoDates(cur_schedule->start_date, cur_schedule->end_date);
			string temp_attendance = "";
			while (weeks > 0) {
				temp_attendance += " ";
				weeks--;
			}
			if (fin1.good()) {

				fin1.ignore(1000, '\n');
				fin1.ignore(1000, '\n');

				while (fin1.good()) {
					fin1.ignore(1000, ',');

					string buffer_student_id;
					getline(fin1, buffer_student_id, ',');
					int student_id = stoi(buffer_student_id);

					presence* cur_presence = createNewNode(cur_course->head_presence);
					cur_presence->id = student_id;

					if (cur_presence->attendance.length() == 0)
						cur_presence->attendance = temp_attendance;
					fin1.ignore(1000, '\n');
				}
			}
			fin1.close();

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
void addACourseSchedule(courseList &course_list, classList &class_list) {

	//	add a new course at the end of the course list and let the user type in its schedule
	//	by Nguyen Ho Huu Nghia

	string class_name;
	cout << "Enter the name of the class: ";
	cin >> class_name;

	//	find the class in the class list
	classYear* cur_class = class_list.head;
	if (class_list.head->class_name != class_name) {
		while (cur_class->next != NULL && cur_class->class_name != class_name)
			cur_class = cur_class->next;
		if (cur_class->next == NULL) {
			cout << "Class not found. Press Enter to continue\n";
			system("pause");
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
			<< "[Y]Yes\n[N]No\n"
			<< "Your answer: ";
		char a;
		cin >> a;
		if (a == 'N') {
			cout << "Press Enter to continue.\n";
			return;
		}
		else {
			cur_course = new course;
		}
	}
	else {
		while (cur_course->next && cur_course->next->course_code != cur_course_code->course_code)
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

	cur_schedule->class_name = cur_class->class_name;

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





//==============================================================================================================


int posi(std::string str, char chr)
{
	//Nguyen Vo Duc Loc
	//fine a character in a substring

	for (int i = 0; i < str.length(); i++)
		if (chr == str[i])
			return i;
	return -1;
}

bool checkStringOfTimes(std::string times)
{
	//Nguyen Vo Duc Loc
	//check if the string is a form of times

	if (posi(times, ':') < 0)
		return false;

	for (int i = 0; i < times.length(); i++)
		if (times[i] != ':')
		{
			int u = int(times[i]);
			if (u < 48 || u>57)
				return false;
		}

	return true;
}

bool changeUnitTimes(string times, Time &T)
{
	//Nguyen Vo Duc Loc
	//change a strings of time into hour and minute 

	T.hour = 0;
	T.minute = 0;

	int tmp = posi(times, ':');

	if (checkStringOfTimes(times))
	{
		for (int i = 0; i < tmp; i++)
			T.hour = T.hour * 10 + int(times[i]) - 48;

		for (int i = tmp + 1; i < times.length(); i++)
			T.minute = T.minute * 10 + int(times[i]) - 48;
	}

	if (T.hour < 0 || T.hour>23 || T.minute > 59 || T.minute < 0)
	{
		T.hour = 0;
		T.minute = 0;
		return false;
	}
	return true;
}

bool isLeapYear(char year)
{
	//Nguyen Vo Duc Loc
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

bool checkDate(date D)
{
	//Nguyen Vo Duc Loc

	if (D.month < 1 || D.month>12 || D.day < 1)
		return false;

	if (D.month == 1 || D.month == 3 || D.month == 5 || D.month == 7 || D.month == 8 || D.month == 10 || D.month == 12)
	{
		if (D.day > 31)
			return false;
	}
	else
		if (D.month == 2)
		{
			if (isLeapYear(D.year))
			{
				if (D.day > 29)
					return false;
			}
			else
				if (D.day > 28)
					return false;
		}
		else
			if (D.day > 30)
				return false;
	return true;
}

bool changeUnitDate(string str, date &D)
{
	//Nguyen Vo Duc Loc

	int temp = 0;

	D.day = 0;
	D.month = 0;
	D.year = 0;

	for (int i = 0; i < str.length(); i++)
		if (str[i] != '-')
		{
			int u = int(str[i]) - 48;
			if (u<0 || u>9)
				return false;
		}
		else
			temp++;

	if (temp != 2)
		return false;

	int posi = 0, sum = 0;

	while (str[posi] != '-')
	{
		sum = sum * 10 + int(str[posi]) - 48;
		posi++;
	}
	D.day = sum;

	posi++;
	sum = 0;
	while (str[posi] != '-')
	{
		sum = sum * 10 + int(str[posi]) - 48;
		posi++;
	}
	D.month = sum;

	posi++;
	sum = 0;
	while (posi < str.length())
	{
		sum = sum * 10 + int(str[posi]) - 48;
		posi++;
	}
	D.year = sum;

	if (checkDate(D))
		return true;
	else
	{
		D.day = 0;
		D.month = 0;
		D.year = 0;
		return false;
	}
}

bool isBefore(date first, date second)
{
	//Nguyen Vo Duc Loc

	if (first.year < second.year)
		return true;

	if (first.year > second.year)
		return false;

	if (first.month < second.month)
		return true;

	if (first.month > second.month)
		return false;

	if (first.day < second.day)
		return true;

	if (first.day > second.day)
		return false;

	return true;
}

bool interrupted(Time start1, Time end1, Time start2, Time end2)
{
	//Nguyen Vo Duc Loc
	//check if 2 interval of time is interrupted

	int begin1 = start1.hour * 60 + start1.minute;
	int stop1 = end1.hour * 60 + end1.minute;

	int begin2 = start2.hour * 60 + start2.minute;
	int stop2 = end2.hour * 60 + end2.minute;

	if (begin1 > stop2 || stop1 < begin2)
		return false;

	return true;
}

bool isDuplicatedTimes(courseList L, string course_code, schedule *tempSchedule, dateofweek date, string room, Time start, Time end)
{

	//Nguyen Vo Duc Loc
	//check if time is duplicated with other schedule


	//------------------------check if there are no duplicated along the courseList
	course *cur = L.head;
	schedule *pre;

	/*	std::cout << std::endl;
	std::cout << course_code << std::endl;
	std::cout << tempSchedule->class_name << std::endl;
	std::cout << tempSchedule->course_session.session_day << std::endl;
	std::cout << tempSchedule->course_session.start.hour << ":" << tempSchedule->course_session.start.minute << std::endl;
	std::cout << tempSchedule->course_session.end.hour << ":" << tempSchedule->course_session.end.minute << std::endl;
	std::cout << tempSchedule->room << std::endl;
	std::cout << std::endl;
	*/
	while (cur != NULL)
	{
		pre = cur->head_schedule;
		while (pre != NULL)
		{
			/*			std::cout << cur->course_code << std::endl;
			std::cout << pre->class_name << std::endl;
			std::cout << pre->course_session.session_day << std::endl;
			std::cout << pre->course_session.start.hour <<":"<<pre->course_session.start.minute<< std::endl;
			std::cout << pre->course_session.end.hour << ":" << pre->course_session.end.minute << std::endl;
			std::cout << pre->room << std::endl <<std::endl;
			*/
			if (pre != tempSchedule)
			{
				if (pre->class_name == tempSchedule->class_name && pre->course_session.session_day == date)
				{
					if (interrupted(start, end, pre->course_session.start, pre->course_session.end))
						return true;
				}
				else
					if (pre->course_session.session_day == date && pre->room == room)
					{
						if (interrupted(start, end, pre->course_session.start, pre->course_session.end))
						{
							/*						std::cout << start.hour << ":" << start.minute << " ";
							std::cout << end.hour << ":" << end.minute << std::endl;
							std::cout << pre->course_session.start.hour << ":" << pre->course_session.start.minute << " ";
							std::cout << pre->course_session.end.hour << ":" << pre->course_session.end.minute;
							std::cout << std::endl;
							*/
							return true;
						}
					}
			}
			pre = pre->next;
		}
		cur = cur->next;
	}

	//-----------------check if there are no interruption in a Course
	cur = L.head;
	while (cur != NULL)
	{
		if (cur->course_code == course_code)
			break;
		cur = cur->next;
	}

	if (cur != NULL)
	{
		pre = cur->head_schedule;
		while (pre != NULL)
		{
			if (pre != tempSchedule)
				if (date == pre->course_session.session_day)
					if (interrupted(pre->course_session.start, pre->course_session.end, start, end))
					{
						return true;
					}
			pre = pre->next;
		}
	}

	return false;
}

//	21
void editCourseSchedule(courseList L)
{
	//Nguyen Vo Duc Loc
	//dep trai phong do


	string course_code, class_name;
	std::cout << "pls enter the course code: "; std::cin >> course_code;
	std::cout << "pls enter the class name: "; std::cin >> class_name;

	course *cur_course = L.head;
	schedule *cur_schedule = NULL;

	//-------------------------check if course_code and class_name existed--

	while (cur_course != NULL)
	{
		if (cur_course->course_code == course_code)
			break;
		cur_course = cur_course->next;
	}

	if (cur_course != NULL)
	{
		cur_schedule = cur_course->head_schedule;
		while (cur_schedule != NULL)
		{
			if (cur_schedule->class_name == class_name)
				break;
			cur_schedule = cur_schedule->next;
		}
	}
	//--------------------------------------------
	if (cur_course != NULL && cur_schedule != NULL)		//if they existed
	{
		dateofweek date;
		int tempDate;

		std::cout << "pls enter the index of date (sunday..saturday = 1..7): ";
		std::cin >> tempDate;
		switch (tempDate)
		{
		case 1:date = sunday;
			break;
		case 2:date = monday;
			break;
		case 3:date = tuesday;
			break;
		case 4:date = wednesday;
			break;
		case 5:date = thursday;
			break;
		case 6:date = saturday;
			break;
		case 7:date = sunday;
			break;
		}

		std::cin.ignore(10, '\n');
		std::string room;
		std::cout << "pls enter the room you want to book: ";
		std::getline(cin, room);

		std::string begin;
		std::cout << "pls enter the time you want to start your lesson (hour:minute): ";
		std::cin >> begin;

		std::string finish;
		std::cout << "pls enter the time you want to finish your lesson (hour:minute): ";
		std::cin >> finish;

		Time start, end;

		if (tempDate>0 && tempDate<8 && changeUnitTimes(begin, start) && changeUnitTimes(finish, end))
		{
			if (!isDuplicatedTimes(L, course_code, cur_schedule, date, room, start, end))
			{
				cur_schedule->room = room;
				cur_schedule->course_session.session_day = date;
				cur_schedule->course_session.start = start;
				cur_schedule->course_session.end = end;
				std::cout << "changed successfully" << std::endl;
			}
			else
				std::cout << " UNSUCESSFULLY ! Your schedule is duplicated" << std::endl;
		}
		else
			std::cout << "syntax Error" << std::endl;
	}
	else
	{
		if (cur_course == NULL)
			std::cout << "course code wrong" << std::endl;
		if (cur_schedule == NULL)
			std::cout << "class name wrong" << std::endl;
		std::cout << "wrong information" << std::endl;	//if they didn't exist
	}


	char tmp;

	std::cout << "pls enter 1 if you want to edit the schedule again: ";
	std::cin >> tmp;

	if (tmp == '1')
		editCourseSchedule(L);
}
//	22
void removeCourseSchedule(courseList L)
{
	//Nguyen Vo Duc Loc

	displayList(L);
	std::string course_code, class_name;
	std::cout << "pls enter the course code: "; std::cin >> course_code;
	std::cout << "pls enter the class's name: "; std::cin >> class_name;

	course *cur_course = L.head;
	schedule *cur_schedule = NULL, *pre_schedule=NULL;

	while (cur_course != NULL)
	{
		if (cur_course->course_code == course_code)
			break;
		cur_course = cur_course->next;
	}

	if (cur_course != NULL)
	{
		pre_schedule = NULL;
		cur_schedule = cur_course->head_schedule;
		while (cur_schedule != NULL)
		{
			if (cur_schedule->class_name == class_name)
				break;
			pre_schedule = cur_schedule;
			cur_schedule = cur_schedule->next;
		}
	}

	if (cur_course != NULL && cur_schedule != NULL)
	{
		if (pre_schedule != NULL)
		{
			pre_schedule->next = cur_schedule->next;
			delete cur_schedule;
		}
		else
		{
			cur_course->head_schedule = cur_schedule->next;
			delete cur_schedule;
		}
		std::cout << "your statement is removed successfully" << std::endl;
	}
	else
	{
		std::cout << "WRONG INFORMATION" << std::endl;
	}
	displayList(L);
}

void displayList(courseList L)
{
	//Nguyen Vo Duc Loc
	//xuat ra tat ca cac schedule cua cac course hien co

	course *cur_course=L.head;
	schedule *cur_schedule;

	while (cur_course != NULL)
	{
		cur_schedule = cur_course->head_schedule;
		while (cur_schedule != NULL)
		{
			std::cout << std::endl;
			std::cout << cur_course->course_code << std::endl;
			std::cout << cur_schedule->class_name << std::endl;
			std::cout << cur_schedule->course_session.session_day << std::endl;
			std::cout << cur_schedule->course_session.start.hour << ":" << cur_schedule->course_session.end.minute;
			std::cout << std::endl;
			std::cout << cur_schedule->course_session.end.hour << ":" << cur_schedule->course_session.end.minute;
			std::cout << std::endl;

			cur_schedule = cur_schedule->next;
		}
		cur_course = cur_course->next;
	}
}
// ko co so
void exportStudentList(studentList_t pupil)
{

	//Loc dep trai

	student *cur = pupil.head;

	std::ofstream fo;

	fo.open("Student-List-Output.csv");

	fo << "ID,name,class,email,phone,password\n";
	
	while (cur != NULL)
	{

		fo << cur->id << ",";
		fo << cur->full_name << ",";
		fo << cur->class_name << ",";
		fo << cur->email<<",";
		fo << cur->phone<<",";
		fo << cur->password;

		if (cur->next != NULL)
			fo << "\n";

		cur = cur->next;
	}

	fo.close();
}

void inputStudentList(studentList_t &pupil)
{
	//Nguyen Vo Duc Loc

	std::ifstream fi;
	fi.open("Student-List-Input.csv");

	if (!fi.is_open())
	{
		std::cout << "file doesn't exist" << std::endl;
		return;
	}

	fi.ignore(200, '\n');		//ignore the titile of the file csv

	string id, full_name, class_name, email, phone, password;
	student *cur=pupil.head;

	while (cur!=NULL && cur->next != NULL)
		cur = cur->next;

	while (!fi.eof())
	{
		getline(fi, id, ',');
		getline(fi, full_name, ',');
		getline(fi, class_name, ',');
		getline(fi, email, ',');
		getline(fi, phone, ',');
		getline(fi, password);

		std::cout << id<<" " << full_name <<" "<< class_name <<" "<< email <<" "<< phone <<" "<< password << std::endl;
		system("pause");

		if (pupil.head == NULL)
		{
			pupil.head = new student;
			pupil.head->next = NULL;
			pupil.head->id = stoi(id);
			pupil.head->full_name = full_name;
			pupil.head->class_name = class_name;
			pupil.head->email = email;
			pupil.head->phone = phone;
			pupil.head->password = password;
			cur = pupil.head;
		}
		else
		{
			cur->next = new student;
			cur = cur->next;
			cur->next = NULL;
			cur->id = stoi(id);
			cur->full_name = full_name;
			cur->class_name = class_name;
			cur->email = email;
			cur->phone = phone;
			cur->password = password;
		}
	}


	fi.close();
}
//==============================================================================================================







//	23
void viewListOfSchedules(courseList &course_list, classList &class_list) {
	//	View list of schedules of a class
	//	By Nghia

	string class_name;
	cout << "Enter the name of the class: ";
	cin.ignore();
	getline(cin, class_name, '\n');

	//	find the class from the list
	classYear* cur_class;
	findClassFromCode(class_list, class_name, cur_class);

	cout << "Class: " << class_name << endl;

	courseCode* cur_course_code = cur_class->head_course_code;
	course* cur_course;
	while (cur_course_code) {
		findCourseFromCode(course_list, cur_course_code->course_code, cur_course);

		schedule* cur_schedule = cur_course->head_schedule;
		while (cur_schedule && cur_schedule->class_name != class_name)
			cur_schedule = cur_schedule->next;
		if (cur_schedule == NULL)
			return;
		else {
			cout << "-----------------------------\n\n"
				<< "Course code: " << cur_course->course_code << endl
				<< "Course name: " << cur_course->course_name << endl
				<< "Lecturer username: " << cur_course->lecturer_username << endl
				<< "Year: " << cur_schedule->year << endl
				<< "Semester: " << cur_schedule->semester << endl
				<< "Start date: " << cur_schedule->start_date.day << '-' << cur_schedule->start_date.month << '-' << cur_schedule->start_date.year << endl
				<< "End date: " << cur_schedule->end_date.day << '-' << cur_schedule->end_date.month << '-' << cur_schedule->end_date.year << endl
				<< "Course session: " << endl;
			cur_schedule->course_session.displaySession();
			cout << endl;
		}
		cur_course_code = cur_course_code->next;
	}

}

void findCourseFromCode(courseList& course_list, string& course_code, course*  &result) {
	//	Find a course in course list given the class_code
	//	Nghia

	if (course_list.head == NULL) {
		cout << "Course_list.head is NULL\n";
		return;
	}
	course* cur_course = course_list.head;
	while (cur_course && cur_course->course_code != course_code)
		cur_course = cur_course->next;
	if (!cur_course) {
		cout << "Course doesn't exist\n";
	}
	else {
		result = cur_course;
	}
}

void findClassFromCode(classList& class_list, string& class_name, classYear*  &result) {
	//	Find a class in class list given the class_code
	//	Nghia

	if (class_list.head == NULL) {
		cout << "Course_list.head is NULL\n";
		return;
	}
	classYear* cur_class = class_list.head;
	while (cur_class && cur_class->class_name != class_name)
		cur_class = cur_class->next;
	if (!cur_class) {
		cout << "Class doesn't exist\n";
	}
	else {
		result = cur_class;
	}

}

//	24
void viewAttendance(courseList course_list)
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
		presence* student_presence = cur->head_presence;
		int n = student_presence->attendance.length();

		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				cout << setw(17) << "Week" << i + 1;
			}
			else
				cout << setw(9) << "Week" << i + 1;
		}
		cout << endl;
		cout << student_presence->id << setw(7);
		for (int i = 0; i < n; ++i) {
			cout << student_presence->attendance[i] << setw(10);
		}
		cout << endl;
	}
}

//	25
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

//	27
void exportScoreboardToCsv(courseList* course_list) {
	//export the Scoreboard of a course to a csv file
	//By Nghia
	//The user version
	string course_code;
	cout << "Enter the code of the course to export the scoreboard: ";
	cin.ignore();
	getline(cin, course_code, '\n');
	course* cur_course = course_list->head;
	while (cur_course && cur_course->course_code != course_code)
		cur_course = cur_course->next;
	//if there is no matching course
	if (!cur_course) {
		cout << "No course match the course code you entered.\n";
	}
	else {
		string temp = course_code + "-Scoreboard.csv";
		ofstream fout(temp);
		fout << "Courses:," << course_code << endl
			<< "Student ID,Midterm score,Lab score,Final score,Bonus,Total score\n";
		presence* cur_presence = cur_course->head_presence;
		while (cur_presence) {
			fout << cur_presence->id << "," << cur_presence->midterm << "," << cur_presence->lab << "," << cur_presence->final << "," << cur_presence->bonus << "," << cur_presence->total << endl;
		}
		fout.close();
		cout << "\nThe scoreboard is exported succesfully.\n";
	}
}

//27
void exportScoreboardToCsv(course* cur_course) {
	//export the Scoreboard of a course to a csv file
	//By Nghia
	//The developer version
	string temp = cur_course->course_code + "-Scoreboard.csv";
	ofstream fout(temp);
	fout << "Courses:," << cur_course->course_code << endl
		<< "Student ID,Midterm score,Lab score,Final score,Bonus,Total score\n";
	presence* cur_presence = cur_course->head_presence;
	while (cur_presence) {
		fout << cur_presence->id << "," << cur_presence->midterm << "," << cur_presence->lab << "," << cur_presence->final << "," << cur_presence->bonus << "," << cur_presence->total << endl;
	}
	fout.close();
}

void inputPassword(string &password)
{
	//	Masking password input
	//	By Nguyen Ho Huu Nghia

	char ch;
	do
	{
		ch = getch();
		if (ch == '\n' || ch == '\r')
			break;
		if (ch == '\b') {
			if (password.empty() == true)
				continue;
			putchar('\b');
			putchar(' ');
			putchar('\b');
			password.pop_back();
			continue;
		}
		password.push_back(ch);
		putchar('*');
	} while (ch != '\n');

}

//	29
void editGrade(courseList &a)
{
	//Vy Vy

	string code;
	cout << "Enter the course's code you want to edit grade: ";
	cin >> code;
	course* cur = a.head;
	while (cur && cur->course_code != code) {
		cur = cur->next;
	}
	if (!cur) {
		cout << "Sorry, the code you entered doesn't exist.\n";
		return;
	}
	else {
		int newid;
		cout << "Enter ID of the student you want to edit grade: ";
		cin >> newid;
		presence* edit = cur->head_presence;
		while (edit && edit->id != newid)
			edit = edit->next;
		if (!edit) {
			cout << "Sorry, the ID student you entered doesn't exist.\n";
			return;
		}
		else
			recursionEditGrade(1, edit);
	}
}

void recursionEditGrade(int n, presence *&edit)
{
	// Vy Vy

	if (n == 0) {
		cout << "Please enter edited total grade: ";
		cin >> edit->total;
		return;
	}

	cout << "Which grade you want to edit?\n";
	cout << "1. Mid-term\n";
	cout << "2. Lab\n";
	cout << "3. Final\n";
	cout << "4. Bonus\n";
	int x;
	cin >> x;

	switch (x) {
	case 1: {
		cout << "Please enter edited mid-term grade: ";
		cin >> edit->midterm;
		break;
	}
	case 2: {
		cout << "Please enter edited lab grade: ";
		cin >> edit->lab;
		break;
	}
	case 3: {
		cout << "Please enter edited final grade: ";
		cin >> edit->final;
		break;
	}
	default: {
		cout << "Please enter edited bonus grade: ";
		cin >> edit->bonus;
	}
	}

	cout << "Do you want to edit another grade?\n";
	cout << "1. Yes\n";
	cout << "0. No\n";
	cin >> n;
	recursionEditGrade(n, edit);
}

void Time::displayTime() {
	//	Nghia
	cout << hour << ":";
	IntToXX(minute);
	cout << endl;
}

void IntToXX(int n) {
	//	Nghia
	char result[3];
	if (n / 10 == 0) {
		result[0] = '0';
		result[1] = n + '0';
		result[2] = '\0';
		cout << result;
	}
	else
		cout << itoa(n, result, 10);
}

////////////////////////////////////////////////////////////////
int countLeapYears(date d)
{
	int years = d.year;

	// Check if the current year needs to be considered
	// for the count of leap years or not
	if (d.month <= 2)
		years--;

	// An year is a leap year if it is a multiple of 4,
	// multiple of 400 and not a multiple of 100.
	return years / 4 - years / 100 + years / 400;
}

int weeksBetweenTwoDates(const date &dt1, const date& dt2) {

	const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31 };

	// initialize count using years and day
	long int n1 = dt1.year * 365 + dt1.day;

	// Add days for months in given date
	for (int i = 0; i<dt1.month - 1; i++)
		n1 += monthDays[i];

	// Since every leap year is of 366 days,
	// Add a day for every leap year
	n1 += countLeapYears(dt1);

	long int n2 = dt2.year * 365 + dt2.day;
	for (int i = 0; i<dt2.month - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	// return difference between two counts
	return (n2 - n1) / 7 + 1;
}

int weeksFromStartDate(const date &dt1) {

	const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31 };

	// initialize count using years and day
	long int n1 = dt1.year * 365 + dt1.day;

	// Add days for months in given date
	for (int i = 0; i<dt1.month - 1; i++)
		n1 += monthDays[i];

	// Since every leap year is of 366 days,
	// Add a day for every leap year
	n1 += countLeapYears(dt1);

	time_t now = time(0);
	tm* today = localtime(&now);
	date dt2;
	dt2.year = today->tm_year + 1900;
	dt2.month = today->tm_mon + 1;
	dt2.day = today->tm_mday;

	long int n2 = dt2.year * 365 + dt2.day;
	for (int i = 0; i<dt2.month - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(dt2);

	// return difference between two counts
	return (n2 - n1) / 7 + 1;
}


//	31
void checkIn(student* you, courseList &course_list) {
	//	Nghia
	//	haven't check yet
	string course_code;
	cout << "Enter the code of the course you want to check in: ";
	cin.ignore();
	getline(cin, course_code, '\n');
	course* cur_course = course_list.head;
	while (cur_course && cur_course->course_code != course_code)
		cur_course = cur_course->next;
	if (!cur_course){
		cout << "Course doesn't exist.\n";
		return;
	}
	else {
		presence* cur = cur_course->head_presence;
		while (cur && cur->id != you->id)
			cur = cur->next;
		if (!cur) {
			cout << "You are not a student of this course.\n";
			return;
		}
		schedule* your_schedule = findSchedule(cur_course->head_schedule, you->class_name);
		int week = weeksFromStartDate(your_schedule->start_date);
		if (week <= cur->week) {
			cout << "Course: " << course_code << endl
				<< "You are at week " << week << endl
				<< "Please confirm that you want to check in:\n"
				<< "[y]Yes\n[n]No\n"
				<< "Your answer: ";
			char ans;
			cin >> ans;
			if (ans == 'y' || ans == 'Y') {
				cur->attendance[week] = 'x';
			}
		}
		else {
			cout << "The course has ended. You can no longer check in.\n";
		}
	}
}
////////////////////////////////////////////////////////////////////

//	32
void viewCheckInResult(student* you, courseList &course_list) {
	//	Nghia
	//	haven't finished
	string course_code;
	cout << "Enter the code of the course you want to check in: ";
	cin.ignore();
	getline(cin, course_code, '\n');
	course* cur_course = course_list.head;
	while (cur_course && cur_course->course_code != course_code)
		cur_course = cur_course->next;
	if (!cur_course) {
		cout << "The code you entered matches no existing course.\n";
	}
	else {
		presence* cur = cur_course->head_presence;
		while (cur &&cur->id != you->id)
			cur = cur->next;
		if (!cur) {
			cout << "You are not a student of this course.\n";
			return;
		}

		int week = weeksFromStartDate(cur_course->start_date);
		if(week<=cur->week){
			cout << "Course: " << course_code << endl
				<< "You are at week " << week << endl
				<< "Please confirm that you want to check in:\n"
				<< "[y]Yes\n[n]No\n"
				<< "Your answer: ";
			char ans;
			cin >> ans;
			if (ans == 'y' || ans == 'Y') {
				cur->attendance[week] = 'x';
			}
		}
		else {
			cout << "The course has ended. You can no longer check in.\n";
		}
	}
}

//	33
void viewMyScore(courseList course_list)
{
	// Vy Vy

	string code;
	int newid;
	cout << "Please enter your student ID: ";
	cin >> newid;
	cout << "Which course you want to view your scores? ";
	cin >> code;
	course *cur = course_list.head;
	while (cur && cur->course_code != code) {
		cur = cur->next;
	}
	if (!cur) {
		cout << "Sorry, the course code you enter doesn't exist.\n";
		return;
	}
	else {
		presence *print = cur->head_presence;
		while (!print && print->id != newid) {
			print = print->next;
		}
		if (!print) {
			cout << "Sorry, you have entered wrong ID.\n";
			return;
		}
		else {
			cout << "Mid-term: " << print->midterm << endl;
			cout << "Lab: " << print->lab << endl;
			cout << "Final: " << print->final << endl;
			cout << "Bonus: " << print->bonus << endl;
			cout << "Total: " << print->total << endl;
		}
	}
}

bool isNumber(const string& s) {
	//	check if a string is a number
	//	Nghia

	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it))
		it++;
	return !s.empty() && it == s.end();
}

schedule* findSchedule(schedule* &head, string class_name) {

	if (!head) {
		head = new schedule;
		head->class_name = class_name;
		return head;
	}
	else {
		if (head->class_name != class_name) {
			schedule* cur = head;
			while (cur->next && cur->next->class_name != class_name)
				cur = cur->next;
			if (!cur->next) {
				cur->next = new schedule;
				cur = cur->next;
				cur->class_name = class_name;
				return cur;
			}
			else
				return cur->next;
		}
		else
			return head;
	}
}