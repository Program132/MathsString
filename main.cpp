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

bool hasElementMulti(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "*");

    if (res != array.end()) {
        return true;
    }
    return false;
}

bool hasElementDiv(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "/");

    if (res != array.end()) {
        return true;
    }
    return false;
}

bool hasElementAdd(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "+");

    if (res != array.end()) {
        return true;
    }
    return false;
}

bool hasElementRemove(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "-");

    if (res != array.end()) {
        return true;
    }
    return false;
}



int expectMulti(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "*");

    if (res != array.end()) {
        return std::distance(array.begin(), res);
    }
    return 0;
}

int expectDiv(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "/");

    if (res != array.end()) {
        return std::distance(array.begin(), res);
    }
    return 0;
}

int expectAdd(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "+");

    if (res != array.end()) {
        return std::distance(array.begin(), res);
    }
    return 0;
}

int expectRemove(std::vector<std::string> array) {
    auto res = std::find(begin(array), end(array), "-");

    if (res != array.end()) {
        return std::distance(array.begin(), res);
    }
    return 0;
}

int main() {
    std::string content = "3 * 5 + 2 * 2 - 1";

    std::vector<std::string> contentSplitted = split(content);
    int totalSizeVector = contentSplitted.size();

    int i = 0;

    while (i < totalSizeVector) {

        while (hasElementMulti(contentSplitted)) {
            auto caseVectorMulti = expectMulti(contentSplitted);

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


        while (hasElementDiv(contentSplitted)) {
            auto caseVectorDiv = expectDiv(contentSplitted);

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

        while (hasElementAdd(contentSplitted)) {
            auto caseVectorAdd = expectAdd(contentSplitted);

            int n1 = convertInt(contentSplitted[caseVectorAdd-1]);
            int n2 = convertInt(contentSplitted[caseVectorAdd+1]);
            int result = n1 + n2;
            contentSplitted[caseVectorAdd - 1] = std::to_string(result);
            contentSplitted[caseVectorAdd] = "N/A";
            contentSplitted[caseVectorAdd + 1] = "N/A";

            while (hasElementNA(contentSplitted)) {
                auto it = std::find(begin(contentSplitted), end(contentSplitted), "N/A");
                contentSplitted.erase(it);
            }
        }

        while (hasElementRemove(contentSplitted)) {
            auto caseVectorRemove = expectRemove(contentSplitted);

            int n1 = convertInt(contentSplitted[caseVectorRemove-1]);
            int n2 = convertInt(contentSplitted[caseVectorRemove+1]);
            int result = n1 - n2;
            contentSplitted[caseVectorRemove - 1] = std::to_string(result);
            contentSplitted[caseVectorRemove] = "N/A";
            contentSplitted[caseVectorRemove + 1] = "N/A";

            while (hasElementNA(contentSplitted)) {
                auto it = std::find(begin(contentSplitted), end(contentSplitted), "N/A");
                contentSplitted.erase(it);
            }
        }
        i++;
    }


    for (auto const& e : contentSplitted) {
        std::cout << e << std::endl;
    }

    return 0;
}