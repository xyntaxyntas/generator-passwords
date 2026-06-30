#include <iostream>
#include <string>
#include <random>

std::string generatePassword(int length = 16, bool includeSpecial = true) {
    const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string numbers = "0123456789";
    const std::string special = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    std::string chars = lowercase + uppercase + numbers;
    if (includeSpecial) {
        chars += special;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.length() - 1);

    std::string password;
    password.reserve(length);

    for (int i = 0; i < length; ++i) {
        password += chars[dis(gen)];
    }

    return password;
}

int main() {
    std::string password = generatePassword(16, true);
    std::cout << password << std::endl;

    std::string simplePassword = generatePassword(12, false);
    std::cout << simplePassword << std::endl;

    return 0;
}