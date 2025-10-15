#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    i64 n;
    cin >> n;

    i64 a, b, c;
    cin >> a >> b >> c;

    i64 ans = 0;
    if (a < (b - c)) {
        ans += n / a;
    } else {
        i64 diff = max(0ll, n - b + 1);
        ans += (diff / (b - c) + (diff % (b - c) != 0));
        n -= ans * (b - c);

        ans += n / a;
    }
    cout << ans << '\n';
    return 0;
}
