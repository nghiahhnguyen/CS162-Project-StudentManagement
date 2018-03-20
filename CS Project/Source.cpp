#include "Function.h"

int main()
{
	user user_a;
	user* a = &user_a;

	readUser("Test User.txt", a);
	generateUsernameAndPassword(a);
	return 0;
}