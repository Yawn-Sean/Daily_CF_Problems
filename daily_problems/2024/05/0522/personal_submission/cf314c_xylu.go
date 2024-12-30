package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

const N int = 1e6 + 5
const mod int = 1e9 + 7

func solveC(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(in, &a[i])
	}
	// dp[i] 表示以 i 结尾的所有非递减子序列的结果
	dp := [N]int{}
	dp[0] = 1
	// bit 维护 dp 的前缀和
	bit := newBIT(N)
	// 初始化空序列（假设以 0 结尾）
	bit.add(0, 1)
	for i := 0; i < n; i++ {
		v := (a[i]*bit.query(a[i]) - dp[a[i]] + mod) % mod
		bit.add(a[i], v)
		dp[a[i]] = (dp[a[i]] + v) % mod
	}
	fmt.Fprintln(out, (bit.query(N-1)+mod-1)%mod)
}

func main() {
	solveC(os.Stdin, os.Stdout)
}

type BIT []int

func newBIT(n int) BIT {
	return make([]int, n+1)
}

func (t BIT) op(a, b int) int {
	return (a + b) % mod
}

func (t BIT) query(x int) (res int) {
	for x++; x > 0; x -= x & -x {
		res = t.op(res, t[x])
	}
	return
}

func (t BIT) add(x, v int) {
	for x++; x < len(t); x += x & -x {
		t[x] = t.op(t[x], v)
	}
}
