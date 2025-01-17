#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1202020],tong[202020];
vector<int>g[202020];
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int _=1;
    cin>>_;
    int res=0;
    while(_--){
        int n,i,j,x,y,k,mi=1e9,ma=0;
        map<int,int>m;
        cin>>k>>n;
        for(i=0;i<max(n,k);i++)g[i].clear(),tong[i]=0;
        for(i=0;i<n;i++){
            int k;
            cin>>k;
            for(j=0;j<k;j++){
                cin>>x;
                g[i].push_back(x);
            }
            m[g[i][0]]++;
            ma=max(ma,m[g[i][0]]);
        }
        int tma=ma;
        if(ma>(n+1)/2){
            for(i=0;i<n;i++){
                if(m[g[i][0]]==tma&&g[i].size()>1)tong[i]++,ma--;
                if(ma<=(n+1)/2)break;
            }
        }
        if(ma>(n+1)/2)cout<<"NO\n";
        else {
            cout<<"YES\n";
            for(i=0;i<n;i++)cout<<g[i][tong[i]]<<' ';
            cout<<'\n';
        }


    }
}
