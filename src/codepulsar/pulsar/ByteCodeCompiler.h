#ifndef CODEPULSAR_BYTECODECOMPILER_H
#define CODEPULSAR_BYTECODECOMPILER_H

#include <string>

#include "Parser.h"
#include "../util/ErrorReporter.h"
#include "../util/ASTPrinter.h"
#include "../analysis/TypeChecker.h"
#include "../analysis/Validator.h"
#include "../variable/SymbolTable.h"


namespace Pulsar {
    class ByteCodeCompiler {
        public:
            ByteCodeCompiler(std::string sourceCode);
            void compileByteCode();
            CompilerError* getErrors();

        private:
            // Input Data
            std::string sourceCode;
            Statement* program;
            SymbolTable* symbolTable;

            // Output Data
            CompilerError* errors;

            // Core Functions
            void compile();
    };
}


#endif
