#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <tuple>

int convertInt(std::string& n) {
    try {
        int v = std::stoi(n);
        return v;
    }
    catch (std::invalid_argument const& ex) {
        std::cout << "It can not be a int value !" << " Final error: " << ex.what() << std::endl;
    }

    return 0;
}

std::vector<std::string> split(std::string& arg) {
    std::string myBuffer;

    std::vector<std::string> myVec;

    std::stringstream ss;
    ss << arg;
    while (ss >> myBuffer) {
        myVec.push_back(myBuffer);
    }

    return myVec;
}

bool hasElementNA(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "N/A");

    if (res != array.end()) {
        return true;
    }
    return false;
}

std::tuple<bool, int> expectMulti(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "*");

    if (res != array.end()) {
        return {true, std::distance(array.begin(), res)};
    }
    return {false, 0};
}

std::tuple<bool, int> expectDiv(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "/");

    if (res != array.end()) {
        return {true, std::distance(array.begin(), res)};
    }
    return {false, 0};
}

[[maybe_unused]] std::tuple<bool, int> expectAdd(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "+");

    if (res != array.end()) {
        return {true, std::distance(array.begin(), res)};
    }
    return {false, 0};
}

[[maybe_unused]] std::tuple<bool, int> expectRemove(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "-");

    if (res != array.end()) {
        return {true, std::distance(array.begin(), res)};
    }
    return {false, 0};
}

int main() {
    std::string content = "10 + 25 * 3 / 2";

    std::vector<std::string> contentSplitted = split(content);

    auto [operatorMulti, caseVectorMulti] = expectMulti(contentSplitted);

    if (operatorMulti) {
        int n1 = convertInt(contentSplitted[caseVectorMulti - 1]);
        int n2 = convertInt(contentSplitted[caseVectorMulti + 1]);
        int result = n1 * n2;
        contentSplitted[caseVectorMulti - 1] = std::to_string(result);
        contentSplitted[caseVectorMulti] = "N/A";
        contentSplitted[caseVectorMulti + 1] = "N/A";

        while (hasElementNA(contentSplitted)) {
            auto it = std::find(begin(contentSplitted), end(contentSplitted), "N/A");
            contentSplitted.erase(it);
        }
    }

    auto [operatorDiv, caseVectorDiv] = expectDiv(contentSplitted);

    if (operatorDiv) {
        int n1 = convertInt(contentSplitted[caseVectorDiv-1]);
        int n2 = convertInt(contentSplitted[caseVectorDiv+1]);
        int result = n1 / n2;
        contentSplitted[caseVectorDiv - 1] = std::to_string(result);
        contentSplitted[caseVectorDiv] = "N/A";
        contentSplitted[caseVectorDiv + 1] = "N/A";

        while (hasElementNA(contentSplitted)) {
            auto it = std::find(begin(contentSplitted), end(contentSplitted), "N/A");
            contentSplitted.erase(it);
        }
    }

    for (auto const& e : contentSplitted) {
        std::cout << e << std::endl;
    }

    return 0;
}