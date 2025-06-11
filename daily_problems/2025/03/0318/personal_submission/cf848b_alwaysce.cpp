#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    int n, w, h;
    cin >> n >> w >> h;

    vector<int> group(n), p(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> group[i] >> p[i] >> t[i];
    }

    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[p[i] - t[i]].push_back(i);
    }
    vector<pair<int,int>> ans(n);

    for (auto& [k, v]: mp) {
        vector<int> v1, v2;
        for (auto&i: v) {
            if (group[i] == 1) {
                v1.emplace_back(i);
            } else {
                v2.emplace_back(i);
            }
        }        
        sort(v1.begin(), v1.end(), [&] (int a, int b) {
            return p[a] < p[b];
        });
        sort(v2.begin(), v2.end(), [&] (int a, int b) {
            return p[a] > p[b];
        });

        for (int i = 0; i < v.size(); i++) {
            int start = (i < v2.size() ? v2[i]: v1[i - v2.size()]);
            int end = (i < v1.size() ? v1[i]: v2[i - v1.size()]);

            ans[start] = (group[end] == 1 ? make_pair(p[end], h) : make_pair(w, p[end]));
        }
    }

    for (auto& [x, y]: ans) {
        cout << x << " " << y << endl;
    }
    return 0;
}
