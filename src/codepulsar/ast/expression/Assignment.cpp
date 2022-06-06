#include "Assignment.h"


Pulsar::Assignment::Assignment(std::string identifier, Expression* value, int line) {
    this->identifier = identifier;
    this->value = value;
    this->line = line;
}

void Pulsar::Assignment::accept(ExprVisitor& visitor) {
    visitor.visitAssignmentExpression(this);
}

std::string Pulsar::Assignment::getIdentifier() {
    return this->identifier;
}

Pulsar::Expression* Pulsar::Assignment::getValue() {
    return this->value;
}

int Pulsar::Assignment::getLine() {
    return this->line;
}
