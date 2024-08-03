#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    copy_n(istream_iterator<int>(cin), n, next(begin(a)));
    vector<vector<pair<int, int>>> tree(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p, w;
        cin >> p >> w;
        tree[i].emplace_back(p, w);
        tree[p].emplace_back(i, w);
    }

    int k = __lg(n + 1);
    vector<vector<int>> st(n + 1, vector<int>(k + 1, 0));
    vector<long long> dist(n + 1, 0);
    vector<long long> diff(n + 1, 0);

    auto build = [&](auto self, int x, int parent, int level) -> void {
        st[x][0] = parent;
        for (int i = 1; i <= k; ++i) {
            st[x][i] = st[st[x][i - 1]][i - 1];
        }

        int target = x;
        for (int i = k; i >= 0; --i) {
            if (st[target][i] && dist[x] - dist[st[target][i]] <= a[x]) {
                target = st[target][i];
            }
        }

        diff[st[x][0]]++;
        diff[st[target][0]]--;

        for (auto[y, w] : tree[x]) {
            if (y == parent) {
                continue; 
            }
            dist[y] = dist[x] + w;
            self(self, y, x, level + 1);
        }
    };
    build(build, 1, 0, 0);

    vector<long long> ret(n + 1);
    auto count = [&](auto self, int x, int parent) -> long long {
        ret[x] = diff[x];
        for (auto[y, _] : tree[x]) {
            if (y == parent) {
                continue;
            }
            ret[x] += self(self, y, x);
        }
        return ret[x];
    };
    count(count, 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cout << ret[i] << " \n"[i == n];
    }

    return 0;
}