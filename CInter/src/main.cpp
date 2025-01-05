#include <iostream>
#include "../include/core/lexer.h"
#include "./utils/tokens.cpp"

int main() {
	Logger logger("my_log.txt");

	std::vector<Token> tokens = lexer::tokenize("1", logger);

	for (Token tk : tokens) {
		std::cout << "Type: " << TokenUtils::typeToString(tk.type);
	}

	return 0;
}