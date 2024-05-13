// links : https://codeforces.com/contest/1028/submission/260469943

func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n int
	Fscan(in, &n)
	a := make([][4]int, n)
	pre := make([][4]int, n+1)
	pre[0] = [4]int{-1e9, -1e9, 1e9, 1e9}
	for i := range a {
		Fscan(in, &a[i][0], &a[i][1], &a[i][2], &a[i][3])
		pre[i+1][0] = max(a[i][0], pre[i][0])
		pre[i+1][1] = max(a[i][1], pre[i][1])
		pre[i+1][2] = min(a[i][2], pre[i][2])
		pre[i+1][3] = min(a[i][3], pre[i][3])
	}
	b := [4]int{-1e9, -1e9, 1e9, 1e9}
	for i := n - 1; i >= 0; i-- {
		x1, y1, x2, y2 := max(pre[i][0], b[0]), max(pre[i][1], b[1]), min(pre[i][2], b[2]), min(pre[i][3], b[3])
		if x1 <= x2 && y1 <= y2 {
			Fprintln(out, x1, y1)
			return
		}
		b[0] = max(a[i][0], b[0])
		b[1] = max(a[i][1], b[1])
		b[2] = min(a[i][2], b[2])
		b[3] = min(a[i][3], b[3])
	}
}