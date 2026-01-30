#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 1e9 + 7;
const int N = 3e3 + 10;
void solve()
{   
    int n, m;
    cin >> m >> n;
  
    string ans;
    int idx = 1e9;
    for(int i = 1; i <= n; i ++){
        char src = 'A', dest = 'B', aux = 'C';
        string s;
        cin >> s;
        string sum;
        for(int j = m-1; j >= 0; j --){
            if(s[j] == src){
                swap(aux, dest);
                sum += "0";
            }
            else{
                swap(src, aux);
                //swap(aux, dest);
                sum += "1";
            }
        }
        //cout << sum << '\n';
        if(sum > ans){
        	ans = sum;
        	idx = i;
		}
		else if(sum == ans){
			idx = min(idx, i);
		}
        //ans = max(ans, sum);
    }
    cout << idx << '\n';
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
