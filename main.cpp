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

bool hasElement(std::vector<std::string> array, std::string element) {
    auto res = std::find(begin(array), end(array), element);

    if (res != array.end()) {
        return true;
    }
    return false;
}

int expectElement(std::vector<std::string> array, std::string element) {
    auto res = std::find(begin(array), end(array), element);

    if (res != array.end()) {
        return std::distance(array.begin(), res);
    }
    return 0;
}

void operations(std::vector<std::string>& array, int& caseVector, std::string op) {
    int n1 = convertInt(array[caseVector-1]);
    int n2 = convertInt(array[caseVector+1]);
    int result = 0;
    if (op == "-") {
        result = n1 - n2;
    } else if (op == "+") {
        result = n1 + n2;
    } else if (op == "*") {
        result = n1 * n2;
    } else if (op == "/") {
        result = n1 / n2;
    }
    array[caseVector - 1] = std::to_string(result);
    array[caseVector] = "N/A";
    array[caseVector + 1] = "N/A";

    while (hasElement(array, "N/A")) {
        auto it = std::find(begin(array), end(array), "N/A");
        array.erase(it);
    }
}

int main() {
    std::string content = "9 + 10";

    std::vector<std::string> contentSplitted = split(content);

    int totalSizeVector = contentSplitted.size();

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

    int final_result = convertInt(contentSplitted[0]);
    std::cout << final_result << std::endl;

    return 0;
}