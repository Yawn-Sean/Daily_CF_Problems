package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func solveB(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var s string
	fmt.Fscan(in, &s)
	n := len(s)

	// 判断是否有一个字符次数大于等于100次
	cnt := [26]int{}
	for _, c := range s {
		cnt[c-'a']++
		if cnt[c-'a'] == 100 {
			fmt.Fprintln(out, strings.Repeat(string(c), 100))
			return
		}
	}

	// 若没有，此时 n 最大为 26 * 99，考虑区间dp
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, n)
		dp[i][i] = 1
	}
	for l := 1; l < n; l++ {
		for i := 0; i+l < n; i++ {
			if s[i] == s[i+l] {
				dp[i][i+l] = dp[i+1][i+l-1] + 2
			} else {
				dp[i][i+l] = max(dp[i+1][i+l], dp[i][i+l-1])
			}
		}
	}
	// 记录答案
	l := min(100, dp[0][n-1])
	ans := make([]byte, l)
	i, j, si, sj := 0, n-1, 0, l-1
	for si <= sj {
		if s[i] == s[j] {
			ans[si], ans[sj] = s[i], s[j]
			i++
			j--
			si++
			sj--
		} else if dp[i+1][j] > dp[i][j-1] {
			i++
		} else {
			j--
		}
	}
	fmt.Fprintln(out, string(ans))
}

func main() {
	solveB(os.Stdin, os.Stdout)
}
