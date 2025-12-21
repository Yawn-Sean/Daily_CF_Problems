#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vc vector
#define pb emplace_back
#define ps emplace
#define be(x) x.begin(), x.end()
#define be1(x) x.begin() + 1, x.end()
#define lowbit(x) (x & -x)
#define popcount __builtin_popcountll
#define sz(x) (int)x.size()
#define pii pair<int, int>
#define YES(x) (cout << ((x) ? "YES" : "NO") << endl)
mt19937_64 rng(random_device{}());
#ifdef ONLINE_JUDGE
#define endl '\n'
#endif

template <class T>
inline void gmax(T &a, T b) { a = max(a, b); }
template <class T>
inline void gmin(T &a, T b) { a = min(a, b); }

constexpr int inf = 0x3f3f3f3f3f3f3f3f;
constexpr signed mod = 1e9 + 7;
constexpr int N = 1e5 + 10;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vc<string>s(n+1);
    for(int i=1;i<=n;i++)cin>>s[i],s[i]='#'+s[i];
    vc<vc<int>>ok(n+1,vc<int>(m+1));
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(s[i][j]!='#'&&!ok[i][j]){
        s[i][j]='L';
        for(int k=i;k>=1;k--){
            if(s[k][j]=='#')break;
            ok[k][j]=1;
        }
        for(int k=i;k<=n;k++){
            if(s[k][j]=='#')break;
            ok[k][j]=1;
        }
        for(int k=j;k>=1;k--){
            if(s[i][k]=='#')break;
            ok[i][k]=1;
        }
        for(int k=j;k<=m;k++){
            if(s[i][k]=='#')break;
            ok[i][k]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)cout<<s[i][j];
        cout<<endl;
    }
}   
