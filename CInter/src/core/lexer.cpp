#include "../headers/lexer.h"
#include "../utils/vectors.cpp"

lexer::Token lexer::token(std::string value, TokenType type)
{
	return { value, type };
}

bool lexer::isSkippable(const std::string& str)
{
	return str == " " || str == "\n" || str == "\t";
}

std::vector<lexer::Token> lexer::tokenize(std::string str, Logger& logger)
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

		else if (characters[0] == '=') {
			tokens.push_back(token(std::string(1, VectorUtils::shift(characters)), TokenType::Equals));
		}

		// Handling string tokens
		else {
			if (isdigit(characters[0])) {
				std::string number = "";

				while (characters.size() > 0 && isdigit(characters[0])) {
					number.append(std::string(1, VectorUtils::shift(characters)));
				}

				tokens.push_back(token(number, TokenType::Number));
			}

			else if (isalpha(characters[0])) {
				std::string identifier = "";

				while (characters.size() > 0 && isalpha(characters[0])) {
					identifier.append(std::string(1, VectorUtils::shift(characters)));
				}

				auto reserved = KEYWORDS.find(identifier);

				if (reserved == KEYWORDS.end()) {
					tokens.push_back(token(identifier, TokenType::Identifier));
				}
				else {
					tokens.push_back(token(identifier, reserved->second));
				}
			}

			else if (isSkippable(std::string(1, characters[0]))) {
				VectorUtils::shift(characters);
			}

			else {
				logger.log(LogLevel::ERROR, "Unrecognized character found in source!");
				exit(1);
			}
		}
	}

	return tokens;
}

