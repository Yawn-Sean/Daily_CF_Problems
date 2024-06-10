# Submission link: https://codeforces.com/contest/551/submission/264660978
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, k, l, m int
	Fscan(in, &n, &k, &l, &m)
	if bits.Len(uint(k)) > l {
		Fprintln(out, 0)
		return
	}
	mod = m
	mat := matrix{
		{1, 1},
		{1, 0},
	}.pow(int64(n + 1))
	fb := mat[0][0]
	n2 := (powMod(2, n, m) - fb + m) % m
	ans := 1
	for i := 0; i < l; i++ {
		if k>>i&1 == 1 {
			ans = ans * n2 % m
		} else {
			ans = ans * fb % m
		}
	}
	Fprintln(out, ans%m)
}