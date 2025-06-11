package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"slices"
)

type pair struct{ x, y int }

func solveC(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, p int
	fmt.Fscan(in, &n, &p)
	ans := 0
	a := make([]pair, n)
	mp1, mp2 := make([]int, n+1), map[pair]int{}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i].x, &a[i].y)
		// 保证 x <= y
		if a[i].x > a[i].y {
			a[i].x, a[i].y = a[i].y, a[i].x
		}
		mp1[a[i].x]++
		mp1[a[i].y]++
		mp2[a[i]]++
	}

	cnts := make([]int, n)
	for i := 0; i < n; i++ {
		cnts[i] = mp1[i+1]
	}
	slices.Sort(cnts)
	// cnts[i] + cnts[j] >= p 的个数 (i < j)
	for i, j := 0, n-1; i < n; i++ {
		j = max(j, i)
		for j > i && cnts[i]+cnts[j] >= p {
			j--
		}
		ans += n - 1 - j
	}

	for i := 0; i < n; i++ {
		// 找出不满足的，cnts[i] + cnts[j] - cnts[(i,j)] < p
		if mp1[a[i].x]+mp1[a[i].y] >= p && mp1[a[i].x]+mp1[a[i].y]-mp2[a[i]] < p {
			ans--
			// 防止重复计算
			mp2[a[i]] = 0
		}
	}

	fmt.Fprintln(out, ans)
}

func main() {
	solveC(os.Stdin, os.Stdout)
}
