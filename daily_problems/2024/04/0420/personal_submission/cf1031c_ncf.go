package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1031C(os.Stdin, os.Stdout) }

func CF1031C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var a, b int
	fmt.Fscan(in, &a, &b)
	x := (a + b) << 1
	l, r := 0, int(1e5)
	for l <= r {
		mid := (l + r) >> 1
		if mid*(mid+1) > x {
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	l -= 1
	var ansA, ansB []int
	for l > 0 {
		if a-l >= 0 {
			a -= l
			ansA = append(ansA, l)
		} else {
			ansB = append(ansB, l)
		}
		l -= 1
	}
	fmt.Fprintf(out, "%d\n", len(ansA))
	for i := 0; i < len(ansA); i++ {
		fmt.Fprintf(out, "%d ", ansA[i])
	}
	fmt.Fprintf(out, "\n%d\n", len(ansB))
	for i := 0; i < len(ansB); i++ {
		fmt.Fprintf(out, "%d ", ansB[i])
	}
}
