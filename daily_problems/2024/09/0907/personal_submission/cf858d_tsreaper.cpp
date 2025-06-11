#include <bits/stdc++.h>
using namespace std;

unordered_set<string> gao(string &s, int len) {
    unordered_set<string> st;
    for (int i = 0; i + len <= s.size(); i++) st.insert(s.substr(i, len));
    return st;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<string> vec;
    unordered_map<string, int> mp[10];
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int len = 1; len <= 9; len++) {
            auto st = gao(s, len);
            for (auto &tmp : st) mp[len][tmp]++;
        }
        vec.push_back(s);
    }
    for (auto &s : vec) {
        auto check = [&]() {
            for (int len = 1; len <= 9; len++) {
                auto st = gao(s, len);
                for (auto &tmp : st) if (mp[len][tmp] == 1) {
                    cout << tmp << "\n";
                    return;
                }
            }
        };
        check();
    }
    return 0;
}
