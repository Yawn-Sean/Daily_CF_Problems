#include <bits/stdc++.h>
using namespace std;

void work() {
    int va, vb;
    cin >> va >> vb;
    
    int tot_cnt = floor((sqrt(8ll * (va + vb) + 1) - 1) / 2);
    long long inner_v = 4ll * tot_cnt * tot_cnt + 4ll * tot_cnt + 1ll - 8ll * va;
    int alen = (inner_v >= 0 ? (tot_cnt + (1 - sqrt(inner_v)) / 2) : tot_cnt);
    int aext = inner_v >= 0 ? max(0ll, va - 1ll * alen * (2 * tot_cnt - alen + 1) / 2) : 0;
    
    cout << alen + (aext != 0) << "\n";
    for (int i = 0; i < alen; i++) {
        cout << tot_cnt - i << " ";
    }
    if (aext) {
        cout << aext << " ";
    }
    cout << "\n";
    
    cout << tot_cnt - alen - (aext != 0) << "\n";
    for (int i = 1; i <= tot_cnt - alen; i++) {
        if (i == aext) continue;
        cout << i << " ";
    }
    cout << "\n";
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