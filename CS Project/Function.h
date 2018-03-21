#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct student {
	int id;
	string full_name;
	string class_name;
	string password;
	string email;
	string phone;
	student *next;
};

struct classYear {
	string class_name;
	student* head;
	classYear* next;
};

struct user {
	string username;
	string full_name;
	string email;
	string phone;
	string password;
	user* next;
};

struct date {
	int day, month, year;
};

struct Time {
	int hour, minute;
};

enum dateofweek {
	sunday = 1,
	monday,
	tuesday,
	wednesday,
	thursday,
	friday,
	saturday,
};

struct session {
	dateofweek session_day;
	Time start, end;
};

struct presence {
	string course_code;
	int semester, id, year, week;
	float midterm, lab, final;
	presence* next;
};

struct course {
	string course_code, course_name, lecturer_username;
	int year, semester;
	date start_date, end_date;
	session* head_session;
	presence* head_presence;
	course* next;
};

struct classList {
	classYear* head;
};

void input(const char path[], classYear&a);
void output(const char path[], classYear &a);
void readUser(string path, user* &a);
void generateUsernameAndPassword(user* &a);
void generatePassword(student* &a);

#endif