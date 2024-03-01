package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF687A(os.Stdin, os.Stdout) }

func CF687A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m, u, v int
	fmt.Fscan(in, &n, &m)
	g := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		g[i] = make([]int, 0)
	}
	for i := 1; i <= m; i++ {
		fmt.Fscan(in, &u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	ans := make([]int, n+1)
	var dfs func(cur, fa int, choose bool) bool
	dfs = func(cur, fa int, choose bool) bool {
		for _, e := range g[cur] {
			if e != fa {
				if !choose {
					if ans[e] == 2 {
						return false
					} else if ans[e] == 0 {
						ans[e] = 1
						if !dfs(e, cur, true) {
							return false
						}
					}
				} else {
					if ans[e] == 1 {
						return false
					} else if ans[e] == 0 {
						ans[e] = 2
						if !dfs(e, cur, false) {
							return false
						}
					}
				}
			}
		}
		return true
	}
	for i := 1; i <= n; i++ {
		if len(g[i]) > 0 && ans[i] == 0 {
			ans[i] = 1
			if !dfs(i, -1, true) {
				fmt.Fprintf(out, "-1\n")
				os.Exit(0)
			}
		}
	}
	var ans1, ans2 []int
	for i := 1; i <= n; i++ {
		if ans[i] == 1 {
			ans1 = append(ans1, i)
		} else if ans[i] == 2 {
			ans2 = append(ans2, i)
		}
	}
	fmt.Fprintf(out, "%d\n", len(ans1))
	for i := len(ans1) - 1; i > -1; i-- {
		fmt.Fprintf(out, "%d ", ans1[i])
	}
	fmt.Fprintf(out, "\n%d\n", len(ans2))
	for i := len(ans2) - 1; i > -1; i-- {
		fmt.Fprintf(out, "%d ", ans2[i])
	}
}
