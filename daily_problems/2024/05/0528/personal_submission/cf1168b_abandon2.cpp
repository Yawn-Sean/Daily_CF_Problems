#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void solve(){
    string s;cin>>s;
    int n=s.size();s=' '+s;
    LL ans=0;
    int r=n+1;
    for(int i=n;i>=1;i--){
        for(int j=1;i+j*2<=n;j++){
            if(s[i]==s[i+j]&&s[i]==s[i+j*2]){
                r=min(r,i+j*2);break;
            }
        }
        ans+=n-r+1;
    }    
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
