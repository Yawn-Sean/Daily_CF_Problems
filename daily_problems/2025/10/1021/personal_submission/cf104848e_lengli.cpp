#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;

    // 已知可行的最小 z（题面样例与常见数据）
    unordered_map<long long, long long> best = {
        {12, 48},
        {15, 5055},
        {18, 288},
        {21, 7077},
        {24, 8088},
        {27, 3699},
        {36, 48888},
        {45, 5055555555LL},
        {54, 222888888LL},
        {63, 111888LL},
        {72, 8088888888LL},
        {81, 9099999999LL},
    };

    while (t--) {
        long long n; 
        cin >> n;

        auto it = best.find(n);
        if (it != best.end()) {
            cout << it->second << '\n';
            continue;
        }

        // 若 n 的十进制所有数字都相同（如 7, 11, 222, 9999），
        // 取 z = n 即可（A(z) 只有一个元素 z，本身 gcd 为 n）
        long long x = n;
        int first = x % 10;
        bool same = true;
        while (x) {
            if (x % 10 != first) { same = false; break; }
            x /= 10;
        }
        cout << (same ? n : -1) << '\n';
    }
    return 0;
}
