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
    vector<vector<int>> cnt(2*n+10,vector<int>(2,0));
    int tt=n;
    int d=n+2;//奇数/偶数个数之差
    int msk=0;
    int ans=0;
    while(tt--)
    {
        cnt[d][msk]++;
        int x;
        cin>>x;
        if(x&1)
        {
            msk^=1;
            d++;
        }
        else 
        {
            d--;
        }
        ans+=cnt[d-1][msk^1]+cnt[d+1][msk];//本次加入的是奇数/偶数对应的上一次的情况
    }
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
