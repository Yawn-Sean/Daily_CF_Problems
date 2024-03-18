#include <bits/stdc++.h>
#define MAXN 1000
#define MAXA ((int) 1e6)
using namespace std;

int n, A[MAXN + 10];

bool flag[MAXA * 2 + 10];

vector<int> solve1() {
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (!flag[A[i] + A[j]]) return {A[i], A[j]};
    return {A[1]};
}

vector<int> solve2() {
    int one = 0;
    for (int i = 1; i <= n; i++) if (A[i] == 1) one++;
    vector<int> ret(one, 1);

    for (int i = 1; i <= n; i++) if (A[i] > 1 && !flag[1 + A[i]]) {
        ret.push_back(A[i]);
        break;
    }
    return ret;
}

void print(vector<int> &vec) {
    printf("%d\n", vec.size());
    for (int i = 0; i < vec.size(); i++) printf("%d%c", vec[i], "\n "[i + 1 < vec.size()]);
}

int main() {
    for (int i = 2; i * i <= MAXA * 2; i++) if (!flag[i]) for (int j = i * 2; j <= MAXA * 2; j += i) flag[j] = true;
    
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    
    vector<int> vec1 = solve1(), vec2 = solve2();
    if (vec1.size() > vec2.size()) print(vec1);
    else print(vec2);
    return 0;
}
