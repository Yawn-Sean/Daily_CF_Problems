/*----------------------------------*/
/* Author : KaMtuo                  */
/* Email : kamtuo@qq.com            */
/* Creation_time : 2024-07-02 17:34 */
/* Software : Visual Studio Code    */
/*----------------------------------*/
const int N = 212345;

int n, m;
int cnt[N];
LL ans;
int res[N];
vector<int> kk;

struct Node {
    int a, i;
} tr[N];

bool cmp(Node a, Node b) {
    return a.a % m < b.a % m;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> tr[i].a, tr[i].i = i, cnt[tr[i].a % m] ++;
    sort(tr + 1, tr + 1 + n, cmp);
    for (int i = n; i; i --) tr[i].a -= tr[i - 1].a;
    int l = 1;
    // for (int i = 1; i <= n; i ++) cout << tr[i].a << " \n"[i == n];
    for (int i = 0; i < m - 1; i ++) {
        if (cnt[i] > n / m) {
            tr[l + n / m].a += 1;
            cnt[(i + 1) % m] += cnt[i] - n / m;
            tr[l + cnt[i]].a -= 1;
            ans += (cnt[i] - n / m);
            l = l + n / m;
            cnt[i] = n / m;
        } else {
            l += cnt[i];
        }
    }
    for (int i = 0; i < m - 1; i ++) {
        if (cnt[i] < n / m) {
            for (int j = 1; j <= n / m - cnt[i]; j ++) kk.push_back(i), ans += ((i - m + 1ll) % m + m) % m;
        }
    }
    for (int i = 0; i < kk.size(); i ++) {
        int k = (kk[i] - m + 1) % m + m;
        k %= m;
        tr[n - i].a += k;
        tr[n - i + 1].a -= k;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i ++) tr[i].a += tr[i - 1].a, res[tr[i].i] = tr[i].a;
    for (int i = 1; i <= n; i ++) cout << res[i] << " \n"[i == n];
    return 0;
}

/*

*/
