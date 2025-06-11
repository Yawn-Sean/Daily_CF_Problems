package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, p int
	fmt.Fscan(in, &n, &p)
	a := make([]float64, n)
	var l, r int
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &l, &r)
		a[i] = float64(r/p-(l-1)/p) / float64(r-l+1)
	}
	var sum float64
	for i := 0; i < n; i++ {
		sum += a[i] + a[(i+1)%n] - a[i]*a[(i+1)%n]
	}
	fmt.Fprintf(out, "%.9f\n", sum*2000)
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
