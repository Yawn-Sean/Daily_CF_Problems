#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, a, b;
    cin >> m >> a >> b;
    vector<int> mxp(a + b, -1);
    queue<int> q;
    q.push(0);
    mxp[0] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x + a < a + b && mxp[x + a] == -1) {
            mxp[x + a] = max(x + a, mxp[x]);
            q.push(x + a);
        }
        if (x - b >= 0 && mxp[x - b] == -1) {
            mxp[x - b] = mxp[x];
            q.push(x - b);
        }
    }
    long long ans = 0;
    for (int i = 0; i < a + b; i++) {
        if (mxp[i] >= 0 && mxp[i] <= m) ans += m + 1 - mxp[i];
    }
    if (m >= a + b) {
        for (int i = 0; i < a; i++) {
            if (mxp[i] < 0) continue;
            int start = m / a * a + i;
            while (start > m) start -= a;
            int end = (a + b) / a * a + i;
            while (end < a + b) end += a;
            start = m + 1 - start, end = m + 1 - end;
            ans += 1LL * (start + end) * (end - start + a) / 2 / a;
        }
    }
    cout << ans << endl;

    return 0;
}
