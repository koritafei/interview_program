/**
 * @file treeorder.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 二叉树，遍历的递归与非递归实现
 * @version 0.1
 * @date 2021-03-07
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
  int       val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x),
        left(left),
        right(right) {
  }
};

class Tree {
public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    // 中序递归
    std::vector<int> res;
    if (root == nullptr) {
      return res;
    }

    inorderTraversal(root, res);
    return res;
  }

  std::vector<int> inorderTraversal_v2(TreeNode *root) {
    // 中序非递归
    std::vector<int> res;
    if (root == nullptr) {
      return res;
    }

    inorderTraversal_v2(root, res);
    return res;
  }

  std::vector<int> firstorderTraversal(TreeNode *root) {
    // 先序递归
    std::vector<int> res;
    if (root == nullptr) {
      return res;
    }

    firstorderTraversal(root, res);
    return res;
  }

  std::vector<int> lastorderTraversal(TreeNode *root) {
    // 后序递归
    std::vector<int> res;
    if (root == nullptr) {
      return res;
    }

    lastorderTraversal(root, res);
    return res;
  }

  std::vector<int> firstorderTraversal_v2(TreeNode *root) {
    // 先序非递归
    std::vector<int> res;
    if (root == nullptr) {
      return res;
    }

    firstorderTraversal_v2(root, res);
    return res;
  }

  std::vector<int> lastorderTraversal_v2(TreeNode *root) {
    // 后序非递归
    std::vector<int> res;
    if (root == nullptr) {
      return res;
    }

    lastorderTraversal_v2(root, res);
    return res;
  }

private:
  void inorderTraversal(TreeNode *root, std::vector<int> &res) {
    // 中序递归
    if (root == nullptr) {
      return;
    }

    inorderTraversal(root->left, res);
    res.push_back(root->val);
    inorderTraversal(root->right, res);
  }

  void firstorderTraversal(TreeNode *root, std::vector<int> &res) {
    // 先序递归
    if (root == nullptr) {
      return;
    }

    res.push_back(root->val);
    firstorderTraversal(root->left, res);
    firstorderTraversal(root->right, res);
  }

  void lastorderTraversal(TreeNode *root, std::vector<int> &res) {
    // 后序递归
    if (root == nullptr) {
      return;
    }

    lastorderTraversal(root->left, res);
    lastorderTraversal(root->right, res);
    res.push_back(root->val);
  }

  void inorderTraversal_v2(TreeNode *root, std::vector<int> &res) {
    // 中序非递归
    std::stack<TreeNode *> stack;
    while (!stack.empty() || root != nullptr) {
      if (root != nullptr) {
        stack.push(root);
        root = root->left;
      } else {
        root = stack.top();
        stack.pop();
        res.push_back(root->val);
        root = root->right;
      }
    }
  }

  void firstorderTraversal_v2(TreeNode *root, std::vector<int> &res) {
    // 先序非递归
    std::stack<TreeNode *> stack;

    while (!stack.empty() || root != nullptr) {
      if (root != nullptr) {
        res.push_back(root->val);
        stack.push(root);
        root = root->left;
      } else {
        root = stack.top();
        stack.pop();
        root = root->right;
      }
    }
  }

  void lastorderTraversal_v2(TreeNode *root, std::vector<int> &res) {
    // 后序非递归
    std::stack<TreeNode *> stack1;
    std::stack<TreeNode *> stack2;
    if (root != nullptr) {
      stack1.push(root);
      while (!stack1.empty()) {
        root = stack1.top();
        stack1.pop();
        stack2.push(root);
        if (root->left != nullptr) {
          stack1.push(root->left);
        }
        if (root->right != nullptr) {
          stack1.push(root->right);
        }
      }

      while (!stack2.empty()) {
        int val = stack2.top()->val;
        res.push_back(val);
        stack2.pop();
      }
    }
  }
};

int main(int argc, char **argv) {
  Tree      tree;
  TreeNode *root  = new TreeNode(1);
  TreeNode *left  = new TreeNode(3);
  TreeNode *right = new TreeNode(2);
  TreeNode *r     = new TreeNode(4);
  root->right     = right;
  right->left     = left;
  root->left      = r;

  std::vector<int> res = tree.inorderTraversal(root);
  std::cout << "inorder traversal: " << std::endl;
  for (auto item : res) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  res = tree.inorderTraversal_v2(root);
  std::cout << "inorder traversal: " << std::endl;
  for (auto item : res) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  res = tree.firstorderTraversal(root);
  std::cout << "first traversal: " << std::endl;
  for (auto item : res) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  res = tree.firstorderTraversal_v2(root);
  std::cout << "first traversal: " << std::endl;
  for (auto item : res) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  res = tree.lastorderTraversal(root);
  std::cout << "last traversal: " << std::endl;
  for (auto item : res) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
  res = tree.lastorderTraversal_v2(root);
  std::cout << "last traversal: " << std::endl;
  for (auto item : res) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}
