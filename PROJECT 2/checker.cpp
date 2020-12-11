#include <iostream>
#include <string>

// checking parenthesis correctness
bool Checker(std::string str) {
	// length of input str
	int n = str.length();
	int count = 0;
	
	// if input str is '\n'
	if (n == 0) {
		return false;
	}

	for (int i=0 ; i<n ; i++) {
		if (str[i] == '(') {
			count++;
		}
		else {
			count--;
			// not corrctly parenthesized
			if (count < 0)	return false;
		}
	}
	//correctly parenthesized
	if (count == 0) return true;
	// not corrctly parenthesized
	else return false;
}


int main() {
	std::string str;

	int correct = 0;
	int wrong = 0;
	
	// end if EOF meet
	while (getline(std::cin, str)) {
		bool CheckerResult = Checker(str);

		if (CheckerResult) correct++;
		else wrong++;
	}

	std::cout << "corret: " << correct << ", wrong: " << wrong << std::endl;
}
