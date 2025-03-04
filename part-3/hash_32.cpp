#include <iostream>
#include <string>
#include <cstdint>

uint32_t hash(const std::string& str, const uint32_t m) {
    uint32_t out = 0;
    uint32_t power = 1; // Tracks 256^i mod m incrementally
    for (unsigned char c : str) { // Ensure c is treated as unsigned
        uint32_t term = (static_cast<uint32_t>(c) % m) * power % m;
        out = (out + term) % m;
        power = (power * 256) % m; // Update power for next character
    }
    return out;
}

int main() {
    std::string s = "olleH";
    uint32_t m = 255;
    std::cout << hash(s, m) << std::endl; // Output: 0
}