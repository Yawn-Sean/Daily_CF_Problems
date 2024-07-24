package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF0B(os.Stdin, os.Stdout) }

func CF0B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, q, x int
	var s string
	fmt.Fscan(in, &n, &q)
	for ; q > 0; q -= 1 {
		fmt.Fscan(in, &x, &s)
		for _, e := range s {
			lb := x & -x
			if e == 'L' {
				if x&1 == 1 { // 叶子节点没有子节点
					continue
				}
				x -= lb >> 1
			} else if e == 'R' {
				if x&1 == 1 { // 叶子节点没有子节点
					continue
				}
				x += lb >> 1
			} else {
				if lb == x && lb<<1 > n { // 根节点没有父节点
					continue
				}
				v := x ^ lb
				if v&-v == lb<<1 { // 右子结点
					x -= lb
				} else { // 左子结点
					x += lb
				}
			}
		}
		fmt.Fprintf(out, "%d\n", x)
	}
}
