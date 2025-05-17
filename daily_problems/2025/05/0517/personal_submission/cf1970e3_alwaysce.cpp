#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int inf= 1e9;

i64 mod = 1e9 + 7;

i64 A[2][2], R[2][2];
i64 tmp[2][2];

void mat_mul(i64 A[2][2], i64 B[2][2]) {
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            if (A[i][k] == 0) continue;

            for (int j = 0; j < 2; j++) {
                tmp[i][j] = (tmp[i][j] % mod + A[i][k] * B[k][j] % mod) % mod;
            }
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            A[i][j] = tmp[i][j] % mod;
        }
    }
}

void mat_pow(i64 A[2][2], int exp) {
    memset(R, 0, sizeof(R));
    for (int i = 0; i < 2; i++) {
        R[i][i] = 1;
    }
    while (exp) {
        if (exp&1) {
            mat_mul(R, A);
        }
        mat_mul(A, A);
        exp >>= 1;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            A[i][j] = R[i][j] % mod;
        }
    }
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<i64> s(m), l(m);

    i64 tot_s = 0, tot_l = 0;
    for (int i = 0; i < m; i++) {
        cin >> s[i];
        tot_s += s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> l[i];
        tot_l += l[i];
    }

    /*
        n和m更大了
        之前的矩阵ksm方法需要算一个m^2的矩阵 显然是不行的

        ndp[i] += A[j, i] * dp[j]

        在经过中间那个点的时候。要求前后两次不能都是长路。
        
        我们设状态为——到达中间点前一步是长路 / 短路
    */
    for (int i = 0; i < m; i++) {
        A[0][0] = ((A[0][0] + (l[i] + s[i]) * s[i]) % mod) % mod;
        A[0][1] = ((A[0][1] + (l[i] + s[i]) * l[i]) % mod) % mod;
        A[1][0] = ((A[1][0] + s[i] * s[i]) % mod) % mod;
        A[1][1] = ((A[1][1] + s[i] * l[i]) % mod) % mod;
    }

    mat_pow(A, n - 1);

    i64 ans = 0;
    ans += (s[0] * A[0][0] % mod + l[0] * A[1][0] % mod) % mod * (tot_s + tot_l) % mod;
    ans += (s[0] * A[0][1] % mod + l[0] * A[1][1] % mod) % mod * tot_s % mod;
    cout << ans % mod;
    return 0;
}
