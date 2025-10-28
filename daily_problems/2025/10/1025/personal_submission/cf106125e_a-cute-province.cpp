#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e5 + 3;
const int N = 2e3 + 10;

void solve()
{   
    int n;
    cin >> n;
    int l = 1, r = n;
    while(1){
        cout << l <<' ' << r <<endl;
        vector<int> ve(n+1), sum(n+1);
        int p;
        for(int i =1 ; i<=n; i ++)cin >> ve[i], sum[i] = sum[i-1] + ve[i];
        cin >> p;
        if(p >= 70)exit(0);
        int ma = -1e9;
        for(int i =1 ; i <= n; i ++){
        	for(int j =i; j <=n; j ++){
        		if((j-i+1)-2* (sum[j] - sum[i-1]) > ma){
        			ma = (j-i+1)-2* (sum[j] - sum[i-1]);
        			l = i, r = j;
				}
			}
		}
	
    }
    
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
