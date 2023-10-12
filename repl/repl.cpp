#include "repl.h"

void Repl::run() {
    string code = readInputFile();

    vector<Token*> tokens = lexer.run(code);

    Program* program = parser.run(tokens);

    Object *evaluated = evaluator.run(program);
    cout << evaluated->print() << endl;
}

void Repl::runWithVM() {
    string code = readInputFile();

    vector<Token*> tokens = lexer.run(code);

    Program* program = parser.run(tokens);


}

void Repl::lexerTest() {
    string input = readInputFile();

    vector<Token*> tokens = lexer.run(input);

    for (const Token* token : tokens) {
        cout << "(\"" << token->literal << "\", " << printTokenType(token->tokenType) << ")" << endl;
    }
}

void Repl::parserTest() {
    string input = readInputFile();

    vector<Token*> tokens = lexer.run(input);

    try {
        Program* program = parser.run(tokens);
        cout << program->String();
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

string Repl::readInputFile() {
    string fileName = "./main.txt";
    string input;
    ifstream inputStream(fileName);

    if (inputStream.is_open()) {
        inputStream.seekg(0, std::ios::end);
        int size = inputStream.tellg();
        input.resize(size);
        inputStream.seekg(0, std::ios::beg);
        inputStream.read(&input[0], size);
    }

    return input;
}