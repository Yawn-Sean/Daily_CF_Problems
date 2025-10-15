#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<string, int> > ops;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op != "removeMin") {
            int num;
            cin >> num;
            ops.emplace_back(op, num);
        } else {
            ops.emplace_back(op, 0);
        }
    }

  
    vector<pair<string, int> > ans;
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < n; i++) {
        string op = ops[i].first;
        int num = ops[i].second;
        if (op == "insert") {
            pq.push(num);
            ans.emplace_back("insert", num);
        } else if (op == "removeMin") {
            if (pq.empty()) {
                ans.emplace_back("insert", 114514);
            } else {
                pq.pop();
            }
            ans.emplace_back("removeMin", 0);
        } else {
            while (!pq.empty() && pq.top() < num) {
                ans.emplace_back("removeMin", 0);
                pq.pop();
            }
            if (pq.empty() || pq.top() > num) {
                ans.emplace_back("insert", num);
                pq.push(num);
            }
            ans.emplace_back("getMin", num);
        }
    }

    cout << ans.size() << endl;
    for (auto& [op, num] : ans) {
        cout << op << " ";
        if (op != "removeMin") {
            cout << num << endl;
        } else {
            cout << endl;
        }
    }
    return 0;
}
