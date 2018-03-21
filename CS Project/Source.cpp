#include "Function.h"

int main() {
	struct classYear a;
	a.head = NULL;
	char path[] = "17APCS1-Students.csv";
	char path2[] = "Output.csv";
	input(path, a);
	generatePassword(a.head);
	output(path2, a);
	/*user a;
	user* user_pointer = &a;
	readUser("Test User.txt", user_pointer);
	generateUsernameAndPassword(user_pointer);*/
	return 0;
}