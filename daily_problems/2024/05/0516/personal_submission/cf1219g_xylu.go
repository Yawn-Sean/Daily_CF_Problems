package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func topK(arr []int, k int) int {
	a1, a2, a3, a4 := 0, 0, 0, 0
	for _, v := range arr {
		if v > a1 {
			a4, a3, a2, a1 = a3, a2, a1, v
		} else if v > a2 {
			a4, a3, a2 = a3, a2, v
		} else if v > a3 {
			a4, a3 = a3, v
		} else if v > a4 {
			a4 = v
		}
	}
	if k == 1 {
		return a1
	} else if k == 2 {
		return a1 + a2
	} else if k == 3 {
		return a1 + a2 + a3
	}
	return a1 + a2 + a3 + a4
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solveG(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, m int
	fmt.Fscan(in, &n, &m)
	grid := make([][]int, n)
	sumV, sumH := make([]int, n), make([]int, m)
	for i := range grid {
		grid[i] = make([]int, m)
		for j := range grid[i] {
			fmt.Fscan(in, &grid[i][j])
			sumV[i] += grid[i][j]
			sumH[j] += grid[i][j]
		}
	}
	// all vertical or horizontal
	ans := max(topK(sumV, 4), topK(sumH, 4))

	// 3 vertical, 1 horizontal
	for i, v := range sumV {
		for j := range sumH {
			sumH[j] -= grid[i][j]
		}
		ans = max(ans, v+topK(sumH, 3))
		for j := range sumH {
			sumH[j] += grid[i][j]
		}
	}

	// 3 horizontal, 1 vertical
	for i, v := range sumH {
		for j := range sumV {
			sumV[j] -= grid[j][i]
		}
		ans = max(ans, v+topK(sumV, 3))
		for j := range sumV {
			sumV[j] += grid[j][i]
		}
	}

	// 2 vertical, 2 horizontal
	if n >= 2 && m >= 2 {
		if n < m {
			for i := 0; i < n; i++ {
				for j := i + 1; j < n; j++ {
					for k := range sumH {
						sumH[k] -= grid[i][k] + grid[j][k]
					}
					ans = max(ans, sumV[i]+sumV[j]+topK(sumH, 2))
					for k := range sumH {
						sumH[k] += grid[i][k] + grid[j][k]
					}
				}
			}
		} else {
			for i := 0; i < m; i++ {
				for j := i + 1; j < m; j++ {
					for k := range sumV {
						sumV[k] -= grid[k][i] + grid[k][j]
					}
					ans = max(ans, sumH[i]+sumH[j]+topK(sumV, 2))
					for k := range sumV {
						sumV[k] += grid[k][i] + grid[k][j]
					}
				}
			}
		}
	}

	fmt.Fprintln(out, ans)
}

func main() {
	solveG(os.Stdin, os.Stdout)
}
