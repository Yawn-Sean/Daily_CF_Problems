package main

import (
	"bufio"
	"fmt"
	"os"
)

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

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m int
	fmt.Fscan(in, &n, &m)
	dsu := NewDsu(n + m)
	adj := make([][]int, n+m)
	str := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &str[i])
		for j := 0; j < m; j++ {
			if str[i][j] == '=' {
				dsu.Union(i, n+j)
			}
		}
	}
	deg := make([]int, n+m)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if str[i][j] == '<' {
				deg[dsu.Find(n+j)]++
				adj[dsu.Find(i)] = append(adj[dsu.Find(i)], dsu.Find(n+j))
			} else if str[i][j] == '>' {
				deg[dsu.Find(i)]++
				adj[dsu.Find(n+j)] = append(adj[dsu.Find(n+j)], dsu.Find(i))
			}
		}
	}
	queue := make([]int, 0, n+m)
	cnt := 0
	dis := make([]int, n+m)
	for i := 0; i < n+m; i++ {
		if dsu.Find(i) == i && deg[i] == 0 {
			dis[i] = 1
			queue = append(queue, i)
		}
	}

	for len(queue) > 0 {
		x := queue[0]
		queue = queue[1:]
		cnt++
		for _, y := range adj[x] {
			dis[y] = max(dis[y], dis[x]+1)
			deg[y]--
			if deg[y] == 0 {
				queue = append(queue, y)
			}
		}
	}
	if cnt != dsu.Groups {
		fmt.Fprintln(out, "No")
		return
	}
	fmt.Fprintln(out, "Yes")
	for i := 0; i < n; i++ {
		fmt.Fprint(out, dis[dsu.Find(i)], " ")
	}
	fmt.Fprintln(out)
	for i := 0; i < m; i++ {
		fmt.Fprint(out, dis[dsu.Find(n+i)], " ")
	}
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
