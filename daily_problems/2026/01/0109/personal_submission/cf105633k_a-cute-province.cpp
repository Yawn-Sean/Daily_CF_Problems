#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> w(1 << m, n+1),c(n+1);
    vector<PII> f(1 << m, {0, n+1});
    vector<int> ve;
    for(int i = 1; i <= n; i ++){
        int s = 0;
        char x;
        for(int j = 0; j < m; j ++){
            cin >> x;
            s += ((x == 'Y' ? 1 : 0) << j);
        }
        c[i] = s;
        if(s == (1 <<m)-1)ve.emplace_back(i);
        if(w[s] == n+1)w[s] = i, f[s] = {__builtin_popcount(s), i};
    }
    
    //特判两行全为Y的情况
    if(ve.size() > 1){
    	cout << ve[0] <<' ' << ve[1] << '\n';
    	return ;
	}
    for(int i = (1 << m); i >= 0; i --){
        for(int j = 0; j < m; j ++){
            if((i & (1 << j)) != 0){
                if(f[i ^ (1 << j)].x < f[i].x){
                    f[i ^ (1 << j)] = f[i];
                }
                else if(f[i ^ (1 << j)].x == f[i].x){
                    f[i ^ (1 << j)].y = min(f[i ^ (1 << j)].y, f[i].y);
                }
            }
        }
    }
    array<int, 3> ans = {-1, 0, 0};
    for(int i = 0; i < (1 << m); i ++){
        if(w[i] > n || f[((1 << m)-1) ^ i].y > n)continue;
        int v2 = w[i],v3 = f[((1 << m)-1) ^ i].y;
        int v1 = __builtin_popcount(c[v2] & c[v3]);
        //cout << v1 <<' ' << v2 << ' ' << v3 << '\n';
        if(v3 == v2)continue;//特判出现有全Y的行的情况
        if(v2 > v3)swap(v2, v3);
        if(v1 > ans[0]){   	
        	ans = array<int, 3>({v1, v2, v3});
		}
		else if(v1 == ans[0]){
			ans = min(ans, array<int, 3>({v1, v2, v3}));
		}
    }
    if(ans[0] == -1)cout << "No\n";
    else cout  << ans[1] <<' ' << ans[2] << '\n';  
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
        3 2
YY
NN
NN
*/
