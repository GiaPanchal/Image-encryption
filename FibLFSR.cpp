// Copyright 2024 <Gia Panchal>

#include "FibLFSR.hpp"
#include <string>

PhotoMagic::FibLFSR::FibLFSR(std::string seed) {
    reg = seed;
}

// Simulate one step and return the new bit as 0 or 1
int PhotoMagic::FibLFSR::step() {
    tap10 = std::stoi(reg.substr(5, 1));
    tap12 = std::stoi(reg.substr(3, 1));
    tap13 = std::stoi(reg.substr(2, 1));
    tap15 = std::stoi(reg.substr(0, 1));
    int xorResult = tap10 ^ tap12 ^ tap13 ^ tap15;
    std::string nextReg = reg.substr(1) + std::to_string(xorResult);
    reg = nextReg;
    return xorResult;
}

// Simulate k steps and return a k-bit integer
int PhotoMagic::FibLFSR::generate(int k) {
    std::string result;
    for (int i = 0; i < k; i++) {
        result += std::to_string(step());
    }
    int num = 0;
    int base = 1;
    while (!result.empty()) {
        int lastnum = std::stoi(std::string(1, result.back()));
        result.pop_back();
        num += lastnum * base;
        base *= 2;
    }
    return num;
}

std::ostream& PhotoMagic::operator<<(std::ostream& os, const PhotoMagic::FibLFSR& lfsr) {
    os << lfsr.getReg();
    return os;
}
