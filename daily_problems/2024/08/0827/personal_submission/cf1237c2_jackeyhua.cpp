#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> vc(n, vector<int>(4));
    for (int i = 0; i < n; ++i) {
        cin >> vc[i][0] >> vc[i][1] >> vc[i][2];
        vc[i][3] = i + 1;
    }
    std::sort(vc.begin(), vc.end(), [](const vector<int>& x, const vector<int>& y) -> bool {
        if (x[0] > y[0]) return true;
        if (x[0] == y[0] && x[1] > y[1]) return true;
        if (x[0] == y[0] && x[1] == y[1] && x[2] > y[2]) return true;
        return false;
    });

    vector<int> defer;  // 不同x平面上剩余的一个点组成的集合，根据x有序
    int left = 0;
    while (left < n) {
        int cur_x = vc[left][0];
        int lb = left;
        int right = left;
        // 处理同一个x的点
        while (right < n && vc[right][0] == cur_x) ++right;
        int len = right - left;
        if (len == 1) {
            defer.push_back(left);
            left = right;
            continue;
        }
        int p = lb;
        stack<int> stk;
        while (p < right) {
            // 先把有相同y的点给移走
            if (stk.empty() || vc[p][1] != vc[stk.top()][1]) {
                stk.push(p++);
                continue;
            }
            cout << vc[p][3] << " " << vc[stk.top()][3] << endl;
            stk.pop();
            ++p;
        }
        // 移走同x，不同y的点
        while (stk.size() > 1) {
            int t = stk.top();
            stk.pop();
            int tt = stk.top();
            stk.pop();
            cout << vc[t][3] << " " << vc[tt][3] << endl;
        }

        if (!stk.empty()) defer.push_back(stk.top());
        left = right;
    }

    for (int i = 0; i < defer.size(); i += 2) cout << vc[defer[i]][3] << " " << vc[defer[i + 1]][3] << endl;
} 

int main() {
    solve();
    return 0;
}
