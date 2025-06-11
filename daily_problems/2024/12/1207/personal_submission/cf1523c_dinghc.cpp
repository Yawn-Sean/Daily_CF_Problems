#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> ans;
        stack<pair<int, string>> stk;
        stk.emplace(0, "");
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            if (x == 1) {
                auto [_, curr] = stk.top();
                curr += "." + to_string(x);
                stk.emplace(x, curr);
                ans.push_back(curr.substr(1));
            } else {
                while (stk.top().first != x - 1) {
                    stk.pop();
                }
                auto [_, curr] = stk.top(); stk.pop();
                int last_pos = curr.rfind(".");
                curr = curr.substr(0, last_pos);
                curr += "." + to_string(x);
                stk.emplace(x, curr);
                ans.push_back(curr.substr(1));
            }
        }
        for (auto& item : ans) {
            cout << item << "\n";
        }
    }
    return 0;
}

