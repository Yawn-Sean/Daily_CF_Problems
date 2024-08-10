    
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
#define rep(i, n) for (int i = 1; i <= n; i ++)
#define rep0(i, n) for (int i = 0; i < n; i ++)

using namespace std;
void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
const int N = 2e6;

void solve(int _) 
{
    int A, B, m;
    cin >> A >> B >> m;
    vector<int> a(N), s(N);
    
    int n = N;
    rep(i, N) {
        a[i] = A + (i - 1) * B;
        s[i] = s[i-1] + a[i];
        if (s[i] > 1e12 ) {
            n = i;
            break;
        }
    }

    auto check = [&](int l, int r, int t, int m) -> bool {
        if (A + (r - 1) * B > t) {
            return false;
        }
        if (s[r] - s[l-1] > m * t) {
            return false;
        }
        return true;
    };
    rep(i, m) {
        int L, t, m;
        cin >> L >> t >> m;
        int l = L, r = n;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(L, mid, t, m)) l = mid;
            else r = mid - 1;
        }
        if (check(L, r, t, m)) cout << r << endl;
        else cout << -1 << endl;
    }
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