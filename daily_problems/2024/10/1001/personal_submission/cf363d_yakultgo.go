package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m, a int
	fmt.Fscan(in, &n, &m, &a)
	b := make([]int, n)
	for i := range b {
		fmt.Fscan(in, &b[i])
	}
	p := make([]int, m)
	for i := range p {
		fmt.Fscan(in, &p[i])
	}
	sort.Slice(b, func(i, j int) bool { return b[i] > b[j] })
	sort.Slice(p, func(i, j int) bool { return p[i] < p[j] })
	left, right := 0, min(n, m)+1
	for left < right {
		mid := (left + right) >> 1
		need := 0
		for i, j := 0, mid-1; i < mid; i, j = i+1, j-1 {
			if p[j] > b[i] {
				need += p[j] - b[i]
			}
		}
		if need <= a {
			left = mid + 1
		} else {
			right = mid
		}
	}
	cnt := left - 1
	sum := 0
	for i := 0; i < cnt; i++ {
		sum += p[i]
	}
	fmt.Fprintln(out, cnt, max(0, sum-a))
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
