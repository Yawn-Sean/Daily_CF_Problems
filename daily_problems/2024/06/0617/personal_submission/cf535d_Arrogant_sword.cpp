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
const int mod = 1e9 + 7;

std::vector<int> zFunction(std::string s) {
    int n = s.size();
    std::vector<int> z(n + 1);
    z[0] = n;
    for (int i = 1, j = 1; i < n; i++) {
        z[i] = std::max(0ll, std::min(j + z[j] - i, z[i - j]));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] > j + z[j]) {
            j = i;
        }
    }
    return z;
}

void solve(int _) 
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> a(n+1);
    int len = SZ(s);

    for (int i = 0; i < m; i ++ ) {
        int pos;
        cin >> pos;
        pos --;
        a[pos] = 1;
    }

    auto z = zFunction(s);
    int cnt = 0, remain = 0;
    for (int i = 0; i < n; i ++ ) {
        if (remain) {
            if (a[i]) {
                if (z[len - remain] >= remain) {
                    remain = len;
                } else {
                    cout << 0 << endl;
                    return;
                }
            } 
        } else {
            if (a[i]) {
                remain = len;
            } else {
                cnt ++;
            }
        }

        if (remain) remain --;
    }

    int ans = 1;
    while (cnt --) {
        ans = ans * 26 % mod;
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