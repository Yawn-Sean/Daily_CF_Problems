func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var T, n int
	var s string
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n)
		Fscan(in, &s)
		f := -1
		for i := range s {
			if s[i] != s[0] {
				f = i
				break
			}
		}
		if f == -1 {
			Fprintln(out, n)
			continue
		}
		ans := n*(n-f) + f
		x, y := 0, 0
		for _, b := range s[f:] {
			if b == 'R' {
				x++
			} else {
				y++
			}
		}
		ans -= x * y
		Fprintln(out, ans)
	}
}
