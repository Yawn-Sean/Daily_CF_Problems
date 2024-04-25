// 分类讨论的数学题。 若max(wr, wb) > sqrt(n)， 那么我们枚举重量大的那种颜色的个数不会超过n / sqrt(n)个。
// 若max(wr, wb) < sqrt(n)，假设hr < hb, 因为wb个wr与wr个wb等重量，且hr < hb，所以我们应该将wb个wr替换为wr个wb。
// 替换到最后r的数量是会小于wb的。
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
    int n, hr, hb, wr, wb;
    cin >> n >> hr >> hb >> wr >> wb;

    int ans = 0;
    for (int i = 0; i <= sqrt(n)+1; i ++ ) {
        if (wr * i > n) break;
        ans = max(ans, hr * i + (n - wr * i) / wb * hb);
    }

    for (int i = 0; i <= sqrt(n)+1; i ++ ) {
        if (wb * i > n) break;
        ans = max(ans, hb * i + (n - wb * i) / wr * hr);
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
