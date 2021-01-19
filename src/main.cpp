// Copyright 19.01.21 DenisKabanov

#include "Mystack.h"
#include "postfix.h"

int main() {
    std::string s1("2 + 6 * 3 / (4 - 2)");
    std::cout << "original: " << s1 << std::endl;
    std::string s2 = infix2prefix(s1);
    std::cout << "changed: "<< s2 << std::endl;
    std::string s3("(1 + 2) / (3 + 4 * 6.7) - 5.3 * 4.4");
    std::cout << "original: " << s3 << std::endl;
    std::string s4 = infix2prefix(s3);
    std::cout << "changed: " << s4 << std::endl;
    return 0;
}