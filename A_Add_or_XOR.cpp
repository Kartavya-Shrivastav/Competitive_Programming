/*
A. Add or XOR

You are given two non-negative integers a,b. You can apply two types of operations on a any number of times and in any order: 
a←a+1. The cost of this operation is x;
a←a⊕1, where ⊕ denotes the bitwise XOR operation. The cost of this operation is y.

Now you are asked to make a=b. If it's possible, output the minimum cost; otherwise, report it.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.
The only line of each test case contains four integers a,b,x,y (1≤a,b≤100,1≤x,y≤107) — the two integers given to you and the respective 
costs of two types of operations.

Output
For each test case, output an integer — the minimum cost to make a=b, or −1 if it is impossible.

Example

Input
7
1 4 1 2
1 5 2 1
3 2 2 1
1 3 2 1
2 1 1 2
3 1 1 2
1 100 10000000 10000000

Output
3
6
1
3
-1
-1
990000000

Note
In the first test case, the optimal strategy is to apply a←a+1 three times. The total cost is 1+1+1=3.
In the second test case, the optimal strategy is to apply a←a+1, a←a⊕1, a←a+1, a←a⊕1 in order. The total cost is 2+1+2+1=6.
In the fifth test case, it can be proved that there isn't a way to make a=b.

*/

// -------------------------------------------------------------------------------------------------------------------------------------

// Approach:
    // 1. If a is less than b, we can only increment a to reach b. For that we have two options:
        //    - Increment a by 1 (cost x).
        //    - Increment a by 1 using XOR operation (cost y). This can be done only when a is odd.
        //    - Example - 5⊕1 = 4 but 4⊕1 = 5, i.e. XOR increases the value by 1 only when the number is even and decreases it when odd.
    // 2. If a is greater than b, then we have to decrement it to reach b.
        //    - We can do that only when a is odd and a is just one more than b (i.e., a = b + 1). In this case, we can use the XOR operation 
        //      to decrement a by 1 (cost y).
        //    - If a is greater than b + 1, it is impossible to make a equal to b using the given operations, since we can only decrement a
        //      by using XOR  operation which only works for odd a. If a is decremented, it will become even and on further XOR operation,
        //      it will increase the value instead of decreasing it.

// Steps:
    // 1. Read the number of test cases.
    // 2. For each test case, read the values of a, b, x, and y.
    // 3. Check the conditions based on the values of a and b:
        //    - If a <= b, calculate the cost to increment a to b using the minimum cost operation.
        //    - If a == b+1 && a is odd, only XOR operation can be used to make a equal to b, so return the cost y.
        //    - If a > b + 1, return -1 as it is impossible to make a equal to b.
    // 4. Print the result for each test case.

// -------------------------------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc; cin >> tc;
    while(tc--){
        int a,b,x,y; cin >> a >> b >> x >> y;
        int cost = 0;
        if(a <= b){
            while(a != b){
                if (a%2==0) cost += min(x,y);
                else cost += x;
                a++;
            }
        }
        else if(a%2==1 && b+1==a)
            cout << y;
        else
            return -1;
    }
    

    return 0;
}