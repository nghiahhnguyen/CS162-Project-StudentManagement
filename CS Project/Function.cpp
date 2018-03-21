#include "Function.h"

void input(const char path[], classYear &a)
{
	//	load an entire new class from 
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
				cur = a.head;
			}
			else {
				cur->next = new student;
				cur = cur->next;
				cur->id = username;
				cur->full_name = (string)full_name;
				cur->class_name = (string)class_year;
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
		fout << "Class," << a.class_name <<","<< endl;
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

void generateUsernameAndPassword(user* &a) {
	//	generete default username and password for academic staff or lecturer
	//	Nguyen Ho Huu Nghia

	//	find the position of the last name
	int last_space_position;
	for (last_space_position = a->full_name.length() - 1; last_space_position >= 0; --last_space_position)
		if (a->full_name[last_space_position] == ' ')
			break;

	//	generate username
	int i;
	string username;
	username += tolower(a->full_name[0]);

	for (i = 1; i < last_space_position; ++i)
		if (a->full_name[i] == ' ')
			username += tolower(a->full_name[i + 1]);

	for (i = last_space_position + 1; i < a->full_name.length(); ++i)
		username += tolower(a->full_name[i]);

	//	generate password
	string password = username;
	for (i = a->phone.size() - 4; i < a->phone.size(); ++i)
		password += a->phone[i];
	
	//	passing the default username and password
	a->username = username;
	a->password = password;
}
void generatePassword(student* &a) {
	//	generate default password for student
	//	by Nghia

	//	find the position of the last name
	int last_space_position;
	for (last_space_position = a->full_name.length() - 1; last_space_position >= 0; --last_space_position)
		if (a->full_name[last_space_position] == ' ')
			break;

	//	generate username
	int i;
	string short_name;
	short_name += tolower(a->full_name[0]);

	for (i = 1; i < last_space_position; ++i)
		if (a->full_name[i] == ' ')
			short_name += tolower(a->full_name[i + 1]);

	for (i = last_space_position + 1; i < a->full_name.length(); ++i)
		short_name += tolower(a->full_name[i]);

	//	generate password
	string password = short_name;
	for (i = a->phone.size() - 4; i < a->phone.size(); ++i)
		password += a->phone[i];
	
	//	passing the defalut password to the student
	a->password = password;
}

void viewListOfStudentsInAClass(const classList &a) {
	cout << "Enter the name of the class you want to view: ";
	string class_name;
	cin >> class_name;
	classYear* cur_class;
	cur_class = a.head;
	while (cur_class && !cur_class->class_name.compare(class_name)) 
		cur_class = cur_class->next;
	if (!cur_class) {
		cout << "Class not found!\n";
		return;
	}
	if (!cur_class->class_name.compare(class_name)) {
		
	}
}