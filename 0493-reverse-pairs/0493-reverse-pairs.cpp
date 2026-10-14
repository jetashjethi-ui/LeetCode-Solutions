#include <vector>

class Solution {
private:
    void mergeAndCount(std::vector<long long>& nums, int low, int mid, int high, long long &count, std::vector<long long>& temp) {
        int lefty = low, righty = mid + 1;
        while (lefty <= mid && righty <= high) {
            if (nums[lefty] <= 2LL * nums[righty]) {
                lefty++;
            } else {
                count += (mid - lefty + 1);
                righty++;
            }
        }
        
        // Merge step using the pre-allocated temp buffer
        int left = low, right = mid + 1, idx = low;
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp[idx++] = nums[left++];
            } else {
                temp[idx++] = nums[right++];
            }
        }
        while (left <= mid) temp[idx++] = nums[left++];
        while (right <= high) temp[idx++] = nums[right++];
        
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i];
        }
    }

    void sort(std::vector<long long>& nums, int low, int high, long long &count, std::vector<long long>& temp) {
        if (low >= high) return;
        int mid = low + (high - low) / 2;
        sort(nums, low, mid, count, temp);
        sort(nums, mid + 1, high, count, temp);
        mergeAndCount(nums, low, mid, high, count, temp);
    }

public:
    long long reversePairs(std::vector<int>& a) {
        if (a.empty()) return 0;
        std::vector<long long> nums(a.begin(), a.end());
        std::vector<long long> temp(nums.size()); // Pre-allocated once
        long long count = 0;
        sort(nums, 0, nums.size() - 1, count, temp);
        return count;
    }
};