#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<int> cnt(n + 1, 0), mx(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        ++cnt[u];
        mx[u] = 1;
        if (v != n) {
            cout << "NO\n";
            return 0;
        }
    }

    vector<int> chain;
    int cur = 1;
    for (int i = 1; i < n; i++) {
        if (cnt[i] > 0) {
            --cnt[i];
            chain.push_back(i);
            while (cnt[i] > 0) {
                while (mx[cur] == 1) { cur++;}
                if (cur > i) {
                    cout << "NO\n";
                    return 0;
                }
                chain.push_back(cur);
                ++cur;
                --cnt[i];
            }
        }
    }

    chain.push_back(n);
    cout << "YES\n";
    for (int i = 1; i < n; i++) {
        cout << chain[i - 1] << " " << chain[i] << "\n";
    }

    return 0;
}
