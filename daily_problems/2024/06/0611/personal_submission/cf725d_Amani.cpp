#include <bits/stdc++.h>
#define int long long
using namespace std;

int Rank(int n, int x, vector<pair<int, int>>& b_w) {
    int left = 0, right = n - 2;
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
    sort(b_w.begin(), b_w.end(), [&](pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    });
    int ans = Rank(n, ball_1, b_w);
    int pre = ans;  // 记录上一次的排名
    int cnt = 0;
    for (int i = 0; i < pre; ++i) {  // 可能要贿赂的队伍入队
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
        int cur = Rank(n, ball_1, b_w);  // ball_1减少后，新的排名
        for (int i = pre; i < cur; ++i) {  // 加入超过的队伍
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
    vector<pair<int, int>> b_w(n-1);
    int ball_1, weight_1;
    cin >> ball_1 >> weight_1;
    for (int i = 0; i < n-1; ++i) {
        cin >> b_w[i].first >> b_w[i].second;
        b_w[i].second -= b_w[i].first - 1;  // 修正 weights，当 weights = 0 时，直接漂浮
    }
    cout << Solve(n, b_w, ball_1) + 1 << endl;  // 排名偏差 +1
    return 0;
}
