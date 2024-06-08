// https://codeforces.com/contest/1461/submission/264600640
int n, m, k, q;
LL a[MAXN], pre[MAXN];
unordered_map<LL, int> exist;
void split(int l, int r) {
    exist[pre[r] - pre[l - 1]] = 1;
    LL maxv = a[r], minv = a[l];
    if (maxv == minv) {
        return ;
    }
    LL midv = (maxv + minv) / 2;
    int head = l, tail = r;
    while (head < tail) {
        // cout << head << ", " << tail << '\n';
        int mid = head + tail >> 1;
        if (a[mid] > midv) tail = mid;
        else head = mid + 1;
    }
    split(l, head - 1);
    split(head, r);
}
void sol()
{
    cin >> n >> q;
    exist.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        // pre[i] = pre[i - 1] + a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i];
    split(1, n);
    LL s;
    for (int i = 1; i <= q; i++) {
        cin >> s;
        if (exist[s] == 1) cout << "Yes\n";
        else cout << "No\n"; 
    }
}
