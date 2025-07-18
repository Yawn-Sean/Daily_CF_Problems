#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//能否由一个特定的排序转移到下面的排序
//下面排序能否转成一个固定的排序
//每一次截图，除了开头的数字，其他都是存在相对顺序的
//那只需要把所有相邻的数字连一条有向边，然后跑一遍拓扑序，看看数字个数是否==n就行
int n,k;
vector<vector<int>>g;
vector<int>ind;
int topo()
{
    queue<int>q;
    int cnt=0;
    for(int i=0;i<n;++i)if(ind[i]==0)q.push(i);
    while(q.size())
    {
        int x=q.front();q.pop();
        cnt++;
        for(const auto &y:g[x])
        {
            ind[y]--;
            if(ind[y]==0)q.push(y);
        }
    }
    return cnt;
}
void sol()
{
    cin>>n>>k;
    g.assign(n, vector<int>());
    ind.assign(n, 0);
    for(int i=0;i<k;++i)
    {
        vector<int>tmp(n);
        for(int j=0;j<n;++j)
        {
            cin>>tmp[j];
            tmp[j]--;
        }
        for(int j=2;j<n;++j)
        {
            g[tmp[j - 1]].push_back(tmp[j]);
            ind[tmp[j]]++;
        }
    }
    int cnt=topo();
    cout<<(cnt==n?"YES\n":"NO\n");
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
