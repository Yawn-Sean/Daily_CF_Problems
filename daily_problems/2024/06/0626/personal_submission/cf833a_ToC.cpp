// https://codeforces.com/contest/833/submission/267624548
void sol()
{
    LL a, b;
    cin >> a >> b;
    LL product = a * b;
    LL head = 1, tail = 1e6;    
    while (head < tail) {
        LL mid = head + tail + 1 >> 1;
        if (mid * mid * mid <= product) head = mid; 
        else tail = mid - 1;
    }
    if (head * head * head == product) {
        if (a % head == 0 && b % head == 0) cout << "Yes\n";
        else cout << "No\n";
    } else {
        cout << "No\n";
    }
}
