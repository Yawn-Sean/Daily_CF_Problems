package main

import (
	"bufio"
	. "fmt"
	"io"
	"math"
	"os"
	"sort"
)

type pair struct{ b, p int }

func solve(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, c, d, b, p int
	Fscan(in, &n, &c, &d)
	ac, ad := make([]pair, 0, n), make([]pair, 0, n)
	for i := 0; i < n; i++ {
		var t string
		Fscan(in, &b, &p, &t)
		if t == "C" {
			ac = append(ac, pair{b, p})
		} else {
			ad = append(ad, pair{b, p})
		}
	}

	calc := func(a []pair, v int) (one, two int) {
		one, two = math.MinInt32, math.MinInt32
		for _, p := range a {
			if p.p <= v {
				one = max(one, p.b)
			}
		}
		sort.Slice(a, func(i, j int) bool { return a[i].p < a[j].p })
		premx := make([]int, len(a)+1)
		premx[0] = math.MinInt32
		for i, p := range a {
			premx[i+1] = max(p.b, premx[i])
		}
		for i, j := len(a)-1, 0; i > 0; i-- {
			for j < i && a[j].p+a[i].p <= v {
				j++
			}
			j = min(i, j)
			two = max(two, a[i].b+premx[j])
		}
		return
	}

	oc, tc := calc(ac, c)
	od, td := calc(ad, d)
	Fprintln(out, max(tc, td, oc+od, 0))
}

func main() {
	solve(os.Stdin, os.Stdout)
}
