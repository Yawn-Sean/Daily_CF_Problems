#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 5], B[MAXN + 5];

int pos[MAXN + 5];
vector<array<int, 3>> vec[MAXN + 5];

struct Magic {
    multiset<int> ms;
    int bias;

    void insert(int x) {
        ms.insert(x - bias);
    }

    void erase(int x) {
        ms.erase(ms.find(x - bias));
    }

    void add(int x) {
        bias += x;
    }

    int query() {
        if (ms.empty()) return n + 1;
        else return *(ms.begin()) + bias;
    }
} m1, m2;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]), pos[A[i]] = i;

    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
        if (pos[B[i]] >= i) {
            int det = pos[B[i]] - i;
            m1.insert(det);
            vec[i + 1].push_back({det + i + 1, n - 1 - pos[B[i]], -1});
            vec[n - det].push_back({0, 0, 1});
        } else {
            int det = i - pos[B[i]];
            m2.insert(det);
            vec[i + 1].push_back({pos[B[i]] + 1, n - 1 - pos[B[i]], -1});
            vec[det].push_back({0, 0, 1});
        }
    }
    printf("%d\n", min(m1.query(), m2.query()));

    for (int i = 1; i < n; i++) {
        m1.add(1); m2.add(-1);
        for (auto &arr : vec[i]) {
            if (arr[2] > 0) m2.erase(arr[0]), m1.insert(arr[1]);
            else m1.erase(arr[0]), m2.insert(arr[1]);
        }
        printf("%d\n", min(m1.query(), m2.query()));
    }
    return 0;
}
