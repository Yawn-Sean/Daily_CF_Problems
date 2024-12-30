package main

import (
	"bufio"
	"fmt"
	"io"
	"math/bits"
	"os"
)

func solveC(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var x, d int
	fmt.Fscan(in, &x, &d)
	cnts, len := []int{}, 0
	for x > 0 {
		a := bits.Len(uint(x))
		if 1<<a-1 > x {
			a--
		}
		cnts = append(cnts, a)
		len += a
		x -= 1<<a - 1
	}
	fmt.Fprintln(out, len)
	for i, c := range cnts {
		for j := 0; j < c; j++ {
			fmt.Fprintf(out, "%d ", i*d+1)
		}
	}
	fmt.Fprintln(out)
}

func main() {
	solveC(os.Stdin, os.Stdout)
}
