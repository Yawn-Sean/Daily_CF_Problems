#include<bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;

constexpr int mod = 1e9 + 9;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * 1LL * a % mod;
        }
        a = a * 1LL * a % mod;
        b >>= 1;
    }
    return ans;
}

int main() {

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //freopen("input.in", "r", stdin);

    int n, m, k;
    cin >> n >> m >> k;

    int t = n - m;//没答对的
    int x = m / (k - 1);//答对的能分多少个 (k-1)
    i64 s = min(x, t) * 1LL * (k - 1);//分割为k-1的长度;
    i64 p = m - s;//还剩多少答对的
    t -= min(x, t);
    //cerr << p << " " << t << "\n";
    int pp = p / k;//能分多少个一组为k的
    //cerr << pp << "\n";
    i64 ans = 0;
    i64 y = 0;
    //2*k  (2*k+k)*2   ((2*k+k)*2+k)*2
    y = (k * 1LL * (power(2, pp + 1) - 2 + mod) % mod) % mod;
    // cerr << y << "\n";
    ans = y + p % k + s;
    cout << ans % mod << "\n";
    return 0;
}
