# Submission Link: https://codeforces.com/contest/1051/submission/266390979
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, k int
	Fscan(in, &n, &k)
	const mod int = 998244353
	f := make([][][4]int, n+1)
	for i := range f {
		f[i] = make([][4]int, k+3)
	}
	f[0][1][0] = 1
	f[0][1][3] = 1
	f[0][2][1] = 1
	f[0][2][2] = 1
	for i := 0; i < n; i++ {
		for j := 0; j <= k; j++ {
			for x := 0; x < 4; x++ {
				f[i+1][j][x] = (f[i+1][j][x] + f[i][j][x]) % mod
			}
			for x := 1; x < 4; x++ {
				f[i+1][j+1][x] = (f[i+1][j+1][x] + f[i][j][0]) % mod
			}
			for x := 1; x < 3; x++ {
				f[i+1][j+1][x] = (f[i+1][j+1][x] + f[i][j][3]) % mod
				f[i+1][j][0] = (f[i+1][j][0] + f[i][j][x]) % mod
				f[i+1][j][3] = (f[i+1][j][3] + f[i][j][x]) % mod
			}
			f[i+1][j+1][0] = (f[i+1][j+1][0] + f[i][j][3]) % mod
			f[i+1][j+2][1] = (f[i+1][j+2][1] + f[i][j][2]) % mod
			f[i+1][j+2][2] = (f[i+1][j+2][2] + f[i][j][1]) % mod
		}
	}
	Fprintln(out, (f[n-1][k][0]+f[n-1][k][1]+f[n-1][k][2]+f[n-1][k][3])%mod)
}
