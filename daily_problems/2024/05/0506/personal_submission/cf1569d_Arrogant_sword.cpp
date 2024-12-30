
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector ans(50, vector<char>(50));
    string s = "ABCD";
    for (int i = 0; i < 50; i ++ ) {
        for (int j = 0; j < 50; j ++ ) {
            ans[i][j] = s[(i >= 25) * 2 + (j  >= 25)];
        }
    }
    vector<int> nums = {a, b, c, d};
    vector<PII> bias = {{0, 1}, {1, 0}, {1, 1}, {0, 0}};
    for (int c = 0; c < 4; c ++ ) {
        int dx = bias[c].x, dy = bias[c].y;
        for (int i = 1; i < 25; i += 2 ) {
            for (int j = 1; j < 25; j += 2 ) {
                if (--nums[c] > 0) {
                    ans[i + 25 * dx][j + 25 * dy] = s[c];
                }
            }
        }
    }

    cout << 50 << ' ' << 50 << endl;
    for (int i = 0; i < 50; i ++ ) {
        for (char c: ans[i]) cout << c;
        cout << endl;
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