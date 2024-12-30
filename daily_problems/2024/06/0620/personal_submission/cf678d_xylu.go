package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { solveD(os.Stdin, os.Stdout) }

func solveD(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	const mod int = 1e9 + 7
	mMul := func(A, B [][]int) [][]int {
		n, m, l := len(A), len(B), len(B[0])
		C := make([][]int, n)
		for i := 0; i < n; i++ {
			C[i] = make([]int, l)
			for j := 0; j < l; j++ {
				for k := 0; k < m; k++ {
					C[i][j] = (C[i][j] + A[i][k]*B[k][j]) % mod
				}
			}
		}
		return C
	}

	mPow := func(A [][]int, x int) [][]int {
		n := len(A)
		res := make([][]int, n)
		for i := 0; i < n; i++ {
			res[i] = make([]int, n)
			res[i][i] = 1
		}
		for x > 0 {
			if x&1 == 1 {
				res = mMul(res, A)
			}
			A = mMul(A, A)
			x >>= 1
		}
		return res
	}

	a, b, n, x := readFourNums(in)
	fmt.Fprintln(out, mMul(mPow([][]int{{a, b}, {0, 1}}, n), [][]int{{x}, {1}})[0][0])
}
