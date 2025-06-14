#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n;
int Q;

int main() {
    scanf("%d%d", &n, &Q);
    vector<int> parent(n + 1);
    vector<vector<int>> children(n + 1);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &parent[i]);
        children[parent[i]].push_back(i);
    }

    vector<int> pointer(n + 1);
    vector<int> dfs_order(n + 1);
    vector<int> l(n + 1);
    vector<int> r(n + 1);
    stack<int> st;
    int order = 1;
    dfs_order[1] = 1;
    l[1] = 1;
    st.push(1);

    while (!st.empty()) {
        int u = st.top();
        if (pointer[u] < children[u].size()) {
            int v = children[u][pointer[u]++];
            dfs_order[++order] = v;
            l[v] = order;
            st.push(v);
        } else {
            r[u] = order;
            st.pop();
        }
    }
    while (Q--) {
        int u;
        int k;
        scanf("%d%d", &u, &k);
        printf("%d\n", (k > r[u] - l[u] + 1) ? -1 : dfs_order[l[u] + k - 1]);
    }
    return 0;
}