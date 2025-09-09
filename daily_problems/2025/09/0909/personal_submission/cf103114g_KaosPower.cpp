#include<bits/stdc++.h>


using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> pos(n + 1);

    for (int i = 0; i < 10; i ++) {
        vector<int> idxs;
        for (int j = 1; j <= n; j ++) {
            if (j >> i & 1) {
                idxs.emplace_back(j);
            }
        }

        if (idxs.size()) {
            cout << idxs.size() << ' ';
            for (auto &idx: idxs) cout << idx << ' ';
            cout << endl;

            vector<int> vals;
            for (int i = 0; i < idxs.size(); i ++) {
                int x;
                cin >> x;
                vals.emplace_back(x);
            }

            for (auto &v: vals) pos[v] |= 1 << i;
        }
    }

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i ++)
        ans[pos[i]] = i;

    cout << "! ";
    for (int i = 1; i <= n; i ++)
        cout << ans[i] << ' ';

    return 0;
}
