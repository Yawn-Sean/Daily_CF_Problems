package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() {
	cf1194D(os.Stdin, os.Stdout)
}

func cf1194D(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var t int
	var n, k int
	for fmt.Fscan(in, &t); t > 0; t-- {
		fmt.Fscan(in, &n, &k)
		fmt.Fprintln(out, solveD(n, k))
	}
}

const (
	A = "Alice"
	B = "Bob"
)

func solveD(n, k int) string {
	if k%3 == 0 {
		n %= k + 1
		if n == k {
			return A
		}

		if n%3 == 0 {
			return B
		}
		return A
	}

	if n%3 == 0 {
		return B
	}
	return A
}
