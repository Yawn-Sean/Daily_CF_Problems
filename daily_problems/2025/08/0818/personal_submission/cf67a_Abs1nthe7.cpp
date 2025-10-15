#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
void sol()
{
    int n;cin>>n;
    string s;cin>>s;
    vector<int>ans(n,1);
    for(int i=0;i<n-1;++i)
    {
       if(s[i]=='R')ans[i+1]=ans[i]+1;
       else if(s[i]=='=')ans[i+1]=ans[i];
    }
    for(int i=n-2;i>=0;--i)
    {
        if(s[i]=='L')ans[i]=max(ans[i],ans[i+1]+1);
        else if(s[i]=='=')ans[i]=ans[i+1];
    }
    for(auto &c:ans)
    {
        cout<<c<<' ';
    }
    cout<<endl;
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
