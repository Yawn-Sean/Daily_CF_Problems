#include <iostream>
#include <vector>

using namespace std;
using pii = pair<int, int>;

bool parallel(const pii& x, const pii& y) {
    return x.first * y.second == x.second * y.first;
}

pii vec(int sx, int sy, int dx, int dy) {
    return make_pair(dx - sx, dy - sy);
}

bool helper(vector<int>& vc, int f, int s) {
    vector<int> spec;
    pii cur = vec(f, vc[f - 1], s, vc[s - 1]);
    for (int i = 0; i < vc.size(); ++i) {
        pii t1 = vec(f, vc[f - 1], i + 1, vc[i]);
        if (!parallel(t1, cur)) {
            spec.push_back(i);
        }
    }
    if (spec.size() <= 1) {
        return spec.size();
    } else {
        bool flag = true;
        for (int i = 1; i < spec.size(); ++i) {
            pii tmp = vec(spec[i - 1] + 1, vc[spec[i - 1]], 
                spec[i] + 1, vc[spec[i]]);
            if (!parallel(tmp, cur)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }
    return false;
}

// 考虑前三个点 a b c
// ab ac bc总有一组是在一条直线上的，枚举验证即可

void solve() {
    int n; 
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; ++i) {
        cin >> vc[i];
    }
    
    if (helper(vc, 1, 2) || helper(vc, 1, 3) || helper(vc, 2, 3)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    solve();
    return 0;
}
