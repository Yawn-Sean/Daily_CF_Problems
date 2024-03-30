#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> c(n);
    copy_n(istream_iterator<int>(cin), n, begin(c));
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
        --x;
    }

    vector<int> visited(n, 0);
    auto dfs = [&](int cur) {
        set<int> s{cur};
        visited[cur] = 1;

        while (!visited[a[cur]]) {
            cur = a[cur];
            visited[cur] = 1;
            s.insert(cur);
        }

        if (s.count(a[cur]) == 0) {
            return 0;
        }

        int cur_cycle_min = c[cur];
        int next = a[cur];
        while (next != cur) {
            cur_cycle_min = min(cur_cycle_min, c[next]);
            next = a[next];
        }
        
        return cur_cycle_min;
    };

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ret += dfs(i);
        }
    }

    cout << ret << endl;
    return 0;
}