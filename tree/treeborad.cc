/**
 * @file treeborad.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 输出二叉树的边界节点
 * @version 0.1
 * @date 2021-03-08
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
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

class Solution {
public:
  void TreeBoard_1(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    int level = maxDepth(root);

    std::vector<std::vector<TreeNode *>> edge;
    edge.resize(level);
    for (int i = 0; i < level; i++) {
      edge[i].resize(2);
    }
    setEdgeMap(root, 0, edge);

    // 最左边界
    for (int i = 0; i < level; i++) {
      std::cout << edge[i][0]->val << std::endl;
    }
    // 非左右边界的叶节点
    getLeafNode(root, 0, edge);

    // 最右边界
    for (int i = level - 1; i >= 0; i--) {
      if (edge[i][0] != edge[i][1]) {
        std::cout << edge[i][1]->val << " ";
      }
    }
    std::cout << std::endl;
  }

  void TreeBoard_2(TreeNode *root) {
    if (root == nullptr) {
      return;
    }

    std::cout << root->val << " ";
    if (root->left != nullptr && root->right != nullptr) {
      printLeft(root->left, true);
      printRight(root->right, true);
    } else {
      TreeBoard_2(root->left == nullptr ? root->right : root->left);
    }
  }

private:
  // 打印左边界
  void printLeft(TreeNode *root, bool print) {
    if (root == nullptr) {
      return;
    }

    if (print || (root->left == nullptr && root->right == nullptr)) {
      std::cout << root->val << " ";
    }

    printLeft(root->left, print);
    printLeft(root->right, print && (root->left == nullptr ? true : false));
  }

  // 打印右边界
  void printRight(TreeNode *root, bool print) {
    if (root == nullptr) {
      return;
    }

    printRight(root->left, print && (root->right == nullptr ? true : false));
    printRight(root->right, print);
    if (print || (root->right == nullptr && root->left == nullptr)) {
      std::cout << root->val << " ";
    }
  }

  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
  }

  void setEdgeMap(TreeNode *root, int level,
                  std::vector<std::vector<TreeNode *>> &edge) {
    if (root == nullptr) {
      return;
    }

    edge[level][0] = edge[level][0] == nullptr ? root : edge[level][0];
    edge[level][1] = root;
    setEdgeMap(root->left, level + 1, edge);
    setEdgeMap(root->right, level + 1, edge);
  }

  void getLeafNode(TreeNode *root, int level,
                   std::vector<std::vector<TreeNode *>> &edge) {
    if (root == nullptr) {
      return;
    }

    if (root->left == nullptr && root->right == nullptr &&
        root != edge[level][0] && root != edge[level][1]) {
      std::cout << root->val << " ";
    }

    getLeafNode(root->left, level + 1, edge);
    getLeafNode(root->right, level + 1, edge);
  }
};

int main(int argc, char **argv) {
  Solution  tree;
  TreeNode *root  = new TreeNode(1);
  TreeNode *left  = new TreeNode(3);
  TreeNode *right = new TreeNode(2);
  TreeNode *r     = new TreeNode(4);
  root->right     = right;
  right->left     = left;
  root->left      = r;
  tree.TreeBoard_1(root);
  tree.TreeBoard_2(root);
}
