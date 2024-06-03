package main

import (
	"bufio"
	"fmt"
	"io"
	"math/bits"
	"os"
)

func solveD(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var q, op, x, k int
	// 每一层右移的偏移量
	shift := make([]int, 64)
	for fmt.Fscan(in, &q); q > 0; q-- {
		fmt.Fscan(in, &op, &x)
		if op == 1 {
			fmt.Fscan(in, &k)
			d := bits.Len(uint(x)) - 1
			shift[d] = (shift[d] + k + 1<<d) % (1 << d)
		} else if op == 2 {
			fmt.Fscan(in, &k)
			d := bits.Len(uint(x)) - 1
			for i := d; i < 64; i++ {
				shift[i] = (shift[i] + k + 1<<i) % (1 << i)
				k <<= 1
			}
		} else {
			d := bits.Len(uint(x)) - 1
			// 找到 x 在第 d 层的位置
			p := (x + shift[d]) % (1 << d)
			for ; d >= 0; p, d = p>>1, d-1 {
				// 倒推回位置 p 在第 d 层的值
				x = (p-shift[d]+1<<d)%(1<<d) + 1<<d
				fmt.Fprint(out, x, " ")
			}
			fmt.Fprintln(out)
		}
	}
}

func main() {
	solveD(os.Stdin, os.Stdout)
}
