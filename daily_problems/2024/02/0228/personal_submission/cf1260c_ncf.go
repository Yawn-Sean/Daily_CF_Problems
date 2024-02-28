package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1260C(os.Stdin, os.Stdout) }

func CF1260C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, r, b, k int
	fmt.Fscan(in, &t)
	for i := 0; i < t; i++ {
		fmt.Fscan(in, &r, &b, &k)
		// 约定r为较小数方便处理
		if r > b {
			r, b = b, r
		}
		gcd := gcd1260C(r, b)
		// 找到最小公倍数llm = r * b / gcd
		// 在一个长为llm的区间内，必为红的个数为b/gcd - 1  减一是因为在llm的那个点可以涂成蓝色
		// 同理，必为蓝的个数为r/gcd - 1，区间个数为r/gcd
		// 将b/gcd - 1个点平均分布在 r/gcd个区间内，每个区间的最大分布为(b/gcd - 1 + (r/gcd - 1)) / (r / gcd)，其中加上除数减一是避免求余判断余数是否大于0，大于0的情况下要+1
		count := (b/gcd - 1 + r/gcd - 1) / (r / gcd)
		if count >= k {
			fmt.Fprintf(out, "REBEL\n")
		} else {
			fmt.Fprintf(out, "OBEY\n")
		}
	}

}

func gcd1260C(a int, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}
