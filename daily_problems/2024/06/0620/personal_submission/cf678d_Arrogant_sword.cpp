
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(int *vi, int st, int ed)
{
    for (int i = st; i <= ed; i ++ ) cout << vi[i] << ' ';
    cout << endl;
}

void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}


//////////////////////////////////////////////////
const int N = 2e5 + 10;

void solve(int _) 
{
   int a, b, n, x;
   cin >> a >> b >> n >> x;

   vector<vector<int>> grid = {
        {a, b},
        {0, 1}
   };

   vector<vector<int>> origin = {
        {x},
        {1}
   };

   int mod = 1e9 + 7;
   cout << matrix_mul(matrix_pow(grid, n, mod), origin, mod)[0][0] << endl;
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