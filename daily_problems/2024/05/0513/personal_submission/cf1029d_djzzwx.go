# links: https://codeforces.com/contest/1029/submission/260729661
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, k int
	Fscan(in, &n, &k)
	a := make([]int, n)
	cnt := [11]map[int]int{}
	for i := range cnt {
		cnt[i] = make(map[int]int)
	}
	for i := range a {
		Fscan(in, &a[i])
		s := strconv.Itoa(a[i])
		cnt[len(s)][a[i]%k]++
	}
	ans := 0
	for _, v := range a {
		cur := v
		dis := len(strconv.Itoa(v))
		for j := 1; j < 11; j++ {
			cur *= 10
			cur %= k
			ans += cnt[j][((-cur)%k+k)%k]
			if dis == j && (cur+v)%k == 0 {
				ans--
			}
		}
	}
	Fprintln(out, ans)
}