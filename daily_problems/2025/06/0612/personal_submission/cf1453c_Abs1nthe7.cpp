#include<bits/stdc++.h>
using namespace std;
#define long long i64
#define unsigned long long u64
#define debug(x) cout<<x<<endl;
#define endl "\n"
//if mp[i]<=1 无法实现三角形 ans=0
//if mp[i]==2 
//如果 两个点已经实现平行轴的话，直接贪心找最远的点
//如果没有的话，就找到这两个点平行轴的最远点
//if mp[i]==3
//可以把这个转化为最远的两个点，然后同上
//记得答案*2
//存一下每个数字的坐标，然后贪心一下
void sol()
{
   int n;cin>>n;
   map<int,int>mp;
   vector<int>_min_x(10,n+1),_max_x(10,-1),_min_y(10,n+1),_max_y(10,-1);
   vector<string>a(n+1);
   for(int i=0;i<n;++i)
   {  
    cin>>a[i];
     for(int j=0;j<n;++j)
     {
        mp[a[i][j]-'0']++;
        _min_x[a[i][j]-'0']=min(_min_x[a[i][j]-'0'],i);
        _max_x[a[i][j]-'0']=max(_max_x[a[i][j]-'0'],i);
        _min_y[a[i][j]-'0']=min(_min_y[a[i][j]-'0'],j);
        _max_y[a[i][j]-'0']=max(_max_y[a[i][j]-'0'],j);
     }
   }
    vector<int>ans(10);
    for(int i=0;i<n;++i)
      for(int j=0;j<n;++j)
      {
        int c=a[i][j]-'0';
        ans[c]=max(ans[c],max(i,n-i-1)*max(_max_y[c]-j,j-_min_y[c]));
        ans[c]=max(ans[c],max(j,n-1-j)*max(_max_x[c]-i,i-_min_x[c]));
      }
    for(int i=0;i<10;++i)cout<<ans[i]<<" \n"[i==9];
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _;cin>>_;
    while(_--)sol();
    return 0;
}
