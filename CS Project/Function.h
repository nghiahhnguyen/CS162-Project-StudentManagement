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
	student *next = NULL;
	void changePassword();
	void generatePassword();
	void printInfo();
};



struct user {
	string username;
	string full_name;
	string email;
	string phone;
	string password;
	user* next = NULL;
	void changePassword();
	void generateUsernameAndPassword();
	void printInfo();
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
	void operator=(Time& a) {
		this->hour = a.hour;
		this->minute = a.minute;
	}
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
	void operator=(session &a) {
		this->start = a.start;
		this->end = a.end;
		this->session_day = a.session_day;
	}
};

//	stands for a student in a course
struct presence {
	string course_code, year;
	int semester, id, week;
	float midterm, lab, final, total;	//Thay bao cho them cot total
	char attendance[6];
	presence* next=NULL;
};

struct schedule {
	string room, year;
	int semester;
	date start_date, end_date;
	session course_session;
	schedule* next = NULL;
};

struct course {
	string course_code, course_name, lecturer_username, room, year;
	int semester;
	date start_date, end_date;
	session course_session;
	presence* head_presence=NULL;
	course* next=NULL;
	schedule* head_schedule = NULL;
};

struct courseCode {
	string course_code;
	courseCode* next=NULL;
};

struct classYear {
	string class_name;
	student *head = NULL;
	classYear* next = NULL;
	courseCode* head_course_code;
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

//	template to create a new node for a linked list given the head node
template<typename T>
T* createNewNode(T* head) {
	T* cur = head;
	if (head == NULL) {
		head = new T;
		return head;
	}
	else {
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new T;
	}
}



void input(char path[], classYear&a);
void output(char path[], classYear &a);
void viewListOfStudentsInAClass(const classList &a);
void viewListOfClass(classList L);
void importCourses(string path, courseList& a);
void importCourses(courseList& a);
void AddNewStudentToClass(classList L, classYear &a);
void EditStudent(classList L, classYear a);
void removeAcourse(courseList b);
void editExistingCourse(courseList &a);
void gotoxy(int x, int y);
void showMenu(classList &class_list, courseList &course_list, userList &staff, userList &lecturer);
//	This version is for importing courses' schedule without asking for the class and path
//	For the developers
void importCoursesSchedulesOfAClass(courseList &course_list, classYear* cur_class, string path);
//	This version asks the user what is the class and the file path
//	For the users
void importCoursesSchedulesOfAClass(courseList &course_list, classList &class_list);
void addACourseSchedule(courseList &course_list, classList &class_list);
void moveStudentsFromClassAToB(classList a);
bool exit();
void exportPresence(string path, course a);
course* searchCourse(string a, course *b);
void viewScore(course* a);
void viewCourseList(courseList a);
void viewAttendance(courseList course_list, presence* head_presence);
void importUsers(userList &staff, string path);
void inputPassword(string &password);

#endif