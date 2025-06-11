#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<ll> ans;
    function<void(int, ll)> dfs = [&](int len, ll mi) {
        if (len == 0)
            return;
        else if (len == 3) {
            ans.emplace_back(mi);
            ans.emplace_back(mi);
            ans.emplace_back(mi * 3);
        } else if (len == 2) {
            ans.emplace_back(mi);
            ans.emplace_back(mi * 2);
        } else if (len == 1) {
            ans.emplace_back(mi);
        } else {
            for (int i = 0; i < (len + 1) / 2; i++)
                ans.emplace_back(mi);
            dfs(len / 2, mi * 2);
        }
    };
    dfs(n, 1);
    for (auto x : ans)
        cout << x << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}