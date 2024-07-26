package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF992B(os.Stdin, os.Stdout) }

func CF992B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var l, r, x, y int
	fmt.Fscan(in, &l, &r, &x, &y)
	count := 0
	mul := x * y
	i := (l + x - 1) / x * x
	for ; i <= r && i*i < mul; i += x {
		if mul%i == 0 && mul/i <= r && gcd992b(i, mul/i) == x {
			count += 2
		}
	}
	if i <= r && mul/i <= r && i == x && i*i == mul {
		count += 1
	}
	fmt.Fprintf(out, "%d", count)
}

func gcd992b(a int, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
