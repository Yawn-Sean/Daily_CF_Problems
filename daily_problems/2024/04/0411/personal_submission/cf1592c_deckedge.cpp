#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

inline int nxt() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = nxt(), k = nxt(), i, j, res = 0;
    vector<int> a(n + 1);
    vector<vector<int>> g(n + 1);
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        res ^= a[i];
    }
    
    for (i = 0; i < n - 1; ++i) {
        int u = nxt(), v = nxt();
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int nums = 0;
    function<int(int, int, int)> Dfs = [&](int u, int p, int w) -> int {
        int t = a[u];
        for (int x : g[u]) {
            if (x != p) {
                int k = Dfs(x, u, w);
                if (k == w) {
                    ++nums;
                } else {
                    t ^= k;
                }
            }
        }
        return t;
    };

    if (!res) {
        cout << "YES\n";
    } else {
        int p = Dfs(1, -1, res);
        if (k > 2 && nums >= 2 && (nums / 3 + nums % 3) <= k && ((nums % 2 == 0 && p == res) || (nums % 2 && !p))) {
            //只有两种可能一种是有偶数个相同的，则最后一组一定和之前的相同;反之则一定为0
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = nxt();
    while (t--) {
        solve();
    }

    return 0;
}

/*
首先将所有节点的异或值w求出，判断其是否为w = 0，为0输出YES，反之进行上述第二种情况的判断；
能否找出满足将其划分为至少3部分，且每一部分的异或值都等于w, 在此处可以采用dfs + 贪心进行判断;
(如何满足题目要求，最后异或不为0为w则说明可以最后的部分为w和存在偶数组异或值相同且为w的部分)
所以至少将其划分为至少3组异或为w的值
*/