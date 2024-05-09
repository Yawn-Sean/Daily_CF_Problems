
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
const int inf = 1e14;

void solve(int _) 
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = s.size();
    int pos = -1;
    for (int i = 1; i < m; i ++ ) {
        if (s[i] != s[0]) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << n << endl;
        return;
    }
    
    int ans = pos + n * (n - pos);
    vector<int> sufd(m+1), sufr(m+1);
    for (int i = m-1; i >= 0; i -- ) {
        sufd[i] = sufd[i+1] + (s[i] == 'D');
        sufr[i] = sufr[i+1] + (s[i] == 'R');
    }

    for (int i = pos; i < m; i ++ ) {
        if (s[i] == 'R') ans -= sufd[i];
        else ans -= sufr[i];
    }
    cout << ans << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}