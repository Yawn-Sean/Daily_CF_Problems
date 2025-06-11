#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
constexpr int mod = 1e9 + 7;
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
    std::cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int>pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + s[i] - '0';
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int x = pre[r] - pre[l - 1];//1的数量
        int y = r - l + 1 - x;//0的数量
        int ans = (power(2, x) - 1 + mod) % mod;
        ans = (ans + ans * 1LL * ((power(2, y) - 1 + mod) % mod))% mod;
        cout << ans << "\n";
    }
    return 0;
}
