#include <bits/stdc++.h>
using namespace std;
typedef double dl;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
// #define int long long
#define endl '\n'
const int MOD=1e9+7,mod=998244353;
const double PI = 3.14159265358979323846;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
std::mt19937_64 rnd(time(0));
#define u64 uint64_t
LL qmi(LL m,LL k,int p)
{
    LL ans=1LL%p;
    while(k)
    {
        if(k&1)ans=ans*m%p;
        m=m*m%p;
        k>>=1;
    }
    return ans;
}
void solve()
{
    LL n,k;
    cin>>n>>k;
    vector<LL> st(19,0),qt(19,1);
    st[1]=9;
    qt[1]=10;
    for(int i=2;i<=18;i++)
    {
        st[i]=qt[i-1]*9*i+st[i-1];
        qt[i]=qt[i-1]*10;
    }
    auto get=[&](LL x)->LL{
        if(x==0)return 0;
        LL xx=x;
        int t=0;
        while(xx)
        {
            t++;
            xx/=10;
        }
        return st[t-1]+(x-qt[t-1]+1)*t;
    };
    // cout<<get(100)<<endl;
    auto check=[&](LL x)->LL{
        return get(x+n-1)-get(x-1);
    };
    LL l=1,r=1e18;
    while(l<r)
    {
        LL mid=l+r>>1;
        if(check(mid)>=k)r=mid;
        else l=mid+1;
        // cout<<mid<<' '<<check(mid)<<endl;
    }
    // cout<<get(2)<<' '<<get(10)<<endl;
    if(check(l)==k)
    {
        cout<<l<<endl;
    }
    else cout<<-1<<endl;

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
