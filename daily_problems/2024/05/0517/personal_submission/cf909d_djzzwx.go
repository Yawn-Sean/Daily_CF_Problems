# Submission link: https://codeforces.com/contest/909/submission/261268063
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var s string
	var ans, cur int
	Fscan(in, &s)
	type pair struct {
		d int
		s rune
	}
	var p rune
	p = rune(s[0])
	q := []pair{}
	for _, b := range s {
		if b == p {
			cur++
		} else {
			q = append(q, pair{cur, p})
			cur = 1
		}
		p = b
	}
	if cur > 0 {
		q = append(q, pair{cur, p})
	}
	for len(q) > 1 {
		t := []pair{}
		for i, pa := range q {
			pa.d -= 2
			if i == 0 || i == len(q)-1 {
				pa.d += 1
			}
			if pa.d <= 0 {
				continue
			}
			if len(t) > 0 && pa.s == t[len(t)-1].s {
				t[len(t)-1].d += pa.d
			} else {
				t = append(t, pa)
			}
		}
		q = t
		ans++
	}
	Fprintln(out, ans)
}