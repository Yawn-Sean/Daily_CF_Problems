#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v1(n+1);
    int val=INT_MAX;
    for(int i=1;i<=n;i++){
        cin>>v1[i];
        if(i%2){
            val=min(val,v1[i]);
        }
    }
    int tm=(n+1)/2;
    int tmp=m/tm;
    int ans=tmp*k;
    if(n%2==0)ans=0;
    cout<<min(ans,val)<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
