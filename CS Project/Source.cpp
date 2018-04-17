#include "Function.h"

int main() {
	
	
	/*
	classList faculty;
	faculty.head = new classYear;
	char path[] = "17APCS1-Students.csv";
	input(path, *(faculty.head));
	viewListOfStudentsInAClass(faculty);
	*/

	/*user a;
	user* user_pointer = &a;
	readUser("Test User.txt", user_pointer);
	generateUsernameAndPassword(user_pointer);*/

	
	classList class_list;
	courseList course_list;
	userList staff, lecturer;
	class_list.head = NULL;
	course_list.head = NULL;
	staff.head = NULL;
	lecturer.head = NULL;

	//	create the first class in class list with the name first class
	class_list.head=new classYear;
	classYear *first_class = class_list.head;

	char path[] = "17APCS1-Students.csv";
	char path2[] = "Output.csv";
	//	first student of the first class is initialized as NULL
	//	to use the input function
	first_class->head = NULL;
	
	input(path, *first_class);
	output(path2, *first_class);

	showMenu(class_list, course_list, staff, lecturer);


	courseList a;

	importCourses("Courses.csv", a);

	classList class_list;
	class_list.head = new classYear;
	class_list.head->class_name = "apcs";
	importCoursesSchedulesOfAClass(a, class_list.head, "Courses-Schedule.csv");
	addACourseSchedule(a, class_list);

	system("pause");

	return 0;
}