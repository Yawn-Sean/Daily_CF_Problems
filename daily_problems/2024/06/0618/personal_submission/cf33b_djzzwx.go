# Submission link: https://codeforces.com/contest/33/submission/266249149
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var s, t, a, b string
	var n, w, ans int
	Fscan(in, &s, &t, &n)
	g := make([][]pair, 26)
	for i := 0; i < n; i++ {
		Fscan(in, &a, &b, &w)
		u, v := int(a[0]-'a'), int(b[0]-'a')
		g[u] = append(
			g[u],
			pair{v, w})
	}
	if len(s) != len(t) {
		Fprintln(out, -1)
		return
	}
	dis := [26][]int{}
	for i := 0; i < 26; i++ {
		dis[i] = shortestPathDijkstra(g, i)
	}
	sb := strings.Builder{}
	for i := range s {
		if s[i] == t[i] {
			sb.WriteByte(s[i])
			continue
		}
		var by byte
		tot := inf
		x, y := int(s[i]-'a'), int(t[i]-'a')
		for j := 0; j < 26; j++ {
			if tmp := dis[x][j] + dis[y][j]; tmp < tot {
				tot = tmp
				by = byte('a' + j)
			}
		}
		if tot == inf {
			Fprintln(out, -1)
			return
		}
		sb.WriteByte(by)
		ans += tot
	}
	Fprintln(out, ans)
	Fprintln(out, sb.String())
}
