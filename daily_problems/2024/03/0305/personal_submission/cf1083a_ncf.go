package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1083A(os.Stdin, os.Stdout) }

func CF1083A(_r io.Reader, out io.Writer) {
	type edge struct{ to, dis int }
	in := bufio.NewReader(_r)
	var n, u, v, c int
	fmt.Fscan(in, &n)
	g := make([][]edge, n)
	w := make([]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]edge, 0)
		fmt.Fscan(in, &w[i])
	}
	for i := 1; i < n; i++ {
		fmt.Fscan(in, &u, &v, &c)
		u, v = u-1, v-1
		g[u] = append(g[u], edge{v, c})
		g[v] = append(g[v], edge{u, c})
	}

	ans := 0
	var dfs func(cur, fa int) int
	dfs = func(cur, fa int) int {
		mx, smx := 0, 0
		for _, e := range g[cur] {
			y, d := e.to, e.dis
			if y != fa {
				c := dfs(y, cur)
				cv := c - d
				if cv > mx {
					mx, smx = cv, mx
				} else if cv > smx {
					smx = cv
				}
			}
		}
		ans = max1083a(ans, mx+smx+w[cur])
		return mx + w[cur]
	}
	dfs(0, -1)
	fmt.Fprintf(out, "%d ", ans)
}

func max1083a(a, b int) int {
	if a > b {
		return a
	}
	return b
}
