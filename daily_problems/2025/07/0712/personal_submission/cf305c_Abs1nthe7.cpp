#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//二进制模拟
//因为数据范围过大，想直接进行计算会爆
//因为是(1LL<<a[i])，考虑在二进制上操作，答案是二进制的总位数减1的位数
void sol()
{
    int n;cin>>n;
    vector<i64>a(n);
    map<i64,i64>mp;
    i64 _max=0;
    i64 num=0;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i)
    {
        mp[a[i]]++;
        num++;
        _max=max(_max,a[i]+1);
        int t=0;
        while(mp[a[i]+t]==2)
        {
            mp[a[i]+t]=0;
            mp[a[i]+1+t]++;
            num--;
            _max=max(_max,a[i]+2+t);
            t++;
        }
    }
    // debug(num);
    // debug(_max);
    cout<<_max-num<<endl;
    return;
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
