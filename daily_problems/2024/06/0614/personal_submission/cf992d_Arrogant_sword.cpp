
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;

void solve(int _) 
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }

    vector<int> nxt_pos(n+1);
    for (int i = n; i >= 1; i -- ) {
        if (a[i] == 1) {
            if (i == n) nxt_pos[i] = n;
            else nxt_pos[i] = nxt_pos[i + 1];
        } else {
            nxt_pos[i] = i;
        }
    }

    int sum = accumulate(all(a), 0ll);
    sum *= k;

    int ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        int j = i;
        int cur = 1, s = 0;
        while (j <= n) {
            if (j != nxt_pos[j] ) {
                if (cur % k == 0 && cur / k > s && cur / k - s <= nxt_pos[j] - j) {
                    ans ++;
                }
                s += nxt_pos[j] - j;
                j = nxt_pos[j];
            } else {
                if (sum * k / a[j] < cur) {
                    break;
                }
                cur *= a[j];
                s += a[j];
                if (cur == k * s) {
                    ans ++;
                }
                j ++;
            }
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