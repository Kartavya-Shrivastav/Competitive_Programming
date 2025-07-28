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