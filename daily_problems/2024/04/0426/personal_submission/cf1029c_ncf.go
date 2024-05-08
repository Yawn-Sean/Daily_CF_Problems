package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() { CF1029C(os.Stdin, os.Stdout) }

func CF1029C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	l, r := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &l[i], &r[i])
	}
	prel, prer := make([]int, n), make([]int, n)
	prel[0], prer[0] = math.MinInt, math.MaxInt
	for i := 0; i < n-1; i++ {
		prel[i+1] = max(prel[i], l[i])
		prer[i+1] = min(prer[i], r[i])
	}
	ans := 0
	sufl, sufr := math.MinInt, math.MaxInt
	for i := n - 1; i > -1; i-- {
		ans = max(ans, min(sufr, prer[i])-max(sufl, prel[i]))
		sufl = max(sufl, l[i])
		sufr = min(sufr, r[i])
	}
	fmt.Fprintf(out, "%d\n", ans)
}
