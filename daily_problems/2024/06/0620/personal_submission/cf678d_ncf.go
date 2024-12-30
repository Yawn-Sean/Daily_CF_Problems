package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF678D(os.Stdin, os.Stdout) }

func CF678D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var a, b, x, n int
	fmt.Fscan(in, &a, &b, &n, &x)

	m1, m2, res := make([][]int, 2), make([][]int, 2), make([][]int, 2)
	for i := 0; i < 2; i++ {
		m1[i] = make([]int, 2)
		m2[i] = make([]int, 1)
		res[i] = make([]int, 2)
	}

	m1[0][0] = a
	m1[0][1] = b
	m1[1][0] = 0
	m1[1][1] = 1
	m2[0][0] = x
	m2[1][0] = 1
	res[0][0] = 1
	res[0][1] = 0
	res[1][0] = 0
	res[1][1] = 1

	mod := int(1e9 + 7)

	// 快速幂
	power := n
	for power > 0 {
		if (power & 1) == 1 {
			res = matrixMultiply(res, m1, mod)
		}
		m1 = matrixMultiply(m1, m1, mod)
		power >>= 1
	}
	res = matrixMultiply(res, m2, mod)
	fmt.Fprintf(out, "%d\n", res[0][0])
}

// matrixMultiply 计算并返回两个矩阵的乘积。
func matrixMultiply(a, b [][]int, mod int) [][]int {
	// 获取矩阵的维度
	rowsA := len(a)
	colsA := len(a[0])
	rowsB := len(b)
	colsB := len(b[0])

	// 检查矩阵是否可以相乘
	if colsA != rowsB {
		panic("矩阵A的列数必须与矩阵B的行数相同")
	}

	// 初始化结果矩阵
	result := make([][]int, rowsA)
	for i := range result {
		result[i] = make([]int, colsB)
	}

	// 执行矩阵乘法
	for i := 0; i < rowsA; i++ {
		for j := 0; j < colsB; j++ {
			for k := 0; k < colsA; k++ {
				result[i][j] = (result[i][j] + a[i][k]*b[k][j]) % mod
			}
		}
	}

	return result
}
