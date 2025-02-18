package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m, u, v int
	fmt.Fscan(in, &n, &m)
	adj := make([][]int, n+1)
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &u, &v)
		adj[u] = append(adj[u], v)
	}
	ans := make([]int, 0, n)
	vis := make([]bool, n+1)
	var dfs func(int, int)
	dfs = func(u, p int) {
		vis[u] = true
		for _, v := range adj[u] {
			if !vis[v] {
				dfs(v, u)
			}
		}
		ans = append(ans, u)
	}
	for i := 1; i <= n; i++ {
		if !vis[i] {
			dfs(i, 0)
		}
	}
	for i := range ans {
		fmt.Fprint(out, ans[i], " ")
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
