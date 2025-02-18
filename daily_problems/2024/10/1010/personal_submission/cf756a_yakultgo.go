package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	p := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &p[i])
		p[i]--
	}
	ans := 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &b[i])
		if b[i] == 1 {
			ans++
		}
	}
	vis := make([]bool, n)
	var dfs func(int)
	dfs = func(x int) {
		vis[x] = true
		if !vis[p[x]] {
			dfs(p[x])
		}
	}
	count := 0
	for i := 0; i < n; i++ {
		if !vis[i] {
			dfs(i)
			count++
		}
	}
	if count == 1 {
		count = 0
	}
	if ans%2 == 0 {
		count++
	}
	fmt.Fprintln(out, count)
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
