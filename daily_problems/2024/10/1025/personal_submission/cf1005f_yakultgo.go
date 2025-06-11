package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m, k int
	fmt.Fscan(in, &n, &m, &k)
	type pair struct{ nex, idx int }
	adj := make([][]pair, n+1)
	var u, v int
	edges := make([]pair, m+1)
	for i := 1; i <= m; i++ {
		fmt.Fscan(in, &u, &v)
		adj[u] = append(adj[u], pair{v, i})
		adj[v] = append(adj[v], pair{u, i})
		edges[i] = pair{u, v}
	}
	qu := make([]int, n)
	qu = append(qu, 1)
	dp := make([]int, n+1)
	st := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		dp[i] = 1e9
	}
	dp[1] = 0
	for len(qu) > 0 {
		u, qu = qu[0], qu[1:]
		for _, p := range adj[u] {
			v := p.nex
			if dp[v] > dp[u]+1 {
				dp[v] = dp[u] + 1
				qu = append(qu, v)
			}
		}
	}
	for i := 1; i <= m; i++ {
		u, v = edges[i].nex, edges[i].idx
		if dp[u] > dp[v] {
			u, v = v, u
		}
		if dp[u] == dp[v]-1 {
			st[v] = append(st[v], i)
		}
	}
	mi := 1
	for i := 2; i <= n; i++ {
		mi *= len(st[i])
		if mi >= k {
			break
		}
	}
	k = min(k, mi)
	vis2 := make([]int, m+1)
	var dfs func(int)
	dfs = func(u int) {
		if u == n+1 {
			for i := 1; i <= m; i++ {
				fmt.Fprint(out, vis2[i])
			}
			fmt.Fprintln(out)
			k--
			if k == 0 {
				out.Flush()
				os.Exit(0)
			}
			return
		}
		for _, v := range st[u] {
			vis2[v] = 1
			dfs(u + 1)
			vis2[v] = 0
		}
	}
	fmt.Fprintln(out, k)
	dfs(2)
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
