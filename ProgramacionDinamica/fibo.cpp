#include <bits/stdc++.h>
using namespace std;

int dp[2005];
int dp2[2005];

int fibo(int n){
    if (n<=1) return n;
    if (dp2[n]>0) return dp2[n];
    dp2[n] = fibo(n-1) + fibo(n-2);
    return dp2[n];
} 

int main(){
    int n; cin >> n;
    for (int i = 0; i <= n; i++)
    {
        dp[2] = -1;
    }
    cout<< "old: " << fibo(n) << endl;
    // TopDown
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<< "old: " << dp[n] << endl;
}