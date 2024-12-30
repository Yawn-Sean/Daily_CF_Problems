#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;

    vector<vector<int>> mmp(n + 1);
    for (int p = 2; p <= n; p ++) {
        int fa; cin >> fa;
        mmp[fa].push_back(p);
    }

    vector<int> ans(n + 1);
    function<int(int)> df_mark = [&](int p){
        if (mmp[p].size() == 0) {
            return ans[p] = 1;
        }
        int v = 0;
        for (auto nxt : mmp[p]) {
            v += df_mark(nxt);
        }
        return ans[p] = v;
    };
    df_mark(1);

    sort(ans.begin() + 1, ans.end());
    for (int i = 1 ; i <= n; i++) {
        cout << ans[i] << " ";
    }

}

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T{1};
    // cin >> T;
    
    while (T--) {
        solve();
    }

}
