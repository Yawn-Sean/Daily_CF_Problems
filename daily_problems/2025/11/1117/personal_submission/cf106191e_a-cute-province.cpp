#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 2e5 + 10;

void solve()
{   
    int n;
    cin >> n;
    cout << "? " << n <<' ';
    for(int i = 1; i <= n; i ++)cout << i <<' ';
    cout << n <<' ';
    for(int i = 1; i <= n; i ++)cout << i <<(i == n ? "" : " ");
    cout << endl;
    int all;
    cin >> all;
    int sum = 0;
    for(int i = 1; i < n; i ++){
        cout << "? " << n-1 <<' ';
        for(int j = 1; j <= n; j ++) 
        if(i != j)
        cout << j <<' ';
        cout << n-1 <<' ';
        for(int j = 1; j <= n; j ++)
        if(i != j)
        cout << j <<(j == n ? "" : " ");
        cout << endl;
        int x;
        cin >> x;
        if(all-x == 1){
            cout << "! " << i << endl;
            return;
        }
        sum += all-x;
    }
    if(2*all - sum == 1){
        cout << "! " << n << endl;
       	return;
    }
    cout << "! " << -1 << endl;
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
