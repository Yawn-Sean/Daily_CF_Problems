#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mod = 998244353;
typedef long long ll;
ll n;

vector<vector<ll>>mul(vector<vector<ll>>a,vector<vector<ll>>b,ll p)
{
    int n = a.size();
    int k = a[0].size();
    int m = b[0].size();
    vector<vector<ll>>ans(n,vector<ll>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int q=0;q<k;q++)
            {
                ans[i][j] += a[i][q]*b[q][j]%p;
                ans[i][j] %= p;
            }
        }
    }   

    return ans;
}

vector<vector<ll>> qpow(vector<vector<ll>> a,ll b,ll p)
{
    int m = a.size();
    vector<vector<ll>> res(m,vector<ll>(m,0));
    for(int i=0;i<m;i++)res[i][i]=1;
    for(;b;b>>=1)
    {
        if(b&1)res =mul(res,a,p);
        a = mul(a,a,p);
    }
    return res;
}

ll qpow2(ll a,ll b,ll p)
{
    ll res = 1;
    for(;b;b>>=1)
    {
        if(b&1)res = (res*a)%p;
        a = (a*a)%p;
    }
    return res;
}


void solve()
{
    cin>>n;

    vector<vector<ll>>A={{1,1},{1,0}};
    ll res =  qpow2(2,qpow(A,n,mod-1)[0][1],mod);
    res %= mod;
    cout<<res<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }


    return 0;
}
