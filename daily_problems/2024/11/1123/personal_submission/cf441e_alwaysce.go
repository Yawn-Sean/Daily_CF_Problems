package main

import (
	"bufio"
	"fmt"
	"io"
	"math/bits"
	"os"
)

func cf441E(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*
			Hint: The suffix of the original number is not changed much.
			a=x
			if rnd <= p:
				a<<=1
			else
				a+= 1
		dp[i][j] 操作次数=i 欠了j次+1操作 后缀连续0数量的期望
	*/

	var x, k, p int64
	fmt.Fscan(in, &x, &k, &p)
	p1 := float64(p) / 100.0
	p2 := 1.0 - p1
	//fmt.Fprintln(out, p1, p2)
	dp := make([][]float64, k+1)
	for i := 0; i <= int(k); i++ {
		dp[i] = make([]float64, k+1)
	}

	for i := 0; i <= int(k); i++ {
		v := x + int64(i)
		// 执行0次操作 欠了i次+1操作情况下 后缀连续0的个数
		dp[0][i] = float64(bits.Len64(uint64(v&-v)) - 1)
		//fmt.Fprintln(out, dp[0][i])
	}

	// 进行i次操作
	for i := 0; i < int(k); i++ {
		// 欠了j次+1的后缀0
		for j := 0; j <= int(k); j++ {
			// p概率进行了x2操作 那么还清次数翻倍 后缀0的个数+1
			if j*2 <= int(k) {
				dp[i+1][j*2] += p1 * (dp[i][j] + 1)
			}
			// 1-p概率简单+1
			// 少欠了一次+1操作
			if j > 0 {
				dp[i+1][j-1] += p2 * dp[i][j]
			}
		}
	}

	fmt.Fprintf(out, "%.10f\n", dp[k][0])
}

// func main() {
// 	cf441E(bufio.NewReader(os.Stdin), os.Stdout)
// }
