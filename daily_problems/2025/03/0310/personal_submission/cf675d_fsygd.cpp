#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
 
using namespace std;
 
map<int, int> m;
int n, x, _min, _max;
int left[100010];
 
int main() {
    scanf("%d%d", &n, &x);
    m[x] = 0;
    _min = x;
    _max = x;
    for (int i = 1; i < n; ++i) {
        if (i > 1) printf(" ");
        scanf("%d", &x);
        m[x] = i;
        if (x < _min) {
            printf("%d", _min);
            left[m[_min]] = 1;
            _min = x;
        } else if (x > _max) {
            printf("%d", _max);
            _max = x;
        } else {
            auto it = m.find(x);
            if (left[next(it)->second] == 0) {
                left[next(it)->second] = 1;
                printf("%d", next(it)->first);
            } else {
                printf("%d", prev(it)->first);
            }
        } 
    }
    printf("\n");
    return 0;
}