#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
void sol()
{
    int n,k;cin>>n>>k;
    vector<int>ar(n);
    for(auto &c:ar)cin>>c;
    sort(ar.rbegin(),ar.rend());
    for(int i=1;i<=n;++i)//个数
     for(int j=i-1;j<n;++j)
     {
        cout<<i<<' ';
        for(int k=0;k<i-1;++k)cout<<ar[k]<<' ';
        cout<<ar[j]<<endl;
        k--;
        if(k==0)return;
     }
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
