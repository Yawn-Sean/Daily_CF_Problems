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
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=' '+s;
    int t=0;
    int ans=0;
    int tt=0;
    for(int i=1;i<n;i++)
    {
        if(tt==0 && s[i]=='?')continue;
        else tt=1;
        if(s[i]!='?')ans++;
        if(i==1)continue;
        if(s[i]=='?' && s[i-1]!='?' && s[i+1]!='?' && s[i-1]!=s[i+1])ans++;
        else if(s[i]=='?' && s[i-1]!='?')
        {
            t=1;
        }
        else if(t && s[i]=='?' && s[i+1]!='?')
        {
            t=0;
            ans++;
        }
        // cout<<i<<":"<<t<<endl;
    }
    if(s[n]!='?')ans++;
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
