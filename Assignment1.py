
# ==========================================
# PART A: REMOVE DUPLICATES FROM SORTED ARRAY
# ==========================================

# 1. Brute Force Approach
# Creates a separate list to store unique values.

def remove_duplicates_brute(nums):

    unique_values = []

    for value in nums:

        if value not in unique_values:
            unique_values.append(value)

    return unique_values


# 2. Optimized Approach
# Uses slow and fast pointers.
# Modifies the original list in place.

def remove_duplicates_optimized(nums):

    if len(nums) == 0:
        return 0

    slow = 0

    for fast in range(1, len(nums)):

        if nums[fast] != nums[slow]:

            slow += 1
            nums[slow] = nums[fast]

    return slow + 1


# ==========================================
# PART B: PAIR SUM IN A SORTED ARRAY
# ==========================================

# 3. Brute Force Approach
# Checks every possible pair using nested loops.

def pair_sum_brute(nums, target):

    for i in range(len(nums)):

        for j in range(i + 1, len(nums)):

            if nums[i] + nums[j] == target:
                return (i, j)

    return (-1, -1)


# 4. Optimized Approach
# Uses left and right pointers at opposite ends.

def pair_sum_optimized(nums, target):

    left = 0
    right = len(nums) - 1

    while left < right:

        current_sum = nums[left] + nums[right]

        if current_sum == target:
            return (left, right)

        elif current_sum < target:
            left += 1

        else:
            right -= 1

    return (-1, -1)


# ==========================================
# MAIN PROGRAM - TESTING ALL FOUR METHODS
# ==========================================


if __name__ == "__main__":

    print("===== DUPLICATE REMOVAL TESTS =====")

    duplicate_tests = [
        [1, 1, 2, 2, 2, 3, 4, 4],
        [5],
        [],
        [-3, -3, -1, 0, 0]
    ]

    for i, test in enumerate(duplicate_tests):

        nums = test.copy()

        k = remove_duplicates_optimized(nums)

        print(
            f"Test {i + 1}: k = {k}, "
            f"prefix = {nums[:k]}"
        )

    print("\n===== PAIR SUM TESTS =====")

    pair_tests = [
        [1, 2, 4, 7, 11, 15],
        [1, 3, 5, 8],
        [2, 4, 6],
        [1, 2, 2, 3]
    ]

    targets = [15, 7, 20, 4]

    for i, nums in enumerate(pair_tests):

        result = pair_sum_optimized(nums, targets[i])

        print(f"Test {i + 5}: {result}")
