# Submission link: https://codeforces.com/contest/835/submission/262842468
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var s string
	Fscan(in, &s)
	n := len(s)
	f := make([][]bool, n)
	for i := range f {
		f[i] = make([]bool, n)
		f[i][i] = true
	}
	for l := 2; l <= n; l++ {
		for i := 0; i+l-1 < n; i++ {
			f[i][i+l-1] = s[i] == s[i+l-1] && (l == 2 || f[i+1][i+l-2])
		}
	}
	ans := make([]int, n+1)
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
		dp[i][i] = 1
		ans[1]++
	}
	for l := 2; l <= n; l++ {
		for i := 0; i+l-1 < n; i++ {
			if f[i][i+l-1] {
				dp[i][i+l-1] = 1
				if l == 2 || f[i][i+l/2-1] {
					dp[i][i+l-1] = dp[i][i+l/2-1] + 1
				}
			}
			ans[dp[i][i+l-1]]++
		}
	}
	for i := n - 1; i > 0; i-- {
		ans[i-1] += ans[i]
	}
	for _, v := range ans[1:] {
		Fprintln(out, v, " ")
	}
}