#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<string, vector<int>> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        int v;
        cin >> s >> v;
        mp[s].push_back(v);
    }
    for (auto &p : mp) sort(p.second.begin(), p.second.end(), greater<int>());

    long long base = 0, delta = 0;
    for (auto &p : mp) {
        string x = p.first, y = x;
        reverse(y.begin(), y.end());
        if (x > y) continue;
        if (x == y) {
            int i;
            for (i = 0; i + 1 < p.second.size(); i += 2) {
                int v = p.second[i] + p.second[i + 1];
                if (v > 0) base += v;
                else break;
            }
            if (i > 0) delta = max(delta, -1LL * p.second[i - 1]);
            if (i < p.second.size()) delta = max(delta, 1LL * p.second[i]);
        } else if (mp.count(y)) {
            auto &vec = mp[y];
            for (int i = 0; i < p.second.size() && i < vec.size(); i++) {
                int v = p.second[i] + vec[i];
                if (v > 0) base += v;
                else break;
            }
        }
    }
    cout << base + delta << "\n";
    return 0;
}
