#include  <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e18, mod = 998244353, N = 100060;
struct seg {
    int l = INF, r = -INF, sz = 0;
};
void solve(){
    int n, q;
    cin >> n >> q;
    vector <seg> segs(q+1);
    vector <int> d(n+2), b(n+2);
    for (int i = 1; i <= q; ++ i){
        cin >> segs[i].l >> segs[i].r;
        ++ d[segs[i].l], -- d[segs[i].r+1];
    }
    for (int i = 1; i <= n; ++ i) d[i] += d[i-1];

    int res = 0;
    for (int i = 1; i <= q; ++ i){
        int l1 = segs[i].l, r1 = segs[i].r;
        for (int j = l1; j <= r1; ++ j) -- d[j];
        int cnt = 0;  //再删去某个区间只与出现次数为1的区间有关
        for (int j = 1; j <= n; ++ j){
            b[j] = b[j-1];
            if (d[j] >= 1) ++ cnt;
            if (d[j] == 1) b[j] += 1;  //统计出现次数为1有多少个
        }
        for (int j = 1; j < i; ++ j)
            res = max(res, cnt-b[segs[j].r] + b[segs[j].l-1]);
        for (int j = l1; j <= r1; ++ j) ++ d[j];
    }
    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
