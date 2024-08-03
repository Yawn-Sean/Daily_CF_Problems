/*
计算出所有要翻转的区间
假如需要翻转 [left, right]，则 i 变成 left + right - i
注意到 left = min(x, l[i] + r[i] - x), right = max(x, l[i] + r[i] - x)
所以每次翻转都是在某个 [l[i], r[i]] 中进行的，且对称轴都是中间
每次把需要翻转的区间打一层标记，最后偶数层标记的不用变，奇数层标记的需要翻转
*/

int T;
int n, k, l[N], r[N], q, x;
int pre[N];
char s[N];

void solve1() {
    cin >> n >> k >> (s + 1);
    for (int i = 1; i <= k; i++) {
        cin >> l[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> r[i];
    }
    cin >> q;
    for (int i = 1; i <= n + 1; i++) {
        pre[i] = 0;
    }
    while (q--) {
        cin >> x;
        int i = upper_bound(l + 1, l + k + 1, x) - l - 1;
        int left = min(x, l[i] + r[i] - x), right = max(x, l[i] + r[i] - x);
        pre[left]++;
        pre[right + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1];
        if (pre[i] % 2 == 0) {
            cout << s[i];
        } else {
            int pos = upper_bound(l + 1, l + k + 1, i) - l - 1;
            cout << s[l[pos] + r[pos] - i];
        }
    }
    cout << "\n";
}               