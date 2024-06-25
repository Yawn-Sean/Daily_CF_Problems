package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solveC(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	const mod int = 998244353
	var a, b, c int
	fmt.Fscan(in, &a, &b, &c)

	const N int = 5001
	fact := make([]int, N)
	invf := make([]int, N)
	fact[0] = 1
	for i := 1; i < N; i++ {
		fact[i] = fact[i-1] * i % mod
	}
	invf[N-1] = pow(fact[N-1], mod-2, mod)
	for i := N - 2; i >= 0; i-- {
		invf[i] = invf[i+1] * (i + 1) % mod
	}

	calc := func(x, y int) int {
		// 同一颜色的两个点不能相连
		// 一个点不能连向同一颜色的两个点
		// 因此两个颜色之间 k 条边，每个颜色分别有 k 个点
		// A(x, k) * A(y, k) / k!
		res := 0
		for k := 0; k <= min(x, y); k++ {
			p1 := fact[x] * invf[k] % mod * invf[x-k] % mod
			p2 := fact[y] * invf[y-k] % mod
			res = (res + p1*p2) % mod
		}
		return res
	}

	ans := calc(a, b) * calc(b, c) % mod * calc(c, a) % mod
	fmt.Fprintln(out, ans)
}

func main() {
	solveC(os.Stdin, os.Stdout)
}

func pow(x, n, mod int) int {
	res := 1
	for n > 0 {
		if n&1 == 1 {
			res = res * x % mod
		}
		x = x * x % mod
		n >>= 1
	}
	return res
}
