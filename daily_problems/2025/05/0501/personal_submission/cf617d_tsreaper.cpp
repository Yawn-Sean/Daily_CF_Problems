#include <bits/stdc++.h>
using namespace std;

int main() {
    int X[3], Y[3];
    unordered_map<int, int> mpX, mpY;
    for (int i = 0; i < 3; i++) {
        scanf("%d%d", &X[i], &Y[i]);
        mpX[X[i]]++; mpY[Y[i]]++;
    }
    
    if (mpX.size() == 1 || mpY.size() == 1) {
        printf("1\n");
    } else if (mpX.size() == 2) {
        int mn = 2e9, mx = -2e9, t;
        for (int i = 0; i < 3; i++) {
            if (mpX[X[i]] == 2) mn = min(mn, Y[i]), mx = max(mx, Y[i]);
            else t = Y[i];
        }
        if (t <= mn || t >= mx) printf("2\n");
        else printf("3\n");
    } else if (mpY.size() == 2) {
        int mn = 2e9, mx = -2e9, t;
        for (int i = 0; i < 3; i++) {
            if (mpY[Y[i]] == 2) mn = min(mn, X[i]), mx = max(mx, X[i]);
            else t = X[i];
        }
        if (t <= mn || t >= mx) printf("2\n");
        else printf("3\n");
    } else {
        printf("3\n");
    }
    return 0;
}
