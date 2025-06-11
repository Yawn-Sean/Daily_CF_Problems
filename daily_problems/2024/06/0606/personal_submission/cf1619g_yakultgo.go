package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, k int
	fmt.Fscan(in, &n, &k)
	type pair struct{ x, y int }
	row := make(map[int][]pair)
	col := make(map[int][]pair)
	a := make([][3]int, n)
	for i := range a {
		var x, y, t int
		fmt.Fscan(in, &x, &y, &t)
		a[i][0] = x
		a[i][1] = y
		a[i][2] = t
		if row[x] == nil {
			row[x] = make([]pair, 0)
		}
		row[x] = append(row[x], pair{y, i})
		if col[y] == nil {
			col[y] = make([]pair, 0)
		}
		col[y] = append(col[y], pair{x, i})
	}
	dsu := NewDsu(n)
	for _, v := range row {
		sort.Slice(v, func(i, j int) bool { return v[i].x < v[j].x })
		for i := 1; i < len(v); i++ {
			if v[i].x-v[i-1].x <= k {
				dsu.Union(v[i].y, v[i-1].y)
			}
		}
	}
	for _, v := range col {
		sort.Slice(v, func(i, j int) bool { return v[i].x < v[j].x })
		for i := 1; i < len(v); i++ {
			if v[i].x-v[i-1].x <= k {
				dsu.Union(v[i].y, v[i-1].y)
			}
		}
	}
	time := make(map[int]int)
	for i := 0; i < n; i++ {
		fa := dsu.Find(i)
		if v, ok := time[fa]; !ok || a[i][2] < v {
			time[fa] = a[i][2]
		}
	}
	ans := make([]int, 0)
	for _, v := range time {
		ans = append(ans, v)
	}
	slices.Sort(ans)
	n = len(ans)
	mx := n - 1
	for i := 0; i < n; i++ {
		mx = min(mx, max(ans[i], n-2-i))
	}
	fmt.Fprintln(out, mx)
}

type Dsu struct {
	Fa     []int
	Size   []int
	Groups int
}

func NewDsu(n int) *Dsu {
	fa := make([]int, n)
	size := make([]int, n)
	for i := 0; i < n; i++ {
		fa[i] = i
		size[i] = 1
	}
	return &Dsu{Fa: fa, Size: size, Groups: n}
}
func (u *Dsu) Find(x int) int {
	if u.Fa[x] != x {
		u.Fa[x] = u.Find(u.Fa[x])
	}
	return u.Fa[x]
}

func (u *Dsu) Union(x, y int) {
	x = u.Find(x)
	y = u.Find(y)
	if x == y {
		return
	}
	if u.Size[x] < u.Size[y] {
		x, y = y, x
	}
	u.Fa[y] = x
	u.Size[x] += u.Size[y]
	u.Groups--
}

func (u *Dsu) Same(x, y int) bool {
	return u.Find(x) == u.Find(y)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	fmt.Fscan(in, &T)
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
