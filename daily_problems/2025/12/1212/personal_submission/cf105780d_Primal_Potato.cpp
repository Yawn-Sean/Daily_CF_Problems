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
#define i128 __int128_t
#define u128 __uint128_t
struct cmp{
    size_t operator()(const PII& p) const {
        return ((size_t)p.first << 32) | (size_t)p.second;
    }
};
void solve()
{
    int n;
    cin>>n;
    unordered_map<PII,int,cmp> mp;
    vector<PII> s(n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        s[i]={a,b};
        mp[{a,b}]++;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            auto [x1,y1]=s[i];
            auto [x2,y2]=s[j];
            LL dx=x2-x1;
			LL dy=y2-y1;
			if (mp[{x1+dx-dy,y1+dx+dy}] && mp[{x1-dy,y1+dx}])ans++;
			if (mp[{x1+dy,y1-dx}] && mp[{x1+dx+dy,y1+dy-dx}])ans++;
        }
    }
    cout<<ans/4<<endl;
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
