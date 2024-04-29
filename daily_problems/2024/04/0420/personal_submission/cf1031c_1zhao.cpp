void solve() {
    int a, b;
    cin >> a >> b;
    
    bool f = a > b;

    if(f) swap(a, b);

    set<int> va, vb;

    int sum = 0;
    int i = 1;
    for(i = 1; sum + i <= a; i ++) {
        sum += i;
        va.insert(i);
    }

    if(sum < a) {
        va.insert(i);
        va.erase(sum + i - a);
    }

    sum = 0;
    for(i=1; i+sum <= b; i++) {
        if(va.count(i)) {
            continue;
        }
        vb.insert(i);
        sum += i;
    }

    if(f) swap(va, vb);

    cout << va.size() << endl;
    for(int num: va) cout << num << ' ';
    cout << endl;

    
    cout << vb.size() << endl;
    for(int num: vb) cout << num << ' ';
    cout << endl;
}
