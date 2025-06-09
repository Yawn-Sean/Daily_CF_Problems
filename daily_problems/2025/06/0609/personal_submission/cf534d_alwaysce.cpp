#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;
i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> pos(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }

    vector<int> ans;
    int rank = 0;
    int g = 0;
    while (true) {
        bool oped = false;
        while (g <= n && pos[g].size() > 0) {
            ans.push_back(pos[g].back());
            pos[g].pop_back();
            
            rank++;
            g += 1;
            oped = true;
        }
        
        while (g - 3 >= 0 && pos[g - 3].size() == 0) {
            g -= 3;
        }

        if (g - 3 >= 0 && pos[g - 3].size() > 0) {
            ans.push_back(pos[g - 3].back());
            pos[g - 3].pop_back();
            rank++;
            g -= 2;
            oped = true;
        }
        if (!oped) break;
    }

    cout << (rank == n ? "Possible" : "Impossible") << endl;
    if (rank == n) {
        for (int i = 0; i < n; ++i) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
