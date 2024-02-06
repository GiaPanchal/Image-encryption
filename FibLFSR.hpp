// Copyright 2024 <Gia Panchal>
#ifndef  _HOME_JPANCHAL_PS1_FIBLFSR_HPP_
#define  _HOME_JPANCHAL_PS1_FIBLFSR_HPP_

#include <string>
#include <iostream>

namespace PhotoMagic {
class FibLFSR {
 public:
    // Constructor to create LFSR with the given initial seed
    explicit FibLFSR(std::string seed);

    // Simulate one step and return the new bit as 0 or 1
    int step();

    // Simulate k steps and return a k-bit integer
    int generate(int k);

    std::string getReg() const { return reg; }

 private:
    // Any fields that you need
    std::string reg;
    int tap10;
    int tap12;
    int tap13;
    int tap15;
};

std::ostream& operator<<(std::ostream& os, const FibLFSR& lfsr);
}  // namespace PhotoMagic

#endif  // _HOME_JPANCHAL_PS1_FIBLFSR_HPP_
