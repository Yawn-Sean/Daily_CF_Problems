# Submission link: https://codeforces.com/contest/869/submission/262948807
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var a, b, c1 int
	Fscan(in, &a, &b, &c1)
	calc := func(x, y int) int {
		z := min(x, y)
		res := 0
		for i := 0; i <= z; i++ {
			res = (res + c[x][i]*c[y][i]%mod*fac[i]%mod) % mod
		}
		return res
	}
	ans := calc(a, b) * calc(b, c1) % mod * calc(a, c1) % mod
	Fprintln(out, ans)
}