#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;cin>>s;
    int n;cin>>n;
    vector<string>a(n);
    for(auto&i:a)cin>>i;
    int l=0,len=0,p=0;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<n;j++){
            int flag=1;
            if((i-a[j].size())<0)continue;
            for(int k=0;flag&&k<a[j].size();k++){
                if(a[j][k]!=s[i-a[j].size()+1+k])flag=0;
            }
            if(flag){
                l=max(l,i-(int)a[j].size()+2);
                // cout<<l<<'\n';
            }
        }
        int nlen=i-l+1;
        if(nlen>len){
            len=nlen;
            p=l;
            // cout<<len<<' '<<l<<'\n';
        }
    }
    cout<<len<<' '<<p;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}