/*
    ੴ ਸਤਿ ਨਾਮੁ ਕਰਤਾ ਪੁਰਖੁ ਨਿਰਭਉ ਨਿਰਵੈਰੁ ਅਕਾਲ ਮੂਰਤਿ ਅਜੂਨੀ ਸੈਭੰ ਗੁਰ ਪ੍ਰਸਾਦਿ
*/
#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <cmath>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define int long long
using namespace std;
using ll=long long;
using lld = long double;
#define mod 10000000007
#define INF 1e18
#define pi 3.141592653589793238462
#define pb push_back
#define ppb pop_back
#define mp make_pair

void solve(){
    long long n;
    int q;
    cin >> n >> q;

    while (q--) {
        int u;
        string s;
        cin >> u >> s;
        for (char c : s) {
            int x = u & -u;
            if (c == 'L') {
                if (x > 1) {
                    u -= x / 2;
                }
            } else if (c == 'R') {
                if (x > 1) {
                    u += x / 2;
                }
            } else if (x * 2 < n) {
                u -= x;
                u |= x * 2;
            }
        }
        cout << u << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc=1;
    // cin>>tc;
    while(tc--)
    {
    solve();
    }
    return 0;
}