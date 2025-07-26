/*
You have a list arr of all integers in the range [1, n] sorted in a strictly increasing order. Apply the following algorithm on arr:
Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
Repeat the previous step again, but this time from right to left, remove the rightmost number and every other number from the remaining numbers.
Keep repeating the steps again, alternating left to right and right to left, until a single number remains.
Given the integer n, return the last number that remains in arr.

Example 1:
Input: n = 9
Output: 6

Explanation:
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9]
arr = [2, 4, 6, 8]
arr = [2, 6]
arr = [6]

Example 2:
Input: n = 1
Output: 1 

Constraints:
1 <= n <= 109
*/

// ----------------------------------------------------------------------------------------------------------------------------------------

// Steps:
// 1. Initialize variables to track the direction of elimination, starting position, and step size.
// 2. Use a while loop to continue the elimination process until only one number remains.
// 3. In each iteration, check the current direction:
//    - If eliminating from left to right, update the starting position based on the current step size.
//    - If eliminating from right to left, adjust the starting position accordingly.
// 4. Update the number of elements remaining by halving it.
// 5. Toggle the direction for the next iteration and double the step size.
// 6. Return the last remaining number after the loop ends.

// ----------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int lastRemaining(int n) {
        int fl=1, st=1, step=1;
        while(n>1){
            if(fl || n%2!=0) st = st+step;
            n = n/2;
            fl = fl^1;
            step *= 2;
        }
        return st;
    }
};