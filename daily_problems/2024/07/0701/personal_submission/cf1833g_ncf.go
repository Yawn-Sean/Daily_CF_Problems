package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1833G(os.Stdin, os.Stdout) }

func CF1833G(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, u, v int
	fmt.Fscan(in, &t)
out:
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n)
		type pair struct {
			a, b int
		}
		g := make([][]pair, n)
		degree := make([]int, n)
		for i := 0; i < n-1; i++ {
			fmt.Fscan(in, &u, &v)
			u, v = u-1, v-1
			g[u] = append(g[u], pair{v, i})
			g[v] = append(g[v], pair{u, i})
			degree[u] += 1
			degree[v] += 1
		}
		if n%3 != 0 {
			fmt.Fprintf(out, "-1\n")
			continue
		}
		vis := make([]bool, n)
		size := make([]int, n)
		for i := 0; i < n; i++ {
			size[i] = 1
		}
		var ans []int
		var q []int
		for i := 0; i < n; i++ {
			if degree[i] == 1 {
				q = append(q, i)
			}
		}
		for len(q) > 0 {
			p := q[0]
			q = q[1:]
			flag := false
			if size[p] > 3 {
				fmt.Fprintf(out, "-1\n")
				continue out
			} else if size[p] == 3 {
				flag = true
			}
			for _, e := range g[p] {
				a, b := e.a, e.b
				if !vis[b] {
					if flag {
						ans = append(ans, b)
					} else {
						size[a] += size[p]
					}
					vis[b] = true
					degree[a] -= 1
					if degree[a] == 1 {
						q = append(q, a)
					}
				}
			}
		}
		fmt.Fprintf(out, "%d\n", len(ans))
		for _, e := range ans {
			fmt.Fprintf(out, "%d ", e+1)
		}
		fmt.Fprintf(out, "\n")
	}
}
