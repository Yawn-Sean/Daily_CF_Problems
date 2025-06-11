#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;
i64 mod = 1e9+9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        n个城市 最多k条边
        问是否能够a-b 走完所有城市
        c-d 也走完所有城市

        (a,b)不能直接连接
        (c,d)也不能直接连接

        假设已经有了: a-v1-v2-...-vn-2-b
        然后c-d怎么寻找? 尽可能多的复用已经用过的边!

        a-c-...-d-b
        c-a-...-b-d

    */
    
    int n, k;
    cin >> n >> k;

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (n == 4) {
        cout << -1;
    } else {
        // 至少要有n-1+2=n+1条边
        if (k < n + 1) {
            cout << -1;
        } else {
            vector<int> path1{a, c};
            vector<int> path2{c, a};
            for (int i = 1; i <= n; i++) {
                if (i != a && i != b && i != c && i != d) {
                    path1.emplace_back(i);
                    path2.emplace_back(i);
                }
            }
            path1.emplace_back(d);
            path1.emplace_back(b);

            path2.emplace_back(b);
            path2.emplace_back(d);

            for (auto& x: path1) {
                cout << x << ' ';
            }
            cout << '\n';
            for (auto& x: path2) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
