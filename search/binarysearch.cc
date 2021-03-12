/**
 * @file binarysearch.cc
 * @author koritafei (koritafei@gmail.com)
 * @brief 二分查找
 * @version 0.1
 * @date 2021-03-12
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>

int binarysearch(std::vector<int> &nums, int left, int right, int target) {
  while (left <= right) {
    int middle = (right - left) / 2 + left;
    if (nums[middle] == target) {
      return middle;
    } else if (nums[middle] < target) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return -1;
}

int main(int argc, char **argv) {
  std::vector<int> nums   = {1, 4, 7, 9, 10, 30};
  int              target = -1;
  std::cout << binarysearch(nums, 0, nums.size() - 1, target) << std::endl;
}
