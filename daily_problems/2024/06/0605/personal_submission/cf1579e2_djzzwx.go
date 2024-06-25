# Submission link: https://codeforces.com/contest/1579/submission/264230795
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var T, n int
	for Fscan(in, &T); T > 0; T-- {
		Fscan(in, &n)
		a := make([]int, n)
		for i := range a {
			Fscan(in, &a[i])
		}
		b := make([]int, n)
		copy(b, a)
		slices.Sort(b)
		ans := 0
		fw := newFenwick(n + 1)
		for _, v := range a {
			k, _ := slices.BinarySearch(b, v)
			k += 1
			var l, r int
			if k > 1 {
				l = fw.query(k - 1)
			}
			r = fw.sumRange(k+1, n)
			if l > r {
				ans += r
			} else {
				ans += l
			}
			fw.update(k, 1)
		}
		Fprintln(out, ans)
	}
}