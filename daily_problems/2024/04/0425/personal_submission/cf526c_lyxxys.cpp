const int N = 1e5;
using ll = long long;
ll C, joy[2], w[2];

void solve(){
    cin >> C >> joy[0] >> joy[1] >> w[0] >> w[1];
    ll res = 0;
    ll n = sqrt(C);
    for (int i = 0; i < N; ++ i){
        if (i > C/w[0]) break;
        res = max(res, i*joy[0] + (C-i*w[0])/w[1]*joy[1]);
    }
    for (int i = 0; i < N; ++ i){
        if (i > C/w[1]) break;
        res = max(res, i*joy[1] + (C-i*w[1])/w[0]*joy[0]);
    }

    cout << res << "\n";
    return;
}
