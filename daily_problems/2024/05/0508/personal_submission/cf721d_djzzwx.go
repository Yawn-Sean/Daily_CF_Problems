
func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	var n, k, x int
	Fscan(in, &n, &k, &x)
	a := make([]int, n)
	neg := false
	mnI := 0
	for i := range a {
		Fscan(in, &a[i])
		if a[i] < 0 {
			neg = !neg
		}
		if abs(a[i]) < abs(a[mnI]) {
			mnI = i
		}
	}
	if !neg {
		if abs(a[mnI]) >= k*x {
			for i, v := range a {
				if i == mnI {
					if v < 0 {
						v += k * x
					} else {
						v -= k * x
					}
				}
				Fprint(out, v, " ")
			}
			return
		}
		t := abs(a[mnI])/x + 1
		if a[mnI] < 0 {
			a[mnI] += t * x
		} else {
			a[mnI] -= t * x
		}
		k -= t
	}
	hp := IntHeap{}
	for i, v := range a {
		hp.push(pair{abs(v), i})
	}
	for ; k > 0; k-- {
		p := hp.pop().(pair)
		p.v += x
		hp.push(p)
	}
	for hp.Len() > 0 {
		p := hp.pop().(pair)
		if a[p.i] < 0 {
			a[p.i] = -p.v
		} else {
			a[p.i] = p.v
		}
	}
	for _, v := range a {
		Fprint(out, v, " ")
	}
}