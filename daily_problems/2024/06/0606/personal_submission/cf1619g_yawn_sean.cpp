#include <bits/stdc++.h>
using namespace std;

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    bool merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return false;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return true;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t --) {
        int n, k;
        cin >> n >> k;
        vector<int> xs(n), ys(n), ts(n);
        map<int, vector<int>> dx, dy;

        for (int i = 0; i < n; i ++) {
            cin >> xs[i] >> ys[i] >> ts[i];
            dx[xs[i]].push_back(i);
            dy[ys[i]].push_back(i);
        }

        dsu unionfind(n);
        for (auto &[_, v]: dx) {
            sort(v.begin(), v.end(), [&](int i, int j) {return ys[i] < ys[j];});
            int x = v.size();
            for (int i = 1; i < x; i ++) {
                if (ys[v[i]] - ys[v[i-1]] <= k)
                    unionfind.merge(v[i-1], v[i]);
            }
        }
        
        for (auto &[_, v]: dy) {
            sort(v.begin(), v.end(), [&](int i, int j) {return xs[i] < xs[j];});
            int x = v.size();
            for (int i = 1; i < x; i ++) {
                if (xs[v[i]] - xs[v[i-1]] <= k)
                    unionfind.merge(v[i-1], v[i]);
            }
        }

        map<int, int> min_time;
        for (int i = 0; i < n; i ++) {
            int p = unionfind.leader(i);
            if (min_time.find(p) == min_time.end() || min_time[p] > ts[i])
                min_time[p] = ts[i];
        }

        vector<int> answers;
        for (auto &[_, v]: min_time)
            answers.push_back(v);
        
        sort(answers.begin(), answers.end());
        int x = answers.size(), ans = x - 1;

        for (int i = 0; i < x; i ++)
            ans = min(ans, max(answers[i], x - 2 - i));
        cout << ans << '\n';
    }

    return 0;
}