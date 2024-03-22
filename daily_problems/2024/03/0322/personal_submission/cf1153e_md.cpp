#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool debug = false;
vector<pair<int, int>> oracle;

int query(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int ret = 0;
    if (debug) {
        vector<pair<int, int>> tocheck{oracle[0], oracle.back()};
        for (auto& p : tocheck) {
            if (x1 <= p.first && p.first <= x2 && y1 <= p.second && p.second <= y2) {
                ++ret;
            }
        }   
    } else {
        cin >> ret;
    }

    return ret;
}

void answer(int x1, int y1, int x2, int y2) {
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (debug) {
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            oracle.push_back({x, y});
        }
    }

    auto check = [n](bool find_x) -> bool {
        vector<int> vals(n);
        iota(begin(vals), end(vals), 1);
        random_shuffle(begin(vals), end(vals));

        int val1 = -1, val2 = -1;
        int cval1 = -1, cval2 = -1;
        auto search = [n](int known_val, bool find_x) -> int {
            int start = 1;
            int end = n;
            while (start + 1 < end) {
                auto mid = start + (end - start) / 2;
                auto ret = 0;
                if (find_x) {
                    ret = query(1, known_val, mid, known_val);
                } else {
                    ret = query(known_val, 1, known_val, mid);
                }

                if (ret % 2 == 1) {
                    end = mid;
                } else {
                    start = mid ;
                }
            }

            if (find_x) {
                if (query(1, known_val, start, known_val) % 2 == 1) {
                    return start;
                } else {
                    return end;
                }
            } else {
                if (query(known_val, 1, known_val, start) % 2 == 1) {
                    return start;
                } else {
                    return end;
                }
            }
        };

        for (int i = 0; i < n - 1; ++i) {
            auto ret = 0;
            if (find_x) {
                ret = query(vals[i], 1, vals[i], n);
            } else {
                ret = query(1, vals[i], n, vals[i]);
            }
            if (ret % 2 == 1) {
                if (val1 == -1) {
                    val1 = vals[i];
                    cval1 = search(val1, !find_x);
                } else {
                    val2 = vals[i];
                    cval2 = search(val2, !find_x);
                    break;
                }
            }
        }

        if (val1 != -1 && val2 == -1) {
            val2 = vals.back();
            cval2 = search(val2, !find_x);
        }

        if (val1 == -1 && val2 == -1) {
            return false;
        }

        if (find_x) {
            answer(val1, cval1, val2, cval2);
        } else {
            answer(cval1, val1, cval2, val2);
        }
        return true;
    };

    bool find_x = true;
    if (check(find_x)) {
        return 0;
    }
    check(!find_x);
    return 0;
}