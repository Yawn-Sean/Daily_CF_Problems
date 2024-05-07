package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF989C(os.Stdin, os.Stdout) }

func CF989C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var a, b, c, d int
	fmt.Fscan(in, &a, &b, &c, &d)
	n, m := ((a+47)/49+(b+47)/49+(c+47)/49+(d+47)/49)*3+4, 50
	fmt.Fprintf(out, "%d %d\n", n, m)
	handle(a, "A", "B", out)
	handle(b, "B", "A", out)
	handle(c, "C", "D", out)
	handle(d, "D", "C", out)
}

func handle(n int, s1, s2 string, out io.Writer) {
	printLine(s2, out)
	for n > 1 {
		for i := 0; i < 50; i += 2 {
			if n > 1 {
				fmt.Fprintf(out, s1+s2)
				n -= 1
			} else {
				fmt.Fprintf(out, s2+s2)
			}
		}
		fmt.Fprintf(out, "\n")
		for i := 0; i < 48; i += 2 {
			if n > 1 {
				fmt.Fprintf(out, s2+s1)
				n -= 1
			} else {
				fmt.Fprintf(out, s2+s2)
			}
		}
		fmt.Fprintf(out, s2+s2+"\n")
		printLine(s2, out)
	}
}

func printLine(s string, out io.Writer) {
	for i := 0; i < 50; i++ {
		fmt.Fprintf(out, s)
	}
	fmt.Fprintf(out, "\n")
}
