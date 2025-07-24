/*
Given an array of n integers, your task is to process q queries of the following types:
    1. update the value at position k to u
    2. what is the sum of values in range [a,b]?

Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x_1,x_2,\dots,x_n: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".

Output
Print the result of each query of type 2.

Constraints
1 ≤ n, q ≤ 10^5
1 ≤ x_i, u ≤ 10^9
1 ≤ k ≤ n
1 ≤ a ≤ b ≤ n

Time limit: 1.00 s
Memory limit: 512 MB

Example
Input:
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4

Output:
14
2
11
*/

// --------------------------------------------------------------------------------------------------------------------------------------

// Steps:
// 1. Read the number of elements `n` and number of queries `q`.
// 2. Read the initial array of integers.
// 3. Initialize a Fenwick Tree (Binary Indexed Tree) to handle range sum queries and point updates.
// 4. For Updating:
//      - Access the current node: Add v to fenwick[idx] to update the current prefix sum position.
//      - Move to next responsible node: Use idx += (idx & -idx) to jump to the next index in the tree that includes idx in its prefix sum.
//      - Repeat until out of bounds: Continue updating while idx is within the Fenwick Tree size to ensure all affected nodes are updated.
// 5. For Prefix Sum Calculation:
//      - Start from index idx: Initialize sum = 0 and begin adding values from fenwick[idx].
//      - Move to parent node: Use idx -= (idx & -idx) to go to the parent index that contributes to the prefix sum.
//      - Repeat until index is 0: Keep moving and adding values until idx becomes 0, then return the accumulated sum.

// --------------------------------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll prefixSum(int idx, vector<ll>& fenwick){
    ll sum = 0;
    while(idx > 0){
        sum += fenwick[idx];
        idx -= (idx & (-idx));
    }
    
    return sum;
}

void update(int idx, ll v, vector<ll>& fenwick){
    int n = fenwick.size();
    while(idx <= n){
        fenwick[idx] += v;
        idx += (idx & (-idx));
    }
}

int main(){
    int n,q; cin >> n >> q;
    vector<ll> arr(n);
    for(auto &i: arr) cin >> i;
    
    vector<ll> fenwick(n+1, 0);
    for(int i=1; i<=n; i++){
        update(i, arr[i-1], fenwick);
    }
    
    for(int i=0; i<q; i++){
        int choice; cin >> choice;
        if(choice == 1){
            int k; cin >> k;
            ll u; cin >> u;
            update(k, u-arr[k-1], fenwick);
            arr[k-1] = u; // Update the original array as well
        }
        else{
            int a,b; cin >> a >> b;
            ll B = prefixSum(b, fenwick);
            ll A = prefixSum(a-1, fenwick);
            cout << B-A << endl;
        }
    }
    
    return 0;
}