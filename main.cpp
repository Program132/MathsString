#include <iostream>
#include <vector>
#include <string>

#include "src/Tokenizer.h"
#include "src/Parser.h"

using namespace MathParser;

int main() {
    std::string content = "9 + 10 * 20 - 5";
    TokenBuilding Tokenizer;
    std::vector<Token> contentMathTokens = MathParser::TokenBuilding::ParserTokens(content);
    double result = parse(contentMathTokens);
    std::cout << result << std::endl;

    content = "9 - 9";
    contentMathTokens = MathParser::TokenBuilding::ParserTokens(content);
    result = parse(contentMathTokens);
    std::cout << result << std::endl;

    content = "9 / 9";
    contentMathTokens = MathParser::TokenBuilding::ParserTokens(content);
    result = parse(contentMathTokens);
    std::cout << result << std::endl;

    content = "9 * 9";
    contentMathTokens = MathParser::TokenBuilding::ParserTokens(content);
    result = parse(contentMathTokens);
    std::cout << result << std::endl;

    content = "9 + 9";
    contentMathTokens = MathParser::TokenBuilding::ParserTokens(content);
    result = parse(contentMathTokens);
    std::cout << result << std::endl;


    return 0;
}