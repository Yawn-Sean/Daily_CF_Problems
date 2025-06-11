#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 5005;
bool cmp(pair<int,int> o1,pair<int,int> o2){
    return o1.second>o2.second;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s,t;
    cin>>s>>t;
    int n;
    cin>>n;
    vector<vector<int>> g(26,vector<int>(26,inf));
    for(int i=0;i<n;i++){
        char a,b;
        int w;
        cin>>a>>b>>w;
        a-='a',b-='a';
        g[a][b]=min(w,g[a][b]);
    }
    for(int i=0;i<26;i++){
        g[i][i]=0;
    }
    if(s.length()!=t.length()){
        cout<<-1<<endl;
        return 0;
    }
    for(int k=0;k<26;k++){
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                int len=g[i][k]+g[k][j];
                if(len<g[i][j]){
                    g[i][j]=len;
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<s.length();i++){
       if(s[i]!=t[i]){
           int res=inf;
           int tochange=-1;
           for(int j=0;j<26;j++){
               int d1=g[s[i]-'a'][j];
               int d2=g[t[i]-'a'][j];
               if(res>d1+d2){
                   res=d1+d2;
                   tochange = j;
               }
           }
           if(res==inf){
               cout<<-1<<endl;
               return 0;
           }
           ans+=res;
           s[i]=char(tochange+'a');
       }
    }
    cout<<ans<<endl;
    cout<<s<<endl;
    return 0;
}
