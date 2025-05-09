/*
我们必须假设每个位置都有坦克，且被轰炸时所有可能的逃逸方向都会有坦克
4: 2 3 1 4 2 3
5: 2 4 3 1 5 2 4
好像是隔一个打一个，然后把剩下没打的再打一遍，最后再隔一个打一个
*/

int n;

void meibao() {
    cin >> n;
    cout << n / 2 * 2 + (n - n / 2) << "\n";
    if (n % 2 == 0) {
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
    } else {
        for (int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }
        for (int i = 2; i <= n; i += 2) {
            cout << i << " ";
        }
    }
}  
