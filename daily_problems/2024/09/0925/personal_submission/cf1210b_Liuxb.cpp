#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 7010;
map<i64, int> mp;
i64 _, n, m, k, x, y, ans, res;
i64 v[N], w[N];
bool ex[N];
void init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; ++ i) cin >> v[i], mp[v[i]] ++ ;
    for(int i = 1; i <= n; ++ i) cin >> w[i];
}

void solve() {
    for(auto &[k, t] :mp) {
        if(t > 1) {
            for(int i = 1; i <= n ; ++ i) {
                if(ex[i] == 0 && (v[i] & k) == v[i])
                {
                    ex[i] = 1;
                    ans += w[i];
                }
            }
        }
    }
    return ;
}

int main() {
    init();
    solve();
    cout << ans << "\n";
    return 0;
}
