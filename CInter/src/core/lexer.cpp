#include "../headers/lexer.h"
#include "../utils/vectors.cpp"

lexer::Token lexer::token(std::string value, TokenType type)
{
	return { value, type };
}

std::vector<lexer::Token> lexer::tokenize(std::string str)
{
	std::vector<Token> tokens;
	std::vector<char> characters(str.begin(), str.end());

	while (characters.size() > 0) {
		if (characters[0] == '(') {			
			tokens.push_back(token(std::string(1, VectorUtils::shift(characters)), TokenType::OpenParen));
		}
		else if (characters[0] == ')') {
			tokens.push_back(token(std::string(1, VectorUtils::shift(characters)), TokenType::CloseParen));
		}

		else if (characters[0] == '+' || characters[0] == '-' || characters[0] == '*' || characters[0] == '/') {
			tokens.push_back(token(std::string(1, VectorUtils::shift(characters)), TokenType::BinaryOperator));
		}
	}

	return tokens;
}
