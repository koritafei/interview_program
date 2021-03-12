/**
 * @file resverstack.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 递归函数和栈操作逆置栈
 * @version 0.1
 * @date 2021-02-25
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <stack>

class Solve {
  public:
  void resverstack(std::stack<int> &stack) {
    // 递归和栈操作，辅助递归函数栈
    if (stack.empty()) {
      return;
    }

    int top = getAndRemoveLastItem(stack);
    resverstack(stack);
    stack.push(top);
  }

  private:
  // 获取栈中最后一个元素
  int getAndRemoveLastItem(std::stack<int> &stack) {
    if (!stack.empty()) {
      int top = stack.top();
      stack.pop();

      if (stack.empty()) {
        // 栈空
        return top;
      }
      int last = getAndRemoveLastItem(stack);
      stack.push(top);
      return last;
    } else
      throw "empty stack";
  }
};

int main(int argc, char **argv) {
  std::stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);

  Solve s;
  s.resverstack(stack);

  while (!stack.empty()) {
    std::cout << stack.top() << std::endl;
    stack.pop();
  }
}
