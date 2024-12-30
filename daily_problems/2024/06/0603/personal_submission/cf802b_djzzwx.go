# Submission link: https://codeforces.com/contest/802/submission/263858807
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, k int
	Fscan(in, &n, &k)
	a := make([]int, n)
	pos := make([]int, n+1)
	next := make([]int, n+1)
	for i := range pos {
		pos[i] = n + 10
		next[i] = n + 10
	}
	for i := range a {
		Fscan(in, &a[i])
	}
	for i := n - 1; i >= 0; i-- {
		next[i] = pos[a[i]]
		pos[a[i]] = i
	}
	hp := new(IntHeap)
	has := make([]bool, n+1)
	ans := 0
	sz := 0
	for i, v := range a {
		if !has[v] {
			for hp.Len() > 0 && (*hp)[0][1] > n+5 {
				hp.pop()
				sz--
			}
			if k == sz {
				sz--
				p := hp.pop()
				has[p[0]] = false
			}
			sz++
			ans++
			has[v] = true
		}
		hp.push(HeapType{v, next[i]})
	}
	Fprintln(out, ans)
}

