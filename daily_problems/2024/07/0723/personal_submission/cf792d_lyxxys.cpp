#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 4e5+10, mod = 1e9 + 7, inf = 1e9;
/*
    'L'最右边的1右移一位，无法右移忽略
    'R'最右边的1右边的0变成1，无法变则忽略
    'U': 如果是左儿子，最右边的1右移一位；如果是右儿子，最右边的1变成0
*/
void solve(){
    ll n, q;
    cin >> n >> q;

    ll up = n+1 >> 1;
    while (q--){
        string s;
        ll u;
        cin >> u >> s;
        for (auto &to : s){
            if (to=='U'){
                if (u != up){
                    int cnt = __builtin_ctzll(u);
                    if (u>>cnt & 1) u -= 1ll << cnt;
                    if (!(u>>cnt+1 & 1)) u += 1ll << cnt+1;
                }
            } else if (to=='L'){
                if (u%2==0){
                    int cnt = __builtin_ctzll(u);
                    u -= 1ll << cnt;
                    u += 1ll << cnt-1;
                }
            } else if (u%2==0){
                int cnt = __builtin_ctzll(u);
                u += 1ll << cnt-1;
            }
        }
        cout << u << "\n";
    }
}
