package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() { CF1175C(os.Stdin, os.Stdout) }

func CF1175C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, k int
	fmt.Fscan(in, &t)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &k)
		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
		}
		if k == 0 {
			fmt.Fprintf(out, "%d\n", a[0])
			continue
		}
		ans, mn := math.MaxInt, math.MaxInt
		for i := k; i < n; i++ {
			cur := (a[i] + a[i-k]) / 2
			if mn > a[i]-cur {
				mn = a[i] - cur
				ans = cur
			}
		}
		fmt.Fprintf(out, "%d\n", ans)
	}
}
