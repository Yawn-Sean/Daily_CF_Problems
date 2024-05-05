#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int a[N], b[N];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int left = 0, right = m;
    while (left < right) {
        int mid = (right + left) / 2;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            // 当前的范围为[a[i], a[i] + mid]如果a[i] + mid >= m，则一分为两个范围即
            // [a[i], m-1]和[0, (a[i]+mid)%m]
            int diff = m - a[i];
            if (b[i - 1] > a[i] + mid) {
                flag = false;
                break;
            }
            b[i] = max(b[i - 1], a[i]);
            if (mid >= diff) {
                if ((a[i] + mid) % m >= b[i - 1])
                    b[i] = b[i - 1];
            }
        }
        if (flag)
            right = mid;
        else
            left = mid + 1;
    }
    cout << left << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}