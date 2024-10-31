package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Dsu struct {
	Fa     []int
	Size   []int
	Groups int
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

func NewDsu(n int) *Dsu {
	fa := make([]int, n)
	size := make([]int, n)
	for i := 0; i < n; i++ {
		fa[i] = i
		size[i] = 1
	}
	return &Dsu{Fa: fa, Size: size, Groups: n}
}
func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m, k int
	fmt.Fscan(in, &n, &m, &k)
	dsu := NewDsu(n * m)
	a := make([][]int, n)
	id := func(x, y int) int { return x*m + y }
	type pair struct{ i, j, val int }
	pos := make([]pair, 0, n*m)
	for i := range a {
		a[i] = make([]int, m)
		for j := range a[i] {
			fmt.Fscan(in, &a[i][j])
			pos = append(pos, pair{i, j, a[i][j]})
		}
	}
	sort.Slice(pos, func(i, j int) bool { return pos[i].val > pos[j].val })
	dir := [4][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	for i := range pos {
		x, y, val := pos[i].i, pos[i].j, pos[i].val
		for j := 0; j < 4; j++ {
			nx, ny := x+dir[j][0], y+dir[j][1]
			if nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] >= val {
				dsu.Union(id(x, y), id(nx, ny))
			}
		}
		if k%val != 0 {
			continue
		}
		t := k / val
		if t <= dsu.Size[dsu.Find(id(x, y))] {
			fmt.Fprintln(out, "YES")
			vis := make([][]bool, n)
			for i := range vis {
				vis[i] = make([]bool, m)
			}
			qu := make([]pair, 0)
			qu = append(qu, pair{x, y, val})
			vis[x][y] = true
			t--
			for len(qu) > 0 {
				x, y, val = qu[0].i, qu[0].j, qu[0].val
				qu = qu[1:]
				for j := 0; j < 4; j++ {
					nx, ny := x+dir[j][0], y+dir[j][1]
					if t == 0 {
						break
					}
					if nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] >= val && !vis[nx][ny] && t > 0 {
						t--
						vis[nx][ny] = true
						qu = append(qu, pair{nx, ny, val})
					}
				}
			}
			for i := range a {
				for j := range a[i] {
					if vis[i][j] {
						fmt.Fprint(out, val, " ")
					} else {
						fmt.Fprint(out, 0, " ")
					}
				}
				fmt.Fprintln(out)
			}
			return
		}
	}
	fmt.Fprintln(out, "NO")
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
