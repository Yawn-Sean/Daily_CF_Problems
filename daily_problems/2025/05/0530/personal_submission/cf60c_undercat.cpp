#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<pair<int,int>>>g(n,vector<pair<int,int>>(n,{-1,-1}));
    vector<int>res(n,-1),st(1000001),pri;
    int flag=1;
    for(int i=0,u,v,gd,cm;i<m;i++){
        cin>>u>>v>>gd>>cm;u--;v--;
        g[u][v]=g[v][u]={gd,cm};
        if(gd>cm)flag=0;
    }
    for(int i=2;i<=1000000;i++){
        if(st[i]==0){
            pri.push_back(i);
        }
        for(int j=0;j<pri.size()&&i*pri[j]<=1000000;j++){
            st[i*pri[j]]=1;
            if(i%pri[j]==0)break;
        }
    }
    auto getu=[&](int u)->set<int>{
        set<int>fir;
        for(int i=0;i<n;i++){
            if(i==u)continue;
            auto [gd,cm]=g[u][i];
            int tempcm=cm;
            if(gd==-1)continue;
            vector<pair<int,int>>temp;
            for(auto j:pri){
                int cnt=0;
                while(cm%j==0){
                    cm/=j;
                    cnt++;
                }
                temp.push_back({j,cnt});
                if(cm==1)break;
                if(j>=cm/j){
                    temp.push_back({cm,1});
                    cm=1;
                    break;
                }
            }
            // cout<<"temp\n";
            // for(auto[x,y]:temp)cout<<x<<' '<<y<<'\n';
            auto dfs=[&](auto&&dfs,int p,int now)->void{
                // cout<<gd<<"?"<<tempcm<<"\n";
                if(now*gd>tempcm)return;
                if(p==temp.size()){
                    fir.insert(now*gd);
                    return;
                }
                auto [x,y]=temp[p];
                for(int j=0,v=1;j<=y;j++){
                    if(j)v*=x;
                    dfs(dfs,p+1,now*v);
                }
            };
            dfs(dfs,0,1);
            // cout<<"fir\n";
            // for(auto x:fir)cout<<x<<' ';cout<<'\n';
        }
        return fir;
    };
    for(int i=0;i<n&&flag;i++){
        if(res[i]!=-1)continue;
        set<int>t=getu(i);
        int zeronum=0;
        for(int j=0;j<n;j++)if(g[i][j].first==-1)zeronum++;
        if(zeronum==n){
            res[i]=1;continue;
        }
        if(zeronum!=n&&t.size()==0)flag=0;
        // cout<<i<<":\n";
        // for(auto&x:t)cout<<x<<' ';cout<<'\n';
        int xflag=0;
        for(auto&j:t){
            int nflag=1;
            auto tres=res;
            auto dfs=[&](auto&&dfs,int u)->void{
                if(!nflag)return;
                for(int k=0;k<n;k++){
                    if(g[k][u].first==-1)continue;
                    if(tres[k]!=-1){
                        if(tres[k]*tres[u]!=g[k][u].first*g[k][u].second){
                            nflag=0;
                        }
                        if(tres[k]%g[k][u].first!=0){
                            nflag=0;
                        }
                        if(__gcd(tres[k],tres[u])!=g[k][u].first){
                            nflag=0;
                        }
                    }else{
                        tres[k]=g[k][u].first*g[k][u].second/tres[u];
                        if(tres[k]*tres[u]!=g[k][u].first*g[k][u].second){
                            nflag=0;
                        }
                        if(tres[k]%g[k][u].first!=0){
                            nflag=0;
                        }
                        if(__gcd(tres[k],tres[u])!=g[k][u].first){
                            nflag=0;
                        }
                        dfs(dfs,k);
                    }
                }
            };
            tres[i]=j;
            dfs(dfs,i);
            if(nflag){
                res=tres;
                xflag=1;
                break;
            }
        }
        if(xflag==0)flag=0;
        // cout<<i<<' '<<flag<<"\n";
        // cout<<i<<'\n';
        // for(auto x:res)cout<<x<<' ';cout<<'\n';
    }
    if(flag){
        cout<<"YES\n";
        for(int&i:res){
            cout<<i<<' ';
        }cout<<'\n';
    }else{
        cout<<"NO\n";
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}