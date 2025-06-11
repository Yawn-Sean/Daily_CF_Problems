package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func solveD(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	a, b := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &b[i])
	}

	f := func(a []int) []int {
		bit := newBITWithOne(n)
		res := make([]int, n)
		for i := 0; i < n; i++ {
			res[i] = bit.query(a[i]) - 1
			bit.add(a[i], -1)
		}
		return res
	}
	ra, rb := f(a), f(b)
	rc := make([]int, n)
	for i := n - 1; i >= 0; i-- {
		rc[i] += ra[i] + rb[i]
		if rc[i] >= n-i {
			rc[i] -= n - i
			if i > 0 {
				rc[i-1]++
			}
		}
	}

	bit := newBITWithOne(n)
	for i := 0; i < n; i++ {
		x := sort.Search(n, func(j int) bool { return bit.query(j) >= rc[i]+1 })
		bit.add(x, -1)
		fmt.Fprint(out, x, " ")
	}
	fmt.Fprintln(out)
}

func main() {
	solveD(os.Stdin, os.Stdout)
}

type BIT []int

func newBITWithOne(n int) BIT {
	t := make(BIT, n+1)
	for i := 0; i < n; i++ {
		t.add(i, 1)
	}
	return t
}

func (t BIT) op(a, b int) int {
	return a + b // max(a, b)
}

func (t BIT) query(x int) (res int) {
	for x++; x > 0; x -= x & -x {
		res = t.op(res, t[x])
	}
	return
}

func (t BIT) add(x, v int) {
	for x++; x < len(t); x += x & -x {
		t[x] = t.op(t[x], v)
	}
}
