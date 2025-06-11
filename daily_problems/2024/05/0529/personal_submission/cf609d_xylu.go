package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

type tuple struct{ x, y, z int }

func main() {
	solveD(os.Stdin, os.Stdout)
}

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n, m, k, s int
	fmt.Fscan(in, &n, &m, &k, &s)
	a := make([][2]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i][0])
		if i > 0 {
			a[i][0] = min(a[i][0], a[i-1][0])
		}
	}
	for i := range a {
		fmt.Fscan(in, &a[i][1])
		if i > 0 {
			a[i][1] = min(a[i][1], a[i-1][1])
		}
	}

	pp := make([]tuple, m)
	for i := 0; i < m; i++ {
		var t, p int
		fmt.Fscan(in, &t, &p)
		pp[i] = tuple{p, t - 1, i + 1}
	}

	check := func(x int) bool {
		ps := make([]int, 0, m)
		for _, v := range pp {
			ps = append(ps, a[x][v.y]*v.x)
		}
		sort.Ints(ps)
		sum := 0
		for i := 0; i < k; i++ {
			sum += ps[i]
		}
		return sum <= s
	}

	ans := sort.Search(n, func(x int) bool { return check(x) }) + 1
	if ans > n {
		fmt.Fprintln(out, -1)
		return
	}

	fmt.Fprintln(out, ans)
	ps := make([]tuple, 0, m)
	for _, v := range pp {
		ps = append(ps, tuple{a[ans-1][v.y] * v.x, v.y, v.z})
	}
	sort.Slice(ps, func(i, j int) bool { return ps[i].x < ps[j].x })
	mn := [2]int{}
	for i := 0; i < ans; i++ {
		for j := 0; j < 2; j++ {
			if mn[j] == 0 && a[i][j] == a[ans-1][j] {
				mn[j] = i + 1
			}
		}
	}
	for i := 0; i < k; i++ {
		fmt.Fprintln(out, ps[i].z, mn[ps[i].y])
	}
}
