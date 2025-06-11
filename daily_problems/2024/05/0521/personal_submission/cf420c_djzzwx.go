# Submission link: https://codeforces.com/contest/420/submission/261975976
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, p, x, y int
	Fscan(in, &n, &p)
	cnt := make([]int, n)
	type pair struct{ x, y int }
	fil := map[pair]int{}
	for i := 0; i < n; i++ {
		Fscan(in, &x, &y)
		cnt[x-1]++
		cnt[y-1]++
		if x < y {
			x, y = y, x
		}
		fil[pair{x - 1, y - 1}]++
	}
	ans := 0
	for pa, c := range fil {
		if cnt[pa.x]+cnt[pa.y] >= p && cnt[pa.x]+cnt[pa.y]-c < p {
			ans--
		}
	}
	slices.Sort(cnt)
	for i, c := range cnt {
		j, _ := slices.BinarySearch(cnt[:i], p-c)
		ans += i - j
	}
	Fprintln(out, ans)
}