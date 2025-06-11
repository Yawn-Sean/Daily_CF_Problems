#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void pos_swap(vector<int>& perm, vector<int>& pos, vector<pair<int, int>>& ans, int u, int v) {
    swap(pos[perm[u]], pos[perm[v]]);
    swap(perm[u], perm[v]);
    ans.emplace_back(u, v);
}

vector<pair<int, int>> solve(int n, vector<int>& perm) {
    vector<int> pos(n + 1);
    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; ++i) {
        pos[perm[i]] = i;
    }
    for (int i = 1; i <= n / 2; ++i) {
        if (pos[i] != i) {
            if (pos[i] <= n / 2) {
                pos_swap(perm, pos, ans, pos[i], n);
                pos_swap(perm, pos, ans, i, n);
            } else {
                pos_swap(perm, pos, ans, 1, pos[i]);
                pos_swap(perm, pos, ans, 1, n);
                pos_swap(perm, pos, ans, i, n);
            }
        }
    }
    for (int i = n / 2 + 1; i <= n; ++i) {
        if (pos[i] != i) {
            if (pos[i] >= n / 2 + 1) {
                pos_swap(perm, pos, ans, 1, pos[i]);
                pos_swap(perm, pos, ans, 1, i);
            } else {
                pos_swap(perm, pos, ans, pos[i], n);
                pos_swap(perm, pos, ans, 1, n);
                pos_swap(perm, pos, ans, 1, i);
            }
        }
    }
    if (perm[1] != 1) {
        pos_swap(perm, pos, ans, 1, n);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> perm(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> perm[i];
    }
    auto ans = solve(n, perm);
    cout << ans.size() << endl;
    for (const auto& p : ans) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
