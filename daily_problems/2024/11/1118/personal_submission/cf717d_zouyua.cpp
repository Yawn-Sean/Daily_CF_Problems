#define Max_rank 130
double p[N];
struct Matrix {
    double a[Max_rank][Max_rank];

    Matrix() {
        memset(a, 0, sizeof(a));
    }

    void init(){
        for(int i = 0; i <= 127; i ++) {
            for(int j = 0; j <= 127; j ++) {
                a[i][j] = p[i ^ j];
            }
        }
    }

    Matrix operator*(const Matrix b) {
        Matrix res;
        for (int i = 0; i <= 127; i++)
            for (int j = 0; j <= 127; j++)
                for (int u = 0; u <= 127; u++)
                    res.a[i][j] = (res.a[i][j] + a[i][u]*b.a[u][j]);
        return res;
    }
};

double q_pow(long long n){
    Matrix ans,base;
    ans.init();
    base.init();
    //这里要填矩阵值
    while(n > 0){
        if(n&1) ans =ans *base;
        base = base *base;
        n >>= 1;
    }
    return ans.a[0][0];
}
int main()
{
    int n, x; cin >> n >> x;
    //vector dp(n + 10, vector<double>(x + 30));
    for(int i = 0; i <= x; i ++) {
        cin >> p[i];
    }
    cout << point(15) <<  1 - q_pow(n - 1) << endl;
    // dp[0][0] = 1;
    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 0; j <= x + 27; j ++) {
    //         for(int k = 0; k <= x; k ++) {
    //             dp[i][j] += dp[i - 1][j ^ k] * p[k];
    //         }
    //     }
    // }
    // cout << point(15) << 1 - dp[n][0] << endl;
    return 0;
}
