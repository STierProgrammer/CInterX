#ifndef CINTER_CORE_AST_H
#define CINTER_CORE_AST_H

#include <vector>

enum class NodeType {
	Program,
	NumericLiteral,
	Identifier,
	BinaryExpression,
};

struct Statement {
	static NodeType kind;
};

struct Program : Statement {
	Program() {
		kind = NodeType::Program;
	}

	std::vector<Statement*> body;
};

#endif // !CINTER_CORE_AST_H
