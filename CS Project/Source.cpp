#include "Function.h"

int main() {
    classYear a;

	char path[] = "17APCS1-Students.csv";
	char path2[] = "Output.csv";

	input(path, a);
	output(path2, a);

	/*user a;
	user* user_pointer = &a;
	readUser("Test User.txt", user_pointer);
	generateUsernameAndPassword(user_pointer);*/

	a.head->changePassword();
	cout << endl;
	cout << a.head->password << endl;

	classList L;
	L.head = &a;
	viewListOfClass(L);

	system("pause");
	return 0;
}