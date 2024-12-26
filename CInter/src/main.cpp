#include <iostream>
#include "./headers/lexer.h"
#include "./utils/tokens.cpp"

int main() {
	//// For testing stuff
	//std::cout << "*** TEST ***" << std::endl;
	//std::cout << "*** **** ***" << std::endl;
	//std::cout << "*** **** ***" << std::endl;
	//std::cout << "\n";
	//
	//run();
	Logger logger("my_log.txt");

	std::cout << "\n";
	std::cout << "*** MAIN ***" << std::endl;
	std::cout << "*** **** ***" << std::endl;
	std::cout << "*** **** ***" << std::endl;
	std::cout << "\n";

	std::vector<lexer::Token> tokens = lexer::tokenize("1", logger);

	for (lexer::Token tk : tokens) {
		std::cout << "Type: " << TokenUtils::typeToString(tk.type);
	}

	return 0;
}