#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<i64> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        /* 
        找到a的一个最长子序列满足
        x,y in subsequence
        lcm(x,y) not in a
        
        找到这样的最长的长度        
        1<=n<=2000 可以n^2暴力

        1. 直接全选 lcm(a1,a2,...,an) 只要不等于 a[n] 就行

        2. 否则说明 lcm(a1,a2,...,an) == a[n]
        - 那么答案序列LCM也是a[n]的因子 所以只能考虑a[n]因子 判断能否成为一个子序列lcm
        */
        bool flag = true;
        i64 mx = a[n - 1];
        for (int i = 0; i < n; i++) {
            if (mx % a[i]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << n;
        } else {
            int ans = 0;            
            auto check = [&] (int v) -> int {
                int cur = 1, cnt = 0;

                for (auto &x: a) {
                    if (v == x) return 0;
                    if (v % x == 0) {
                        cnt++;
                        cur = cur / gcd(cur, x) * x;
                    }
                }
                return (cur == v ? cnt : 0);
            };

            for (i64 i = 2; i * i <= a[n - 1]; i++) {
                if (a[n - 1] % i == 0) {
                    // lcm的一个因数 能否成为一个子序列的答案?
                    ans = max(ans, check(i));
                    ans = max(ans, check(a[n - 1] / i));
                }
            }
            cout << ans;
        }
        cout << '\n';
    }
    return 0;
}
