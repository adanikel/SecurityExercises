#include <iostream>

int main()
{

	char second_buffer[15];
	char first_buffer[15]; // located below second_buffer on stack frame (assuming memory address increases up)

	/* - Highest address
	* ....
	* ========= STACK FRAME
	* second_buffer
	* first_buffer
	* =========
	* ....
	* Lowest adress
	*/

	std::cout << second_buffer - first_buffer << std::endl;
	// distance is 15 -> writing to first_buffer above 15 will smash into second_buffer

	std::cout << "enter value for first buffer" << std::endl;
	std::cin >> first_buffer; // enter input: "@@@@@@@@@@@@@@@Conquered"

	std::cout << "current value of second buffer is " << second_buffer; // Will be "Conquered"

	return 0;
}