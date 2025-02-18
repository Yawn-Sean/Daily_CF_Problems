    #include<bits/stdc++.h>

    using namespace std;

    using u32 = unsigned;
    using i64 = long long;
    using u64 = unsigned long long;

    int main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        cout << fixed << setprecision(12);
        int n, m;
        cin >> n >> m;

        i64 mx = -1e18;
        i64 mi = 1e18;
        //d >= 0  sigma(dis(i,j))大
        //d < 0   sigma(dis(i,j))小
        //dis(i,j) = abs(i-j)
        // i<j  j-i
        //i>=j  i-j
        for (int i = 1; i <= n; i++) {
            mx = max(mx, i * 1LL * i - ((1 + i) * 1LL * i) / 2 + ((i + 1 + n) * 1LL * (n - i) / 2) - (n - i) * 1LL * i);
            mi = min(mi, i * 1LL * i - ((1 + i) * 1LL * i) / 2 + ((i + 1 + n) * 1LL * (n - i) / 2) - (n - i) * 1LL * i);
        }
        //cerr << mx << " " << mi << "\n";
        long double ans = 0;
        long double s = 0;
        for (int i = 0; i < m; i++) {
            int x, d;
            cin >> x >> d;
            s += x;
            ans += max(d * 1LL * mx, d * 1LL * mi);
        }
        ans = ans * 1.0 / n;
        // cerr << ans << "\n";
        ans += s;

        cout << ans << "\n";
        return 0;
    }
