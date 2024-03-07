package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() {
	cf453A(os.Stdin, os.Stdout)
}

func cf453A(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var m, n int
	fmt.Fscan(in, &m, &n)
	fmt.Fprintf(out, "%.12f", solveA(m, n))
}

func solveA(m, n int) float64 {
	var res, pre float64
	for i := 1; i <= m; i++ {
		cur := math.Pow(float64(i)/float64(m), float64(n))
		res += (cur - pre) * float64(i)
		pre = cur
	}
	return res
}
