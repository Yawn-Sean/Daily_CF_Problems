package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1025B(os.Stdin, os.Stdout) }

func CF1025B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	arr := make([]int, 2)
	fmt.Fscan(in, &n, &arr[0], &arr[1])

	a, b := make([]int, n), make([]int, n)

	for i := 1; i < n; i++ {
		fmt.Fscan(in, &a[i], &b[i])
	}

	for _, e := range arr {
		val := 1
		for {
			if val*val > e {
				break
			}
			if e%val == 0 {
				for val != 1 && e/val%val == 0 {
					e /= val
				}
				for _, vv := range []int{val, e / val} {
					if vv == 1 {
						continue
					}
					if vv < val {
						break
					}
					flag := true
					for i := 1; i < n; i++ {
						if a[i]%vv != 0 && b[i]%vv != 0 {
							flag = false
							break
						}
					}
					if flag {
						fmt.Fprintf(out, "%d ", vv)
						return
					}
				}
			}
			val++
		}
	}
	fmt.Fprintf(out, "%d ", -1)
}
