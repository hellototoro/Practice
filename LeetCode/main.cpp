#include <iostream>
#include <vector>
#include <algorithm>
#include "1.cpp"

//class Solution1;

int main()
{
    vector<int> nums = { 4, 2, 3, 4, 1, 2 };
    
    int val = 4;
    int n = nums.size();
    int left = 0;
    for (int right = 0; right < n; right++) {
        if (nums[right] != val) {
            nums[left] = nums[right];
            left++;
        }
    }
    //std::sort(nums.begin(), nums.end());

    // 输出结果
    for (auto i = nums.begin(); i != nums.end(); ++i) {
        if (i != nums.begin()) {
            cout << ' ';
        }
        cout << *i;
    }

    return 0;
}