#include <bits/stdc++.h>
 
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned int;
 
using i128 = __int128;
using u128 = unsigned __int128;

std::ifstream is("input.txt");
std::ofstream os("output.txt");

template <typename Info, typename Tag>
class SegmentTree {
public:
    // 构造空的线段树.
    SegmentTree() : n(0), info(), tag() {}

    // 用支持下标访问的容器构造线段树.
    template <typename Container>
    SegmentTree(const Container &values) : n(values.size()), info(4 * n, Info()), tag(4 * n, Tag()) {
        if (n >= 1) {
            build(0, 0, n - 1, values);
        }
    }

    // 对区间 [ql, qr] 的信息按照修改标记 t 进行修改. 如果区间不合法则不进行任何操作.
    void modify(int ql, int qr, const Tag &t) {
        if (ql < 0 || qr > n - 1 || ql > qr) {
            return;
        }
        modify(0, ql, qr, t);
    }

    // 查询区间 [ql, qr] 的信息. 如果区间不合法返回无效 Info, 否则返回有效的 Info 表示结果.
    Info query(int ql, int qr) {
        if (ql < 0 || qr > n - 1 || ql > qr) {
            return Info();
        }
        return query(0, ql, qr);
    }

    // 查找区间 [ql, qr] 中第一个满足 p 的元素的位置, 如果不存在返回 -1. 
    // p 是一个一元谓词, 传入一个 Info 返回一个 bool, 表示该 Info 对应的区间中是否存在满足 p 的元素.
    // p 应满足: 对于完全在 [ql, qr] 中的 Info 对象 a 和 b, 有 p(a + b) == p(a) || p(b).
    template <typename UnaryPredicate>
    int find_first(int ql, int qr, UnaryPredicate p) {
        if (ql < 0 || qr > n - 1 || ql > qr) {
            return -1;
        }
        return find_first(0, ql, qr, p);
    }

    // 查找区间 [ql, qr] 中最后一个满足 p 的元素的位置, 如果不存在返回 -1. 
    // p 是一个一元谓词, 传入一个 Info 返回一个 bool, 表示该 Info 对应的区间中是否存在满足 p 的元素.
    // p 应满足: 对于完全在 [ql, qr] 中的 Info 对象 a 和 b, 有 p(a + b) == p(a) || p(b).
    template <typename UnaryPredicate>
    int find_last(int ql, int qr, UnaryPredicate p) {
        if (ql < 0 || qr > n - 1 || ql > qr) {
            return -1;
        }
        return find_last(0, ql, qr, p);
    }

    // 线段树的大小, 即元素个数.
    int size() const {
        return n;
    }
    
private:
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;

