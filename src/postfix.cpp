// Copyright 19.01.21 DenisKabanov

#include "postfix.h"
#include "MyStack.h"

std::string infix2prefix(std::string ArExpr) {
    std::string newExpr, space(" "), numbers = "0123456789.";
    ArExpr = ArExpr + space;
    MyStack<char> storage(999);
    char previous = 0;
    for (int i = 0; i < ArExpr.length(); i++) {
        if ((numbers.find(previous) != -1) &&
(numbers.find(ArExpr[i]) == -1)) {
            newExpr = newExpr + space;
        }
        if (ArExpr[i] == '(') {
            storage.push(ArExpr[i]);
        } else if (ArExpr[i] == ')') {
            while ((storage.isEmpty() == false) &&
(storage.get() != '(')) {
                newExpr = newExpr + storage.pop() + space;
            }
            if (storage.get() == '(')
                storage.pop();
        } else if ((ArExpr[i] == '/' ) || (ArExpr[i] == '*')) {
            while ((storage.isEmpty() == false) &&
(storage.get() != '(') && (storage.get() != '+') &&
(storage.get() != '-')) {
                newExpr = newExpr + storage.pop() + space;
            }
            storage.push(ArExpr[i]);
        } else if ((ArExpr[i] == '+') || (ArExpr[i] == '-')) {
            while ((storage.isEmpty() == false) &&
(storage.get() != '(')) {
                newExpr = newExpr + storage.pop() + space;
            }
            storage.push(ArExpr[i]);
        } else if (numbers.find(ArExpr[i]) != -1) {
             newExpr = newExpr + ArExpr[i];
        }
        previous = ArExpr[i];
    }
    while (storage.isEmpty() == false) {
        newExpr = newExpr + storage.pop() + space;
    }
	return newExpr;
}
