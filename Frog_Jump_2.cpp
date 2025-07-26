/*
B - Frog 2

Problem Statement
There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi. There is a frog who is initially on Stone 1. 
He will repeat the following action some number of times to reach Stone N:
    If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,…,i+K. Here, a cost of ∣hi − hj∣ is incurred, where 
    j is the stone to land on. Find the minimum possible total cost incurred before the frog reaches Stone N.

Constraints
All values in input are integers.
2≤N≤10^5
1≤K≤100
1≤hi≤10^4

Time Limit: 2 sec / Memory Limit: 1024 MiB

Output
Print the minimum possible total cost incurred.

Sample Input 1          Sample Output 1
5 3                     30
10 30 40 50 20
If we follow the path 1 → 2 → 5, the total cost incurred would be ∣10−30∣+∣30−20∣=30.

Sampele Input 2         Sample Output 2
3 1             10      20
10 20 10    
If we follow the path 1 → 2 → 3, the total cost incurred would be ∣10−20∣+∣20−10∣=20.

Sample Input 3          Sample Output 3
2 100                   0
10 10
If we follow the path 1 → 2, the total cost incurred would be ∣10−10∣=0.

Sample Input 4          Sample Output 4
10 4                    40
40 10 20 70 80 10 20 70 80 60
If we follow the path 1 → 4 → 8 → 10, the total cost incurred would be ∣40−70∣+∣70−70∣+∣70−60∣=40.
*/

// ------------------------------------------------------------------------------------------------------------------------------------------

// Steps:
// 1. Read the number of stones (N) and the maximum jump distance (K).
// 2. Read the heights of the stones into an array.
// 3. Initialize a dynamic programming array (dp) to store the minimum cost to reach each stone.
// 4. Set the cost to reach the first stone to 0 and the second stone based on the height difference.
// 5. Iterate through each stone starting from the second one.
// 6. For each stone, check all possible jumps from the previous K stones and update the dp array with the minimum cost.
// 7. Finally, print the minimum cost to reach the last stone.

// ------------------------------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k; cin >> n >> k;
  vector<int> arr(n);
  for(int i=0; i<n; i++) cin >> arr[i];
  
  vector<int> dp(n, INT_MAX);
  dp[0] = 0;
  dp[1] = abs(dp[1] - dp[0]);
  
  for(int i=1; i<n; i++){
    for(int j=1; j<=k; j++){
      if(i-j >= 0){
        dp[i] = min(dp[i], dp[i-j] + abs(arr[i] - arr[i-j]));
      }
    }
  }
  
  cout << dp[n-1] << endl;
  return 0;
  
}