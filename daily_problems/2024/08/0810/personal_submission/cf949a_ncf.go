package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF949A(os.Stdin, os.Stdout) }

func CF949A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var s string
	fmt.Fscan(in, &s)
	var ans [][]int

	var t0, t1 []int
	n := len(s)
	for i := 0; i < n; i++ {
		if s[i] == '0' {
			if len(t1) > 0 {
				t0 = append(t0, t1[len(t1)-1])
				t1 = t1[:len(t1)-1]
				ans[t0[len(t0)-1]] = append(ans[t0[len(t0)-1]], i+1)
			} else {
				t0 = append(t0, len(ans))
				tmp := make([]int, 1)
				tmp[0] = i + 1
				ans = append(ans, tmp)
			}
		} else {
			if len(t0) > 0 {
				t1 = append(t1, t0[len(t0)-1])
				t0 = t0[:len(t0)-1]
				ans[t1[len(t1)-1]] = append(ans[t1[len(t1)-1]], i+1)
			} else {
				fmt.Fprintf(out, "-1")
				return
			}
		}
	}

	if len(t1) > 0 {
		fmt.Fprintf(out, "-1")
		return
	}

	fmt.Fprintf(out, "%d\n", len(ans))
	for _, a := range ans {
		fmt.Fprintf(out, "\n%d ", len(a))
		for _, e := range a {
			fmt.Fprintf(out, "%d ", e)
		}
	}

}
