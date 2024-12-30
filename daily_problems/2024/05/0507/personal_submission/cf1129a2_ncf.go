package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1129A2(os.Stdin, os.Stdout) }

func CF1129A2(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m, a, b int
	fmt.Fscan(in, &n, &m)
	dist := make([]int, n) // 有个(count[j] - 1) * n， 所以这里初始化成n就算没更新也没关系
	for i := 0; i < n; i++ {
		dist[i] = n
	}
	count := make([]int, n)
	for i := 0; i < m; i++ {
		fmt.Fscan(in, &a, &b)
		a, b = a-1, b-1
		count[a] += 1
		dist[a] = min(dist[a], (b-a+n)%n)
	}
	for i := 0; i < n; i++ {
		cur := 0
		for step := 0; step < n; step++ {
			j := (i + step) % n
			if count[j] > 0 {
				cur = max(cur, step+(count[j]-1)*n+dist[j])
			}
		}
		fmt.Fprintf(out, "%d ", cur)
	}
}
