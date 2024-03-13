#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;
const int N = 2e6;

struct DSU { // 并查集
    vector<int> pre, siz;
    
    DSU() {}
    DSU(int n) {
        pre.resize(n);
        std::iota(pre.begin(), pre.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        if (pre[x] == x) {
            return x;
        }
        return pre[x] = find(pre[x]);
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        pre[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, mx = 0;
    string ans(N, 'a');
    cin >> n;
    DSU dsu(N); // 并查集降低时间复杂度
    while (n--) {
        string s;
        int k;
        cin >> s >> k;
        while (k--) {
            int x;
            cin >> x;
            x--;
            mx = max(mx, (int)s.size() + x); // 更新答案的最长长度
            int y = dsu.find(x); // 如果这个位置已经处理过了，那么其父节点必定不是自己
            while (y < x + s.size()) {
                ans[y] = s[y - x];
                dsu.merge(y + 1, y); // 将下一个要放入的字符位置向后移，直至找到没放过的位置或超过范围
                y = dsu.find(y);
            }
        }
    }
    ans.resize(mx); // 把后面多余的字符去掉
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
