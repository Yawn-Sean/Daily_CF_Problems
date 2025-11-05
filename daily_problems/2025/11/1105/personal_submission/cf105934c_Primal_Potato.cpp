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
    int n;
    cin>>n;
    vector<LL> a1(n+1);
    for(int i=1;i<=n;i++)cin>>a1[i];
    vector<LL> a2=a1;
    LL ans1=0,ans2=0;
    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            if(a1[i]<=a1[i-1])
            {
                ans1+=a1[i-1]-a1[i]+1;
                a1[i]=a1[i-1]+1;
            }
        }
        else
        {
            if(a1[i]>=a1[i-1])
            {
                ans1+=a1[i]-a1[i-1]+1;
                a1[i]=a1[i-1]-1;
            }
        }
    }

    for(int i=2;i<=n;i++)
    {
        if(i%2==1)
        {
            if(a2[i]<=a2[i-1])
            {
                ans2+=a2[i-1]-a2[i]+1;
                a2[i]=a2[i-1]+1;
            }
        }
        else
        {
            if(a2[i]>=a2[i-1])
            {
                ans2+=a2[i]-a2[i-1]+1;
                a2[i]=a2[i-1]-1;
            }
        }
    }

    cout<<min(ans1,ans2)<<endl;
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
