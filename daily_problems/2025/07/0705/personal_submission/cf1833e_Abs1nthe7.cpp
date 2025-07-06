#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//初步判断，如果一个环的大小大于3的话，它就不能进行合并操作，由此判断min
//max就是初步环的数量
//操作就是DSU
const int N=2e5+9;
int pre[N],deg[N];
int find(int x){return pre[x]==x?x:find(pre[x]);}
void merge(int x,int y)
{
    int nx=find(x),ny=find(y);
    if(nx!=ny)pre[y]=x;
}
void sol()
{
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i)
    {
        pre[i]=i;
        deg[i]=0;
    }
    set<pair<int,int>>seen;
    int tot=n;
    for(int i=1;i<=n;++i)
    {
        int x;cin>>x;
        int u=min(x,i),v=max(x,i);
        if(!seen.count({u,v}))
        {
           seen.insert({u,v});
           deg[i]++,deg[x]++;
           if(find(i)!=find(x))
           {
            merge(i,x);
            tot--;
           }
        }
    }

    int res=0;
    for(int i=1;i<=n;++i)
    {
        if(deg[i]==1)
        {
            res++;
        }
    }
    int _min=tot+1-res/2;
    cout<<min(tot,_min)<<' '<<tot<<endl;
    return;
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
