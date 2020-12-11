#include <iostream>
#include <string>

// generate parenthesis
void generator (std::string S, int n, int opened) {
	// insert '(' to given string S
	if (n > 0) {
		generator(S + '(', n-1, opened+1 );
	}

	// insert ')' to given string S
	if (opened > 0) {
		generator(S + ')', n, opened-1);
	}

	// when parenthesis generation finished
	else if (n == 0 && opened == 0) {
		std::cout << S << std::endl;
		return;
	}
}

// passed as a command line argument
int main(int argc, char* argv[]) {

	// if input isn't only name of the program and one integer
	if (argc != 2) {
		std::cerr << "input error" << std::endl;
		return 0;
	}
	
	int n = atoi(argv[1]);

	// n shoud be between 1 and 10
	if (n < 1 || n > 10) {
		std::cerr << "input error" << std::endl;
		return 0;
	}

	std::string S;

	generator (S, n, 0);

	return 0;
}

