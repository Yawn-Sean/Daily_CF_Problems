package main

import (
	"bufio"
	"fmt"
	"io"
	"math/big"
	"os"
)

func main() { CF457A(os.Stdin, os.Stdout) }

func CF457A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t int
	var a, b string
	for t = 1; t > 0; t -= 1 {
		fmt.Fscan(in, &a, &b)

		// 使用 big.Int 初始化系数和常数
		coefficient := big.NewInt(0)
		con := big.NewInt(1)

		// 使用 big.Int 初始化 v1, v2, v3, v4
		v1 := big.NewInt(0)
		v2 := big.NewInt(0)
		v3 := big.NewInt(0)
		v4 := big.NewInt(0)

		for i, j := len(a)-1, len(b)-1; i > -1 || j > -1; i, j = i-1, j-1 {
			if i > -1 && a[i] == '1' {
				// 使用 big.Int 进行加法运算
				v1.Add(v1, coefficient)
				v2.Add(v2, con)
			}
			if j > -1 && b[j] == '1' {
				v3.Add(v3, coefficient)
				v4.Add(v4, con)
			}

			// 使用 big.Int 进行加法和赋值操作
			tt := new(big.Int).Set(coefficient)
			coefficient.Add(coefficient, con)
			con.Set(tt)
		}

		// 计算 v，这里假设 1.618033988 是一个已知的大整数（例如，从输入或常量定义而来）
		goldenRatio := big.NewInt(1618033988) // 注意这里假设是整数部分，若包含小数需调整为 big.Rat
		v1MinusV3 := new(big.Int).Sub(v1, v3)
		v1MinusV3.Mul(v1MinusV3, goldenRatio)
		v2MinusV4 := new(big.Int).Sub(v2, v4)
		v := new(big.Int).Add(v1MinusV3, v2MinusV4)

		// 比较 v 与 0 的大小关系，输出结果
		if v.Cmp(big.NewInt(0)) > 0 {
			fmt.Fprintf(out, ">")
		} else if v.Cmp(big.NewInt(0)) == 0 {
			fmt.Fprintf(out, "=")
		} else {
			fmt.Fprintf(out, "<")
		}
	}
}
