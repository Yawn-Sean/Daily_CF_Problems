/*
    ੴ ਸਤਿ ਨਾਮੁ ਕਰਤਾ ਪੁਰਖੁ ਨਿਰਭਉ ਨਿਰਵੈਰੁ ਅਕਾਲ ਮੂਰਤਿ ਅਜੂਨੀ ਸੈਭੰ ਗੁਰ ਪ੍ਰਸਾਦਿ
*/
// #include <iostream>
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define int long long
using namespace std;
// using ll=long long;
// using lld = long double;
#define mod 1000000007
// #define INF 1e18
// #define pi 3.141592653589793238462
// #define pb push_back
// #define ppb pop_back
// #define mp make_pair

void solve(){
    int a , b;
    cin>>a>>b;
    // Step 1: Calculate (b * (b - 1) / 2) % mod
    long long b_part = (1LL * b * (b - 1) / 2) % mod;
    
    // Step 2: Calculate (a * (a + 1) / 2) % mod
    long long a_part = (1LL * a * (a + 1) / 2) % mod;
    
    // Step 3: Calculate (a_part * b) % mod
    long long inner_term = (a_part * b) % mod;
    
    // Step 4: Calculate (inner_term + a) % mod
    long long full_inner_term = (inner_term + a) % mod;
    
    // Step 5: Calculate (b_part * full_inner_term) % mod
    long long result = (b_part * full_inner_term) % mod;
    cout << result << endl;
}

signed main()
{
    FAST_IO;
    int tc=1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}