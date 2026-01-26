#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1), num(n+1);
    for(int i =1 ; i <= n; i ++)cin >> a[i], num[i] = i;
    sort(num.begin(), num.end(), [&](int i, int j){
        return a[i] < a[j];
    });
    int p1 = 1, p2 = 1;
    while(p1 <= n && a[num[p1]] <= 0)p1 ++;
    while(p2 <= n && a[num[p2]] <= 1)p2 ++;
    vector<int> ans;
    int ok = 1;
    while(p1 <= p2){
    	while(p1 <= n && a[num[p1]] <= 0)p1 ++;
        a[num[p1]] --;
        ans.emplace_back(num[p1]);
        if(p1 == n && a[num[p1]] == 0)break;
        while(p2 <= n && a[num[p2]] <= 1)p2 ++;
        if(p2 <= n)a[num[p2]] --;
        else{
        	ok = 0;
            break;
		}
        ans.emplace_back(num[p2]);
        
    }
    if(ok){
        cout << "YES\n";
        for(auto i : ans)cout << i <<' ';
        cout << '\n';
    }
    else cout << "NO\n";
    

}
signed cute_prov0nce()
{   
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
