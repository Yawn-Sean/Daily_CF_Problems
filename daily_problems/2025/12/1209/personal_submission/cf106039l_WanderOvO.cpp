/*
当前位置的下一个状态，是由自己以及周围 8 个元素共同决定的
当前是 0:
- 周围是奇数(1)，则下个状态是 1
- 周围是偶数(0)，则下个状态是 0
当前是 1:
- 周围是奇数(1)，则下个状态是 0
- 周围是偶数(0)，则下个状态是 1
所以相当于把这 9 个数加起来，新状态就是 % 2 的结果
这是线性组合，所以考虑快速幂加速
对于 (i, j)，假如其是 0 或者 1，就把周围 9 个位置的贡献系数都设成 1
假如是 #，则贡献系数全都是 0 就好了，并且，初始状态也要设为 0
*/

const int N = 9;
const int M = 70;

LL transition[M][M], cur[M];
LL n, k;
string grid[N];
int dx[10] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[10] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

int get_id(int i, int j) {
    return (i - 1) * n + j;
}

void mat_mul(LL a[][M], LL b[][M]) {
    LL res[M][M] = {{0}};
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < M; j++) {
            for (int k = 1; k < M; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= 2;
        }
    }
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < M; j++) {
            a[i][j] = res[i][j];
        }
    }
}

void qpow(LL a[][M], LL b) {
    LL res[M][M] = {{0}};
    for (int i = 1; i < M; i++) {
        res[i][i] = 1;
    }
    
    LL base[M][M];
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < M; j++) {
            base[i][j] = a[i][j];
        }
    }
    
    while (b) {
        if (b & 1) {
            mat_mul(res, base);
        }
        mat_mul(base, base);
        b >>= 1;
    }
    
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < M; j++) {
            a[i][j] = res[i][j] % 2;
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }
    
    auto ok = [&] (int i, int j) -> bool {
        return (i > 0 && i <= n && j > 0 && j <= n);  
    };
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (isdigit(grid[i][j])) {
                cur[get_id(i, j)] = grid[i][j] - '0';
                for (int k = 0; k < 9; k++) {
                    int xx = dx[k] + i, yy = dy[k] + j;
                    if (ok(xx, yy)) {
                        transition[get_id(i, j)][get_id(xx, yy)] = 1;
                    }
                }
            } else {
                cur[get_id(i, j)] = 0;
            }
        }
    }
    
    qpow(transition, k);
    
    LL res[M] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int r = get_id(i, j);
            for (int c = 1; c <= n * n; c++) {
                res[r] += transition[r][c] * cur[c];
            }
            res[r] %= 2;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] == '#') {
                cout << "#";
            } else {
                cout << res[get_id(i, j)];
            }
        }
        cout << "\n";
    }
}
