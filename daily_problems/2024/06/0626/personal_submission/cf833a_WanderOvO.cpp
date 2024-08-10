int T;
LL a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        cin >> a >> b;
        LL t = round(pow(a * b, 1.0 / 3));
        if (t * t * t != a * b) {
            puts("No");
        } else {
            if (a % t == 0 && b % t == 0) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
    
    return 0;
}