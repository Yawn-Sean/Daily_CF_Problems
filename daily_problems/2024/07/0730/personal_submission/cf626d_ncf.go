package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF626D(os.Stdin, os.Stdout) }

func CF626D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	v := make([]int, 5000)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			v[abs(a[i]-a[j])] += 1
		}
	}

	suf := make([]int, 5001)
	for i := 4999; i > -1; i-- {
		suf[i] = suf[i+1] + v[i]
	}

	ans := 0
	for i := 0; i < 5000; i++ {
		for j := 0; i+j+1 < 5000; j++ {
			ans += v[i] * v[j] * suf[i+j+1]
		}
	}
	fmt.Fprintf(out, "%.12f", float64(ans)/float64(pow3(n*(n-1)/2)))
}

func pow3(a int) int {
	return a * a * a
}

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}
