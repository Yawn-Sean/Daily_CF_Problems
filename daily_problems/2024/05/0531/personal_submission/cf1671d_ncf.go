package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1671D(os.Stdin, os.Stdout) }

func CF1671D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, x int
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &x)
		a := make([]int, n)
		mx, mn := 0, int(2e5)
		ans := 0
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
			mx = max(mx, a[i])
			mn = min(mn, a[i])
			if i > 0 {
				ans += abs(a[i] - a[i-1])
			}
		}
		ans += min(abs(a[0]-1), abs(a[len(a)-1]-1), (mn-1)<<1)
		if x > mx {
			ans += min(abs(a[0]-x), abs(a[len(a)-1]-x), (x-mx)<<1)
		}
		fmt.Fprintf(out, "%d\n", ans)
	}
}

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}
