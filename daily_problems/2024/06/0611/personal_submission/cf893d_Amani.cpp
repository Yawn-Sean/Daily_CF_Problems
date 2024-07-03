#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &trade, int limit) {
    int ans = 0, lb = 0, ub = 0;
    for (int elmt : trade) {
        if (!elmt) {  // 检查
            if (ub < 0) {
                ans++;
                ub = limit;
            }
            lb = max(lb, 0);
        } else {
            lb += elmt;
            ub += elmt;
            if (lb > limit) {  // 若不存钱时都会超过限制，则只能输出-1
                ans = -1;
                break;
            }
            ub = min(ub, limit);
        }
    }
    return ans;
}

signed main() {
    int n, limit;
    cin >> n >> limit;
    vector<int> trade(n);
    for (int i = 0; i < n; i++) {
        cin >> trade[i];
    }
    cout << solve(trade, limit) << endl;
    return 0;
}
