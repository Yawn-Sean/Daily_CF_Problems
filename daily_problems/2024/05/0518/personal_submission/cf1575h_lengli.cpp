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

const int N=510,inf=1e9;

int n,m;
int tr[N][2],idx;
int cnt[N],ne[N];

void insert(string s,int k){
    int p=0;
    for(auto x:s){
        int t=x-'0';
        if(!tr[p][t]) tr[p][t]=++idx;
        p=tr[p][t];
    }
    cnt[p]+=k;
}

void get_fail(){
    queue<int> q;
    for(int i=0;i<2;i++){
        if(tr[0][i]) q.push(tr[0][i]);
    }
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<2;i++){
            int j=tr[t][i];
            if(!j) tr[t][i]=tr[ne[t]][i];
            else{
                ne[j]=tr[ne[t]][i];
                q.push(j);
            }
        }
        cnt[t]+=cnt[ne[t]];
    }
}

int f[N][N][N];

void solve(){
    cin>>n>>m;
    string a,b;
    cin>>a>>b;

    insert(b,1);
    get_fail();

    for(int i=0;i<=n;i++)
        for(int j=0;j<=idx;j++) 
            for(int k=0;k<=n-m+1;k++) f[i][j][k]=inf; 

    f[0][0][0]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=0;j<=idx;j++){
            for(int k=0;k<=n-m+1;k++){
                for(int l=0;l<2;l++){
                    int c=a[i-1]-'0';
                    int u=tr[j][l];
                    int nk=k+cnt[u];
                    f[i][u][nk]=min(f[i][u][nk],f[i-1][j][k]+(l!=c));
                }
            }
        }
    }

    for(int i=0;i<=n-m+1;i++){
        int res=inf;
        for(int j=0;j<=idx;j++) res=min(res,f[n][j][i]);
        if(res==inf) cout<<-1<<" ";
        else cout<<res<<" ";
    }

}

signed main(){

    #ifndef ONLINE_JUDGE
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif

    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
