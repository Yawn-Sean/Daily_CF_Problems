void solve(){
    const int N = 1 << 10;

    int n, k, x;
    cin >> n >> k >> x;
    vector <int> cnts1(N), cnts2(N);
    for (int i = 0,x; i < n; ++ i){
        cin >> x;
        cnts1[x] += 1;
    }

    while (k--){
        bool odd = 1;
        for (int i = 0; i < N; ++ i){
            if (cnts1[i]%2){
                int v1 = (cnts1[i]+1)/2, v2 = cnts1[i]-v1;
                if (!odd) swap(v1, v2);

                cnts2[i^x] += v1;
                cnts2[i] += v2;

                odd = !odd;
            } else {
                int v = cnts1[i] / 2;

                cnts2[i^x] += v;
                cnts2[i] += v;
            }
        }

        for (int i = 0; i < N; ++ i){
            cnts1[i] = cnts2[i];
            cnts2[i] = 0;
        }
    }

    int ma = -1, mi = 10001;
    for (int i = 0; i < N; ++ i){
        if (cnts1[i]){
            fmax(ma, i);
            fmin(mi, i);
        }
    }

    cout << ma << " " << mi << "\n";
}
