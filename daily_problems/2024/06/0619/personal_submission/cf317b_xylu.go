package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { solveB(os.Stdin, os.Stdout) }

func solveB(_r io.Reader, _w io.Writer) {
	in, out := bufio.NewReader(_r), bufio.NewWriter(_w)
	defer out.Flush()

	d := [4][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	const N, M = 200, 100

	var n, q int
	fmt.Fscan(in, &n, &q)
	cnt := [N][N]int{}
	cnt[M][M] = n

	for {
		f := false
		for i := 0; i < N; i++ {
			for j := 0; j < N; j++ {
				if cnt[i][j] < 4 {
					continue
				}
				for k := 0; k < 4; k++ {
					x, y := i+d[k][0], j+d[k][1]
					cnt[x][y] += cnt[i][j] / 4
					if cnt[x][y] >= 4 {
						f = true
					}
				}
				cnt[i][j] %= 4
			}
		}
		if !f {
			break
		}
	}

	for i := 0; i < q; i++ {
		var x, y int
		fmt.Fscan(in, &x, &y)
		x, y = x+M, y+M
		if x < 0 || x >= N || y < 0 || y >= N {
			fmt.Fprintln(out, 0)
		} else {
			fmt.Fprintln(out, cnt[x][y])
		}
	}
}
