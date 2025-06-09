#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//感觉是一道正常的遍历找值的问题
//invalid应该是在构造的时候判断
void sol()
{
   int n,m;cin>>n>>m;
   vector<int>l(m+1);
   for(int i=1;i<=m;++i)cin>>l[i];
   vector<int>a(n+1,0);
   vector<int>vis(n+1,0);
   for(int i=1;i+1<=m;++i)
   {
     int tmp=l[i+1]-l[i];
     if(tmp<=0)tmp+=n;
    if (a[l[i]] != 0) 
    {  // 位置已被赋值
     if (a[l[i]] != tmp) 
     {  // 当前计算的tmp与原值不同 → 冲突
        cout << -1 << endl;
        return;
     }
    } 
    else 
    {  // 位置未赋值
     if (vis[tmp]) 
      {  // tmp已被使用 → 冲突
        cout << -1 << endl;
        return;
      }
      a[l[i]] = tmp;
      vis[tmp] = 1;
    }
   }
   vector<int>valid(n+1,0);
   for(int i=1;i<=n;++i)
   {
      if(a[i]!=0)valid[a[i]]=1;
   }
//    for(int i=1;i<=n;++i)
//    {
//     cout<<valid[i]<<" \n"[i==n];
//    }
   for(int i=1;i<=n;++i)
   {
     if(a[i]==0)
     {
        for(int j=1;j<=n;++j)
        {
            if(valid[j]==0)
            {
                a[i]=j;
                valid[j]=1;
                break;
            }
        }
     }
   }
   for(int i=1;i<=n;++i)
   {
     cout<<a[i]<<" \n"[i==n];
   }
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
