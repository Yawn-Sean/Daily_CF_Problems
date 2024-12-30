# Submission Link: https://codeforces.com/contest/317/submission/266403284
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, t, a, b int
	Fscan(in, &n, &t)
	cnt := [200][200]int{}
	k := func(x int) int { return x + 100 }
	dirs := [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
	var dfs func(x, y int)
	dfs = func(x, y int) {
		tmp := cnt[k(x)][k(y)]
		if tmp < 4 {
			return
		}
		tmp /= 4
		cnt[k(x)][k(y)] %= 4
		for _, d := range dirs {
			i, j := x+d[0], y+d[1]
			cnt[k(i)][k(j)] += tmp
			dfs(i, j)
		}
	}
	cnt[k(0)][k(0)] = n
	dfs(0, 0)
	for ; t > 0; t-- {
		Fscan(in, &a, &b)
		x, y := k(a), k(b)
		if x >= 200 || y >= 200 || x < 0 || y < 0 {
			Fprintln(out, 0)
			continue
		}
		Fprintln(out, cnt[x][y])
	}
}
