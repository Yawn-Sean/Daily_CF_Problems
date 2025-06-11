package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solveD(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var s string
	fmt.Fscan(in, &s)
	n := len(s)
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
		dp[i][i] = 1
	}
	// 中心扩散求回文串
	// 更新答案
	ans := make([]int, n)
	ans[0] = n
	for i := 0; i < 2*n-1; i++ {
		l, r := i/2, i/2+i%2
		for l >= 0 && r < n && s[l] == s[r] {
			if r != l {
				// 一个回文串的阶数等于左边一半的阶数+1（由于回文，也等于右边一半的阶数+1）
				// k 阶同样满足 k-1, k-2, ..., 1 阶
				dp[l][r] = dp[l][l+(r-l-1)/2] + 1
				ans[dp[l][r]-1]++
			}
			l--
			r++
		}
	}
	// 统计答案
	for i := n - 2; i >= 0; i-- {
		ans[i] += ans[i+1]
	}
	for _, v := range ans {
		fmt.Fprint(out, v, " ")
	}
}

func main() {
	solveD(os.Stdin, os.Stdout)
}
