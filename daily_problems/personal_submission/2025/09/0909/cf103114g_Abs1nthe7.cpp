#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//n<=1000,进行二进制拆分，从2**0-2**9
void sol()
{
    int n;cin>>n;
    vector<int>pos(n+1);//每一个对应的索引
    for(int i=0;i<10;++i)
    {
      vector<int>idx;
      for(int j=1;j<=n;++j)
      {
        if(j>>i&1)idx.emplace_back(j);//判断索引第i位是不是1
      }
      if(idx.size())
      {
        cout<<idx.size()<<endl;
        for(auto c:idx)cout<<c<<' ';//query
        cout<<endl;cout.flush();

        vector<int>tmp;
        for(int i=0;i<idx.size();++i)
        {
            int x;cin>>x;
            tmp.emplace_back(x);
        }
        for(auto &c:tmp)
        {
            pos[c]|=1<<i;//按位查询，同样也按位复原就行
            //如 3 1 2 4
            //第0位（1，3） 2，3，pos[2]+=1,pos[3]+=1;
            //第1位(2,3) 1,2 ,pos[1]+=2,pos[2]+=2;
            //第2位（4）4，pos[4]+=4;
            //pos[1]=2,pos[2]=3,pos[3]=1,pos[4]=4;
        }
      }
    }
    vector<int>ans(n+1);
    for(int i=1;i<=n;++i)
    {
        ans[pos[i]]=i;
    }
    cout<<"! ";
    for(int i=1;i<=n;++i)
    {
        cout<<ans[i]<<' ';
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
