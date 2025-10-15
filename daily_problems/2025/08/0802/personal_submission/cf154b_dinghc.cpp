#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
vector<int> lpf(N + 1, 0);
vector<int> pr;

auto init = [] {
    for (int i = 2; i <= N; ++i) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lpf[i * pr[j]] = pr[j];
            if (pr[j] == lpf[i]) break;
        }
    }
    return 0;
}();

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    map<int, set<int>> ps;
    set<int> on;
    for (int i = 0; i < m; i++) {
        char type;
        int seq;
        scanf("\n%c %d", &type, &seq);
        vector<int> fs;
        int x = seq;
        while (x > 1) {
            int p = lpf[x];
            fs.push_back(p);
            while (x % p == 0) {
                x /= p;
            }
        }
        if (type == '+') {
            if (on.find(seq) != on.end()) {
                printf("Already on\n");
                continue;
            }
            int conflictNum = 0;
            for (auto& p : fs) {
                auto ite = ps.find(p);
                if (ite != ps.end()) {
                    auto& ids = ite->second;
                    if (!ids.empty()) {
                        conflictNum = *ids.begin();
                        break;
                    }
                }
            }
            if (conflictNum) {
                printf("Conflict with %d\n", conflictNum);
            } else {
                for (auto& p : fs) {
                    ps[p].insert(seq);
                }
                on.insert(seq);
                printf("Success\n");
            }
        } else {
            if (on.find(seq) == on.end()) {
                printf("Already off\n");
                continue;
            }
            for (auto& p : fs) {
                auto ite = ps.find(p);
                if (ite != ps.end()) {
                    auto& ids = ite->second;
                    ids.erase(seq);
                }
            }
            on.erase(seq);
            printf("Success\n");
        }
    }
    return 0;
}

