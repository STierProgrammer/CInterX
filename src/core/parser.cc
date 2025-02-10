#include "include/core/parser.hh"

bool Parser::not_eof()
{
	return this->tokens[0].type != TokenType::EOFToken;
}

Token* Parser::at()
{
	return &this->tokens[0];
}

Token* Parser::eat()
{
	Token* previous = &VectorUtils::shift(this->tokens);

	return previous;
}

Statement* Parser::parseStatement()
{
	return this->parseExpression();
}

Expression* Parser::parseExpression() {
	parseExpression();
}

Expression* Parser::parsePrimaryExpression()
{
	Token* token = this->at();

	if (!token) {
		return nullptr;
	}

	switch (token->type)
	{
		case TokenType::Identifier: {
			Identifier* identifier = new Identifier();

			identifier->symbol = this->eat()->value;

			return identifier;
		}
		case TokenType::Number: {
			NumericLiteral* numericLiteral = new NumericLiteral();

			numericLiteral->value = std::stold(this->eat()->value);

			return numericLiteral;
		}

		default: {
			return new Expression();
		}
	}
}

Program* Parser::produceAST(std::string src, Logger& logger)
{
	this->tokens = lexer::tokenize(src, logger);

	Program* program = new Program();

	while (this->not_eof()) {
		program->body.push_back(parseStatement());
	}

	return program;
}
