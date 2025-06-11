
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;
int cal(int x) {
    int ans = 0;
    while (x) {
        ans ++;
        x /= 10;
    }
    return ans;
}

void solve(int _) 
{
    int n, k;
    cin >> n >> k;
    vector<int> pw10(11), a(n);
    pw10[0] = 1;
    for (int i = 1; i < 11; i ++ ) pw10[i] = (pw10[i-1] * 10) % k;

    int ans = 0;
    unordered_map<int,int> mp[11];
    for (int i = 0, x; i < n; i ++ ) {
        cin >> x;
        a[i] = x;
        int id = cal(x);
        mp[id][(x % k)] ++;
        if (((x * pw10[id] + x) % k) == 0) ans --;
        
    }
  
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < 11; j ++ ) {
            int x = ((-a[i] * pw10[j] % k) + k ) % k;
            ans += mp[j][x];
        }
    }

    cout << ans << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}