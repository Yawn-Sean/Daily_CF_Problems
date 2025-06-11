#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;cin>>s;
    int n=s.size();s=' '+s;
    std::vector<int>nxt(n+100);
    nxt[n+1]=n+1;
    for(int i=n;i>=1;i--){
        if(s[i]=='0')nxt[i]=nxt[i+1];
        else nxt[i]=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=nxt[i];j<=min(nxt[i]+20,n);j++){
            sum=sum*2+s[j]-'0';
            //cout<<i<<" "<<j<<" "<<sum<<"\n";
            if(sum==j-i+1){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--)
        solve();
    return 0;
}
