#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#include "Utils/Converts.h"
#include "Tokenizer.h"

bool hasElement(std::vector<MathParser::Token>& array, std::string const& element) {
    for (auto const& e : array) {
        if (e.TokenText == element) {
            return true;
        }
    }
    return false;
}

int expectElement(std::vector<MathParser::Token>& array, std::string const& element) {
    for (MathParser::Token const& e : array) {
        if (e.TokenText == element) {
            auto it = std::find(begin(array), end(array), e);
            return (int) std::distance(array.begin(), it);
        }
    }
    return 0;
}

void operations(std::vector<MathParser::Token>& array, int& caseVector, std::string const& op) {
    double n1 = convertDouble(array[caseVector - 1].TokenText);
    double n2 = convertDouble(array[caseVector + 1].TokenText);

    double result = 0;

    if (op == "-") {
        result = n1 - n2;
    } else if (op == "+") {
        result = n1 + n2;
    } else if (op == "*") {
        result = n1 * n2;
    } else if (op == "/") {
        result = n1 / n2;
    }

    array[caseVector - 1].TokenText = std::to_string(result);
    array[caseVector].TokenText = "N/A";
    array[caseVector + 1].TokenText = "N/A";

    while (hasElement(array, "N/A")) {
        for (MathParser::Token const& e : array) {
            if (e.TokenText == "N/A") {
                auto it = std::find(begin(array), end(array), e);
                array.erase(it);
            }
        }
    }
}

double parse(std::vector<MathParser::Token> contentSplitted) {
    size_t totalSizeVector = contentSplitted.size();
    int i = 0;

    while (i < totalSizeVector) {

        while (hasElement(contentSplitted, "*")) {
            auto caseVectorMulti = expectElement(contentSplitted, "*");
            operations(contentSplitted, caseVectorMulti, "*");
        }


        while (hasElement(contentSplitted, "/")) {
            auto caseVectorDiv = expectElement(contentSplitted, "/");
            operations(contentSplitted, caseVectorDiv, "/");
        }

        while (hasElement(contentSplitted, "+")) {
            auto caseVectorAdd = expectElement(contentSplitted, "+");
            operations(contentSplitted, caseVectorAdd, "+");
        }

        while (hasElement(contentSplitted, "-")) {
            auto caseVectorRemove = expectElement(contentSplitted, "-");
            operations(contentSplitted, caseVectorRemove, "-");
        }
        i++;
    }

    return convertDouble(contentSplitted[0].TokenText);
}
