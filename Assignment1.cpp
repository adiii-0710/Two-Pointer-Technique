
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// ==========================================
// PART A: REMOVE DUPLICATES FROM SORTED ARRAY
// ==========================================

// 1. Brute Force Approach
// Creates a separate vector to store unique values.

vector<int> removeDuplicatesBrute(vector<int> nums) {
    vector<int> uniqueValues;

    for (int value : nums) {
        bool found = false;

        for (int existing : uniqueValues) {
            if (existing == value) {
                found = true;
                break;
            }
        }

        if (!found) {
            uniqueValues.push_back(value);
        }
    }

    return uniqueValues;
}

// 2. Optimized Approach using Slow and Fast Pointers
// Modifies the original array in place and returns k.

int removeDuplicatesOptimized(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    int slow = 0;

    for (int fast = 1; fast < nums.size(); fast++) {
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
    }

    return slow + 1;
}

// ==========================================
// PART B: PAIR SUM IN A SORTED ARRAY
// ==========================================

// 3. Brute Force Approach
// Checks every possible pair using nested loops.

pair<int, int> pairSumBrute(vector<int> nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

// 4. Optimized Approach using Two Pointers
// Starts from opposite ends of the sorted array.

pair<int, int> pairSumOptimized(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) {
            return {left, right};
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    return {-1, -1};
}

// ==========================================
// MAIN FUNCTION - TESTING ALL FOUR METHODS
// ==========================================

int main() {

    cout << "===== DUPLICATE REMOVAL TESTS =====\n";

    vector<vector<int>> duplicateTests = {
        {1, 1, 2, 2, 2, 3, 4, 4},
        {5},
        {},
        {-3, -3, -1, 0, 0}
    };

    for (int i = 0; i < duplicateTests.size(); i++) {

        vector<int> nums = duplicateTests[i];
        int k = removeDuplicatesOptimized(nums);

        cout << "Test " << i + 1 << ": k = " << k << ", prefix = [";

        for (int j = 0; j < k; j++) {
            cout << nums[j];
            if (j < k - 1) cout << ", ";
        }

        cout << "]\n";
    }

    cout << "\n===== PAIR SUM TESTS =====\n";

    vector<vector<int>> pairTests = {
        {1, 2, 4, 7, 11, 15},
        {1, 3, 5, 8},
        {2, 4, 6},
        {1, 2, 2, 3}
    };

    int targets[] = {15, 7, 20, 4};

    for (int i = 0; i < pairTests.size(); i++) {

        pair<int, int> result =
            pairSumOptimized(pairTests[i], targets[i]);

        cout << "Test " << i + 5 << ": ("
             << result.first << ", "
             << result.second << ")\n";
    }

    return 0;
}
