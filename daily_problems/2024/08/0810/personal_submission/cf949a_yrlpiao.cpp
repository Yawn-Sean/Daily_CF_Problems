#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

const int N = 2e5 + 10;

int idx = 0;
string s;
vector<int> ans[N];
stack<int> st[2];

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] & 1) {
            if (st[0].empty()) return cout << -1, 0;
            ans[st[0].top()].push_back(i);
            st[1].push(st[0].top());
            st[0].pop();
        } else {
            if (st[1].size()) {
                ans[st[1].top()].push_back(i);
                st[0].push(st[1].top());
                st[1].pop();
            } else {
                ans[idx].push_back(i);
                st[0].push(idx++);
            }
        }
    }
    if (st[1].size()) return cout << -1, 0;
    cout << idx << endl;
    while (st[0].size()) {
        int x = st[0].top(); st[0].pop();
        cout << ans[x].size() << " ";
        for (int i : ans[x]) cout << i + 1 << " ";
        cout << endl;
    }
    return 0;
}
