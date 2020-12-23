#include <iostream>
#include <cstring>

#define _PASS_LEN 15

bool check_password(char* password)
{
	char password_buffer[_PASS_LEN];
	bool access_flag{ 0 }; // NOTE: the overflow can be avoided by placing the flag before the buffer

	strcpy(password_buffer, password); // NOTE: the overflow can be avoided by using strcpy_s(password_buffer , _PASS_LEN, password)

	if (password_buffer == "correct") access_flag = 1;

	return access_flag;
}

int main(int argc, char* argv[]) // pass the password in as a CMD line argument (try input: @@@@@@@@@@@@@@@@)
{

	std::cout << "entered password - " << argv[1] << std::endl;

	unsigned int granted_access = check_password(argv[1]); 
	if (granted_access) std::cout << "Access granted" << std::endl; // should be true if overwritten successfully
	else std::cout << "Access denied" << std::endl;

	return 0;
}