package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solve(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	p := make([][]float64, 1<<n)
	for i := range p {
		p[i] = make([]float64, 1<<n)
		for j := range p[i] {
			fmt.Fscan(in, &p[i][j])
		}
	}

	// dp[i][j] 表示第 i 轮比赛结束后，队伍 j 获胜的期望得分
	// prob[i][j] 表示第 i 轮比赛结束后，队伍 j 获胜的概率
	dp, prob := make([][]float64, n+1), make([][]float64, n+1)
	for i := 0; i <= n; i++ {
		dp[i], prob[i] = make([]float64, 1<<n), make([]float64, 1<<n)
	}
	for j := range prob[0] {
		prob[0][j] = 1
	}

	for round, w := 1, 1; round <= n; round, w = round+1, w*2 {
		for i := 0; i < 1<<n; i++ {
			// i 和 j 第 rd 轮碰到
			// 当且仅当第 rd-1 位不相等，>=rd 位相等
			start, end := i>>round<<round, (i>>round<<round)+(1<<round)
			preStart, preEnd := i>>(round-1)<<(round-1), (i>>(round-1)<<(round-1))+(1<<(round-1))
			mxdp := 0.0
			// prob[rd][i] = sum(prob[rd-1][i] * prob[rd-1][j] * p[i][j] / 100)
			// dp[rd][i] = dp[rd-1][i] + max(dp[rd-1][j]) + prob[rd][i] * (1<<(rd-1))
			for j := start; j < preStart; j++ {
				prob[round][i] += prob[round-1][i] * prob[round-1][j] * p[i][j] / 100
				mxdp = max(mxdp, dp[round-1][j])
			}
			for j := preEnd; j < end; j++ {
				prob[round][i] += prob[round-1][i] * prob[round-1][j] * p[i][j] / 100
				mxdp = max(mxdp, dp[round-1][j])
			}
			dp[round][i] = dp[round-1][i] + mxdp + prob[round][i]*float64(w)
		}
	}
	ans := 0.0
	for i := 0; i < 1<<n; i++ {
		ans = max(ans, dp[n][i])
	}
	fmt.Fprintf(out, "%.9f\n", ans)
}

func main() {
	solve(os.Stdin, os.Stdout)
}
