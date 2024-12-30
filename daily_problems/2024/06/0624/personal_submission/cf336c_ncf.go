package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF336C(os.Stdin, os.Stdout) }

func CF336C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	m := make([][]int, 31)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		for j := 30; j > -1; j-- {
			if a[i]&(1<<j) > 0 {
				m[j] = append(m[j], a[i])
			}
		}
	}
	for i := 30; i > -1; i-- {
		num := 0x7fffffff
		for _, e := range m[i] {
			num &= e
		}
		if num&-num == 1<<i {
			fmt.Fprintf(out, "%d\n", len(m[i]))
			for _, e := range m[i] {
				fmt.Fprintf(out, "%d ", e)
			}
			return
		}
	}
	fmt.Fprintf(out, "%d\n", len(a))
	for _, e := range a {
		fmt.Fprintf(out, "%d ", e)
	}
}
