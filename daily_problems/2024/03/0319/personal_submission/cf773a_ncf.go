package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF773A(os.Stdin, os.Stdout) }

func CF773A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, x, y, p, q int
	fmt.Fscan(in, &t)
	for i := 0; i < t; i++ {
		fmt.Fscan(in, &x, &y, &p, &q)
		if p == q {
			if x != y {
				fmt.Fprintf(out, "-1\n")
			} else {
				fmt.Fprintf(out, "0\n")
			}
		} else if p == 0 {
			if x != 0 {
				fmt.Fprintf(out, "-1\n")
			} else {
				fmt.Fprintf(out, "0\n")
			}
		} else {
			if p*y >= q*x {
				//x / y <= p / q
				//(x + m) / (y + m) >= p / q
				// qx + qm >= py + pm
				// m >= (py - qx) / (q - p)
				fmt.Fprintf(out, "%d\n", (y+(p*y-q*x+q-p-1)/(q-p)+q-1)/q*q-y)
			} else {
				//x / y > p / q
				//x / (y + m) <= p / q
				//m >= (qx - py) / p
				fmt.Fprintf(out, "%d\n", (y+(q*x-p*y+p-1)/p+q-1)/q*q-y)
			}
		}
	}
}
