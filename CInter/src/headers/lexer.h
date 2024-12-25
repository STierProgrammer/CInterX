#pragma once

#include <string>
#include <vector>

class lexer
{
public:
	enum TokenType {
		Number,
		Identifier,
		Equals,
		Let,

		OpenParen,
		CloseParen,
	
		BinaryOperator
	};

	struct Token {
		std::string value;
		TokenType type;
	};

	Token token(std::string value, TokenType type);
	std::vector<Token> tokenize(std::string src);
};

