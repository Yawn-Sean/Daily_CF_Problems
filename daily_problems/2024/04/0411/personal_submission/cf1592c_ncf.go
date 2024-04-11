package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1592C(os.Stdin, os.Stdout) }

func CF1592C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, k, u, v int
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &k)
		a := make([]int, n)
		xor := 0
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
			xor ^= a[i]
		}
		g := make([][]int, n)
		for i := 0; i < n-1; i++ {
			fmt.Fscan(in, &u, &v)
			u, v = u-1, v-1
			g[u] = append(g[u], v)
			g[v] = append(g[v], u)
		}
		if xor == 0 {
			fmt.Fprintf(out, "YES\n")
			continue
		}
		count := 0
		var dfs func(cur, fa int) int
		dfs = func(cur, fa int) int {
			res := a[cur]
			for _, e := range g[cur] {
				if e != fa {
					s := dfs(e, cur)
					if s == xor {
						count += 1
					} else {
						res ^= s
					}
				}
			}
			return res
		}
		dfs(0, -1)
		if count >= 2 && k >= 3 {
			fmt.Fprintf(out, "YES\n")
		} else {
			fmt.Fprintf(out, "NO\n")
		}
	}
}
