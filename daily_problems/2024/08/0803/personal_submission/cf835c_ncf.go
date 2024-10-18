package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF835C(os.Stdin, os.Stdout) }

func CF835C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, q, c int
	fmt.Fscan(in, &n, &q, &c)
	type star struct {
		x, y, s int
	}
	a := make([]star, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i].x, &a[i].y, &a[i].s)
		a[i].x -= 1
		a[i].y -= 1
	}

	acc := make([]*MatrixSum, c+1)
	for i := 0; i <= c; i++ {
		matrix := make([][]int, 101)
		for j := 0; j < 101; j++ {
			matrix[j] = make([]int, 101)
		}
		for j := 0; j < n; j++ {
			matrix[a[j].x][a[j].y] += (a[j].s + i) % (c + 1)
		}
		acc[i] = NewMatrixSum(matrix)
	}

	type view struct {
		t, x1, y1, x2, y2 int
	}
	var b view
	for i := 0; i < q; i++ {
		fmt.Fscan(in, &b.t, &b.x1, &b.y1, &b.x2, &b.y2)
		//b.t = (b.t + c) % (c + 1)
		b.x1 -= 1
		b.y1 -= 1
		b.x2 -= 1
		b.y2 -= 1
		fmt.Fprintf(out, "%d\n", acc[b.t%(c+1)].Query(b.x1, b.y1, b.x2+1, b.y2+1))
	}
}

// MatrixSum 结构体用于存储二维前缀和
type MatrixSum struct {
	sum [][]int
}

// NewMatrixSum 创建一个新的 MatrixSum 实例
func NewMatrixSum(matrix [][]int) *MatrixSum {
	m := len(matrix)
	n := len(matrix[0])
	sum := make([][]int, m+1)
	for i := range sum {
		sum[i] = make([]int, n+1)
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + matrix[i][j]
		}
	}

	return &MatrixSum{sum: sum}
}

// Query 返回左上角在 (r1,c1) 右下角在 (r2-1,c2-1) 的子矩阵元素和
func (ms *MatrixSum) Query(r1, c1, r2, c2 int) int {
	return ms.sum[r2][c2] - ms.sum[r2][c1] - ms.sum[r1][c2] + ms.sum[r1][c1]
}
