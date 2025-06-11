
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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c1 = 0;
    for (char c: s) c1 += (c == '(');

    int lcnt = n / 2 - c1;
    int now = 0;
    for (int i = 0; i < n; i ++ ) {
        if (s[i] == '(') {
            now ++;
        } else if (s[i] == ')') {
            now --;
        } else {
            if (lcnt > 0) {
                s[i] = '(';
                now ++;
                lcnt --;
            } else {
                s[i] = ')';
                now --;
            }
        }
        
        if (now <= 0 && i != n - 1) {
            cout << ":(" << endl;
            return;
        }
    }

    if (now != 0) {
        cout << ":(" << endl;
    } else {
        cout << s << endl;
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