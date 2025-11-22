#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <random>
#include <ctime>
#include <cmath>

class FenwickTree {
private:
    std::vector<int> tree;
    int size;

public:
    FenwickTree(int n) : size(n) {
        tree.assign(n + 1, 0); 
    }

    void add(int i, int delta) {
        i += 1; 
        while (i <= size) {
            tree[i] += delta;
            i += i & (-i);
        }
    }

    int query(int i) {
        i += 1; 
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }

    int rsum(int l, int r) {
        if (l > r) return 0;
        return query(r) - ((l > 0) ? query(l - 1) : 0);
    }
};

void solve() {
    long long t;
    if (!(std::cin >> t)) return;

    std::vector<long long> outs;
    std::mt19937_64 rng(static_cast<unsigned long long>(std::time(0)));
    long long rnd = rng() & ((1LL << 30) - 1);

    for (int _ = 0; _ < t; ++_) {
        int n;
        if (!(std::cin >> n)) break;

        std::vector<long long> v1(n);
        for (int i = 0; i < n; ++i) {
            long long x;
            std::cin >> x;
            v1[i] = x ^ rnd;
        }

        std::vector<long long> v2(n);
        for (int i = 0; i < n; ++i) {
            long long x;
            std::cin >> x;
            v2[i] = x ^ rnd;
        }

        long long ans = 0;
        FenwickTree fen(n);
        std::unordered_map<long long, std::list<int>> cur_status;
        std::unordered_map<long long, int> last_pos;

        for (int i = 0; i < n; ++i) {
            last_pos[v2[i]] = i;

            int start = 0;
            if (last_pos.count(v1[i])) {
                start = last_pos[v1[i]] + 1;
            }

            cur_status[v1[i]].push_back(i);

            while (!cur_status[v2[i]].empty()) {
                int idx = cur_status[v2[i]].back();
                cur_status[v2[i]].pop_back();
                fen.add(idx, 1);
            }

            ans += fen.rsum(start, i);
        }
        outs.push_back(ans);
    }

    for (size_t i = 0; i < outs.size(); ++i) {
        std::cout << outs[i] << (i == outs.size() - 1 ? "" : "\n");
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();

    return 0;
}
