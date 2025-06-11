#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

class UnionSet {
public :
    int n;
    vector<int> fa;

    UnionSet(int t) : n(t), fa(t + 1) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }

    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }

    void merge(int a, int b) {
        fa[get(b)] = get(a);
        return;
    }
};

void solve() { 
    int n; cin >> n;
    UnionSet u(n + 1);
    vector<int> ne(n + 1), end(n + 1);
    for (int i = 1; i <= n; i++) end[i] = i;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        int fa_a = u.get(a), fa_b = u.get(b);
        if (fa_a > fa_b) swap(fa_a, fa_b);
        u.merge(fa_a, fa_b);
        ne[end[fa_a]] = fa_b;
        end[fa_a] = end[fa_b];
    }
    int ans = 1;
    while (ans) {
        cout << ans << " ";
        ans = ne[ans];
    }
    cout << endl;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
