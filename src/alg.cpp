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
  std::string pstfx;
  int i = 0;
  char top = 0;
  int pr;
  pr = prioritet(ch);

  for (i = 0; i < inf.length(); i++) {
    if (pr > -1) {
      if ((pr == 0 || pr > pr(top) || stackChar.isEmpty()) && inf[i] != ')') {
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
        while (!stackChar.isEmpty() && pr(stackChar.get()) >= pr) {
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
  TStack<int> stackInt;
  int a, b, temp = 0;
  int i, result;

  for (i = 0; i < pst.length(); i++) {
    if (pst[i] <= '9' && pst[i] >= '0')
      temp = temp + (pst[i] - '0');
    else {
      a = pop();
      b = pop();

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
      push(temp);
    }
  }
  result = pop();
  return result;
}
