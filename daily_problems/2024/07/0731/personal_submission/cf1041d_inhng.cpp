#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, h, rear = 0, front = 0, ans = 0, cnt = 0;
    cin >> n >> h;
    vector<int> left(n), right(n);
    for (int i = 0; i < n; ++i) {
        cin >> left[i] >> right[i];
    }
    int fly = h;
    while (rear < n) {
        while (front < n - 1 and left[front + 1] - right[front] < fly) {
            cnt += right[front] - left[front];
            fly -= left[front + 1] - right[front];
            ++front;
        }
        ans = max(ans, cnt + right[front] - left[front] + h);
        cnt -= right[rear] - left[rear];
        if (++rear < n) {
            fly += left[rear] - right[rear - 1];
        }
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
