#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, d;
vector<pair<int, int>> edges;

int main() {
    scanf("%d%d", &n, &k);
    vector<vector<int>> queues(n, vector<int>());
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &d);
        queues[d].push_back(i);
    }

    if (queues[0].size() != 1) {
        printf("-1\n");
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        if (queues[i].size() > queues[i - 1].size() * k) {
            printf("-1\n");
            return 0;
        }
        for (int j = 0; j < queues[i].size(); ++j)
            edges.emplace_back(queues[i - 1][j / k], queues[i][j]);
        if (i == 1) --k;
    }

    printf("%d\n", edges.size());
    for (const auto edge: edges) printf("%d %d\n", edge.first, edge.second);
    return 0;
}