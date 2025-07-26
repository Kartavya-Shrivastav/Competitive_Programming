/*
D - Kanpsack 1

Problem Statement
There are N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of wi and a value of vi. Taro has decided to choose some of
the N items and carry them home in a knapsack. The capacity of the knapsack is W, which means that the sum of the weights of items taken 
must be at most W.

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1 ≤ N ≤ 100
1 ≤ W ≤ 10^5
1 ≤ wi ≤W
1 ≤ vi ≤ 10^9
Time Limit: 2 sec / Memory Limit: 1024 MiB

Input
Input is given from Standard Input in the following format:
N W
w1 v1
w2 v2
...
wN vN

Output
Print the maximum possible sum of the values of items that Taro takes home.

Sample Input 1      Sample Output 1
3 8                 90
3 30
4 50
5 60
Items 1 and 3 should be taken. Then, the sum of the weights is 3+5=8, and the sum of the values is 30+60=90.

Sample Input 2      Sample Output 2
5 5                 5000000000
1 1000000000
1 1000000000
1 1000000000
1 1000000000
1 1000000000
The answer may not fit into a 32-bit integer type.

Sample Input 3      Sample Output 3
6 15                17
6 5
5 6
6 4
6 6
3 5
7 2
Items 2,4 and 5 should be taken. Then, the sum of the weights is 5+6+3=14, and the sum of the values is 6+6+5=17.

*/

// -------------------------------------------------------------------------------------------------------------------------------------

// Steps:
// 1. Input number of items n and knapsack capacity W.
// 2. Read each item's weight[i] and value[i].
// 3. Initialize a 1D dp array of size W+1 to 0.
// 4. Loop over each item and update dp[w] in reverse to avoid overwrite.
// 5. For each valid weight, update dp[w] = max(dp[w], dp[w-wi] + vi).
// 6. Print dp[W] as the max value possible within capacity W.

// -------------------------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,W; cin >> n >> W;
  vector<int> w(n), v(n);
  for(int i=0; i<n; i++) cin >> w[i] >> v[i];
  
  vector<long long> dp(W+1, 0);
  
  for(int i=0; i<n; i++){
    for(int j=W; j>=w[i]; j--){
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
  }
  
  cout << dp[W] << endl;
  return 0;
}