package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1016D(os.Stdin, os.Stdout) }

func CF1016D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, m int
	for t = 1; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &m)
		a := make([]int, n)
		b := make([]int, m)
		ans := make([][]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
			ans[i] = make([]int, m)
		}
		for i := 0; i < m; i++ {
			fmt.Fscan(in, &b[i])
		}
		cur := 0
		for i := 0; i < n-1; i++ {
			ans[i][m-1] = a[i]
			cur ^= ans[i][m-1]
		}
		ans[n-1][m-1] = cur ^ b[m-1]
		cur = a[n-1] ^ ans[n-1][m-1]
		for i := m - 2; i > -1; i-- {
			ans[n-1][i] = b[i]
			cur ^= ans[n-1][i]
		}
		if cur != 0 {
			fmt.Fprintf(out, "NO")
		} else {
			fmt.Fprintf(out, "YES\n")
			for i := 0; i < n; i++ {
				for j := 0; j < m; j++ {
					fmt.Fprintf(out, "%d ", ans[i][j])
				}
				fmt.Fprintf(out, "\n")
			}
		}
	}
}
