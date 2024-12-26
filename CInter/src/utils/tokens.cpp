#include <string>
#include "../headers/lexer.h"

namespace TokenUtils {
	static std::string typeToString(TokenType type) {
		switch (type)
		{
		case TokenType::Number:
			return "Number";
		case TokenType::Identifier:
			return "Identifier";
		case TokenType::Equals:
			return "Equals";
		case TokenType::Let:
			return "Let";
		case TokenType::OpenParen:
			return "OpenParen";
		case TokenType::CloseParen:
			return "CloseParen";
		case TokenType::BinaryOperator:
			return "BinaryOperator";
		default:
			return "None";
		}
	}
}