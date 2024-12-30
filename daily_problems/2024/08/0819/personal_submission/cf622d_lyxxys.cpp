#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1e7, mod = 1e9+7, inf = 1e9;

void solve(){
    int n;
    cin >> n;
    vector <int> ans(2*n+1), d(n+1);
    for (int i = 1; i <= n; ++ i) d[i] = n-i;
    int num = 1, cur = 1;
    while (num <= n){
        ans[cur] = ans[cur+d[num]] = num;
        num += 2;
        cur += 1;
    }
    num = 2, cur = n+1;
    ans[2*n] = n;
    while (num <= n){
        ans[cur] = ans[cur+d[num]] = num;
        num += 2;
        cur += 1;
    }

    for (int i = 1; i <= 2*n; ++ i){
        cout << ans[i] << "\n "[i < 2*n];
    }
}
