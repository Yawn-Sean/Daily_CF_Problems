#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9+7;
const int N = 1e6 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> A(n+1), B(n+1);
    int Sa = 0, Sb = 0;
    for(int i = 1; i <= n; i ++)cin >> A[i], Sa += A[i];
    for(int i = 1; i <= n; i ++)cin >> B[i], Sb += B[i];
    if(Sa > Sb){
        cout << -1 << '\n';
        return ;
    }
    int l = 0, r = n;
    while(l < r){
        int k = (l + r)/2;
        vector<int> a = A, b = B;
        int ok = 1;
        for(int i = 1, j = 1; i <= j + k && j <= n; j ++){
            if(i < max(j-k, 1ll)){
                ok = 0;
                break;
            }
            while(i <= min(n, j + k) && b[j] >= a[i]){
            	
                b[j] -= a[i]; 
				a[i++] = 0;    
            }
            if(i <= min(n, j + k)){
            	a[i] -= b[j];
            	b[j] = 0;
			}
        } 
        for(int i = 1; i <= n; i ++){
            if(a[i] || ok == 0){
                ok = 0;
                break;
            }
        }
        if(ok)r = k;
        else l = k+1;
    }
    cout << l << '\n';
    
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
