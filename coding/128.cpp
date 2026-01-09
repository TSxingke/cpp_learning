#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> num_set;
            for(int num : nums){
                num_set.insert(num);
            }

            int longest_streak = 0;

            for(int num : num_set){
                if(num_set.find(num - 1) == num_set.end()){
                    int current_num = num;
                    int current_streak = 1;

                    while(num_set.find(current_num + 1) != num_set.end()){
                        current_streak += 1;
                        current_num += 1;
                    }
                    longest_streak = max(longest_streak, current_streak);
                }
            }

            return longest_streak;
        }
    };

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Test Case 1: " << sol.longestConsecutive(nums1) << " (Expected: 4)" << endl;

    // 测试用例 2
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Test Case 2: " << sol.longestConsecutive(nums2) << " (Expected: 9)" << endl;
    
    // 测试用例 3: 空数组
    vector<int> nums3 = {};
    cout << "Test Case 3: " << sol.longestConsecutive(nums3) << " (Expected: 0)" << endl;

    return 0;
}


// 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

// 示例 1：

// 输入：nums = [100,4,200,1,3,2]
// 输出：4
// 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
// 示例 2：

// 输入：nums = [0,3,7,2,5,8,4,6,0,1]
// 输出：9
// 示例 3：

// 输入：nums = [1,0,1,2]
// 输出：3
 

// 提示：

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109