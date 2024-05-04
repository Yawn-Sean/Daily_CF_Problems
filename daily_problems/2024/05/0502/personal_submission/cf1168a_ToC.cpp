// https://codeforces.com/contest/1168/submission/259372629
int n, m;
vector<int> a(MAXN);
bool check(int mid) {
    int last = 0;
    for (int i = 1; i <= n; i++) {
        int cur = a[i];
        if (cur < last) {
            if (last - cur <= mid) continue;
            else return false;
        } else if (cur > last) {
            if (m - 1 - cur + last + 1 <= mid) continue;
            else last = cur;
        }
    }
    return true;
}
void sol()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int head = 0, tail = m - 1;
    while (head < tail) {
        int mid = head + tail >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }
    cout << tail << '\n';
}
