# Submission link: https://codeforces.com/contest/893/submission/265179316
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, d, x int
	Fscan(in, &n, &d)
	ans := 0
	low, up := 0, 0
	for i := 0; i < n; i++ {
		Fscan(in, &x)
		if x == 0 {
			if up < 0 {
				up = d
				ans++
			}
			if low < 0 {
				low = 0
			}
		} else {
			low += x
			up += x
			if up > d {
				up = d
			}
			if low > d {
				Fprintln(out, -1)
				return
			}
		}
	}
	Fprintln(out, ans)
}