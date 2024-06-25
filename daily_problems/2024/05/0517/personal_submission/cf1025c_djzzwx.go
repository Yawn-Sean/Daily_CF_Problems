# Submission link: https://codeforces.com/contest/1025/submission/261266524
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var s string
	var ans, cur int
	Fscan(in, &s)
	s += s
	p := s[0]
	for i := range s {
		if s[i] == p {
			ans = max(ans, cur)
			cur = 0
		}
		p = s[i]
		cur += 1
	}
	Fprintln(out, min(max(ans, cur), len(s)/2))
}