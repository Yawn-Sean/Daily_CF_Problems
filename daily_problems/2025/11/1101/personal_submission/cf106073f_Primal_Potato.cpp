#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <array>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <cassert>
#include <iomanip>
#include <utility>
#include <cctype>
#include <iterator>
using namespace std;
typedef double dl;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
// #define int long long
#define endl '\n'
const int mod=1e9+7;
const double PI = 3.14159265358979323846;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
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
LL inv(LL x)
{
    return qmi(x,mod-2,mod);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<LL> a(m+1);
    for(int i=1;i<=m;i++)cin>>a[i];
    vector<LL> suf(m+10);
    suf[m]=0;
    for(int i=m-1;i>=0;i--)
    {
        suf[i]=(suf[i+1]+a[i+1])%mod*inv(2)%mod;
    }
    vector<LL> ans(n+1,0);
    for(int i=m;i>=1;i--)
    {
        ans[a[i]]=(ans[a[i]]+suf[i]*inv(2)%mod)%mod;
    }
    ans[1]=(ans[1]+suf[0])%mod;
    for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
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
