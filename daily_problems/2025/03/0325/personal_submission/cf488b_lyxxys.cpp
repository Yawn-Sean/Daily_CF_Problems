void solve(){
    int n;
    cin >> n;
    vector <int> A(4);
    for (int i = 0; i < n; ++ i){
        cin >> A[i];
    }

    if (n == 0){
        cout << "YES\n";
        cout << 1 << "\n" << 2 << "\n" << 2 << "\n" << 3 << "\n";
    } else if (n == 1){
        cout << "YES\n";
        cout << 2*A[0] << "\n" << 2*A[0] << "\n" << 3*A[0] << "\n";
    } else if (n == 4){
        sort(A.begin(), A.end());
        bool jug = 3*A[0]==A[3] && A[1]+A[2] == 2*(A[3]-A[0]);
        if (!jug) cout << "NO\n";
        else cout << "YES\n";
    } else if (n == 2){
        sort(A.begin(), A.begin()+n);
        int x = A[0], y = A[1];
        if (y%3 == 0){  // [2, 4]、[3, 4]
            int res = y/3;
            if (res <= x){
                cout << "YES\n";
                cout << res << "\n" << 4*res-x << "\n";
                return;
            }
        }
        if ((x+y)%4 == 0){  // [2, 3]
            int res = (x+y)/4;
            if (3*res >= y && res <= x){
                cout << "YES\n";
                cout << res << "\n" << 3*res << "\n";
                return;
            }
        }

        // [1, 2]、[1, 3]、[1, 4]
        if (y > 3*x){
            cout << "NO\n";
        } else {
            cout << "YES\n";
            if (y == 3*x){
                cout << 2*x << "\n" << 2*x << "\n";
            } else {
                cout << 4*x-y << "\n" << 3*x << "\n";
            }
        }
    } else {
        sort(A.begin(), A.begin()+n);
        int x = A[0], y = A[1], z = A[2];
        if (z%3 == 0){  // [2,3,4]
            int res = z/3;
            if (x+y == 4*res){
                cout << "YES\n" << res << "\n";
                return;
            }
        }

        if (z > 3*x){   // [1,2,4]、[1,3,4]
            cout << "NO\n";
        } else if (z == 3*x){
            cout << "YES\n";
            cout << 4*x-y << "\n";
        } else {
            if (y+z == 4*x){  // [1, 2, 3]
                cout << "YES\n" << 3*x << "\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}
