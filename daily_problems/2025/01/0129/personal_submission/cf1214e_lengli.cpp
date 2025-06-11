#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define dep(i,a,b) for(register int i=(a);i>=(b);i--)
//priority_queue<int,vector<int>,less<int> >q;
int dx[]= {-1,1,0,0,-1,-1,1,1};
int dy[]= {0,0,-1,1,-1,1,1,-1};
const int maxn = 1000000+66;
const int maxm=100000+66;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f3f3f3f3fLL;
const int INF=99999999;
struct node
{
    int lid;
    int len;
} arr[maxn];
bool cmp(node a,node b)
{
    return a.len>b.len;
}
vector<vector<node> >v(maxn);
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        rep(i,1,n)
        {
            v[i].clear();
            scanf("%d",&arr[i].len);
            arr[i].lid=2*i-1;
        }
        sort(arr+1,arr+n+1,cmp);
        rep(i,1,n)
        {
            v[i].push_back(arr[i]);
        }
        int r=n;
        rep(i,1,n)
        {
            node tmp=v[i][0];
            int len=tmp.len;
            int lid=tmp.lid;
            if(i+len<=r)
            {
                v[i+len-1].push_back(node{lid+1,1});
            }
            else
            {
                v[++r].push_back(node{lid+1,1});
            }
        }
        rep(i,1,r)
        {
            if(i!=1)
                printf("%d %d\n",v[i-1][0].lid,v[i][0].lid);
            int s=v[i].size();
            for(int j=1; j<s; ++j)
                printf("%d %d\n",v[i][0].lid,v[i][j].lid);
        }
    }
}
