# Submission link: https://codeforces.com/contest/1561/submission/264353007
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, m int
	Fscan(in, &n, &m)
	f := make([]int, n+1)
	ps := make([]int, n+2)
	f[n] = 1
	ps[n] = 1
	for i := n - 1; i >= 1; i-- {
		f[i] = (f[i] + ps[i+1]) % m
		for j := 2; i*j <= n; j++ {
			f[i] = (f[i] + ps[i*j] - ps[min(n+1, (i+1)*j)]) % m
			f[i] = (f[i] + m) % m
		}
		ps[i] = (ps[i+1] + f[i]) % m
	}
	Fprintln(out, f[1])
}