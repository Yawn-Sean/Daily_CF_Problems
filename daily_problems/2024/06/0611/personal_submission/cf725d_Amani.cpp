#include <bits/stdc++.h>
#define int long long
using namespace std;

int Rank(int n, int x, vector<pair<int, int>>& b_w) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (b_w[mid].first > x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int Solve(int n, vector<pair<int, int>>& b_w, int ball_1) {
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(b_w.begin()+1, b_w.end(), [&](pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    });
    int ans = Rank(n, ball_1, b_w);
    int pre = ans;  // 记录上一次的排名
    int cnt = 0;
    for (int i = 1; i < pre; ++i) {  // 可能要贿赂的队伍入队
        pq.push(b_w[i].second);
    }
    while (!pq.empty()) {
        int w = pq.top();
        if (w > ball_1) {
            break;
        }
        pq.pop();
        cnt++;
        ball_1 -= w;
        int cur = Rank(n, ball_1, b_w);
        for (int i = pre; i < cur; ++i) {
            pq.push(b_w[i].second);
        }
        pre = cur;
        ans = min(ans, cur - cnt);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> b_w(n);
    int ball_1, weight_1;
    cin >> ball_1 >> weight_1;
    b_w[0] = {ball_1, weight_1};
    for (int i = 1; i < n; ++i) {
        cin >> b_w[i].first >> b_w[i].second;
        b_w[i].second -= b_w[i].first - 1;  // 修正 weights，当 weights = 0 时，直接漂浮
    }
    cout << max(1LL, Solve(n, b_w, ball_1)) << endl;
    return 0;
}
