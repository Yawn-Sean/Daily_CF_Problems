# Submission link: https://codeforces.com/contest/533/submission/261976532
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	var s, t string
	Fscan(in, &n, &s, &t)
	l, r := n, -1
	for i := range s {
		if s[i] != t[i] {
			l = min(l, i)
			r = max(r, i)
		}
	}
	ans := 0
	if s[l:r] == t[l+1:r+1] {
		ans++
	}
	if s[l+1:r+1] == t[l:r] {
		ans++
	}
	Fprintln(out, ans)
}