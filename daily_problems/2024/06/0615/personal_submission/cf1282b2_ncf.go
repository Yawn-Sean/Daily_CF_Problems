package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"slices"
)

func main() { CF1282B2(os.Stdin, os.Stdout) }

func CF1282B2(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, p, k int
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &p, &k)
		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
		}
		slices.Sort(a)
		dp := make([]int, n+1)
		for i := 1; i <= n; i++ {
			if i < k {
				dp[i] = dp[i-1] + a[i-1]
			} else {
				dp[i] = dp[i-k] + a[i-1]
			}
		}
		for i := n; i > -1; i-- {
			if dp[i] <= p {
				fmt.Fprintf(out, "%d\n", i)
				break
			}
		}
	}
}
