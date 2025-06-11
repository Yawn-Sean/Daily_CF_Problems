// https://codeforces.com/contest/725/submission/265363491
using PLL = pair<LL, LL>;
int n, m, k;
vector<array<LL, 3>> vec;
void sol()
{
    cin >> n;
    LL t, w;
    for (int i = 1; i <= n; i++) {
        cin >> t >> w;
        vec.push_back({t, w, i});
    }
    t = vec[0][0], w = vec[0][1];
    sort(vec.begin(), vec.end(), [&](auto &a, auto &b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        } else {
            return a[1] - a[0] > b[1] - b[0];
        }
    });   
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    LL rank = 1, cut = -1, skip = -1;
    for (int i = n - 1; i >= 0; i--) {
        auto &e = vec[i];
        if (e[0] > t) {
            // 可以飞走
            if (t >= e[1] - e[0] + 1)
                pq.push(e[1] - e[0] + 1);
            rank++;
        } else if (e[0] == t) {
            if (cut == -1)
                cut = i;
            if (e[2] == 1) 
                skip = i;
        } else break;
    }
    LL res = rank;
    while (!pq.empty() && t >= pq.top()) {
        auto tmp = pq.top();
        pq.pop();
        t -= tmp;
        rank--;
        while (cut >= 0) {
            if (cut == skip) {
                cut--;
                continue;
            }
            if (vec[cut][0] > t) {
                pq.push(vec[cut][1] - vec[cut][0] + 1);
                rank++;
                cut--;
            } else {
                break;
            }
        }
        res = min(res, rank);
    }
    cout << res << "\n";
}
