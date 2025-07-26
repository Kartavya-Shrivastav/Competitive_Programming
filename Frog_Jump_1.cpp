/*
A Frog Jump 1

Problem Statement
There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi. There is a frog who is initially on Stone 1. 
He will repeat the following action some number of times to reach Stone N:
    If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2. Here, a cost of ∣hi − hj∣ is incurred, where 
    j is the stone to land on. Find the minimum possible total cost incurred before the frog reaches Stone N.

Constraints
All values in input are integers.
2≤N≤10^5
1≤hi≤10^4

Time Limit: 2 sec / Memory Limit: 1024 MiB

Output
Print the minimum possible total cost incurred.

Sample Input 1      Sample Output 1
4                   30
10 30 40 20
If we follow the path 1 → 2 → 4, the total cost incurred would be ∣10−30∣+∣30−20∣=30.

Sample Input 2      Sample Output 2
2                   0       
10 10
If we follow the path 1 → 2, the total cost incurred would be ∣10−10∣=0.

Sample Input 3      Sample Output 3
6                   40
30 10 60 10 60 50
If we follow the path 1 → 3 → 5 → 6, the total cost incurred would be ∣30−60∣+∣60−60∣+∣60−50∣=40.

*/


// ------------------------------------------------------------------------------------------------------------------------------------------

// Steps:
// 1. Read the number of stones (N).
// 2. Read the heights of the stones into an array.
// 3. Initialize a dynamic programming array (dp) to store the minimum cost to reach each stone.
// 4. Set the cost to reach the first stone to 0 and the second stone based on the height difference.
// 5. Iterate through each stone starting from the third one.
// 6. For each stone, calculate the cost to jump from the previous two stones and update the dp array with the minimum cost.
// 7. Finally, print the minimum cost to reach the last stone.

// ------------------------------------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> dp(n, INT_MAX); // dp[i] = min cost to reach stone i
    dp[0] = 0; // cost to stay on the first stone is 0
    dp[1] = abs(arr[1] - arr[0]); // only one way to jump from stone 1 to 2

    for (int i = 2; i < n; ++i) {
        int one = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int two = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        dp[i] = min(one, two);
    }

    cout << dp[n - 1] << endl; // minimum cost to reach last stone
    return 0;
}