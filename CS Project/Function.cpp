#include "Function.h"

void input(const char path[], classYear &a)
{
	ifstream fin(path);
	if (fin.good()) {
		//	ignore Class,
		fin.ignore(1000, ',');
		//	get Class Year
		char class_year[16];
		fin.getline(class_year, 16, ',');
		//	ignore line 2
		fin.ignore(1000, '\n');
		fin.ignore(1000, '\n');

		user* cur;

		//	start reading students' info
		char temp_number[13], username[8];
		int number;
		char full_name[101];
		while (fin.good()) {

			//	get ordinal number
			fin.getline(temp_number, 13, ',');
			number = atoi(temp_number);

			//	get username(student_id)
			fin.getline(username, 8, ',');

			//	get fullname
			fin.getline(full_name, 101, '\n');

			if (a.head == NULL) {
				a.head = new user;
				a.head->number = number;
				a.head->username = username;
				a.head->fullname = (string)full_name;
				a.head->Class = (string)class_year;
				a.head->next = NULL;
				cur = a.head;
			}
			else {
				cur->next = new user;
				cur = cur->next;
				cur->number = number;
				cur->username = username;
				cur->fullname = (string)full_name;
				cur->Class = (string)class_year;
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

	user *cur = a.head;

	if (fout.good()) {
		fout << "Class," << a.head->Class << endl;
		fout << "No,Student ID,Student name" << endl;
		while (cur != NULL) {
			fout << cur->number << ",";
			fout << cur->username << ",";
			fout << cur->fullname << ",";
			fout << endl;
			cur = cur->next;
		}
	}

	fout.close();
}

void readUser(string path, user* &a) {
	ifstream fin(path.c_str());
	while (fin.good()) {
		getline(fin, a->fullname, ',');
		getline(fin, a->phone, ',');
	}
	fin.close();
}
void generateUsernameAndPassword(user* &a) {
	int last_space_position;
	for (last_space_position = a->fullname.length() - 1; last_space_position >= 0; --last_space_position)
		if (a->fullname[last_space_position] == ' ')
			break;
	int i;
	string username;
	username += tolower(a->fullname[0]);
	for (i = 1; i < last_space_position; ++i)
		if (a->fullname[i] == ' ')
			username += tolower(a->fullname[i + 1]);
	for (i = last_space_position + 1; i < a->fullname.length(); ++i)
		username += tolower(a->fullname[i]);
	string password = username;
	for (i = a->phone.size() - 4; i < a->phone.size(); ++i)
		password += a->phone[i];
}