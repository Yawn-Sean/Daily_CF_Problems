#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//图论，先搞懂图
//点从0-n-1,边是（u+1)%n,值为1-k;
//求最大生成树
//迭代计算,从k开始选，我们每一次可以选择__gcd(n,k)的边，直到最后的边变成1
void sol()
{
    i64 n,k;cin>>n>>k;
    i64 ans=0;
    while(n>1)
    {
        int now=__gcd(k,n);
        ans+=k*(n-now);
        k--;
        n=now;
    }
    cout<<ans<<endl;
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
