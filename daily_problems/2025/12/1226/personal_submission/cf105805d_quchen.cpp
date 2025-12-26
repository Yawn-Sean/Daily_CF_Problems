#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
int n;
int tree[N];
int cnt1[N],cnt2[N];
int lowbit(int x)
{
    return x&-x;
}

void add(int i,int v)
{
    while(i<=n)
    {
        tree[i]+=v;
        i += lowbit(i);
    }
}

int sum(int i)
{
    int res = 0;
    while(i>0)
    {
        res += tree[i];
        i -= lowbit(i);
    }
    return res;
}

void solve()
{
    cin>>n;
    for(int i=0;i<=n;i++)tree[i]=0;
    ll cur = 0;
    vector<int>diff;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        cnt1[i] = sum(n)-sum(x);
        cnt2[i] = sum(x-1);
        cur+=cnt1[i];
        diff.push_back(cnt2[i]-cnt1[i]);
        add(x,1);
    }
    sort(diff.begin(),diff.end());
    cout<<cur<<' ';
    for(auto v:diff)
    {
        cur += v;
        cout<<cur<<' ';
    }
    cout<<'\n';
    
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<cnt1[i]<<' '<<cnt2[i]<<'\n';
    // }
    // cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}
