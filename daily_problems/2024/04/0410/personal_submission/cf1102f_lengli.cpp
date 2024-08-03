/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010,inf=2e9;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int> (m));
    vector<vector<int>> d(n,vector<int> (n,inf));
    vector<vector<int>> cost(n,vector<int> (n,inf));
    for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++) cin>>a[i][j];

    if(n==1){
        int res=2e9;
        for(int j=0;j<m-1;j++) res=min(res,abs(a[0][j]-a[0][j+1]));
        cout<<res<<endl;
        return;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) {
                d[i][j]=0;
                continue;
            }
            for(int k=0;k<m;k++){
                d[i][j]=min(d[i][j],abs(a[i][k]-a[j][k]));
            }
            for(int k=0;k<m-1;k++){
                cost[i][j]=min(cost[i][j],abs(a[j][k]-a[i][k+1]));
            }
        }
    }

    vector<vector<vector<int>>> f((1<<16),vector<vector<int>> (n,vector<int> (n,0)));

    for(int mask=0;mask<(1<<n);mask++){
        if(mask==(mask&-mask)) continue;
        for(int i=0;i<n;i++){
            if(!(mask>>i&1)) continue;
            for(int j=0;j<n;j++){
                if(!(mask>>j&1) or i==j) continue;
                if((mask^(1<<i)^(1<<j))==0){
                    f[mask][i][j]=d[i][j];
                    continue;
                }
                int la=mask^(1<<j);
                for(int tt=0;tt<n;tt++){
                    if(!(la>>tt&1) or tt==i) continue;
                    f[mask][i][j]=max(f[mask][i][j],min(f[la][i][tt],d[tt][j]));
                }

                
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(n!=1 and i==j) continue;
            res=max(res,min(f[(1<<n)-1][i][j],cost[i][j]));
        }
    }
    cout<<res; 
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
