package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

type pair struct{ x, y int }

func solve(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n, m, u, v, ans int
	Fscan(in, &n, &m)
	g := make([][]pair, n)
	deg := make([]int, n)

	for i := 0; i < m; i++ {
		Fscan(in, &u, &v)
		u, v = u-1, v-1
		g[u] = append(g[u], pair{v, i})
		deg[v]++
	}

	pre := -1
	for i := 0; i < n; i++ {
		if deg[i] == 0 {
			if pre != -1 {
				Fprint(out, "-1\n")
				return
			}
			pre = i
		}
	}

	for i := 0; i < n; i++ {
		next := -1
		for _, v := range g[pre] {
			deg[v.x]--
			if deg[v.x] == 0 {
				if next != -1 {
					Fprint(out, "-1\n")
					return
				}
				next = v.x
				ans = max(ans, v.y+1)
			}
		}
		pre = next
	}
	Fprint(out, ans, "\n")
}

func main() { solve(os.Stdin, os.Stdout) }
