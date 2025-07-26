/*
C - Vacations

Problem Statement
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.
The vacation consists of N days. For each i (1≤i≤N), Taro will choose one of the following activities and do it on the i-th day:

    - A: Swim in the sea. Gain ai points of happiness.
    - B: Catch bugs in the mountains. Gain bi points of happiness.
    - C: Do homework at home. Gain ci points of happiness.

As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.
Find the maximum possible total points of happiness that Taro gains.

Constraints
All values in input are integers.
1≤ N ≤ 10^5
1≤ ai,bi,ci ≤ 10^4
Time Limit: 2 sec / Memory Limit: 1024 MiB

Input
Input is given from Standard Input in the following format:
N
a1 b1 c1
​a2 b2 c2
.
.
an bn cn

Output
Print the maximum possible total points of happiness that Taro gains.

Sample Input 1      Sample Input 1
3                   210
10 40 70
20 50 80
30 60 90
If Taro does activities in the order C, B, C, he will gain 70+50+90 = 210 points of happiness.

Sample Input 2      Sample Input 2
1                   100          
100 10 1

Sample Input 3      Sample Input 3
7                   46
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1
If Taro does activities in the order C, A, B, A, C, B, A he will gain 8+8+5+7+8+3+7 = 46 points of happiness.

*/

// ------------------------------------------------------------------------------------------------------------------------------------------

// Steps:
// 1. Read number of days N and initialize dp[n][3] for tracking max happiness per activity per day.
// 2. Set base case dp[0][0] = a0, dp[0][1] = b0, dp[0][2] = c0 from day 1's input.
// 3. For each day i from 1 to n-1, read a, b, c and compute:
//          dp[i][0] = a + max(dp[i-1][1], dp[i-1][2])
//          dp[i][1] = b + max(dp[i-1][0], dp[i-1][2])
//          dp[i][2] = c + max(dp[i-1][0], dp[i-1][1])
// 4. This ensures no activity is repeated on consecutive days.
// 5. After the loop, final answer is max(dp[n-1][0], dp[n-1][1], dp[n-1][2]).
// 6. Print the result as the maximum happiness achievable.

// ------------------------------------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<vector<int>> dp(n, vector<int>(3));
    
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
    
    for(int i=1; i<n; i++){
        int a,b,c; cin >> a >> b >> c;
        
        dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]);     // If we do activity A today, we can't do A yesterday
        dp[i][1] = b + max(dp[i-1][0], dp[i-1][2]);     // If we do activity B today, we can't do B yesterday
        dp[i][2] = c + max(dp[i-1][0], dp[i-1][1]);     // If we do activity C today, we can't do C yesterday
    }
    
    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << endl;
    return 0;
}