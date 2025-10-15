#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//模拟
//1.如何输出这个模拟的矩阵
//2.预处理出矩阵的最值，方便输出矩阵
//3.'\'要用'\\'
//4.把奇数转换为下降的情况，方便实现矩阵
void sol()
{
    int n;cin>>n;
    int tot=0;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i)
    cin>>a[i],tot+=a[i];

    for(int i=1;i<=n;++i)
    {
        a[i]=(i&1?a[i-1]-a[i]:a[i-1]+a[i]);
    }
    int _min=*min_element(a.begin(),a.end());
    int _max=*max_element(a.begin(),a.end());

    for(int i=0;i<=n;++i)
     a[i]-=_min;
     vector<string>ans(_max-_min,string(tot,' '));
    int cur=0;
     for(int i=0;i<n;++i)
     {
        int l=a[i],r=a[i+1];
        if(r>=l)
        {
           for(int j=0;j<r-l;++j)
           ans[j+l][cur+j]='\\';
           cur+=r-l;
        }
        else
        {
            for(int j=0;j<l-r;++j)
            ans[l-j-1][cur+j]='/';
            cur+=l-r;
        }
     }
     for(auto &x:ans)cout<<x<<endl;
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
