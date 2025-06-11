// 0603
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;  
    vector<int> a(n);
    copy_n(istream_iterator<int>(std::cin), n, begin(a));

    map<int, int> appear_at;
    vector<int> future_use(n);
    for (int i = n - 1; i >= 0; --i) {
        future_use[i] = appear_at.contains(a[i]) ? appear_at[a[i]] : n;
        appear_at[a[i]] = i;
    }

    auto solve_by_pq = [&]() -> int {    
        priority_queue<pii> owned_books;
        set<int> owned;
        int ret = 0;
        int real_size = 0;
        for (int i = 0; i < n; ++i) {
            if (!owned.contains(a[i])) {
                ret++;
                if (!empty(owned_books) && real_size >= k) {
                    auto[_, book] = owned_books.top();
                    owned_books.pop();
                    owned.erase(book);
                } else {
                    ++real_size;
                }
            } 

            owned_books.push({future_use[i], a[i]});
            owned.insert(a[i]);
        }
        return ret;
    };

    auto solve_by_map = [&]() -> int {
        int ret = 0;
        map<int, vector<int>> owned_books;
        map<int, int> owned_future_use;
        for (int i = 0; i < n; ++i) {
            if (owned_future_use.contains(a[i])) {
                auto cur_val = owned_future_use[a[i]];
                owned_books[cur_val].erase(find(begin(owned_books[cur_val]), end(owned_books[cur_val]), a[i]));
                if (empty(owned_books[cur_val])) {
                    owned_books.erase(cur_val);
                }
                owned_future_use[a[i]] = future_use[i];
                owned_books[future_use[i]].push_back(a[i]);
                continue;
            }

            if (size(owned_future_use) >= k) {
                auto rit = rbegin(owned_books);            
                owned_future_use.erase(rit->second.back());
                rit->second.pop_back();
                if (empty(rit->second)) {
                    owned_books.erase(rit->first); 
                }
            } 

            owned_books[future_use[i]].push_back(a[i]);
            owned_future_use[a[i]] = future_use[i];
            ret++;
        }
        return ret;
    };

    cout << solve_by_pq() << endl;
    // cout << solve_by_map() << endl;
    return 0;
}