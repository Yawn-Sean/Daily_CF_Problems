# Submission link: https://codeforces.com/contest/1168/submission/262950693
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var s string
	Fscan(in, &s)
	n := len(s)
	r := n
	ans := 0
	for i := n - 1; i >= 0; i-- {
		for j := 1; i+j*2 < n; j++ {
			if s[i] == s[i+j] && s[i] == s[i+j*2] {
				r = min(r, i+j*2)
				break
			}
		}
		ans += n - r
	}
	Fprintln(out, ans)
}