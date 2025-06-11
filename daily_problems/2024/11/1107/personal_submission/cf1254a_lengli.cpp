/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

void solve(){
    int n,m,k;
    std::cin>>n>>m>>k;
    std::vector<std::vector<char>> g(n+2,std::vector<char> (m+2));

    int cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            std::cin>>g[i][j];
            cnt+=g[i][j]=='R';
        }

    std::vector<int> dy={1,-1};

    std::vector<char> q;
    for(char i='0';i<='9';i++) q.pb(i);
    for(char i='a';i<='z';i++) q.pb(i);
    for(char i='A';i<='Z';i++) q.pb(i);

    std::vector<std::vector<char>> res(n+2,std::vector<char> (m+2,'*'));

    std::vector<int> nd;
    for(int i=0;i<cnt%k;i++) nd.pb(cnt/k+1);
    while(nd.size()<k) nd.pb(cnt/k);

    int flag=0;
    int sx=1,sy=1,ct=0,idx=0;
    while(sx<=n){
        res[sx][sy]=q[idx];
        ct+=g[sx][sy]=='R';

        if(sy+dy[flag]<1 or sy+dy[flag]>m){
            sx++;
            flag^=1;
        }else sy+=dy[flag];

        if(ct==nd[idx]){
            idx++;
            if(idx>=k) idx--;
            ct=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) std::cout<<res[i][j];
        std::cout<<"\n";
    }
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
