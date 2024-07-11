#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, n;
    cin >> a >> b >> n;

    while (n--) {
        ll l, t, m;
        cin >> l >> t >> m;
        ll L = l - 1, R = l + t * m + 1;
        ll st = a + (l - 1) * b;
        while (L + 1 < R) {
            ll mid = (L + R) >> 1;
            ll ed = a + (mid - 1) * b;
            if ((st + ed) * (mid - l + 1) / 2 > t * m || 
                ed > t)
                R = mid;
            else
                L = mid;
        }
        cout << (L >= l ? L : -1) << '\n';
    }

    return 0;
}