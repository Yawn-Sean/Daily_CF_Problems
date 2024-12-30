#include<bits/stdc++.h>
using namespace std;
const int N=30,inf =1e9;
typedef long long LL;
void solve(){
    string a,b;cin>>a>>b;
    int n;cin>>n;
    vector<vector<int>>d(31,vector<int>(31,inf));

    for(int i=1;i<=n;i++){
        char x,y;int w;cin>>x>>y>>w;
        d[x-'a'][y-'a']=min(d[x-'a'][y-'a'],w);
    }   
    if(a.size()!=b.size()){
        cout<<"-1\n";return;
    }
    for(int i=0;i<30;i++){
        d[i][i]=0;
    }
    
    for(int k=0;k<30;k++){
        for(int i=0;i<30;i++){
            for(int j=0;j<30;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    
    LL ans=0;
    string s;
    for(int i=0;i<a.size();i++){
        int res=inf;
        int c;
        for(int j=0;j<26;j++){
            if(res>d[a[i]-'a'][j]+d[b[i]-'a'][j]){
                res=d[a[i]-'a'][j]+d[b[i]-'a'][j];
                c=j;
            }
            
        }
        s+=(char)(c+'a');
        if(res>=inf){cout<<"-1\n";return;}
        //cout<<res<<"\n";
        ans+=res;
    }
    cout<<ans<<"\n";
    cout<<s<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
