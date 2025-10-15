/*
 * @Author: BlaCat
 */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
const int mod=1e9+7;
int a[300005];
int b[300005];
int d(int i){
    if(a[i]!=0){
        return a[i];
    }
    a[i]=d(i-1)+((2*(i-1))%mod*d(i-2)%mod)%mod;
    a[i]=(mod+a[i])%mod;
    return a[i];
}
void solve(){
    int n,k;
    cin>>n>>k;
    int m=n;
    int l,r;
    for(int i=0;i<k;i++){
        cin>>l>>r;
        if(l==r){
            m--;
        }
        else{
            m-=2;
        }
    }
    cout<<d(m)<<endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(a,0,sizeof(a));
    b[1]=1;
    for(int i=2;i<300005;i++){
        b[i]=b[i-1]*i;
        b[i]%=mod;
    }
    a[0]=1;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
