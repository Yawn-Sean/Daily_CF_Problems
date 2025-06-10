#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//k是<=100,直接进行暴力模拟的话是2**100-1024*10
//所以肯定有优化的地方
// 1.操作就是用原来的q数组进行
// 2.操作用q数组操作以后的数组进行
//一正一反的可以抵消的
//所以最后的实现其实是k次的正或者负能不能实现
//最后如果k-i==0或者%2==0，并且验证前面是否!=target
void sol()
{
    int n,k;cin>>n>>k;
    vector<int>p(n),s(n),q(n),now(n);
    for(int i=0;i<n;++i)cin>>p[i],p[i]--;
    for(int i=0;i<n;++i)cin>>s[i],s[i]--;
    for(int i=0;i<n;++i)q[p[i]]=i;
    iota(now.begin(),now.end(),0);
    auto check=[&](vector<int>&a,vector<int>&b)->bool
    {
        for(int i=0;i<n;++i)
        {
            if(a[i]!=b[i])return false;
        }
        return true;
    };

    auto op=[&](vector<int>&a,vector<int>&b)->vector<int>
    {
         vector<int>ans(n);
         for(int i=0;i<n;++i)
         ans[i]=b[a[i]];
         return ans;
    };
    if(check(now,s))
    {
        cout<<"NO\n";
        return;
    }

    for(int i=1;i<=k;++i)
    {
        now=op(now,p);//先进行正面
        if(check(now,s))
        {
            if((k-i)%2==0&&(k==1||i>1||!check(q,s)))
            {
                cout<<"YES\n";
                return;
            }
            break;
        }
    }

    iota(now.begin(),now.end(),0);
    for(int i=1;i<=k;++i)
    {
        now=op(now,q);
        if(check(now,s))
        {
            if((k-i)%2==0&&(i>1||k==1||!check(p,s)))
            {
                cout<<"YES\n";
                return;
            }
            break;
        }
    }
    cout<<"NO\n";
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    while(_--)sol();
    return 0;
}
