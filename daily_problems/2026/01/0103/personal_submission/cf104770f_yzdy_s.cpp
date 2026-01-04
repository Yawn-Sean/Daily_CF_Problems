#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define PPI pair<PII, int>

const int maxN = 2e5 + 7;

struct p {
    int num;
    int lc, rc;
}tree[4 * maxN];


vector<int> ans;
void dfs(int x) {
    if (!tree[x].lc) {
        ans.push_back(tree[x].num);
        return;
    }
    // cout << tree[x].num << endl;
    dfs(tree[x].lc);
    dfs(tree[x].rc);
}

void solve(){
    int n;cin >> n;
    if (n == 1) {
        int x;cin >> x;
        cout << x << endl;
        return;
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        mp[x]++;
    }
    int k = 0;
    while (n > (1LL << k)) k++;
    if (mp.size() != (1 << (k - 1))) {
        cout << -1 << endl;
        return;
    }
    

    map<int, int> idx;
    int pos = 1;
    for (int i = k; i > 1; i--) {
        vector<int> one;
        vector<int> oth;
        for (auto &[x, cnt] : mp) {
            if (cnt == 0) continue;
            if (cnt == 1) one.push_back(x);
            else oth.push_back(x);
            cnt--;
        }
        if (one.size() != oth.size() || one.size() != (1LL << (i - 2))) {
            cout << -1 << endl;
            return;
        }

        for (int i = 0; i < one.size(); i++) {
            if (oth[i] >= one[i]) {
                cout << -1 << endl;
                return;
            }
            int mn = oth[i], mx = one[i];
            if (idx[mn] == 0) {
                idx[mn] = pos;
                tree[pos].num = mn;
                pos++;
            }
            if (idx[mx] == 0) {
                idx[mx] = pos;
                tree[pos].num = mx;
                pos++;
            }
            tree[pos].num = mn;
            tree[pos].lc = idx[mn];
            tree[pos].rc = idx[mx];
            idx[mn] = pos;
            pos++;
        }
    }
    // cout << tree[pos-1].num << endl;
    dfs(pos - 1);
    for (auto &i : ans) cout << i << ' ';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}