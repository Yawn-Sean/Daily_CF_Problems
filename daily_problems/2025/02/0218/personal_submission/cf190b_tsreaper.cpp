#include <bits/stdc++.h>
using namespace std;

int main() {
    array<int, 3> A[2];
    for (int i = 0; i < 2; i++) for (int j = 0; j < 3; j++) scanf("%d", &A[i][j]);
    if (A[0][2] < A[1][2]) swap(A[0], A[1]);
    double d = sqrt((A[0][0] - A[1][0]) * (A[0][0] - A[1][0]) + (A[0][1] - A[1][1]) * (A[0][1] - A[1][1]));
    if (d >= A[0][2] + A[1][2]) printf("%.12f\n", (d - A[0][2] - A[1][2]) / 2);
    else if (d <= A[0][2] - A[1][2]) printf("%.12f\n", (A[0][2] - A[1][2] - d) / 2);
    else printf("0\n");
    return 0;
}
