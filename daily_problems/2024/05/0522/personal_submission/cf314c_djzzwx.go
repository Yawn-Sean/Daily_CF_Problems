# Submission link: https://codeforces.com/contest/314/submission/262116430
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, x int
	Fscan(in, &n)
	fw := newFenwick(1e6 + 1)
	f := make([]int, 1e6+1)
	for i := 0; i < n; i++ {
		Fscan(in, &x)
		v := ((fw.query(x)+1)*x%mod - f[x] + mod) % mod
		f[x] = (f[x] + v) % mod
		fw.update(x, v)
	}
	Fprintln(out, fw.query(1e6)%mod)
}