package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() { CF301A(os.Stdin, os.Stdout) }

func CF301A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, t int
	fmt.Fscan(in, &n)
	a := make([]int, n*2-1)
	count := 0
	ans := 0
	for i := 0; i < 2*n-1; i++ {
		fmt.Fscan(in, &t)
		if t < 0 {
			t = -t
			count += 1
		}
		ans += t
		a[i] = t
	}
	if count > 0 {
		mn := math.MaxInt
		for i := 0; i < n*2-1; i++ {
			if mn > a[i] {
				mn = a[i]
			}
		}
		if count%2 == 1 && count%n%2 == 1 && (count > n || (count+n)%2 == 1) {
			ans -= 2 * mn
		}
	}
	fmt.Fprintf(out, "%d\n", ans)
}
