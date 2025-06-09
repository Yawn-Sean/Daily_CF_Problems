#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//最小生成树的反向？
//通过边构造图
//应该是一道图论结合构造的题目
//难点在于mit以外的如何判断和构造
struct node
{
    int idx,w,ok;
    bool operator <(const node&a)const
    {
        return w==a.w?ok>a.ok:w<a.w;
    }
};
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<node>es;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        es.push_back({i,x,y});
    }
    sort(es.begin(),es.end());
    vector<pair<int,int>>ans(m+1);
    int cnt=2;
    int st=2,lst=1;
    vector<int>vis(n+1);
    for(auto&[idx,w,ok]:es)
    {
        if(ok==1)
        {
           ans[idx]={1,cnt++};
        }
        else
        {
           if(++lst==st)
           {
            st++,lst=2;
           }
            if (st>=cnt) {  // 顶点编号溢出或无法生成有效边
                cout << -1 << endl;
                return;
            }
           ans[idx]={st,lst};
        }
    }
    for(int i=1;i<=m;++i)
    {
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
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
