links: https://codeforces.com/contest/960/submission/261159739
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var x, d int
	Fscan(in, &x, &d)
	a := []int{}
	for i, c := 0, 1; i < 31; i++ {
		if x>>i&1 == 1 {
			for j := 0; j < i; j++ {
				a = append(a, c)
			}
			c += d
			a = append(a, c)
			c += d
		}
	}
	Fprintln(out, len(a))
	for _, v := range a {
		Fprint(out, v, " ")
	}
}