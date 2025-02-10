#ifndef CINTER_CORE_AST_H
#define CINTER_CORE_AST_H

#include <vector>
#include <string>

enum class NodeType {
	Program,
	NumericLiteral,
	Identifier,
	BinaryExpression,
};

struct Statement {
	NodeType kind;
};

struct Expression : Statement {};

struct Program : Statement {
	Program() {
		kind = NodeType::Program;
	}

	std::vector<Statement*> body;
};

struct BinaryExpression : Expression {
	BinaryExpression() {
		kind = NodeType::BinaryExpression;
		left = nullptr;
		right = nullptr;
	}

	Statement* left;
	Statement* right;
	std::string op;
};

struct Identifier : Expression {
	Identifier() {
		kind = NodeType::Identifier;
	}

	std::string symbol;
};

struct NumericLiteral : Expression {
	NumericLiteral() {
		kind = NodeType::NumericLiteral;
		value = NULL;
	}

	long double value;
};

#endif // !CINTER_CORE_AST_H
