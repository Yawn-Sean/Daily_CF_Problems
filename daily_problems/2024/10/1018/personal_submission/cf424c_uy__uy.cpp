#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans ^= a;
    }
    vector<int>f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] ^ i;
    }
    for (int i = 2; i <= n; i++) {
        // n/i 组 (0 1 ... i-1) 考虑每个模数 i
        int t = n / i;
        if (t % 2 == 1) {
            ans ^= f[i - 1];
        }
        int x = n % i;
        assert(x <= i);
        ans ^= f[x];
    }
    cout << ans << "\n";
    return 0;
}
