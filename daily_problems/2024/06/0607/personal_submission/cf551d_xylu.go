package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func solveD(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, k, l, mod int
	Fscan(in, &n, &k, &l, &mod)
	if k>>l > 0 || mod == 1 {
		Fprintln(out, 0)
		return
	}

	matrixMul := func(A, B [][]int) [][]int {
		a, b, c := len(A), len(B), len(B[0])
		res := make([][]int, a)
		for i := range res {
			res[i] = make([]int, c)
		}
		for i := 0; i < a; i++ {
			for j := 0; j < c; j++ {
				for k := 0; k < b; k++ {
					res[i][j] += A[i][k] * B[k][j]
					res[i][j] %= mod
				}
			}
		}
		return res
	}

	matrixPow := func(a [][]int, b int) [][]int {
		res := make([][]int, len(a))
		for i := range res {
			res[i] = make([]int, len(a))
			res[i][i] = 1
		}
		for ; b > 0; b >>= 1 {
			if b&1 > 0 {
				res = matrixMul(res, a)
			}
			a = matrixMul(a, a)
		}
		return res
	}

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

	ans := 1
	tmp := matrixPow([][]int{{1, 1}, {1, 0}}, n-1)
	tmp = matrixMul([][]int{{1, 1}}, tmp)
	res := [2]int{}
	res[0] = (tmp[0][0] + tmp[0][1]) % mod
	res[1] = (pow(2, n) + mod - res[0]) % mod
	for i := 0; i < l; i++ {
		ans = ans * res[k>>i&1] % mod
	}
	Fprintln(out, ans)
}

func main() {
	solveD(os.Stdin, os.Stdout)
}
