#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>
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

std::tuple<bool, int> expectAdd(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "+");

    if (res != array.end()) {
        return {true, std::distance(array.begin(), res)};
    }
    return {false, 0};
}

std::tuple<bool, int> expectRemove(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "-");

    if (res != array.end()) {
        return {true, std::distance(array.begin(), res)};
    }
    return {false, 0};
}

int main() {
    std::string content = "10 + 25 * 3 / 2";

    std::vector<std::string> contentSplitted = split(content);

    auto [operatorMulti, caseVector] = expectMulti(contentSplitted);



    return 0;
}