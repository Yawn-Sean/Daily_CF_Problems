#include <bits/stdc++.h>
using namespace std;

int main() {
    int A[6];
    for (int i = 0; i < 6; i++) scanf("%d", &A[i]);

    if (A[2] == 0 && A[3] > 0) printf("Ron\n");
    else if (A[0] == 0 && A[1] > 0 && A[3] > 0) printf("Ron\n");
    else if (A[1] == 0 || A[3] == 0 || A[5] == 0) printf("Hermione\n");
    else {
        int x = 1, y = 1;
        for (int i = 0; i < 6; i++) {
            if (i & 1) x *= A[i];
            else y *= A[i];
        }
        if (x > y) printf("Ron\n");
        else printf("Hermione\n");
    }
    return 0;
}
