#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//贪心题
//其实只需要判断每一种所需要的最大即可
//为何？我们从小到大判断，对于小的值，现在的max肯定能实现，而且后面如果要修改肯定是大于当前的
//如果现在选的正方形的边长为t，a要大于(2**t/2**k)**2=4**(t-k);
void sol()
{
    int n;cin>>n;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        int k,a;cin>>k>>a;
        ans=max(ans,k+1);
        int tmp=k+1;
        while(1)
        {
            if(a>pow(4,tmp-k))tmp++;
            else break;
        }
        ans=max(ans,tmp);
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
