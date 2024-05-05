#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using Pli = pair<ll, int>;
const int N = 2000050, p = 998244353;
int a[N], n, k;
map <int, int> mp;
void solve(){
    cin >> n >> k;
    int pos = 0;
    for (int i = 1; i <= k+1; ++ i){
        cout << "? ";
        for (int j = 1; j <= k+1; ++ j)
            if (j != i) cout << j << " ";
        cout.flush();
        int x, y;
        cin >> x >> y;
        ++ mp[y];
        pos = max(pos, y);
    }
    cout << "! " << mp[pos];
}   
