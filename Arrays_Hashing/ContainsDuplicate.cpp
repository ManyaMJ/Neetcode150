/*
================================================================================
LeetCode 217: Contains Duplicate
================================================================================
Difficulty: Easy
Topics: Array, Hash Table
Link: https://leetcode.com/problems/contains-duplicate/

Problem Description:
Given an integer array nums, return true if any value appears at least twice 
in the array, and return false if every element is distinct.

Examples:
Input: nums = [1,2,3,1]
Output: true

Input: nums = [1,2,3,4] 
Output: false

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Constraints:
• 1 <= nums.length <= 10^5
• -10^9 <= nums[i] <= 10^9

================================================================================
Approach: Hash Set (Optimal Solution)
================================================================================
Algorithm:
1. Use an unordered_set to track seen elements
2. Iterate through the array once
3. For each element, check if it's already in the set using count()
4. If found (count returns 1), return true immediately
5. If not found, insert the element into the set
6. If we complete the loop without finding duplicates, return false

Time Complexity: O(n) - single pass through the array
Space Complexity: O(n) - worst case when all elements are unique

Why unordered_set?
- Average O(1) insertion and lookup
- Perfect for membership testing
- count() method is cleaner than find() != end()

Alternative Approaches:
1. Sorting: Sort array and check adjacent elements - O(n log n) time, O(1) space
2. Brute Force: Nested loops - O(n²) time, O(1) space
================================================================================
*/

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        
        for(int num : nums) {
            if(seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        
        return false;
    }
};

/*
================================================================================
Test Cases & Dry Run
================================================================================
Test Case 1: nums = [1,2,3,1]
- num = 1: seen = {}, count(1) = 0, insert 1 → seen = {1}
- num = 2: seen = {1}, count(2) = 0, insert 2 → seen = {1,2}  
- num = 3: seen = {1,2}, count(3) = 0, insert 3 → seen = {1,2,3}
- num = 1: seen = {1,2,3}, count(1) = 1, return true ✓

Test Case 2: nums = [1,2,3,4]
- All elements unique, seen grows to {1,2,3,4}, return false ✓

Edge Cases:
- Single element [1] → return false
- Two identical [1,1] → return true
- Large array with duplicate at end → O(n) performance maintained
================================================================================
*/