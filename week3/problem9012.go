package main

import (
	"fmt"
)
import "bufio"
import "os"

var N, top int
var stack []int

func main() {
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d\n", &N)

	// Make Array
	stack = make([]int, 100)

	for k := 0; k < N; k++ {
		text, _, _ := reader.ReadLine()
		top = 0
		stack[top] = 0

		for i := 0; i < len(text); i++ {
			if i+1 == len(text) {
				if top == 1 && stack[0] == 1 && string(text[i]) == ")" {
					fmt.Println("YES")
				} else {
					fmt.Println("NO")
				}
				break
			}

			if string(text[i]) == "(" {
				stack[top] = 1 // push
				top++
			} else {
				// if stack is empty
				if stack[top] == 0 && top == 0 {
					fmt.Println("NO")
					break
				} else {
					top--
					stack[top] = 0
				}
			}
		}
	}
}