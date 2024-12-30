package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
)

func main() { CF1028C(os.Stdin, os.Stdout) }

func CF1028C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, v int
	fmt.Fscan(in, &n)
	t1 := makeDynamicSegmentTree1028c(n)
	t2 := makeDynamicSegmentTree1028c(n)
	t3 := makeDynamicSegmentTree1028c(n)
	t4 := makeDynamicSegmentTree1028c(n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &v)
		t1.updateRange(i, i, v)
		fmt.Fscan(in, &v)
		t2.updateRange(i, i, v)
		fmt.Fscan(in, &v)
		t3.updateRange(i, i, -v)
		fmt.Fscan(in, &v)
		t4.updateRange(i, i, -v)
	}

	for i := 1; i < n-1; i++ {
		x1 := max(t1.queryRange(0, i-1), t1.queryRange(i+1, n-1))
		y1 := max(t2.queryRange(0, i-1), t2.queryRange(i+1, n-1))
		x2 := -max(t3.queryRange(0, i-1), t3.queryRange(i+1, n-1))
		y2 := -max(t4.queryRange(0, i-1), t4.queryRange(i+1, n-1))
		if x1 <= x2 && y1 <= y2 {
			fmt.Fprintf(out, "%d %d", x1, y1)
			return
		}
	}
	x1 := t1.queryRange(1, n-1)
	y1 := t2.queryRange(1, n-1)
	x2 := -t3.queryRange(1, n-1)
	y2 := -t4.queryRange(1, n-1)
	if x1 <= x2 && y1 <= y2 {
		fmt.Fprintf(out, "%d %d", x1, y1)
		return
	}
	x1 = t1.queryRange(0, n-2)
	y1 = t2.queryRange(0, n-2)
	x2 = -t3.queryRange(0, n-2)
	y2 = -t4.queryRange(0, n-2)
	if x1 <= x2 && y1 <= y2 {
		fmt.Fprintf(out, "%d %d", x1, y1)
		return
	}
	fmt.Fprintf(out, "no answer")
}
