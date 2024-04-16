#include <iostream>

using namespace std;
typedef long long ll;
ll n, a, f1, f12, f121, f1212;

int main() {
    scanf("%lld", &n); while (n--) {
        scanf("%lld", &a);
        if (a == 1)
            f1++, f121++;
        else
            f12++, f1212++;
        f12 = max(f12, f1), f121 = max(f121, f12), f1212 = max(f1212, f121);
    }
    printf("%lld\n", f1212);
    return 0;
}
