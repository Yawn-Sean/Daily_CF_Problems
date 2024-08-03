// https://codeforces.com/contest/830/submission/256499981
int n, t, m, x;
int a[MAXN];
vector<int> v2i[MAXN];

class Fenwick {
public:
    Fenwick(int _n) : a (vector<int>(_n + 1)), size(_n) {}

    void add(int pos, int val) {
        for (int i = pos; i <= size; i += i & -i)
            a[i] += val;
    }
    int query(int pos) {
        int res = 0;
        while (pos > 0) {
            res += a[pos];
            pos -= (pos & -pos);
        }
        return res;
    }
private:
    vector<int> a;
    int size;
};

void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v2i[a[i]].push_back(i);
    }

    Fenwick ft(n);
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        ft.add(i, 1);
    }
    int last_pos = 0;
    for (int i = 1; i < MAXN; i++) {
        if (!v2i[i].empty()) {
            //cout << "i: " << i << '\n';
            auto &v = v2i[i];

            auto it = upper_bound(v.begin(), v.end(), last_pos);
            int idx;
            if (it == v.end()) idx = 0;
            else idx = it - v.begin();

            int cnt = 0, pos;
            // printf("i: %d, pos: ", i);
            while (cnt++ < v.size()) {
                pos = v[idx];
                // printf("%d ", pos);
                if (pos > last_pos) {
                    res += (ft.query(pos) - ft.query(last_pos));
                } else {
                    // printf("last_pos: %d, pos: %d\n", last_pos, pos);
                    res += (ft.query(n) - ft.query(last_pos) + ft.query(pos));
                }
                ft.add(pos, -1);
                last_pos = pos;
                idx = (idx + 1) % v.size();
            }
            // puts("");
        }
    }
    cout << res << '\n';
}
