package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	g := make([][]int, n+1)
	for i := 1; i <= n; i++ {
		g[i] = make([]int, 0)
	}
	c := make([]int, n+1)
	var root int
	for i := 1; i <= n; i++ {
		var p int
		fmt.Fscan(in, &p)
		fmt.Fscan(in, &c[i])
		if p == 0 {
			root = i
		} else {
			g[p] = append(g[p], i)
		}
	}
	flag := make([]int, n+1)
	var judge func(x int) int
	judge = func(x int) int {
		var tot, j int
		for j = 1; j <= n && tot < x; j++ {
			if flag[j] == 0 {
				tot++
			}
		}
		flag[j-1] = 1
		return j - 1
	}
	sz := make([]int, n+1)
	ans := make([]int, n+1)
	var dfs func(x int)
	dfs = func(x int) {
		sz[x] = 1
		ans[x] = judge(c[x] + 1)
		for _, y := range g[x] {
			dfs(y)
			sz[x] += sz[y]
		}
	}
	dfs(root)
	for i := 1; i <= n; i++ {
		if sz[i]-1 < c[i] {
			fmt.Fprintln(out, "NO")
			return
		}
	}
	fmt.Fprintln(out, "YES")
	for i := 1; i <= n; i++ {
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
