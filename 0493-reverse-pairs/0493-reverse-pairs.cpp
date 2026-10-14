#include <vector>

class Solution {
public:
    void merge(std::vector<long long>& nums, long long low, long long mid, long long high, long long &count) {
        long long lefty = low, righty = mid + 1;
        while (lefty <= mid && righty <= high) {
            // Fixed: Use multiplication with 2LL to prevent integer division truncation and overflow
            if (nums[lefty] <= 2LL * nums[righty]) {
                lefty++;
            } else {
                count += mid - lefty + 1;
                righty++;
            }
        }
        
        std::vector<long long> temp;
        long long left = low, right = mid + 1;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid) { temp.push_back(nums[left]); left++; }
        while (right <= high) { temp.push_back(nums[right]); right++; }
        
        for (long long i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    
    void sort(std::vector<long long>& nums, long long low, long long high, long long &count) {
        if (low >= high) { return; }
        long long mid = low + (high - low) / 2;
        sort(nums, low, mid, count);
        sort(nums, mid + 1, high, count);
        merge(nums, low, mid, high, count);
    } 
    
    long long reversePairs(std::vector<int>& a) {
        if (a.empty()) return 0;
        std::vector<long long> nums(a.begin(), a.end());
        long long count = 0;
        sort(nums, 0, nums.size() - 1, count);
        return count;
    }
};