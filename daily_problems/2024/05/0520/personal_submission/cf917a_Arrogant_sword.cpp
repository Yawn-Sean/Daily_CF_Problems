
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

void solve(int _) 
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;

    for (int i = 0; i < n; i ++ ) {
        int now = 0, cnt = 0;
        for (int j = i; j < n; j ++ ) {
            if (s[j] == '(') {
                now ++;
            } else if (s[j] == ')') {
                now --;
            } else {
                now --;
                cnt ++;
            }

            if (now < 0) {
                if (cnt == 0) break;
                cnt -= 1;
                now += 2;
            }
            if (now == 0) ans ++;
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