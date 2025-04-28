#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 3e5 * 32;
int cnt, tree[MAXN][2], pass[MAXN], value[MAXN];

void init_tree() {
    cnt = 1;
}

void insert(int n) {
    int cur = 1;
    pass[cur]++;
    for (int i = 31; i >= 0; --i) {
        int path = (n >> i) & 1;
        if (tree[cur][path] == 0) {
            tree[cur][path] = ++cnt;
        }
        cur = tree[cur][path];
        pass[cur]++;
    }
    value[cur] = n;
}

int operation(int n) {
    int cur = 1;
    for (int i = 31; i >= 0; --i) {
        int path = (n >> i) & 1;
        if (tree[cur][path] && pass[tree[cur][path]]) {
            cur = tree[cur][path];
        } else {
            cur = tree[cur][path ^ 1];
        }
        pass[cur]--;
    }
    return value[cur];
}

void clear_tree() {
    for (int i = 0 ; i <= cnt; ++i) {
        memset(tree[i], 0, sizeof(tree[i]));
        pass[i] = 0;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    while (n--) {
        int a;
        cin >> a;
        insert(a);
    }
    for (int x : vec) {
        int res = operation(x);
        cout << (x ^ res) << ' ';
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        init_tree();
        solve();
        clear_tree();
    }
    return 0;
}