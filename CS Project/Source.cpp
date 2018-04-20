#include "Function.h"

int main() {

	classList class_list;
	courseList course_list;
	userList staff, lecturer;
	studentList_t student_list;
	class_list.head = NULL;
	course_list.head = NULL;
	staff.head = NULL;
	lecturer.head = NULL;
	student_list.head = NULL;

	//	create the first class in class list with the name first class
	class_list.head = new classYear;
	classYear *first_class = class_list.head;

	char path[] = "17APCS1-Students.csv";
	char path2[] = "Output.csv";

	char path3[] = "17APCS2-Students.csv";

	//	first student of the first class is initialized as NULL
	//	to use the input function
	first_class->head = NULL;
	importUsers(staff, "Academic-Staff.csv");
	importUsers(lecturer, "Lecturer.csv");

	//	import students into 17APCS1
	input(path, *first_class, student_list);
	output(path2, *first_class);

	first_class->next = new classYear;
	first_class->next->next = NULL;
	input(path3, *(first_class->next), student_list);

	//	import courses
	importCourses("Courses.csv", course_list, student_list);

	//	import courses' schedule of 17APCS1
	importCoursesSchedulesOfAClass(course_list, class_list, (string)"Courses-Schedule.csv", (string)"17APCS1");
	//	import courses' schedule of 17APCS2
	importCoursesSchedulesOfAClass(course_list, class_list, (string)"Courses-Schedule2.csv", (string)"17APCS2");

	showMenu(class_list, course_list, staff, lecturer, student_list);
	
	saveNewPasswordForLecturer((char*)"Academic-Staff.csv", staff);
	saveNewPasswordForLecturer((char*)"Lecturer.csv", lecturer);
	return 0;
}