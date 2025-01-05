#ifndef CINTER_CORE_LEXER_H
#define CINTER_CORE_LEXER_H

#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>

#include "../../src/utils/logger.cpp"

enum class TokenType {
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

namespace lexer
{
	static std::unordered_map<std::string, TokenType> KEYWORDS = {
		{ "let", TokenType::Let },
	};

	Token token(std::string value, TokenType type);
	std::vector<Token> tokenize(std::string src, Logger& logger);
};

#endif // !CINTER_CORE_LEXER_H