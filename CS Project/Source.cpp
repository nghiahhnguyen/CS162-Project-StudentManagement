#include "Function.h"

int main() {
	classYear a;
	char path[] = "17APCS1-Students.csv";
	char path2[] = "Output.csv";

	input(path, a);
	output(path2, a);
	
	
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

	courseList L;
	L.addNewCourse();
	L.addNewCourse();

	system("pause");
	return 0;
}