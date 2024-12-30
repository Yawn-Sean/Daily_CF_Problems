void solve()
{
    ll A, B, n, x;
    cin >> A >> B >> n >> x;
    Matrix a, b, ans;
    a.mat[0][0] = A;
    a.mat[0][1] = B;
    a.mat[1][0] = 0;
    a.mat[1][1] = 1;
    b.mat[0][0] = x;
    b.mat[1][0] = 1;
    a = quick_power(a, n, 2);
    // print_matrix(a, 2, 2);
    ans = mat_mul(a, b, 2);
    cout << ans.mat[0][0] << "\n";
}
