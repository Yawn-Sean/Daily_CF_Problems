#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<string> ans;
    for (int i = 1; i <= n; i++) {
        string op; cin >> op;
        if (op == "insert") {
            int x; cin >> x;
            pq.push(x);
            ans.push_back("insert " + to_string(x));
        } else if (op == "getMin") {
            int x; cin >> x;
            while (!pq.empty() && pq.top() < x) {
                pq.pop();
                ans.push_back("removeMin");
            }
            if (pq.empty() || pq.top() > x) {
                pq.push(x);
                ans.push_back("insert " + to_string(x));
            }
            ans.push_back("getMin " + to_string(x));
        } else {
            if (pq.empty()) {
                pq.push(1);
                ans.push_back("insert 1");
            }
            pq.pop();
            ans.push_back("removeMin");
        }
    }

    cout << ans.size() << "\n";
    for (auto &s : ans) cout << s << "\n";
    return 0;
}
