/*
灵神讲过的根号分治
对于 a[t + i * k] 的和
当 k 比较大时，没有几项要加，可以暴力枚举
当 k 比较小时，可以提前预处理出 k 较小时的后缀和
题目卡空间，考虑按照 k 从小到大排序，对于相同的 k，先预处理这个 k 的前缀和，然后回答
k 变化时重新预处理一下
*/

int T;  
LL s[N], a[N], n, m, res[N];
PIII queries[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> queries[i].x.y >> queries[i].x.x;
        queries[i].y = i;
    }
    sort(queries + 1, queries + m + 1);
    int last_k = 0;
    for (int i = 1; i <= m; i++) {
        int t = queries[i].x.y, k = queries[i].x.x, id = queries[i].y;
        if (k < M) {
            if (last_k != k) {
                for (int j = n; j > 0; j--) {
                    if (j + k <= n) {
                        s[j] = s[j + k] + a[j];
                    } else {
                        s[j] = a[j];
                    }
                }
                last_k = k;
            }
            res[id] = s[t];
        } else {
            res[id] = 0;
            for (int j = t; j <= n; j += k) {
                res[id] += a[j];
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << res[i] << "\n";
    }
}