#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> PII;
typedef long long LL;
const int mod = 998244353;
const int N = 2e5 + 1, M = 350;

struct node {
    int v, d, p;
};
void solve() {
    int n;
    cin >> n;
    std::vector<node> ve(n);
    vector<bool>vis(n,0);
    for (int i = 0; i < n; i++) {
        int v, d, q;
        cin >> v >> d >> q;
        ve[i] = {v, d, q};
    }
    vector<int>ans;
    for (int i = 0; i < n; i++) {
        auto &[x, y, z] = ve[i];
        queue<int>q;
        if(vis[i])continue;
        if (z >= 0) {
            int cnt = -x;
            for (int j = i + 1; j < n; j++) {
                auto &[x, y, z] = ve[j];
                int t=z;
                z += cnt;
                if (z < 0 && vis[j]==false) {
                    q.push(j);
                    vis[j] = true;
                }
                if(t>=0)
                cnt++;
                if (cnt == 0)break;
            }
            vis[i]=true;
            ans.push_back(i);
        }
        while (!q.empty()) {
            int xx = q.front();
            q.pop();
            auto &[a, b, c] = ve[xx];
            int cnt = -b;
            for (int j = xx+1; j < n; j++) {
                auto &[x, y, z] = ve[j];
                z += cnt;
                if (z < 0 && vis[j] == false) {
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }


    cout << ans.size() << endl;
    for (auto v : ans) {
        cout << v + 1 << ' ';
    } cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // init();
    int t = 1;
    //cin >> t;
    while (t--)solve();
    return 0;
}
