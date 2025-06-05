#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void sol()
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>g(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }

    vector<int> row(n+1),col(m+1);
    
    int mx=*min_element(g[1].begin()+1,g[1].end());
    bool exi=0;
    vector<pair<int,int>> ans;
    for(int x=0;x<=mx;x++){
        row[1]=x;
        for(int j=1;j<=m;j++){
            col[j]=g[1][j]-x;
        }
        bool ok=1;
        for(int i=2;i<=n;i++){
            row[i]=g[i][1]-col[1];
            if(row[i]<0){
                ok=0;
                break;
            }
            for(int j=2;j<=m;j++){
                if(row[i]+col[j]!=g[i][j]){
                    ok=0;
                    break;
                }
            }
            if(!ok) break;
        }
        if(ok){
            int k=accumulate(row.begin()+1,row.end(),0)+accumulate(col.begin()+1,col.end(),0);
            if(exi&&k>=ans.size()) continue;
            exi=1;
            ans.clear();
            for(int i=1;i<=n;i++){
                while(row[i]--){
                    ans.push_back({0,i});
                }
            }
            for(int i=1;i<=m;i++){
                while(col[i]--){
                    ans.push_back({1,i});
                }
            }
        }
    }
    if(!exi) cout<<-1<<'\n';
    else{
        cout<<ans.size()<<'\n';
        for(auto [op,x]:ans){
            if(op) cout<<"col "<<x<<'\n';
            else cout<<"row "<<x<<'\n';
        }
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    while(_--)sol();
    return 0;
}
