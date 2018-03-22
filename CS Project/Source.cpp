#include "Function.h"

int main() {
	
	struct classYear a;
	a.head = NULL;
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

	return 0;
}