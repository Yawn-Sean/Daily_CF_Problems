#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define endl "\n"

const int N = 1e6 + 5;
int n;
vector<ll> x(N, 0), y(N, 0);
vector<vector<pll>> x1(N), y1(N);
ll ans = 0;

void dfs (int pos, int type, ll sum) {
    if (pos == 4) {
        ans = max(ans, sum);
        return;
    }

    int xm = -1, ym = - 1;
    if (type == 1) {
        ll maxn = 0;
        for (int i = 0; i < x.size(); i++) {
            if (x[i] > maxn) {
                maxn = x[i];
                ym = -1;
                xm = i;
            }
        }

        sum += maxn;
        if (xm != -1) {
            for (int i = 0; i < x1[xm].size(); i++) {
                auto [yx, v] = x1[xm][i];
                y[yx] -= v;
                x[xm] -= v;
            }
        }

        dfs(pos + 1, 0, sum);
        dfs(pos + 1, 1, sum);

        if (xm != -1) {
            for (int i = 0; i < x1[xm].size(); i++) {
                auto [yx, v] = x1[xm][i];
                y[yx] += v;
                x[xm] += v;
            }
        }
    }
    else {
        ll maxn = 0;
        for (int i = 0; i < y.size(); i++) {
            if (y[i] > maxn) {
                maxn = y[i];
                xm = -1;
                ym = i;
            }
        }

        sum += maxn;
        if (ym != -1) {
            for (int i = 0; i < y1[ym].size(); i++) {
                auto [xy, v] = y1[ym][i];
                x[xy] -= v;
                y[ym] -= v;
            }
        }

        dfs(pos + 1, 0, sum);
        dfs(pos + 1, 1, sum);

        if (ym != -1) {
            for (int i = 0; i < y1[ym].size(); i++) {
                auto [xy, v] = y1[ym][i];
                x[xy] += v;
                y[ym] += v;
            }
        }
    }
}

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, v;
        cin >> a >> b >> v;
        x[a] += v;
        y[b] += v;
        x1[a].push_back({b,v});
        y1[b].push_back({a,v});
    }
    dfs(1, 0, 0);
    dfs(1, 1, 0);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
