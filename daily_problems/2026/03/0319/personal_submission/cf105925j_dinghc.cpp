#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int N = 2e5;
int a[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n * 2; i++) {
        int64 cur = a[i % n] - 1LL * i * k;
        while (!st.empty() && cur < a[st.top() % n] - 1LL * st.top() * k) {
            ans[st.top() % n] = i % n;
            st.pop();
        }
        if (i < n) st.push(i);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}

