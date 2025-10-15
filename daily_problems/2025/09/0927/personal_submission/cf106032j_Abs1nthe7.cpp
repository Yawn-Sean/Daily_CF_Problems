#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl "\n"
//移动是环的移动
//对于一个数字，他的下一位是奇数的情况下，他的移动就会结束，所以对于每一位的查询，我们只需要判断他和结束的位置，不然就正常位移就行
//主要考验代码的能力
const int inf=1e9+9;
void sol()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    vector<int>cnt(m+1,0);
    for(int i=1;i<=n;++i)
    {
        cnt[a[i]]^=1;
    }
    vector<int>next(m+1,inf);
    for(int i=1;i<=m;++i)
    {
       if(cnt[i])next[i]=0;//本身就是odd
    }
    for(int i=m;i>=1;--i)
    {
        next[i-1]=min(next[i-1],next[i]+1);
    }
    next[m]=min(next[m],next[0]);
    for(int i=m;i>=1;--i)
    {
        next[i-1]=min(next[i-1],next[i]+1);
    }
    int res=0;
    while(q--)
    {
        int op;cin>>op;
        if(op==1)res++;
        else
        {
            int x;cin>>x;
            int now=a[x],nxt=min(res,next[now]);
            cout<<(now+nxt-1)%m+1<<endl;
        }
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    cin>>_;
    while(_--)sol();
    return 0;
}
