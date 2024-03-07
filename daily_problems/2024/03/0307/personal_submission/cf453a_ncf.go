package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF453A(os.Stdin, os.Stdout) }

func CF453A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m int
	fmt.Fscan(in, &n, &m)
	ans := 0.0
	pre := 0.0

	for i := 1; i <= n; i++ {
		cur := pow453A(float64(i)/float64(n), m)
		ans += (cur - pre) * float64(i)
		pre = cur
	}
	fmt.Fprintf(out, "%.12f ", ans)
}

func pow453A(x float64, n int) float64 {
	result := 1.0
	base := x

	for n > 0 {
		if n&1 == 1 { // 当n的最低位为1时，进行一次乘法
			result *= base
		}
		base *= base // 不管n的最低位是否为1，都要左移一位进行下一次迭代
		n >>= 1
	}

	return result
}
