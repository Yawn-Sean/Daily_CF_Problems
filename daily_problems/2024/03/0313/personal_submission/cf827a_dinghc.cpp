#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

int main() {
    int n;
    cin >> n;

    int total_length = 0;
    vector<string> strings;
    map<string, int> indices;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++) {
        string s; int k;
        cin >> s >> k;
        int idx = indices.size();
        auto it = indices.find(s);
        if (it != indices.end()) {
            idx = it->second;
        } else {
            indices[s] = idx;
            strings.push_back(s);
        }
        int sz = s.length();
        for (int i = 0; i < k; i++) {
            int pi;
            cin >> pi; pi--;
            pair<int, int> pp { pi, sz };
            mp[pp] = idx;
            total_length = max(total_length, pi + sz);
        }
    }

    string ans(total_length, 'a');
    int i = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        auto& [pos, idx] = *it;
        string& s = strings[idx];
        int start_pos = max(i, pos.first);
        int end_pos = pos.first + pos.second - 1;
        if (end_pos < i) continue;
        for (int j = end_pos, k = s.length() - 1; j >= start_pos; j--, k--) {
            ans[j] = s[k];
        }
        i = end_pos + 1;
    }

    cout << ans << "\n";
    return 0;
}
