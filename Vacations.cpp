
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