#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
    int n,k; cin >> n >> k;
    if(k % 2 == 0) cout << -1 << endl;
    else{
        vector<int> a(n);
        iota(begin(a),end(a),1);
        k /= 2;

        function<void(int,int)> f = [&](int l, int r){
            if(k == 0 || l == r) return;
            int mid = l + r + 1 >> 1;
            k --;
            swap(a[mid],a[mid - 1]);
            f(l,mid - 1), f(mid, r);
        }; f(0,n - 1);

        if(k) cout << -1 << endl;
        else {
            for(auto i:a) cout << i << " ";
            cout << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