    template <typename Container>
    void build(int i, int l, int r, const Container &values) {
        if (l == r) {
            info[i] = Info(l, values[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i + 1, l, mid, values);
        build(2 * i + 2, mid + 1, r, values);
        info[i] = info[2 * i + 1] + info[2 * i + 2];
    }

    void push_down(int i) {
        info[2 * i + 1].apply(tag[i]);
        tag[2 * i + 1].apply(tag[i]);
        info[2 * i + 2].apply(tag[i]);
        tag[2 * i + 2].apply(tag[i]);
        tag[i].status = false;
    }

    void modify(int i, int ql, int qr, const Tag &t) {
        int l = info[i].l;
        int r = info[i].r;
        if (ql <= l && r <= qr) {
            info[i].apply(t);
            tag[i].apply(t);
            return;
        }
        push_down(i);
        int mid = (l + r) / 2;
        if (ql <= mid) {
            modify(2 * i + 1, ql, qr, t);
        }
        if (qr >= mid + 1) {
            modify(2 * i + 2, ql, qr, t);
        }
        info[i] = info[2 * i + 1] + info[2 * i + 2];
    }

    Info query(int i, int ql, int qr) {
        int l = info[i].l;
        int r = info[i].r;
        if (ql <= l && r <= qr) {
            return info[i];
        }
        push_down(i);
        int mid = (l + r) / 2;
        if (ql <= mid && qr >= mid + 1) {
            return query(2 * i + 1, ql, qr) + query(2 * i + 2, ql, qr);
        } else if (ql <= mid) {
            return query(2 * i + 1, ql, qr);
        } else {
            // qr >= ql >= mid + 1
            return query(2 * i + 2, ql, qr);
        }
    }

    template <typename UnaryPredicate>
    int find_first(int i, int ql, int qr, UnaryPredicate p) {
        int l = info[i].l;
        int r = info[i].r;
        if (ql <= l && r <= qr) {
            if (!p(info[i])) {
                return -1;
            } else if (l == r) {
                return l;
            }
        }
        push_down(i);
        int mid = (l + r) / 2;
        if (ql <= mid) {
            int res = find_first(2 * i + 1, ql, qr, p);
            if (res != -1) {
                return res;
            }
        }
        if (qr >= mid + 1) {
            int res = find_first(2 * i + 2, ql, qr, p);
            if (res != -1) {
                return res;
            }
        }
        return -1;
    }

    template <typename UnaryPredicate>
    int find_last(int i, int ql, int qr, UnaryPredicate p) {
        int l = info[i].l;
        int r = info[i].r;
        if (ql <= l && r <= qr) {
            if (!p(info[i])) {
                return -1;
            } else if (l == r) {
                return l;
            }
        }
        push_down(i);
        int mid = (l + r) / 2;
        if (qr >= mid + 1) {
            int res = find_last(2 * i + 2, ql, qr, p);
            if (res != -1) {
                return res;
            }
        }
        if (ql <= mid) {
            int res = find_last(2 * i + 1, ql, qr, p);
            if (res != -1) {
                return res;
            }
        }
        return -1;
    }
};

class Tag {
public:
    bool status;
    i64 v;

    Tag() : status(false) {}

    Tag(i64 v_) : status(true), v(v_) {}

    void apply(const Tag &t) {
        if (!t.status) {
            return;
        }
        if (!status) {
            *this = t;
            return;
        }
        v = std::max(v, t.v);
    }
};

class Info {
public:
    int l;
    int r;
    i64 max;

    Info() : l(-1), r(-1) {}

    Info(int pos, i64 value) : l(pos), r(pos), max(value) {}

    void apply(const Tag &t) {
        if (!t.status) {
            return;
        }
        max = std::max(max, t.v);
    }

    friend Info operator+(const Info &a, const Info &b) {
        Info res;
        res.l = a.l;
        res.r = b.r;
        res.max = std::max(a.max, b.max);
        return res;
    }
};

void solve() {
    int n;
    is >> n;

    std::vector<int> h(n, 0), l(n, 0), r(n, 0), v;
    for (int i = 0; i < n; ++i) {
        is >> h[i] >> l[i] >> r[i];
        v.push_back(l[i]);
        v.push_back(r[i]);
    }

    std::stable_sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    int s = v.size();
    
    SegmentTree<Info, Tag> st(std::vector<int>(v.size(), 0));
    for (int i = 0; i < n; ++i) {
        int l_ = std::lower_bound(v.begin(), v.end(), l[i]) - v.begin();
        int r_ = std::lower_bound(v.begin(), v.end(), r[i]) - v.begin();
        st.modify(l_, r_ - 1, h[i]);
    }

    std::vector<std::pair<int, int>> ans;
    int now_h = 0;
    for (int i = 0; i < s; ++i) {
        int next_h = st.query(i, i).max;
        if (next_h != now_h) {
            ans.emplace_back(v[i], now_h);
            ans.emplace_back(v[i], next_h);
            now_h = next_h;
        }
    }

    os << ans.size() << "\n";
    for (auto [x, y] : ans) {
        os << x << " " << y << "\n";
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t = 1;
    // is >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
