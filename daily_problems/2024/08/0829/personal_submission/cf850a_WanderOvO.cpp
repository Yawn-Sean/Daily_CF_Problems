/*
锐角要求 arccos(内积/长度积) < pi / 2
所以 内积 / 长度积 > 0
长度积一定是 > 0 的，所以看的就是内积的符号
考虑所有以 i 点为起点的向量，应该有 n 个，我们把 i 当成原点，就相当于从原点出去很多向量
只要夹角最小的两个向量的角度是锐角，就寄了，但是似乎并不容易去找哪两个向量的夹角最小
根据羊神的提示，我们可以发现向量超过一定数量，就肯定会有夹角为锐角的情况，这个数量和维度有关系
事实上我们可以发现一个上界就是 2k
由于以某个点 p 为起点的向量有 n - 1 个，所以如果 n - 1 > 2k，则肯定有为锐角的情况
如果 n - 1 <= 2k，则可以 n^3 暴力枚举向量
*/

int T;
int points[N][M], n;
int vecs[N][M];

int mult(int p1[], int p2[]) {
    int res = 0;
    for (int i = 1; i <= 5; i++) {
        res += p1[i] * p2[i];
    }
    return res;
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> points[i][j];
        }
    }

    if (n - 1 > 10) {
        cout << "0\n";
        return;
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j != i) {
                for (int k = 1; k <= 5; k++) {
                    vecs[j][k] = points[j][k] - points[i][k];
                }
            }
        }
        bool ok = true;
        for (int j = 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (k == i || j == i) continue;
                int prod = mult(vecs[j], vecs[k]);
                if (prod > 0) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) {
            res.pb(i);
        }
    }
    cout << res.size() << "\n";
    for (auto id : res) {
        cout << id << "\n";
    }
}   
