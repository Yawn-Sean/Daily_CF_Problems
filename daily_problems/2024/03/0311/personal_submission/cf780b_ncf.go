package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() { CF780B(os.Stdin, os.Stdout) }

func CF780B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	x, v := make([]float64, n), make([]float64, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x[i])
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &v[i])
	}
	l, r := 0.0, 2000000000.0
	minValue := 0.0000001
	for l <= r {
		mid := (l + r) / 2
		ll, rr := -math.MaxFloat64, math.MaxFloat64
		flag := true
		for i := 0; i < n; i++ {
			offset := v[i] * mid
			ll = max780b(ll, x[i]-offset)
			rr = min780b(rr, x[i]+offset)
			if rr < ll {
				flag = false
				break
			}
		}
		if flag {
			r = mid - minValue
		} else {
			l = mid + minValue
		}
	}
	fmt.Fprintf(out, "%.12f ", l)
}

func max780b(a, b float64) float64 {
	if a > b {
		return a
	}
	return b
}

func min780b(a, b float64) float64 {
	if a > b {
		return b
	}
	return a
}
