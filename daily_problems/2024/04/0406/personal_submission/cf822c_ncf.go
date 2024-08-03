package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
)

func main() { CF822C(os.Stdin, os.Stdout) }

func CF822C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, x int
	for t = 1; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &x)
		a := make([][]int, n)
		for i := 0; i < n; i++ {
			a[i] = make([]int, 3)
			fmt.Fscan(in, &a[i][0], &a[i][1], &a[i][2])
		}
		sort.Slice(a, func(i, j int) bool {
			if a[i][1] != a[j][1] {
				return a[i][0] < a[j][0]
			}
			return a[i][1] < a[j][1]
		})
		m := map[int][][]int{}
		ans := math.MaxInt
		for i := 0; i < n; i++ {
			cur := m[x-(a[i][1]-a[i][0]+1)]
			if len(cur) > 0 {
				left, right := 0, len(cur)-1
				for left <= right {
					mid := (left + right) >> 1
					if cur[mid][1] >= a[i][0] {
						right = mid - 1
					} else {
						left = mid + 1
					}
				}
				if left > 0 {
					ans = min822c(ans, cur[left-1][2]+a[i][2])
				}
			}
			offset := a[i][1] - a[i][0] + 1
			// 如果cost更大，那么必然可以选择更小的r，因此形成r单调递增，cost单调递减的单调栈，根据a[i]的l对单调栈元素的r二分，得到的第一个值就是最小的cost
			if len(m[offset]) == 0 || a[i][2] < m[offset][len(m[offset])-1][2] {
				m[offset] = append(m[offset], a[i])
			}
		}
		if ans == math.MaxInt {
			fmt.Fprintf(out, "-1")
		} else {
			fmt.Fprintf(out, "%d", ans)
		}
	}
}

func min822c(a, b int) int {
	if a < b {
		return a
	}
	return b
}
