#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

/*
逆序数记到谁头上？
我们按照插入顺序，每插一个，新增的逆序数记到这个数头上
第 i 个数头插，则增加的个数就是前面 i - 1 个数里比自己小的，因为自己在最左边
尾插，增加的格式就是前面 i - 1 个数里比自己大的，因为自己在最右边
这样每个数的贡献，其实就是只和前面的数字有关，并且，和前面数字的具体插法无关
*/

void solve() {
    LL n;
    cin >> n;
    vector<LL> a(n + 1);
    BIT fen;
    fen.init(n);
    vector<LL> change;
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        LL smaller = fen.query(a[i] - 1);
        LL bigger = i - 1 - fen.query(a[i]);
        res += bigger;
        change.push_back(bigger - smaller);
        fen.add(a[i], 1);
    }
    
    sort(change.rbegin(), change.rend());
    
    cout << res << " ";
    for (int i = 0; i < n; i++) {
        res -= change[i];
        cout << res << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
