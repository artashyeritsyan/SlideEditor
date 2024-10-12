#include "SyntaxAnalyzer.hpp"

std::vector<SToken> SyntaxAnalyzer::start(std::stringstream &input)
{
    tokenizer = new Tokenizer(input);
    std::vector<SToken> tokens;
    SToken token = tokenizer->nextToken();

    while(token.type != TokenType::END) {

        if (token.type == TokenType::WORD && (
        tokens.size() == 0 || 
        tokens[tokens.size() - 1].type == TokenType::WORD)) 
        {
            tokens.push_back(token);
        }

        else if (tokens.size() == 0 && 
        token.type == TokenType::FLAG && 
        tokens[tokens.size() - 1].type != TokenType::FLAG) 
        {
            tokens.push_back(token);
        }

        else if (token.type == TokenType::VALUE && (
        tokens[tokens.size() - 1].type == TokenType::FLAG ||
        tokens[tokens.size() - 1].type == TokenType::VALUE )) 
        {
            tokens.push_back(token);
        }
        
        else 
        {
            // TODO: write custom exceptions class and add this error to it
            std::cerr << "Incorrect command order" << std::endl;
            return;
        }

        token = tokenizer->nextToken();
    }

    if (!tokens.size()) {
        return tokens;
    }
}
