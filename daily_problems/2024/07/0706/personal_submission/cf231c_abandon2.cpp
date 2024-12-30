#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
using LL=long long;
LL a[N],s[N];

void solve(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }   
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        //cout<<a[i]<<" ";
        s[i]=s[i-1]+a[i];
    }
    //cout<<"\n";

    int num=0,ans=0;
    for(int i=1;i<=n;i++){
        //cout<<s[i]<<" ";
        int l=0,r=i+1;
        while(l+1<r){
            int mid=l+r>>1;
            if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=k)r=mid;
            else l=mid;
        }
        //cout<<i<<" "<<r<<"\n";
        if(num<i-r+1){
            num=i-r+1;
            ans=a[i];
        }
    }
    //cout<<"\n";
    cout<<num<<" "<<ans<<"\n";

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
