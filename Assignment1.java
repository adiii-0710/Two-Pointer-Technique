
import java.util.ArrayList;
import java.util.Arrays;

// ==========================================
// PART A: REMOVE DUPLICATES FROM SORTED ARRAY
// ==========================================

public class Assignment1 {

    // 1. Brute Force Approach
    // Uses a separate ArrayList to store unique values.

    static ArrayList<Integer> removeDuplicatesBrute(int[] nums) {

        ArrayList<Integer> uniqueValues = new ArrayList<>();

        for (int value : nums) {

            if (!uniqueValues.contains(value)) {
                uniqueValues.add(value);
            }
        }

        return uniqueValues;
    }

    // 2. Optimized Approach
    // Uses slow and fast pointers.
    // Modifies the original array.

    static int removeDuplicatesOptimized(int[] nums) {

        if (nums.length == 0) {
            return 0;
        }

        int slow = 0;

        for (int fast = 1; fast < nums.length; fast++) {

            if (nums[fast] != nums[slow]) {

                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }

    // ==========================================
    // PART B: PAIR SUM IN SORTED ARRAY
    // ==========================================

    // 3. Brute Force Approach
    // Checks every possible pair.

    static int[] pairSumBrute(int[] nums, int target) {

        for (int i = 0; i < nums.length; i++) {

            for (int j = i + 1; j < nums.length; j++) {

                if (nums[i] + nums[j] == target) {
                    return new int[]{i, j};
                }
            }
        }

        return new int[]{-1, -1};
    }

    // 4. Optimized Approach
    // Uses opposite-end two pointers.

    static int[] pairSumOptimized(int[] nums, int target) {

        int left = 0;
        int right = nums.length - 1;

        while (left < right) {

            int sum = nums[left] + nums[right];

            if (sum == target) {
                return new int[]{left, right};
            }

            else if (sum < target) {
                left++;
            }

            else {
                right--;
            }
        }

        return new int[]{-1, -1};
    }

    // ==========================================
    // MAIN METHOD
    // ==========================================

    
public static void main(String[] args) {

    System.out.println("===== DUPLICATE REMOVAL TESTS =====");

    int[][] duplicateTests = {
        {1, 1, 2, 2, 2, 3, 4, 4},
        {5},
        {},
        {-3, -3, -1, 0, 0}
    };

    for (int i = 0; i < duplicateTests.length; i++) {

        int[] nums = duplicateTests[i].clone();

        int k = removeDuplicatesOptimized(nums);

        System.out.println("Test " + (i + 1) +
                ": k = " + k +
                ", prefix = " +
                Arrays.toString(Arrays.copyOf(nums, k)));
    }

    System.out.println("\n===== PAIR SUM TESTS =====");

    int[][] pairTests = {
        {1, 2, 4, 7, 11, 15},
        {1, 3, 5, 8},
        {2, 4, 6},
        {1, 2, 2, 3}
    };

    int[] targets = {15, 7, 20, 4};

    for (int i = 0; i < pairTests.length; i++) {

        int[] result =
                pairSumOptimized(pairTests[i], targets[i]);

        System.out.println("Test " + (i + 5) + ": " +
                Arrays.toString(result));
    }
}
}