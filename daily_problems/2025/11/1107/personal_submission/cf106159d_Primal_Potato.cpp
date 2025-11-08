#include <bits/stdc++.h>
using namespace std;
typedef double dl;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
// #define int long long
#define endl '\n'
// const int MOD=1e9+7,mod=998244353;
const int M=10000;
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
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    int st=b[1];
    vector<int> sa(n-1,0),sb(m-1,0);
    for(int i=0;i<=n-2;i++)
    {
        sa[i]=((a[i+2]-a[i+1])%M+M)%M;
    }
    for(int i=0;i<=m-2;i++)
    {
        sb[i]=((b[i+2]-b[i+1])%M+M)%M;
    }
    // for(int i=0;i<n-1;i++)cout<<sa[i]<<' ';
    // cout<<endl;
    // for(int i=0;i<m-1;i++)cout<<sb[i]<<' ';
    // cout<<endl;
    auto kmp = [&](const vector<int>& s, const vector<int>& t) {
        int n = s.size(), m = t.size();
        if (m == 0) return vector<int>(); // 空模式串
        vector<int> kmp_arr(m, 0), ans;
        // 构建KMP数组（next数组）
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && t[i] != t[j]) {
                j = kmp_arr[j - 1];
            }
            if (t[i] == t[j]) {
                j++;
            }
            kmp_arr[i] = j;
        }
        // 进行匹配
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && s[i] != t[j]) {
                j = kmp_arr[j - 1];
            }
            if (s[i] == t[j]) {
                j++;
            }
            if (j == m) {
                ans.push_back(i - m + 1); // t 在 s 中出现的位置
                j = kmp_arr[j - 1]; // 继续寻找下一个匹配
            }
        }
        return ans;
    };
    vector<int> res=kmp(sa,sb);
    vector<int> cnt(10010,0);
    for(auto i:res)
    {
        // cout<<i<<' ';
        cnt[((st-a[i+1])%M+M)%M]++;
    }
    // cout<<endl;
    int t=max_element(cnt.begin(),cnt.end())-cnt.begin();
    cout<<t<<' '<<cnt[t]<<endl;
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
