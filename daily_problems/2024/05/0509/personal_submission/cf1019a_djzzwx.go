# Submission link: https://codeforces.com/contest/1019/submission/260062122
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, m int
	Fscan(in, &n, &m)
	type pair struct{ to, w int }
	a := make([]pair, n)
	cnt := make([]int, m)
	mxCnt := 0
	for i := range a {
		Fscan(in, &a[i].to, &a[i].w)
		a[i].to--
		cnt[a[i].to]++
		mxCnt = max(mxCnt, cnt[a[i].to])
	}
	slices.SortFunc(a, func(a, b pair) int {
		return cmp.Compare(a.w, b.w)
	})
	cnt2 := make([]int, m)
	do := make([]bool, n)
	ans := int(1e18)
	for i := 1; i <= n; i++ {
		res := 0
		copy(cnt2, cnt)
		clear(do)
		for j, p := range a {
			if p.to != 0 && cnt2[p.to] >= i {
				res += p.w
				cnt2[p.to]--
				cnt2[0]++
				do[j] = true
			}
		}
		for j, p := range a {
			if cnt2[0] >= i {
				break
			}
			if !do[j] && p.to != 0 {
				cnt2[0]++
				res += p.w
			}
		}
		ans = min(ans, res)
	}
	Fprintln(out, ans)
}