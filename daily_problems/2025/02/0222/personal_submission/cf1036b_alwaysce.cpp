#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        对角线移动
        d(x-y)=2/0/-2
        奇偶不变
        所以考虑nm差值

        恰好k步全部用完

    */
    int q;
    cin >> q;
    while (q--) {
        i64 n, m, k;
        cin >> n >> m >> k;
        if (k < max(n, m)) {
            cout << -1 << '\n';
            continue;
        } else if ((n + m) % 2) {
            // n m奇偶性不同 那么走一次非对角变成相同
            cout << k - 1 << '\n';
        } else if (n % 2 == k % 2) {
            // nm奇偶相同 和k也相同
            cout << k << '\n';
        } else {
            // nm奇偶相同 和k不同 至少需要走两次其他线
            cout << k - 2 << '\n';
        }
    }

    return 0;
}
