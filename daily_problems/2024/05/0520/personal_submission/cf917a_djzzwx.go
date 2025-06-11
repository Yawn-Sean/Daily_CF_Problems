# Submission link: https://codeforces.com/contest/917/submission/261716487
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var s string
	Fscan(in, &s)
	n := len(s)
	ans := 0
	for i := range s {
		cur := 0
		mark := 0
		for j := i; j < n; j++ {
			if s[j] == '?' {
				cur--
				mark++
			} else if s[j] == '(' {
				cur++
			} else {
				cur--
			}
			if cur < 0 {
				if mark == 0 {
					break
				}
				cur += 2
				mark--
			}
			if cur == 0 {
				ans++
			}
		}
	}
	Fprintln(out, ans)
}