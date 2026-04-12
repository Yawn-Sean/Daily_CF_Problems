#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

struct p {
    int b, w, v;
    bool operator < (p &a) {
        return b < a.b;
    }
};

#define lowbit(x) (x & -x)

const int maxN = 1e5 + 7;
vector<int> tree(4 * maxN);

void change(int p, int l, int r, int pos, int x) {
    if (l == r && l == pos) {
        tree[p] += x;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) change(2*p, l, mid, pos, x);
    else change(2*p+1, mid+1, r, pos, x);
    tree[p] = tree[2*p] + tree[2*p+1];
}

int calc(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tree[p];
    int res = 0;
    int mid = l + r >> 1;
    if (x <= mid) res += calc(2*p, l, mid, x, y);
    if (y > mid) res += calc(2*p+1, mid+1, r, x, y);
    return res;
}

void solve(){
    int n, k;cin >> n >> k;
    vector<p> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i].b;
    for (int i = 1; i <= n; i++) cin >> arr[i].w;
    for (int i = 1; i <= n; i++) cin >> arr[i].v;
    sort(arr.begin() + 1, arr.end());
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i].b + arr[i].w > k) continue;
        change(1, 1, k, arr[i].w, arr[i].v);
        int t = calc(1, 1, k, 1, k - arr[i].b);
        res = max(res, t);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
