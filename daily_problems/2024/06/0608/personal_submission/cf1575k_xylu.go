package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solveK(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	const mod int = 1e9 + 7
	pow := func(x, n int) int {
		res := 1
		for ; n > 0; n >>= 1 {
			if n&1 > 0 {
				res = res * x % mod
			}
			x = x * x % mod
		}
		return res
	}

	var n, m, k, r, c, ax, ay, bx, by int
	fmt.Fscan(in, &n, &m, &k, &r, &c, &ax, &ay, &bx, &by)
	empty := n * m // 空白格子数量（随便填）
	if ax != bx || ay != by {
		// 两个矩阵没有完全重合时
		// 如果相交，其中一个矩阵没有相交的部分填好后，另外一个矩阵也就确定了，可以随便填的格子减少 r*c
		// 如果不相交，一个矩阵可以随便填，同样可以随便填的格子减少 r*c
		empty -= r * c
	}
	fmt.Fprintln(out, pow(k, empty))
}

func main() {
	solveK(os.Stdin, os.Stdout)
}
