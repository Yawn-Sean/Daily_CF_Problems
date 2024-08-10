/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-04 17:16 */
/* Software : Visual Studio Code    */
/*----------------------------------*/

const int N = 212345;

int a[N], n;
int pin, p[N], col[N];
map<int, int> mp;
int ne[N], fr[N];

struct Node {
    int l, r;
    int maxa, maxi;
} tr[N << 2];

void pushup(int u) {
    if (tr[u << 1].maxa >= tr[u << 1 | 1].maxa) {
        tr[u].maxi = tr[u << 1].maxi;
    } else {
        tr[u].maxi = tr[u << 1 | 1].maxi;
    }
    tr[u].maxa = max(tr[u << 1].maxa, tr[u << 1 | 1].maxa);
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].maxa = p[l];
        tr[u].maxi = l;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

struct P {
    int maxa;
    int maxi;
};

void modify(int u, int pos, int x) {
    if (tr[u].l == tr[u].r) {
        tr[u].maxa = x;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (pos <= mid) modify(u << 1, pos, x);
    else modify(u << 1 | 1, pos, x);
    pushup(u);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) {
        if (mp[a[i]] == 0) mp[a[i]] = i;
        int sum = 0;
        int k = a[i];
        for (int j = i; j <= n + 1; j ++) {
            if (a[j] - k) {
                i = j - 1;
                break;
            }
            sum ++;
        }
        p[++ pin] = sum;
        col[pin] = mp[k];
    }
    build(1, 1, pin);
    for (int i = 1; i <= pin; i ++) {
        ne[i] = i + 1;
        fr[i] = i - 1;
    }
    ne[n] = 0;
    int ans = 0;
    while (tr[1].maxa) {
        ans ++;
        int now = tr[1].maxi;
        if (fr[now]) ne[fr[now]] = ne[now];
        if (ne[now]) fr[ne[now]] = fr[now];
        if (col[fr[now]] == col[ne[now]]) {
            int sl = fr[now], sr = ne[now];
            modify(1, tr[1].maxi, 0);
            modify(1, sl, p[sl] + p[sr]);
            modify(1, sr, 0);
            p[sl] += p[sr];
            ne[sl] = ne[sr];
            fr[ne[sl]] = sl;
        } else {
            modify(1, tr[1].maxi, 0);
        }
    }
    cout << ans << endl;
    return 0;
}

/*

*/
