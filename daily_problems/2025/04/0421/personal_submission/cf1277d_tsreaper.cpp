#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    
    vector<string> s(n + 1);
    vector<int> vec[2];
    int flag = 0;
    unordered_set<string> st;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (s[i][0] != s[i].back()) {
            vec[s[i][0] - '0'].push_back(i);
            st.insert(s[i]);
        } else {
            flag |= 1 << (s[i][0] - '0');
        }
    }

    if (flag == 3 && vec[0].empty() && vec[1].empty()) { cout << "-1\n"; return; }

    vector<int> ans;
    int det = (int) vec[0].size() - (int) vec[1].size();
    for (int i = 0; i < vec[0].size() && det > 1; i++) {
        string r = s[vec[0][i]];
        reverse(r.begin(), r.end());
        if (st.count(r) == 0) { ans.push_back(vec[0][i]); det -= 2; }
    }
    for (int i = 0; i < vec[1].size() && det < -1; i++) {
        string r = s[vec[1][i]];
        reverse(r.begin(), r.end());
        if (st.count(r) == 0) { ans.push_back(vec[1][i]); det += 2; }
    }
    if (det >= -1 && det <= 1) {
        cout << ans.size() << "\n";
        for (int x : ans) cout << x << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tcase; cin >> tcase;
    while (tcase--) solve();
    return 0;
}
