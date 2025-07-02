#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, A[MAXN + 10];

int main() {
    scanf("%d", &n);
    vector<pii> vec;
    for (int i = 1, j = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        if (A[i] == 0) {
            sort(vec.begin(), vec.end(), greater<pii>());
            for (int k = j; k < i; k++) {
                if (vec.size() > 0 && k == vec[0].second) printf("pushFront\n");
                else if (vec.size() > 1 && k == vec[1].second) printf("pushQueue\n");
                else if (vec.size() > 2 && k == vec[2].second) printf("pushStack\n");
                else printf("pushBack\n");
            }
            printf("%d", min(3, (int) vec.size()));
            if (vec.size() > 0) printf(" popFront");
            if (vec.size() > 1) printf(" popQueue");
            if (vec.size() > 2) printf(" popStack");
            printf("\n");
            vec.clear();
            j = i + 1;
        } else {
            vec.push_back({A[i], i});
        }
    }
    for (pii p : vec) printf("pushBack\n");
    return 0;
}
