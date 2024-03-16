
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e6 + 10;
vector<int> primes, st(N+10);
map<int,int> mp;
void get_prime() {
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) {
            mp[i] = 1;
            primes.pb(i);
        }
        for (int j = 0; primes[j] <= N/i; j ++ ) {
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() 
{   
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt1 = 0;
    for (int i = 0; i < n; i ++ ) {
        cin >> a[i];
        cnt1 += (a[i] == 1);
    }
    get_prime();
    if (cnt1 <= 1) {
        for (int i = 0; i < n; i ++ ) {
            for (int j = i+1; j < n; j ++ ) {
                if (mp[a[i] + a[j]]) {
                    cout << 2 << endl;
                    cout << a[i] << ' ' << a[j] << endl;
                    return;
                }
            }
        }
        cout << 1 << endl;
        cout << a[0] << endl;
        return;
    } else {
        int t = -1;
        for (int i = 0; i < n; i ++ ) {
            if (a[i] != 1 && mp[1+a[i]]) {
                t = a[i];
                break;
            }
        }
        if (t == -1 ) {
            cout << cnt1 << endl;
            for (int i = 0; i < cnt1; i ++) cout << 1 << ' ';
        } else {
            cout << cnt1 + 1 << endl;
            for (int i = 0; i < cnt1; i ++) cout << 1 << ' ';
            cout << t << endl;
        }
    }
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}