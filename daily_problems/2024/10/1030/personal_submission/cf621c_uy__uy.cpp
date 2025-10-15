#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, p;
    cin >> n >> p;
    vector<double>a(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[i] = double(r / p - (l - 1) / p) / (r - l + 1);
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {//考虑相邻能得到钱的概率
        ans += a[i] + a[(i + 1) % n] - a[i] * a[(i + 1) % n];
    }
    cout << fixed << setprecision(10) << ans * 2000 << "\n";
    return 0;
}
