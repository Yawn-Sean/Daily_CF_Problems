#include <bits/stdc++.h>
using namespace std;
typedef double dl;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
// #define int long long
#define endl '\n'
const int N=2e5+10;
LL w[N];
struct Node{
    int l,r;
    LL s;
}tr[N*4];
void pushup(int u)
{
    tr[u].s=tr[u<<1].s&tr[u<<1|1].s;
}
void build(int u,int l,int r)
{
    if(l==r)
    {
        tr[u]={l,l,w[l]};
        return;
    }
    tr[u]={l,r};
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
    pushup(u);
}
LL query(int u,int l,int r)
{
    if(l<=tr[u].l && tr[u].r<=r)
    {
        return tr[u].s;
    }
    int mid=tr[u].l+tr[u].r>>1;
    if(l>mid)return query(u<<1|1,l,r);
    else if(r<=mid)return query(u<<1,l,r);
    else return (query(u<<1,l,r)&query(u<<1|1,l,r));
}
void solve()
{
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        if((w[i]&k)!=k)w[i]=(1LL<<31)-1;
    }
    build(1,1,n);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(query(1,l,r)!=k)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
