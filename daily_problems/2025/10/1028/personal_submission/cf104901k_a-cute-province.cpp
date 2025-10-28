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
const int N = 1e5 + 10;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i ++)cin >> a[i], a[i] -= i;
    multiset<int> lower, upper;
    int sum1 = 0, sum2 = 0, ans = 0;
    for(int l = 1, r = 1; r <= n && l <= r;  r ++){ 
        
            lower.insert(a[r]);
            sum1 += a[r];
            while(!upper.empty() && *lower.rbegin() > *upper.begin()){
                int a = *lower.rbegin(), b = *upper.begin();
                lower.erase(lower.find(a));
                upper.erase(upper.find(b));
                sum1 = sum1 - a + b;
                sum2 = sum2 - b + a;
                lower.insert(b);
                upper.insert(a);
            }
            while(lower.size() > upper.size()+1){
                sum2 += *lower.rbegin();
                sum1 -= *lower.rbegin();
                upper.insert(*lower.rbegin());
                lower.erase(--lower.end());
            }
            while((*lower.rbegin()) * (lower.size()) - sum1 + sum2 - (*lower.rbegin()) * (upper.size()) > k){
                if(lower.find(a[l]) != lower.end()){
                    lower.erase(lower.find(a[l]));
                    sum1 -= a[l];
                    if(lower.size() < upper.size()){
                        sum1 += *upper.begin();
                        sum2 -= *upper.begin();
                        lower.insert(*upper.begin());
                        upper.erase(upper.begin());
                    }
                }
                else{
                    upper.erase(upper.find(a[l]));
                    sum2 -= a[l];
                    if(upper.size() < lower.size()-1){
                        sum2 += *lower.rbegin();
                        sum1 -= *lower.rbegin();
                        upper.insert(*lower.rbegin());
                        lower.erase(--lower.end());
                    }
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        
    }
    cout << ans << '\n';
    
    
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
