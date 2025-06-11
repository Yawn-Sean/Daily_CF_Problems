#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
const int N = 1000550, mod = 1000001, inf = 1e9;
bool vis[N];

void solve(){
    int n, aim;
    cin >> n >> aim;
    if (n == 1) return cout << "YES\n" << aim << "\n", void();
    if (n == 2){
        if (aim) cout << "YES\n0 " << aim << "\n";
        else cout << "NO\n";
        return;
    }
    vector <int> a(n+1);
    srand(time(NULL));
    int cnt = 0, sum = 0;
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution <int> distri(0, mod-1);

    while (cnt < n-1){
        ++ cnt;
        int x = distri(mt);
        while (vis[x]) x = distri(mt);
        vis[x] = true;
        a[cnt] = x, sum ^= x;
    }
    cout << "YES\n";
    int x = distri(mt);
    while ((x^sum) != aim || vis[x]){
        int pos = x%n;
        if (!pos) ++ pos;

        sum ^= a[pos];
        int y = distri(mt);
        while (vis[y]) y = distri(mt);
        vis[a[pos]] = false, vis[y] = true;
        sum ^= y, a[pos] = y;
        x = distri(mt);
    }

    a[++ cnt] = x;
    for (int i = 1; i <= n; ++ i) cout << a[i] << "\n "[i < n];
}

int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    while (_--) solve();
    return 0;
}
