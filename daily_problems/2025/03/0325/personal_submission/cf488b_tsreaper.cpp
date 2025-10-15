#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &vec) {
    int a = 0;
    for (int i = 0; i < 4; i++) a += vec[i];
    int b = (vec[1] + vec[2]) * 2;
    int c = (vec[3] - vec[0]) * 4;
    return a == b && b == c;
}

int main() {
    int n; scanf("%d", &n);
    if (n == 0) printf("YES\n1\n1\n3\n3\n");
    else if (n == 1) {
        int x; scanf("%d", &x);
        printf("YES\n%d\n%d\n%d\n", x, x * 3, x * 3);
    } else if (n == 2) {
        int x, y; scanf("%d%d", &x, &y);
        for (int i = 1; i <= 2000; i++) for (int j = i; j <= 2000; j++) {
            vector<int> vec = {x, y, i, j};
            sort(vec.begin(), vec.end());
            if (check(vec)) { printf("YES\n%d\n%d\n", i, j); return 0; }
        }
        printf("NO\n");
    } else if (n == 3) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        for (int i = 1; i <= 2000; i++) {
            vector<int> vec = {x, y, z, i};
            sort(vec.begin(), vec.end());
            if (check(vec)) { printf("YES\n%d\n", i); return 0; }
        }
        printf("NO\n");
    } else {
        vector<int> vec;
        for (int i = 0; i < 4; i++) {
            int x; scanf("%d", &x);
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end());
        if (check(vec)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
