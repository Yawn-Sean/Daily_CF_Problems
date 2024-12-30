
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
const int N = 105;
int cnt[N*2][N*2];

void solve(int _) 
{
    int n, q;
    cin >> n >> q;
    cnt[N][N] = n;

    bool ok = 1;
    while (ok) {
        ok = 0;
        for (int i = 1; i < N * 2; i ++ ) {
            for (int j = 1; j < N * 2; j ++ ) {
                if (cnt[i][j] >= 4) {
                    ok = 1;
                    int num = cnt[i][j] / 4;
                    cnt[i][j] %= 4;
                    cnt[i+1][j] += num;
                    cnt[i-1][j] += num;
                    cnt[i][j+1] += num;
                    cnt[i][j-1] += num;
                }
            }
        }
    }

    while (q --) {
        int x, y;
        cin >> x >> y;
        x += N; y += N;
        if (0 < x && x < N*2 && 0 < y && y < N * 2) {
            cout << cnt[x][y] << endl;
        } else {
            cout << 0 << endl;
        }
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