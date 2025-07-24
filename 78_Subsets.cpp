/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
 

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/

// ------------------------------------------------------------------------------------------------------------------------------------------

// Steps:
// 1. Initialize an empty vector `ans` to store all subsets.
// 2. Determine the size of the input vector `nums` and store it in `n`.
// 3. Loop through all integers from 0 to (1 << n) - 1, which represents all possible subsets.
// 4. For each integer `i`, initialize an empty vector `subset` to build the current subset.
// 5. Loop through each bit position from 0 to n-1:
//   - If the bit at position j in i is set (i.e., `i & (1 << j)` is true), include `nums[j]` in the current subset.
// 6. After checking all bits, add the current `subset` to `ans`.
// 7. Finally, return the vector `ans` containing all subsets.

// ------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        for(int i=0; i<(1<<n); i++){
            vector<int> subset;
            for(int j=0; j<n; j++){
                if (i & (1<<j))
                    subset.push_back(nums[j]);
            }

            ans.push_back(subset);
        }

        return ans;
    }
};