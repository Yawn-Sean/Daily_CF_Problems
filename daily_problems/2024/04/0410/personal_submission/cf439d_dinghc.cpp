#include <bits/stdc++.h>

using namespace std;
constexpr int MXN = 100001;
long long a[MXN];
long long sum_a[MXN];
long long b[MXN];
long long sum_b[MXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        sum_a[i + 1] = sum_a[i] + a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b, b + m);
    for (int i = 0; i < m; i++) {
        sum_b[i + 1] = sum_b[i] + b[i];
    }

    long long ans = LONG_LONG_MAX;
    int i = 0, j = 0;
    while (i < n || j < m) {
        long long x = i < n ? a[i] : 1e9+1;
        long long y = j < m ? b[j] : 1e9+1;
        if (x <= y) {
            ans = min(ans, (x * i - sum_a[i]) + ((sum_b[m] - sum_b[j]) - (m - j) * x));
            i++;
        } else {
            ans = min(ans, (y * i - sum_a[i]) + ((sum_b[m] - sum_b[j]) - (m - j) * y));
            j++;
        }
    }

    cout << ans << "\n";

    return 0;
}

