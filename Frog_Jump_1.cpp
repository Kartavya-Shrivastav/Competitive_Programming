

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