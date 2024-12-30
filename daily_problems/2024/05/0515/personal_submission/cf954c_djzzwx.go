# Submission link: https://codeforces.com/contest/954/submission/260995822
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	Fscan(in, &n)
	a := make([]int, n)
	x, y := int(1e9), int(1e9)
	for i := range a {
		Fscan(in, &a[i])
		a[i]--
		if i > 0 && abs(a[i]-a[i-1]) > 1 {
			y = abs(a[i] - a[i-1])
		}
	}
	p := a[0]
	for _, v := range a[1:] {
		if v == p {
			Fprintln(out, "NO")
			return
		}
		px, py := p/y, p%y
		sx, sy := v/y, v%y
		if px == sx && abs(py-sy) != 1 {
			Fprintln(out, "NO")
			return
		} else if py == sy && abs(px-sx) != 1 {
			Fprintln(out, "NO")
			return
		} else if px != sx && py != sy {
			Fprintln(out, "NO")
			return
		}
		p = v
	}
	Fprintln(out, "YES")
	Fprintln(out, x, y)
}
