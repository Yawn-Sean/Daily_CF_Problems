#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    string a,b;cin>>a>>b;
    int x=0,y=0,t=0;
    for(int i=0;i<n;i++){
        if(a[i]=='1')x++;
        if(b[i]=='1')y++;
        if(a[i]!=b[i])t++;
    }    

    if(t==0){
        cout<<0<<"\n";return;
    }
    int ans=1e9;
    if(x==y){
        ans=min(ans,t);//有几个不同就交换几次
    }
    if(n-x==y-1){//先翻转
        ans=min(ans,n-t);
    }
    if(ans==(int)1e9){
        cout<<"-1\n";
    }
    else{
        cout<<ans<<"\n";
    }

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--)
        solve();
    return 0;
}
