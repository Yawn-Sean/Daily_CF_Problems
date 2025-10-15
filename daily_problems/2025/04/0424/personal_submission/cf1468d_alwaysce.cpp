#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        vector<int> s(m);
        for (auto&x: s) { cin >> x; }
        sort(s.begin(), s.end());

        // 最多能放多少个
        int maxNum = min(m, abs(b - a) - 1);
        // 能走多少步
        int caughtTime = (a < b ? b - 1 : n - b);
        // cout << maxNum << ' ' << caughtTime << '\n';
        int ans = 0;
        for (int i = maxNum - 1; i >= 0; i--) {
            if (s[i] < caughtTime) {
                ans++;
                caughtTime--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
