#ifndef CINTER_CORE_PARSER_H
#define CINTER_CORE_PARSER_H

#include "ast.h"
#include "lexer.h"
#include "../utils/vectors.h"

#include <vector>

class Parser final {
private:
	std::vector<Token> tokens;

	bool not_eof();
	Statement* parseStatement();
	Expression* parseExpression();
	Expression* parsePrimaryExpression();
	Token* at();
	Token* eat();
public:
	Program* produceAST(std::string src, Logger& logger);
};

#endif // !CINTER_CORE_PARSER_H
