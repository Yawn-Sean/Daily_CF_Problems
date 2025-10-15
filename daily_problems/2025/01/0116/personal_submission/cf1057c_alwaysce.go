package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func CF1057C(in io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, s, k int
	fmt.Fscan(in, &n, &s, &k)
	s--
	nums := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &nums[i])
	}

	var color string
	fmt.Fscan(in, &color)

	inf := 1000_000_000
	// dp[i][k]: 在位置i吃了总共k糖果的最小成本
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, k+1)
		for j := 0; j <= k; j++ {
			dp[i][j] = inf
		}
	}

	for i := 0; i < n; i++ {
		candies := min(nums[i], k)
		dp[i][candies] = abs(i - s)
	}

	order := make([]int, n)
	for i := 0; i < n; i++ {
		order[i] = i
	}
	sort.Slice(order, func(i, j int) bool {
		return nums[order[i]] < nums[order[j]]
	})

	for i := 0; i < n; i++ {
		idx1 := order[i]
		for j := 0; j < n; j++ {
			idx2 := order[j]
			if nums[idx2] >= nums[idx1] {
				break
			}

			if color[idx1] != color[idx2] {
				for v := 0; v <= k; v++ {
					newCandies := min(v+nums[idx1], k)
					dp[idx1][newCandies] = min(dp[idx1][newCandies], dp[idx2][v]+abs(idx1-idx2))
				}
			}
		}
	}
	ans := inf
	for i := 0; i < n; i++ {
		ans = min(ans, dp[i][k])
	}

	if ans == inf {
		fmt.Fprintln(out, -1)
	} else {
		fmt.Fprintln(out, ans)
	}
}

func main() {
	CF1057C(bufio.NewReader(os.Stdin), os.Stdout)
}
