
int n;
 
void meibao() {
    cin >> n;
    if (n == 1) {
        cout << "1\n1\n"; 
    } else if (n == 2) {
        cout << "2\n1 2\n";
    } else if (n == 3) {
        cout << "2\n1 2 2\n";
    } else if (n == 4) {
        cout << "3\n1 2 2 3\n";
    } else if (n == 5) {
        cout << "3\n1 2 2 3 3\n";
    } else {
        cout << "4\n";
        for (int i = 1; i <= n; i++) {
            cout << i % 4 + 1 << " ";
        }
        cout << "\n";
    }
}   
 
