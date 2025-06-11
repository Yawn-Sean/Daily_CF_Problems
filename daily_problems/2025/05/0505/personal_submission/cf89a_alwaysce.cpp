#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    /*
        需要能够移动走一个的条件是什么?
        每个奇数->偶数移动1个 会有一个多出来1
        于是我们就可以拿走这个
        总共的操作次数=(N/2) + 1

        发现偶数长度是怎么都操作不了的
    */
    if (n % 2 == 0) {
        cout << 0 << endl;
    } else {
        i64 take = 1e9;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                take = min(take, 1ll * a[i]);
            }
        }
        cout << min(take, 1ll * m / (n / 2 + 1) * k) << endl;
    }
    return 0;
}
