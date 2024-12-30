// https://codeforces.com/contest/960/submission/261224108
int n, m, x, d;
void sol()
{
    cin >> x >> d;
    vector<LL> res;
    LL head, tail, ele = 1 - d;
    while (x > 0) {
        head = 1, tail = 1e9;
        ele += d;
        while (head < tail) {
            LL mid = head + tail + 1>> 1;
            if (pow(2, mid) - 1 <= x) head = mid;
            else tail = mid - 1;
        }
        x -= (pow(2, head) - 1);
        for (int i = 1; i <= head; i++)
            res.push_back(ele);
    }
    cout << res.size() << '\n';
    for (auto &e : res) cout << e << ' ';
    cout << '\n';
}
