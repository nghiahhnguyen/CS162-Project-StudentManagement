#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include <cstring>
#include "windows.h"

using namespace std;

struct student {
	int id;
	string full_name;
	string class_name;
	string password;
	string email;
	string phone;
	student *next;
	void changePassword();
	void generatePassword();
};

struct classYear {
	string class_name;
	student *head=NULL;
	classYear* next=NULL;
};

struct user {
	string username;
	string full_name;
	string email;
	string phone;
	string password;
	user* next;
	void changePassword();
	void generateUsernameAndPassword();
};

struct userList {
	user* head;
};

struct date {
	int day, month, year;
};

struct Time
{
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

struct session
{
	dateofweek session_day;
	Time start, end;
};

struct presence {
	string course_code;
	int semester, id, year, week;
	float midterm, lab, final, total;	//Thay bao cho them cot total
	char attendance[6];
	presence* next;
};

struct course {
	string course_code, course_name, lecturer_username, room;
	int year, semester;
	date start_date, end_date;
	session* head_session;
	presence* head_presence;
	course* next;
};

struct courseList 
{
	course* head=NULL;
	void addNewCourse();
};

struct classList 
{
	classYear *head=NULL;
	void addEmptyClass();
};

void input(const char path[], classYear&a);
void output(const char path[], classYear &a);
void viewListOfStudentsInAClass(const classList &a);
void viewListOfClass(classList L);
void importCourse(string path, courseList& a);
void removeAcourse(courseList b);
void editExistingCourse(courseList &a);
void gotoxy(int x, int y);
void showMenu(classList class_list, courseList course_list, userList staff, userList lecturer);
#endif