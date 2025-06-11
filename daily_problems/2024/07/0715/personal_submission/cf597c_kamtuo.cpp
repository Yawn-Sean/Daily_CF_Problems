/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-15 17:27 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 123456, M = 12;

int n, k;
LL tr[N][M];
int a[N];
LL ans;

int lowbit(int x) {
    return x & -x;
}

void add(int now, int idx, LL x) {
    for (int i = now; i <= n; i += lowbit(i)) tr[i][idx] += x;
}

LL query(int now, int idx) {
    LL res = 0;
    for (int i = now; i; i -= lowbit(i)) res += tr[i][idx];
    return res;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        add(a[i], 1, 1);
        for (int j = 1; j <= k; j ++) {
            add(a[i], j + 1, query(a[i] - 1, j));
        }
    }
    cout << query(n, k + 1) << endl;
    return 0;
}

/*

*/
