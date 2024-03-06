package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1194D(os.Stdin, os.Stdout) }

func CF1194D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, k int
	fmt.Fscan(in, &t)
	for i := 0; i < t; i++ {
		fmt.Fscan(in, &n, &k)
		if k%3 > 0 {
			if n%3 > 0 {
				fmt.Fprintf(out, "Alice\n")
			} else {
				fmt.Fprintf(out, "Bob\n")
			}
		} else if n%(k+1)%3 > 0 || n%(k+1) == k {
			fmt.Fprintf(out, "Alice\n")
		} else {
			fmt.Fprintf(out, "Bob\n")
		}
	}
}
