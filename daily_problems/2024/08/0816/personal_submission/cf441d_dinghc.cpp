#include <bits/stdc++.h>

using namespace std;
constexpr int N = 3'000;
int p[N+1];
int reps[N+1];
int vis[N+1];

int traverse(int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i] == 1) continue;
        reps[i] = 1;
        int q = p[i];
        while (q != i) {
            vis[q] = 1;
            q = p[q];
        }
        vis[i] = 1;
        res++;
    }
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    int m;
    scanf("%d", &m);
    m = n - m;
    int c = traverse(n);
    int k = abs(c - m);
    printf("%d\n", k);
    if (c > m) { // merge
        for (int i = 1; i < n && k > 0; i++) {
            if (reps[i] == 1) {
                printf("%d %d ", 1, i + 1);
                k--;
            }
        }
    } else { // breakdown
		for (int i = 0; i < n && k > 0; ++i) {
			vector<int> pos(n, -1);
			int cur = 0;
			for (int j = p[i]; j != i; j = p[j])
				pos[j] = cur++;
			pos[i] = cur;
			cur = 0;
			for (int j = i + 1; j < n && k > 0; ++j)
				if (pos[j] >= cur) {
					printf("%d %d ", i + 1, j + 1);
					k--;
					cur = pos[j] + 1;
					swap(p[i], p[j]);
				}
		}
    }
    return 0;
}

