/*
 * @Author: BlaCat
 */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod=1e9+7;
void solve(){
    int n,k;
    cin>>n>>k;
    int m=n/k;
    vector<int> a(m)，b(m);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int ans=1;
    int maxn=pow(10,k)-1;
    cerr<<maxn<<endl;
    for(int i=0;i<m;i++){
        int h=maxn/a[i]+1;
        cerr<<h<<" ";
        if(b[i]!=0){
        h-=(((int)pow(10,k-1)*(b[i]+1)-1)/a[i]-((int)pow(10,k-1)*b[i]-1)/a[i]);
        cerr<<((int)pow(10,k-1)*(b[i]+1)-1)/a[i]<<" "<<((int)pow(10,k-1)*b[i]-1)/a[i]<<endl;
        }
        else{
            h=(((int)pow(10,k)-1)/a[i]-((int)pow(10,k-1)-1)/a[i]);
        }
        cerr<<h<<endl;
        ans*=h;
        ans%=mod;
    }
    cout<<ans<<endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
