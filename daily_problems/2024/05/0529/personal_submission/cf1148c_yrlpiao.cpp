#include <iostream>
#include <vector>
using namespace std;

void yrlpSolve() {
    int n; cin >> n;
    vector<int> p(n + 1), ind(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i]; 
        ind[p[i]] = i;
    }
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) continue;
        int id = ind[i];
        if (abs(i - ind[i]) >= n / 2) {
            v.push_back({i, id});
        } else {
            if (i * 2 <= n) {
                if (ind[i] * 2 > n) { //左右
                    v.push_back({1, id});
                    v.push_back({1, n});
                    v.push_back({i, n});
                    v.push_back({1, n});
                    v.push_back({1, id});
                } else { //直接右
                    v.push_back({id, n});
                    v.push_back({i, n});
                    v.push_back({id, n});
                }
            } else {
                //直接左
                v.push_back({1, id});
                v.push_back({1, i});
                v.push_back({1, id});
            }
        }
        ind[p[i]] = id;
        p[id] = p[i];
    }
    cout << v.size() << endl;
    for (auto x : v) {
        cout << x.first << " " << x.second << endl;
    }
    return; 
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
