#include <iostream>
#include <cstring>

#define _BREAK_CHAR_STREAM "aa1aa2aa3aa4aa5aa6aa7aa8aa9ab1ab2ab3ab4ab5ab6ab7ab8ab9ac1ac2ac3ac4ac5ac6ac7ac8ac9ad1ad2ad3ad4ad5ad6ad7ad8ad9" // enter this as argv[1] and then pass the result to this function in another program

unsigned int calc_distance(const char* value_of_buffer)
{
	unsigned int buffer_str_len = strlen(value_of_buffer);

	for (unsigned int i = 0; i < strlen(_BREAK_CHAR_STREAM); i++)
	{
		bool match{ 0 };
		for (unsigned int j = 0; j < buffer_str_len; j++)
		{
			if (value_of_buffer[j] != _BREAK_CHAR_STREAM[i + j])
			{
				match = 0; // invalidation
				break;
			}

			match = 1; // should never get here if one char is wrong
		}
		if (match) // if gets here with match = 1, then the inner loop had all the comparisons return true
		{
			return i;
		}
	}

	return 0;
}

int main(int argc, char* argv[])
{
	char third_buffer[150]; // we want to find the location of this buffer
	unsigned int second_buffer[32]; // located below third_buffer on stack frame (size of array 32 is random)
	char first_buffer[15]; // located below second_buffer on stack frame

	strcpy(first_buffer, argv[1]);
	unsigned int distance = calc_distance(third_buffer);
	std::cout << "calculated distance: " << distance << std::endl;
	std::cout << "actual distance: " << third_buffer - first_buffer << std::endl;

	return 0;
}
