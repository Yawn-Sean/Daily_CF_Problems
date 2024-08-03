package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n+1)
	sz := make([]int, int(2e5)+10)
	mx := 0
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &a[i])
		sz[a[i]]++
		mx = max(mx, a[i])
	}
	var dfs1 func(int)
	dfs1 = func(u int) {
		if u > mx {
			return
		}
		dfs1(u << 1)
		dfs1(u<<1 + 1)
		sz[u] += sz[u<<1] + sz[u<<1+1]
	}
	dfs1(1)
	var root int
	for i := 100000; i >= 1; i-- {
		if sz[i] == n {
			root = i
			break
		}
	}
	var dfs2 func(int, int)
	ans := 0
	for i := 1; i <= n; i++ {
		for a[i]^root != 0 {
			ans++
			a[i] >>= 1
		}
	}
	dfs2 = func(u, sum int) {
		if u > mx {
			return
		}
		tmp := sum + sz[1] - 2*sz[u]
		ans = min(ans, tmp)
		dfs2(u<<1, tmp)
	}
	dfs2(root<<1, ans)
	fmt.Fprintln(out, ans)
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

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}