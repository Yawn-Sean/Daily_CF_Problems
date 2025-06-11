package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { solveF(os.Stdin, os.Stdout) }

func solveF(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	n, m, k := readThreeNums(in)
	ss := make([]string, n)
	psum := make([][]int, n)
	for i := 0; i < n; i++ {
		ss[i] = readString(in)
		psum[i] = make([]int, m)
	}
	for i := 1; i < n-1; i++ {
		for j := 1; j < m-1; j++ {
			if ss[i][j] == '1' && ss[i-1][j] == '1' && ss[i+1][j] == '1' && ss[i][j-1] == '1' && ss[i][j+1] == '1' {
				psum[i][j] = 1
			}
			psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1]
		}
	}

	ans := 0
	for u := 1; u < n-1; u++ {
		for d := u; d < n-1; d++ {
			for l, r := 1, 1; l < m-1; l++ {
				for r < m-1 && psum[d][r]-psum[u-1][r]-psum[d][l-1]+psum[u-1][l-1] < k {
					r++
				}
				if r < m-1 {
					ans += m - r - 1
				}
			}
		}
	}
	fmt.Fprintln(out, ans)
}
