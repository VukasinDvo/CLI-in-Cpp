//
// Created by vladi on 8/19/2026.
//

#include <stdexcept>

class ParseExeptions :public std::runtime_error {
    explicit ParseExeptions(const std::string& msg) : std::runtime_error(msg) {}
};