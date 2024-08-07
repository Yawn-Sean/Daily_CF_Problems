package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
)

func main() { CF1177B(os.Stdin, os.Stdout) }

func CF1177B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	if n < 10 {
		fmt.Fprintf(out, "%d", n)
		return
	}
	i := 1
	last := 0
	v := 9
	for v < n {
		x := pow(10, i)
		last = v
		i += 1
		v += 9 * x * i
	}
	n -= last
	x := (n - 1) / i
	n = (n-1)%i + 1
	v = pow(10, i-1) + x
	sv := strconv.Itoa(v)
	fmt.Fprintf(out, "%c", sv[n-1])
}

func pow(a, b int) int {
	i := 1
	for b > 0 {
		i *= a
		b--
	}
	return i
}
