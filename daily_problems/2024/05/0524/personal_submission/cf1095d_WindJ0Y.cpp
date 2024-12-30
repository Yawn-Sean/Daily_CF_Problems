#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;
    
    if (n == 3) {
        cout << "1 2 3\n";
        return;
    }

    vector<int> lson(n + 1), rson(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> lson[i] >> rson[i];
    }

    auto hasson = [&](int f, int s) {
        return ((lson[f] == s) || (rson[f] == s));
    };

    int nowid = 1;
    for (int i = 0; i < n; i ++) {
        cout << nowid << " ";
        if (hasson(lson[nowid], rson[nowid])) {
            nowid = lson[nowid];
        } else {
            nowid = rson[nowid];
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}