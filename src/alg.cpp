
// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int prioritet(char sym) {
  switch (sym) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
    case '-':
      return 2;
    case '*':
    case '/':
      return 3;
    default:
      return -1;
  }
}

std::string infx2pstfx(std::string inf) {
  TStack<char> stackChar;
  std::string res;
  int i = 0;
  char top = 0;

  for (i; i < inf.length(); i++) {
    int p;
    p = prioritet(inf[i]);
    if (p > -1) {
      if ((p == 0 || p > p(top) || stackChar.isEmpty()) && inf[i] != ')') {
        if (stackChar.isEmpty()) top = inf[i];
        stackChar.push(inf[i]);
      } else if (inf[i] == ')') {
        while (stackChar.get() != '(') {
          res.push_back(stackChar.get());
          res.push_back(' ');
          stackChar.pop();
        }
        stackChar.pop();
        if (stackChar.isEmpty()) top = 0;
      } else {
        while (!stackChar.isEmpty() && p(stackChar.get()) >= p) {
          res.push_back(stackChar.get());
          res.push_back(' ');
          stackChar.pop();
        }
        if (stackChar.isEmpty()) top = inf[i];
        stackChar.push(inf[i]);
      }
    } else {
      res.push_back(inf[i]);
      res.push_back(' ');
    }
  }
  while (!stackChar.isEmpty()) {
    res.push_back(stackChar.get());
    res.push_back(' ');
    stackChar.pop();
  }
  res.erase(res.end() - 1, res.end());

  return res;
}

int eval(std::string pst) {
  TStack<int> stack;
  int a, b, temp = 0;
  int i, result;
  int top = 0;

  for (i = 0; i < pst.length(); i++) {
    if (pst[i] <= '9' && pst[i] >= '0') {
      temp = temp + (pst[i] - '0');
    } else {
      a = stack.top();
      stack.pop();
      b = stack.top();
      stack.pop();
    }

    switch (pst[i]) {
      case '+':
        temp = a + b;
        break;
      case '-':
        temp = b - a;
        break;
      case '*':
        temp = b * a;
        break;
      case '/':
        temp = b / a;
        break;
    }
    stack.push(temp);
  }
}
result = stack.top();
return result;
}
