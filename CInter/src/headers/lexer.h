#pragma once

#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>
#include "../utils/logger.cpp"

enum class TokenType {
	Number,
	Identifier,
	Equals,
	Let,

	OpenParen,
	CloseParen,

	BinaryOperator
};

namespace lexer
{
	static std::unordered_map<std::string, TokenType> KEYWORDS = {
		{ "let", TokenType::Let },
	};

	struct Token {
		std::string value;
		TokenType type;
	};

	Token token(std::string value, TokenType type);
	std::vector<Token> tokenize(std::string src, Logger& logger);
	bool isSkippable(const std::string& str);
};

