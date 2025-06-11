package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1660E(os.Stdin, os.Stdout) }

func CF1660E(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n int
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n)
		s := make([]string, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &s[i])
		}
		count := 0
		mx := 0
		for i := n - 1; i > -1; i-- {
			cur := 0
			for j, k := 0, i; j < n; j, k = j+1, k+1 {
				if s[k%n][j] == '1' {
					cur++
				}
			}
			count += cur
			mx = max(mx, cur)
		}
		fmt.Fprintf(out, "%d\n", count-mx+n-mx)
	}
}
