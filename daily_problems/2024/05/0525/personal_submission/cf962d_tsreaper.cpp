#include <bits/stdc++.h>
#define MAXN 150000
using namespace std;
typedef pair<long long, int> pli;
typedef pair<int, long long> pil;

int main() {
    int n; scanf("%d", &n);
    set<pli> st;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        st.insert(pli(x, i));
    }
    set<pil> ans;

    while (st.size() >= 2) {
        long long x = st.begin()->first;
        long long y = next(st.begin())->first;
        if (x != y) {
            ans.insert(pil(st.begin()->second, x));
            st.erase(st.begin());
            continue;
        }
        st.erase(st.begin());
        int pos = st.begin()->second;
        st.erase(st.begin());
        st.insert(pli(x * 2, pos));
    }

    for (pli p : st) ans.insert(pil(p.second, p.first));
    printf("%d\n", ans.size());
    for (pil p : ans) printf("%lld ", p.second);
    printf("\n");
    return 0;
}
