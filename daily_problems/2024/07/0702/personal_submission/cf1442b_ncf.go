package main

import (
"bufio"
"fmt"
"io"
"os"
)

func main() { CF1442B(os.Stdin, os.Stdout) }

func CF1442B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, k int
	fmt.Fscan(in, &t)
out:
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &k)
		a := make([]int, n)
		ma := make([]int, n)
		mb := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
			a[i] -= 1
			ma[a[i]] = i
			mb[i] = -1
		}
		b := make([]int, k)
		for i := 0; i < k; i++ {
			fmt.Fscan(in, &b[i])
			b[i] -= 1
			mb[b[i]] = i
		}
		mod := 998244353
		ans := 1
		for i := 0; i < k; i++ {
			idx := ma[b[i]]
			count := 0
			if idx > 0 && (mb[a[idx-1]] == -1 || mb[a[idx-1]] < mb[a[idx]]) {
				count++
			}
			if idx < n-1 && (mb[a[idx+1]] == -1 || mb[a[idx+1]] < mb[a[idx]]) {
				count++
			}
			if count == 0 {
				fmt.Fprintf(out, "0\n")
				continue out
			}
			ans = ans * count % mod
		}
		fmt.Fprintf(out, "%d\n", ans)
	}
}
