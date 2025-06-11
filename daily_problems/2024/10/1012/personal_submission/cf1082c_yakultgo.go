package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m int
	fmt.Fscan(in, &n, &m)
	cnt := make([][]int, m+1)
	for i := 1; i <= m; i++ {
		cnt[i] = make([]int, 0)
	}
	var s, r int
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &s, &r)
		cnt[s] = append(cnt[s], r)
	}
	ans := make([]int, n+1)
	for i := 1; i <= m; i++ {
		sort.Slice(cnt[i], func(j, k int) bool {
			return cnt[i][j] > cnt[i][k]
		})
		sum := 0
		for j := 0; j < len(cnt[i]); j++ {
			sum += cnt[i][j]
			ans[j+1] += max(0, sum)
		}
	}
	fmt.Fprintln(out, slices.Max(ans))
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
