#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, W[MAXN + 5], H[MAXN + 5];
long long ans;

void gao(int h) {
    int rem = n / 2;
    long long sm = 0;
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        if (H[i] > h) {
            if (W[i] > h) return;
            sm += H[i];
            rem--;
        } else if (W[i] > h) {
            sm += W[i];
        } else {
            sm += W[i];
            vec.push_back(H[i] - W[i]);
        }
    }
    if (rem < 0) return;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < rem && i < vec.size(); i++) {
        if (vec[i] >= 0) break;
        sm += vec[i];
    }
    ans = min(ans, 1LL * h * sm);
}

int main() {
    scanf("%d", &n);
    unordered_set<int> st;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &W[i], &H[i]);
        st.insert(W[i]);
        st.insert(H[i]);
    }

    ans = 1e18;
    for (int h : st) gao(h);
    printf("%lld\n", ans);
    return 0;
}
