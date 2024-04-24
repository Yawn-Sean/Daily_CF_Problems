// 如果b很小，可以写出dp递推式dp[k+1][(j*10+val)%x] += dp[k][j]
// 可是这里b太大，不过我们可以注意到每轮dp的转移都很相似，所以借助矩阵来优化
// dpn = A*dpn-1 = A*A*dpn-2 …… = pow(A,b) * dp0。
// 考虑如何求出转移矩阵A,A[i][j]的含义其实是从模数i转移到模数j有多少种方式，求法其实就是上面的递推式。
// 考虑如何初始化，dp0设置为单位阵即可。
// 考虑答案：dp[0][k].其实dp只有第0行有意义。
// 这里的处理给我的感觉像是这样： dp设置为一个列向量，每一行表示%x=i的数量，然后设初值主要是为了第一次把A的值转移过来
// A中包含有所有的信息了，不过实现时为了好些,把dp设置为x*x的矩阵，这样把第一行当作原来的列了，所有只有第0行有意义。
// 其实还是看递推方程把，递推方程才是根本，保证转移正确就好了。
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////

vector<vector<int>> Mul(vector<vector<int>> a, vector<vector<int>> b, int mod = 1e9 + 7) {
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < n; j ++ ) {
            for (int k = 0; k < n; k ++ ) {
                res[i][k] = (res[i][k] + a[i][j] * b[j][k]) % mod;
            }
        }
    }
    return res;
}

void solve() 
{
    int n, b, k, x;
    cin >> n >> b >> k >> x;

    vector<vector<int>> A(x, vector<int>(x));
    vector<int> cnt(10);
    for (int i = 0; i < n; i ++ ) {
        int t;
        cin >> t;
        cnt[t] ++;
    }

    for (int i = 0; i < x; i ++ ) {
        for (int j = 1; j <= 9; j ++ ) {
            A[i][(i*10+j)%x] += cnt[j];
        }
    }

    vector<vector<int>> dp(x, vector<int>(x));
    for (int i = 0; i < x; i ++ ) dp[i][i] = 1;
    while (b) {
        if (b & 1) {
            dp = Mul(A, dp);
        }
        b >>= 1;
        A = Mul(A, A);
    }

    cout << dp[0][k] << endl;
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