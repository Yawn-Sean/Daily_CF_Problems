#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;

    string s,t;
    cin >> s >> t;
    /*
       考虑同一位置上 s[i]!=t[i] 的情况
       需要"连接"两个字符

       DSU维护连通性
    */
    DSU d(27);
    vector<pair<int,int>> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int from = s[i] - 'a';
            int to = t[i] - 'a';
            if (!d.same(from, to)) {
                d.merge(from, to);
                ans.emplace_back(from, to);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto& [x, y] : ans) {
        cout << (char)(x + 'a') << ' ' << (char)(y + 'a') << '\n';
    }
    return 0;
}
