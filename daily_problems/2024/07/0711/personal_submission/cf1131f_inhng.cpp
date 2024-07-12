#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

struct DSU { // 并查集
    vector<int> nex, head, ends;
    
    DSU() {}
    DSU(int n) {
        head = vector<int>(n + 1, -1);
        nex = vector<int>(n + 1, -1);
        ends.resize(n + 1);
        std::iota(ends.begin(), ends.end(), 0);
    }
    
    int find(int x) {
        int p = x;
        while (head[p] >= 0) {
            p = head[p];
        }
        while (x != p) {
            int mid = head[x];
            head[x] = p;
            x = mid;
        }
        return p;
    }
    
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (head[x] > head[y]) {
            swap(x, y);
        }
        head[x] += head[y];
        head[y] = x;
        nex[ends[x]] = y;
        ends[x] = ends[y];
    }
};

void solve() {
    int n;
    cin >> n;
    DSU dsu(n);
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        dsu.merge(x, y);
    }
    int now = dsu.find(1);
    for (int i = 0; i < n; ++i) {
        cout << now << " ";
        now = dsu.nex[now];
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
