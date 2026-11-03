#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int N = (1<<n);
    vector<int> a(n+1,0);
    for(int i = 0;i < n;i++) cin >> a[i];
    vector<vector<int>> f(N+1,vector<int>(1001,INT_MAX));
    f[0][0] = 0;
    for(int mask = 0;mask < N;mask++){
        for(int j = 0;j < n;j++){
            if((mask>>j)&1) continue;
            for(int k = 0;k <= 1000;k++){
                if(f[mask][k] == INT_MAX) continue;
                if(k+a[j] <= 1000) f[mask|(1<<j)][k+a[j]] = min(f[mask|(1<<j)][k+a[j]],max(f[mask][k],k+a[j]));
                f[mask|(1<<j)][abs(k-a[j])] = min(f[mask|(1<<j)][abs(k-a[j])],max(f[mask][k],abs(k-a[j])));
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 0;i <= 1000;i++){
        ans = min(ans,f[N-1][i]);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
