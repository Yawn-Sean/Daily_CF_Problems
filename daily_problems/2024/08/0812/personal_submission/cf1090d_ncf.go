package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1090D(os.Stdin, os.Stdout) }

func CF1090D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m, u, v int
	fmt.Fscan(in, &n, &m)
	if n == 1 || m == n*(n-1)/2 {
		fmt.Fprintf(out, "NO")
		return
	}
	fmt.Fprintf(out, "YES\n")
	g := make([][]int, n+1)
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	for i := 1; i <= n; i++ {
		if len(g[i]) < n-1 {
			vis := make([]bool, n+1)
			vis[i] = true
			for _, e := range g[i] {
				vis[e] = true
			}
			j := 1
			for ; j <= n; j++ {
				if !vis[j] {
					break
				}
			}
			v = n - 1
			u = 1
			for k := 1; k <= n; k++ {
				if k == i || k == j {
					fmt.Fprintf(out, "%d ", v)
					v++
				} else {
					fmt.Fprintf(out, "%d ", u)
					u++
				}
			}
			fmt.Fprintf(out, "\n")
			u = 1
			for k := 1; k <= n; k++ {
				if k == i || k == j {
					fmt.Fprintf(out, "%d ", n-1)
				} else {
					fmt.Fprintf(out, "%d ", u)
					u++
				}
			}
			return
		}
	}

}
