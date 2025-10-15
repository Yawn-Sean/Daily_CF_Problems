#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*
    If you know the original direction and the current direction of i, 
    you can decide that of  i+1.
    */
    string s;
    cin >> s;
    // 我们已经考虑了长=i的前缀
    // dp_A[i], dp_B[i] (第i个人原来是A/B)
    // 第i+1人 让第i人 满足条件


    /*
        i=A
        i+1=A 不影响 dp_A[i]+dp_B[i]
        i+1=B i不能是A i+1调整后只能是B dp_A[i]    
    */
    i64 ans = 0;
    int n = s.size();

    s += s[0]; // 变成链

    vector<i64> dp_A(n + 1), dp_B(n + 1);
    dp_A[0] = 1;
    dp_B[0] = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            dp_A[i + 1] = dp_A[i] + dp_B[i];
            dp_B[i + 1] = (s[i + 1] == 'A') ? 0 : dp_B[i];
        } else {
            // s[i] == 'B'
            // BA
            dp_A[i + 1] = dp_B[i];
            dp_B[i + 1] = (s[i + 1] == 'A') ? dp_A[i] : dp_B[i];
        }
    }

    // 开头=结尾
    ans += dp_A[n];

    dp_A.clear();
    dp_B.clear();
    dp_A[0] = 0;
    dp_B[0] = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            dp_A[i + 1] = dp_A[i] + dp_B[i];
            dp_B[i + 1] = (s[i + 1] == 'A') ? 0 : dp_B[i];
        } else {
            dp_A[i + 1] = dp_B[i];
            dp_B[i + 1] = (s[i + 1] == 'A') ? dp_A[i] : dp_B[i];
        }
    }

    ans += dp_B[n];
    cout << ans << '\n';
    return 0;
}
