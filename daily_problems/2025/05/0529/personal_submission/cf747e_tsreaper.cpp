#include <bits/stdc++.h>
using namespace std;

vector<string> vec;
vector<vector<string>> ans;

vector<string> split(string s, string delim) {
    int now = 0;
    vector<string> ret;
    while (true) {
        auto pos = s.find(delim, now);
        if (pos == string::npos) break;
        ret.push_back(s.substr(now, pos - now));
        now = pos + delim.size();
    }
    ret.push_back(s.substr(now));
    return ret;
}

void dfs(int d) {
    string tmp = vec.back(); vec.pop_back();
    if (ans.size() < d) ans.push_back({});
    ans[d - 1].push_back(tmp);
    int x = stoi(vec.back()); vec.pop_back();
    while (x--) dfs(d + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    vec = split(s, ",");
    reverse(vec.begin(), vec.end());
    while (!vec.empty()) dfs(1);
    
    cout << ans.size() << "\n";
    for (auto &layer : ans) {
        for (int i = 0; i < layer.size(); i++) {
            cout << layer[i];
            if (i + 1 == layer.size()) cout << "\n";
            else cout << " ";
        }
    }
    return 0;
}
