package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1025C(os.Stdin, os.Stdout) }

// 灵感来源：https://leetcode.cn/problems/rotate-array/description/
func CF1025C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var s string
	fmt.Fscan(in, &s)
	n := len(s)

	if n == 1 {
		fmt.Fprintf(out, "1")
		return
	}

	pre := make([]int, n)
	pre[0] = 1
	ans := 1
	start := 0
	for i := 1; i < n; i++ {
		if s[i] != s[i-1] {
			pre[i] = pre[i-1] + 1
			ans = max(ans, pre[i])
			if pre[i] == i+1 {
				start = i
			}
		} else {
			pre[i] = 1
		}
	}
	if s[0] != s[n-1] {
		start += 1
		l, r := start, n-1
		for l <= r {
			mid := (l + r) / 2
			if pre[n-1]-pre[mid] == n-1-mid {
				r = mid - 1
			} else {
				l = mid + 1
			}
		}
		ans = max(ans, start+(n-l))
	}

	fmt.Fprintf(out, "%d", ans)
}
