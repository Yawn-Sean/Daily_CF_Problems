#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

const ll mod = 998244353;
const int N = 2e5 + 7;
vector<int> tree[N];
int son[N];
ll fact[N];

ll dfs(int root, int pre) {
    ll subres = 1;
    for (int ch : tree[root]) {
        if (ch == pre) continue;
        subres *= dfs(ch, root);
        subres %= mod;
        son[root] += 1;
    }
    ll res = fact[son[root] + (root != 0)] * subres;
    res %= mod;
    return res;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * ll(i);
        fact[i] %= mod;
    }
    ll ans = (n * dfs(0, -1)) % mod;
    cout << ans << "\n";
}

