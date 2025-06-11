// https://codeforces.com/contest/1575/submission/264663457
void solve() {
	i64 n, m, k, r, c; cin >> n >> m >> k >> r >> c;
	i64 ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
	//overlap
	if (ax == bx && ay == by){
		cout << power(Z(k), n * m).val() << "\n";
	}
	//partially overlap or no overlap, we can move it such that only 1 rectangle should be considered.
	else {
		cout << power(Z(k), n * m - r * c).val() << "\n";
	}

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}