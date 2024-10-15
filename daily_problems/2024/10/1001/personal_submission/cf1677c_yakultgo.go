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
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &a[i])
	}
	b := make([]int, n+1)
	p := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &b[i])
		p[a[i]] = b[i]
	}
	cnt := 0
	vis := make([]int, n+1)
	for i := 1; i <= n; i++ {
		if vis[i] == 0 {
			tmp := 0
			for j := i; vis[j] == 0; j = p[j] {
				vis[j] = 1
				tmp++
			}
			cnt += tmp / 2
		}
	}
	fmt.Fprintln(out, 2*cnt*(n-cnt))
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	fmt.Fscan(in, &T)
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
