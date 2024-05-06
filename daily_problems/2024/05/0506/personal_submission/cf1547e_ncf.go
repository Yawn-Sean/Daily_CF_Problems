package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
)

func main() { CF1547E(os.Stdin, os.Stdout) }

func CF1547E(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var q, n, k int
	fmt.Fscan(in, &q)

	for i := 0; i < q; i++ {
		fmt.Fscan(in, &n, &k)
		ac := make([][]int, k)
		for j := 0; j < k; j++ {
			ac[j] = make([]int, 2)
			fmt.Fscan(in, &ac[j][0])
		}
		suf := make([]int, n+1)
		for j := 0; j < k; j++ {
			fmt.Fscan(in, &ac[j][1])
		}
		sort.Slice(ac, func(i, j int) bool {
			return ac[i][0] < ac[j][0]
		})
		idx := k - 1
		suf[n] = math.MaxInt32
		for i := n - 1; i > -1; i-- {
			suf[i] = suf[i+1] + 1
			if idx > -1 && ac[idx][0] == i+1 {
				suf[i] = min1547e(suf[i], ac[idx][1])
				idx--
			}
		}
		pre := math.MaxInt32
		idx = 0
		for i := 0; i < n; i++ {
			pre = min1547e(pre+1, suf[i])
			if idx < k && ac[idx][0] == i+1 {
				pre = min1547e(pre, ac[idx][1])
				idx++
			}
			fmt.Fprintf(out, "%d ", pre)
		}
		fmt.Fprintf(out, "\n")
	}
}

func min1547e(a, b int) int {
	if a < b {
		return a
	}
	return b
}
