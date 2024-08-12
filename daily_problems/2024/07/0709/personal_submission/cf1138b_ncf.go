package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1138B(os.Stdin, os.Stdout) }

func CF1138B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	var c, a string
	fmt.Fscan(in, &c, &a)
	idx := make([][]int, 4)
	for i := 0; i < n; i++ {
		v1, v2 := int(a[i]-'0'), int(c[i]-'0')
		v := (v1 << 1) | v2
		idx[v] = append(idx[v], i+1)
	}
	c1 := len(idx[1])
	c2 := len(idx[2])
	c3 := len(idx[3])
	if n/2 < c1 || n/2 < c2 || c1 == 0 && c2 == 0 && c3%2 == 1 {
		fmt.Fprintf(out, "-1")
		return
	}

	for c3 > 0 {
		if c1 < c2 {
			idx[1] = append(idx[1], idx[3][c3-1])
			c1++
		} else {
			idx[2] = append(idx[2], idx[3][c3-1])
			c2++
		}
		c3--
	}
	if c1 < c2 {
		idx[1] = append(idx[1], idx[2][:c2-c1]...)
	} else {
		idx[1] = idx[1][c1-c2:]
	}

	remainder := n >> 1
	for _, e := range idx[1] {
		if remainder == 0 {
			break
		}
		fmt.Fprintf(out, "%d ", e)
		remainder--
	}
	for _, e := range idx[0] {
		if remainder == 0 {
			break
		}
		fmt.Fprintf(out, "%d ", e)
		remainder--
	}
}

func abs1138b(num int) int {
	if num >= 0 {
		return num
	}
	return -num
}
