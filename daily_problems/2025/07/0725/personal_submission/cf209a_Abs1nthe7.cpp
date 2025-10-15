#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
const int mod=1e9+7;
void sol()
{
    int n;cin>>n;
    int dpl=0,dpr=0;
    for(int i=0;i<n;++i)
    {
        if(i&1)dpl=(dpl+dpr+1)%mod;
        else dpr=(dpr+dpl+1)%mod;
    }
    cout<<(dpl+dpr)%mod<<endl;
}
signed main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}
