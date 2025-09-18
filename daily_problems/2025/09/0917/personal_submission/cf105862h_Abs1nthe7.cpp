#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
const int mod=1e9+7;
//期望题
//很显然的是，每一个数被选择的数量是一样的,然后只需要知道每一个数被选多少次就行
//步长为s，当跑到一定长度的时候，会进入循环，设次数为k，ks要是n的倍数，所以k=n/s，k的最小值是n/gcd(n,s);
//总的选择是n2，记得求逆元
i64 qmi(i64 a,i64 b)
{
    i64 res=1;
    while(b)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;b>>=1;
    }
    return res;
}
void sol()
{
    int n;cin>>n;
    vector<int>a(n);
    int num=0;
    for(auto &c:a)
    {
        cin>>c,num+=c;
        if(num>=mod)num-=mod;
    }
    i64 cnt=0;
    for(int i=0;i<n;++i)
    {
         cnt+=n/__gcd(i,n);
         if(cnt>=mod)cnt-=mod;
    }
    cout<<1ll*num*cnt%mod*qmi(n,mod-2)%mod*qmi(n,mod-2)%mod<<endl;
}
signed main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)sol();
    return 0;
}
