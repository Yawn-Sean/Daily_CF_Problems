package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF960C(os.Stdin, os.Stdout) }

func CF960C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var x, d int
	fmt.Fscan(in, &x, &d)
	if x <= int(1e4) {
		fmt.Fprintf(out, "%d\n", x)
		cur := 1
		for i := 0; i < x; i++ {
			fmt.Fprintf(out, "%d ", cur)
			cur += d
		}
		return
	}
	cd, cur := 60, 1
	pw := pow960c(2, cd, 0)
	var ans []int
	for x > 0 {
		for pw > x {
			pw /= 2
			cd -= 1
		}
		for i := 0; i < cd; i++ {
			ans = append(ans, cur)
		}
		x -= pw - 1
		cur += d
		if x == 1 {
			ans = append(ans, cur)
			break
		}
	}
	fmt.Fprintf(out, "%d\n", len(ans))
	for _, e := range ans {
		fmt.Fprintf(out, "%d ", e)
	}
}

func pow960c(x, n, mod int) int {
	result := 1
	base := x

	for n > 0 {
		if n&1 == 1 { // 当n的最低位为1时，进行一次乘法
			result *= base
			if mod != 0 {
				result %= mod
			}
		}
		base *= base // 不管n的最低位是否为1，都要左移一位进行下一次迭代
		if mod != 0 {
			base %= mod
		}
		n >>= 1
	}

	return result
}
