#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//构造题
//第一想法-词性和字典序有没有关系?-应该还是有关系的，反正在可行条件下，字典序应该是越小越好
//思维不是难度-难在如何去构造这个数组
//关键就是要从大到小进行构造，剩下就是码力的问题
void sol()
{
    int n,k;cin>>n>>k;
    vector<int>b(n+1);
    for(int i=1;i<=n;++i)cin>>b[i];
    vector<int>ans;
    for(int i=n;i>=1;--i)
    {
        vector<int>tmp;//创建一个临时数组，方便我们进行插入啥的操作，保证这个临时数组vaild，最后的答案就vaild
        int c=0;
        for(auto&x:ans)
        {
          if(c==b[i])//i的目标已经实现了
          {
            tmp.emplace_back(i);
            c++;
          }
          tmp.push_back(x);
          c+=(x>=i+k);//c表示前面符合条件的个数
        }
        if(c==b[i])tmp.emplace_back(i);//当i最后才成立，就跳出来再判断一遍
        swap(ans,tmp);
    }
    for(auto&c:ans)cout<<c<<' ';
    cout<<endl;
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
