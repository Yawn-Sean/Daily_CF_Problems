# Submission link: https://codeforces.com/contest/1954/submission/262820325
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	const mod int = 998244353
	Fscan(in, &n)
	a := make([]int, n)
	for i := range a {
		Fscan(in, &a[i])
	}
	slices.Sort(a)
	f := make([]int, 5001)
	f[0] = 1
	ans := 0
	for _, v := range a {
		for j := 5000; j >= 0; j-- {
			if j > v {
				ans = ((j+v+1)/2*f[j]%mod + ans) % mod
			} else {
				ans = (v*f[j]%mod + ans) % mod
			}
			if v+j <= 5000 {
				f[v+j] += f[j]
				f[v+j] %= mod
			}
		}
	}
	Fprintln(out, ans)
}