/*
如果删除之后某个人连续出价了，分别为 p1 和 p2, p1 < p2
如果这个人最后赢了，那就是 p1，否则，最大值肯定比 p2 还大
因此，我们考虑维护所有人出价的最大值，以及出价列表
删除人之后，剩下的人里面最大值最大的就是赢家，但是至于具体出多少钱，还得看次大的
赢家应该刚好比次大的人大，这可以二分
*/

int T;
map<int, int> mx;
map<int, int> mx_id;
vector<int> p[N];
int n, q;

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int id, price;
        cin >> id >> price;
        p[id].pb(price);
        mx[id] = price;
    }
    for (int i = 1; i <= n; i++) {
        if (p[i].size() > 0) {
            mx_id[p[i].back()] = i;
        }
    }
    
    cin >> q;
    while (q--) {
        vector<int> deleted;
        int id, cnt;
        cin >> cnt;
        for (int i = 1; i <= cnt; i++) {
            cin >> id;
            deleted.pb(id);
            int mx_price;
            if (mx.count(id)) {
                mx_price = mx[id];
            } else {
                mx_price = 0;
            }
            mx.erase(id);
            mx_id.erase(mx_price);
        }
        
        if (mx_id.size() == 0) {
            cout << "0 0\n";
        } else {
            auto it = prev(mx_id.end());
            int winner = it->y;
            // cout << winner << "\n";
            int win_price;
            if (it == mx_id.begin()) {
                win_price = p[winner][0];
            } else {
                auto it2 = prev(it);
                int pos = lower_bound(p[winner].begin(), p[winner].end(), it2->x) - p[winner].begin();
                win_price = p[winner][pos];
            }
            cout << winner << " " << win_price << "\n";
        }
        for (auto i : deleted) {
            if (p[i].size() > 0) {
                mx[i] = p[i].back();
                mx_id[mx[i]] = i;
            }
        } 
    }
}             