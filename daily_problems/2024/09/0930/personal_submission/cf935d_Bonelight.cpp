/*
    Bonelight * v *
    20240930：放假的前一天，欧耶
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    const int mo = 1e9 + 7;
    int n,m; cin >> n >> m;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> b[i];

#pragma region 
    auto M = [&](int x){return (x % mo + mo) % mo;};
    auto qpow = [&](int x, int y){
        int res = 1; 
        while(y > 0){
            if(y & 1) res = res * x % mo;
            x = x * x % mo;
            y >>= 1;
        }
        return res;
    };
    auto inv = [&](int x){return qpow(x, mo - 2);};
#pragma endregion
    int ans = 0, prob = 1; // 总概率 & 前缀概率
    int inv2 = inv(2), invm = inv(m);
    for(int i = 0; i < n; i ++){
        // 枚举 4 种 情况
        if(a[i] && b[i]){
            if(a[i] == b[i]) continue;
            if(a[i] > b[i]) ans += prob, ans %= mo;
            break;
        } else if (a[i] && !b[i]) {
            prob = M(prob * invm);
            ans += M(prob * (a[i] - 1)); 
            ans %= mo;
        } else if (!a[i] && b[i]) {
            prob = M(prob * invm);
            ans += M(prob * (m - b[i])); 
            ans %= mo;
        } else if(!a[i] && !b[i]) {
            prob = M(prob * invm);
            ans += M(prob * (m - 1)) * inv2; 
            ans %= mo;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
