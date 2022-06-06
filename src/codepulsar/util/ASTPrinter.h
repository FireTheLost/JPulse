#ifndef CODEPULSAR_ASTPRINTER_H
#define CODEPULSAR_ASTPRINTER_H

#include "../pulsar/Pulsar.h"
#include "../ast/ExprVisitor.h"
#include "../ast/Expression.h"
#include "../ast/StmtVisitor.h"
#include "../ast/Statement.h"


namespace Pulsar {
    class ASTPrinter: public ExprVisitor, public StmtVisitor {
        public:
            ASTPrinter();
            void print(Statement* ast);

            // Expression AST Visitors
            void visitAssignmentExpression(Assignment* expression) override;
            void visitBinaryExpression(Binary* expression) override;
            void visitCallExpression(Call* expression) override;
            void visitGroupingExpression(Grouping* expression) override;
            void visitLiteralExpression(Literal* expression) override;
            void visitLogicalExpression(Logical* expression) override;
            void visitUnaryExpression(Unary* expression) override;
            void visitVariableExpression(VariableExpr* expression) override;

            // Statement AST Visitors
            void visitBlockStatement(Block* statement) override;
            void visitExpressionStatement(ExpressionStmt* statement) override;
            void visitFunctionStatement(Function* statement) override;
            void visitIfStatement(If* statement) override;
            void visitPrintStatement(Print* statement) override;
            void visitReturnStatement(Return* statement) override;
            void visitVariableStatement(VariableDecl* statement) override;
            void visitWhileStatement(While* statement) override;

        private:
            int indentCount;

            void constructTree(Statement* ast);
            void blockStatement(Block* statement);

            std::string giveTabs() const;
            void incrementIndentCount();
            void decrementIndentCount();
    };
}


#endif
