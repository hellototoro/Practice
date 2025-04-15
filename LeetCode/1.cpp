#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m-- + n-- - 1;
        while ((m | n) >= 0) {
            nums1[index--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
        }
        while (n >= 0) {
            nums1[index--] = nums2[n--];
        }
    }
};