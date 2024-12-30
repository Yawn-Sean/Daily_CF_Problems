/*
OPT 页面置换算法
*/

int T;
LL n, k, a[N];
vector<int> positions[N];
set<int> cur_books;
map<int, int> position_to_book;

void solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        positions[a[i]].pb(i);
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!cur_books.count(a[i])) {
            res++;
            if (cur_books.size() < k) {
                cur_books.insert(a[i]);
            } else {
                auto max_book = *prev(position_to_book.end());
                int id = max_book.y, pos = max_book.x;
                position_to_book.erase(pos);
                cur_books.erase(id);
                cur_books.insert(a[i]);
            }
        }
        auto it = upper_bound(positions[a[i]].begin(), positions[a[i]].end(), i);
        if (it == positions[a[i]].end()) {
            cur_books.erase(a[i]);
            position_to_book.erase(i);
        } else {
            position_to_book.erase(i);
            int pos = *it;
            position_to_book[pos] = a[i];
        }
    }
    cout << res << "\n";
}               