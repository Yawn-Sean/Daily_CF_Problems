#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,sum=0,avg;cin>>n;
    vector<int>a(n);
    for(auto&i:a){
        cin>>i;
        sum+=i;
    }
    avg=sum/n;
    int res=0;
    for(int i=0,now=0;i<n;i++){
        now+=avg;
        now-=a[i];
        res+=abs(now);
    }
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}