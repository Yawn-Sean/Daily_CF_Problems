package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() { CF908C(os.Stdin, os.Stdout) }

func CF908C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, r int
	fmt.Fscan(in, &n, &r)
	x := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x[i])
	}
	d := r << 1
	ans := make([]float64, n)
	for i := 0; i < n; i++ {
		h := float64(r)
		for j := 0; j < i; j++ {
			diff := abs908c(x[i], x[j])
			if diff <= d {
				h = max908c(h, math.Sqrt(float64(d*d-diff*diff))+ans[j])
			}
		}
		ans[i] = h
		fmt.Fprintf(out, "%.12f ", h)
	}
}

func max908c(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

func abs908c(a, b int) int {
	if a > b {
		return a - b
	}
	return b - a
}
