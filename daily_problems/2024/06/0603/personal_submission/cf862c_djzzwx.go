# Submission link: https://codeforces.com/contest/862/submission/263870647
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, x int
	Fscan(in, &n, &x)
	if n == 1 {
		Fprintln(out, "YES")
		Fprintln(out, x)
	} else if n == 2 {
		if x > 0 {
			Fprintln(out, "YES")
			Fprintln(out, 0, x)
		} else {
			Fprintln(out, "NO")
		}
	} else {
		Fprintln(out, "YES")
		xor := 0
		for i := 1; i < n-2; i++ {
			Fprint(out, i, " ")
			xor ^= i
		}
		a, b := 1<<17, 1<<18
		Fprintln(out, a^b, b^xor, x^a)
	}
}