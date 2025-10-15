#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//对于r来说
//我们的每个转移都是大的减小的，所以只要后面两个数字确定了，所有都知道了
//所以我们去考虑枚举第二个数，然后进行类似辗转相除就行

void sol()
{
   int n,r;cin>>n>>r;
   int chosen=-1,cur=1e7;
   for(int val=1;val<=r;++val)
   {
    int a=r,b=val,cnt=0,mis=0;
    //mis表示错误的伦茨
    //cnt表示总的轮次
    while(b)//辗转相除-对于错误的轮次是自身*2
    {
        int x=a/b;
        a%=b,swap(a,b);
        cnt+=x;
        mis+=x-1;
    }
    if(a==1&&cnt==n&&mis<cur)//a等于1，轮次相同记录
    {
        cur=mis;
        chosen=val;
    }
   }
   if(cur>n)
   {
    cout<<"IMPOSSIBLE\n";
    return;
   }
   cout<<max(0ll,cur-1)<<endl;
   vector<int>ans;
   int a=r,b=chosen;
   while(b)
   {
    ans.emplace_back(a/b);
    a%=b,swap(a,b);
   }
   ans.back()--;
   ans.emplace_back(1);
   reverse(ans.begin(),ans.end());

   for(int i=0;i<ans.size();++i)
   {
    while(ans[i]--)
    {
        cout<<"TB"[i&1];
    }
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
