

void solve(){
    int x, a, b, c, k, t;
    cin >> x >> a >> b >> c;
    if(a <= (b - c) || x < b)
        cout << x / a;
    else
        cout<< (x - b) / (b - c) + 1 + ((x - b) % (b - c) + c) / a;
}

