#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,sum=0;cin>>n;
    vector<int>a(n);
    for(auto&i:a){cin>>i;sum+=i;}
    a[0]=-a[0];
    int mi=0,mx=0;
    for(int i=1;i<n;i++){
        if(i%2==0)a[i]=a[i-1]-a[i];
        else a[i]=a[i-1]+a[i];
    }
    for(int i=0;i<n;i++){
        mi=min(mi,a[i]);
        mx=max(mx,a[i]);
    }
    for(int i=0;i<n;i++){
        a[i]-=mi;
    }
    // cout<<mx<<' '<<mi<<'\n';
    // cout<<mx-mi<<'\n';
    // cout<<sum<<'\n';
    vector<string>res(mx-mi,string(sum, ' '));
    for(int i=0,now=0;i<n;i++){
        int l,r=a[i];
        if(i)l=a[i-1];
        else l=-mi;
        // cout<<l<<' '<<r<<'\n';
        if(l<r){
            for(int j=0;j<r-l;j++)res[l+j][now+j]='\\';
            now+=r-l;
        }else{
            for(int j=0;j<l-r;j++)res[l-1-j][now+j]='/';
            now+=l-r;
        }
    }
    for(auto&i:res){
        cout<<i<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}