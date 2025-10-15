#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,a,b,c;cin>>n>>a>>b>>c;
    if(a<=(b-c)){
        cout<<n/a;
    }else{
        int res=0;
        while(n>=b){
            n-=b;
            res++;
            int cnt=n/(b-c);
            res+=cnt;
            n-=cnt*(b-c);
            n+=c;
        }
        res+=n/a;
        cout<<res;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}