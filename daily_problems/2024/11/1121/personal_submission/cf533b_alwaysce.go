package main

import (
	"bufio"
	"fmt"
	"io"
)

func cf533B(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*

	 */
	var n int
	fmt.Fscan(in, &n)

	path := make([][]int, n)
	weight := make([]int64, n)
	for i := 0; i < n; i++ {
		var pi int
		var wt int64
		fmt.Fscan(in, &pi, &wt)
		if pi != -1 {
			pi--
			path[pi] = append(path[pi], i)
		}
		weight[i] = wt
	}

	dp := make([][]int64, n)
	for i := range dp {
		dp[i] = append(dp[i], int64(0), int64(-1_000_000_000_000))
	}

	var dfs func(int, int)
	dfs = func(u, fa int) {
		if len(path[u]) == 0 {
			dp[u][0], dp[u][1] = 0, weight[u]
			return
		}

		for _, v := range path[u] {
			if v == fa {
				continue
			}
			dfs(v, u)
			v0 := max(dp[v][0]+dp[u][0], dp[v][1]+dp[u][1])
			v1 := max(dp[v][0]+dp[u][1], dp[v][1]+dp[u][0])
			dp[u][0] = v0
			dp[u][1] = v1
		}
		dp[u][1] = max(dp[u][1], dp[u][0]+weight[u])
	}

	dfs(0, -1)
	fmt.Fprintln(out, max(dp[0][0], dp[0][1]))
}

//func main() {
//	cf533B(bufio.NewReader(os.Stdin), os.Stdout)
//}
