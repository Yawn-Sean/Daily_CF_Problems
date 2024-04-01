package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

// https://codeforces.com/problemset/submission/1027/254046191
func main() { CF1027D(os.Stdin, os.Stdout) }

func CF1027D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n int
	t = 1
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n)
		c, a := make([]int, n), make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &c[i])
		}
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
			a[i] -= 1
		}
		vis := make([]bool, n)
		ans := 0
		disjointSet := makeSet1027d(n)
		for i := 0; i < n; i++ {
			if vis[i] {
				continue
			}
			cur := i
			for !vis[cur] {
				vis[cur] = true
				union1027d(cur, a[cur], disjointSet)
				cur = a[cur]
			}
			p := find1027d(cur, disjointSet)
			if disjointSet.val[p] > 0 {
				continue
			}
			start := cur
			cost := c[start]
			cur = a[cur]
			for cur != start {
				cost = min1027d(cost, c[cur])
				cur = a[cur]
			}
			disjointSet.val[p] = cost
			ans += cost
		}
		fmt.Fprintf(out, "%d", ans)
	}
}

func min1027d(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max1027d(a, b int) int {
	if a > b {
		return a
	}
	return b
}

