#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

static const int MAXN = 101;
static const i64 MOD = 1000000007;

static i64 A[MAXN][MAXN], R[MAXN][MAXN], tmpA[MAXN][MAXN];

void matMult(i64 A[MAXN][MAXN], i64 B[MAXN][MAXN], int sz) {
    memset(tmpA, 0, sizeof(tmpA));
    for(int i = 0; i < sz; i++){
        for(int k = 0; k < sz; k++){
            i64 val = A[i][k];
            if(!val) continue;
            for(int j = 0; j < sz; j++){
                tmpA[i][j] = (tmpA[i][j] % MOD + val * B[k][j] % MOD) % MOD;
            }
        }
    }
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            A[i][j] = tmpA[i][j];
        }
    }
}

void matPow(i64 A[MAXN][MAXN], int sz, int exp){
    memset(R, 0, sizeof(R));
    for(int i = 0; i < sz; i++){
        R[i][i] = 1;
    }
    while(exp > 0){
        if(exp & 1){
            matMult(R, A, sz);
        }
        matMult(A, A, sz);
        exp >>= 1;
    }
    for(int i = 0; i < sz; i++){
        for(int j = 0; j < sz; j++){
            A[i][j] = R[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<i64> s(m), l(m);
    for(int i = 0; i < m; i++){
        cin >> s[i];
    }
    for(int i = 0; i < m; i++){
        cin >> l[i];
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            i64 val = s[i]*(s[j]+l[j]) + l[i]*s[j];
            A[i][j] = val % MOD;
        }
    }

    matPow(A, m, n);
    i64 ans = 0;
    for(int j = 0; j < m; j++){
        ans = (ans + A[0][j]) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
