#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using rbtree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int i64

void solve() {
    int n;
    cin >> n;
    vec<int> a(n);
    for (auto &i : a) cin >> i;

    vec<int> p(n);
    iota(p.begin(), p.end(), 0);
    ranges::stable_sort(p, greater{}, [&](auto x) { return a[x]; });

    int q;
    cin >> q;
    vec<int> ans(q);
    vec2<pair<int, int>> qs(n);
    for (int i = 0; i < q; i++) {
        int l, p;
        cin >> l >> p;
        l--;
        qs[l].push_back({p, i});
    }

    rbtree<pair<int, int>> seq;
    for (int i = 0; i < n; i++) {
        seq.insert({p[i], a[p[i]]});
        for (auto &[pos, id] : qs[i]) {
            ans[id] = seq.find_by_order(pos - 1)->second;
        }
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
