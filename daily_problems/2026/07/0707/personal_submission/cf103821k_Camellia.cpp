#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int MOD = 1e9 + 7;
void fujikaze(){
    i64 n, m;
    cin >> n >> m;
    vector<i64> v1(m + 1), v2(m + 1);
    for(i64 i = 0; i < n; i++){
        i64 l, r;
        cin >> l >> r;
        v1[l] = (v1[l] + m - r + 1) % MOD;
        v2[r] = (v2[r] + l) % MOD;
    }
    i64 ans = 0, suffix = 0;
    for(i64 i = m; i >= 1; i--){
        ans = (ans + 1LL * suffix * v2[i]) % MOD;
        suffix = (suffix + v1[i]) % MOD;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        fujikaze();
    }
    return 0;
}

