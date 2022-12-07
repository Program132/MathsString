#include <string>
#include <vector>
#include <sstream>
#include <iostream>

double convertDouble(std::string& n) {
    try {
        double v = std::stod(n);
        return v;
    }
    catch (std::invalid_argument const& ex) {
        std::cout << "It can not be a int value !" << " Final error: " << ex.what() << std::endl;
    }

    return 0;
}