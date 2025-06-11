/*
理论上的 mex 的最小值的最大值为最短的区间的长度（包括左右端点），这个上界是显然的
能否/如何达到这个上界？
假设最短区间是 len，我们考虑让每个为 len 的区间都充满这些数
*/

int T;
int n, m, l[N], r[N];

void solve1() {
    cin >> n >> m;
    int minlen = n;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        minlen = min(minlen, r[i] - l[i] + 1);
    }
    cout << minlen << "\n";
    int val = 0;
    for (int i = 1; i <= n; i++, val++) {
        val %= minlen;
        cout << val << " ";
    }
}                                                                                                                  