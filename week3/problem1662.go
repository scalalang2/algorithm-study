package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// 33(562(71(9)2(6)3(2)4(1123)))
// 3(5(2)3(6)) = 3 * (5 + 3)

var stack []int

func push(val int) {
	stack = append(stack, val)
}

func pop() int {
	temp := stack[len(stack)-1]
	stack = stack[0:len(stack)-1]
	return temp
}

func main() {
	var text string
	plus_sign := -1
	mul_sign := -2

	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%s\n", &text)

	if len(text) == 1 {
		fmt.Println(1)
		return
	}

	// -1 : +
	// -2 : *

	// 3(5(2)3(6))
	// 1 + 4 * 1 + 0 + 1 * 1
	temp := ""
	for i := 0; i < len(text); i++ {
		if string(text[i]) == "(" {
			push(len(temp) - 1)
			push(plus_sign)

			val, _ := strconv.Atoi(string(temp[len(temp)-1]))
			push(val)
			push(mul_sign)

			temp = ""
		} else if string(text[i]) == ")" {
			//fmt.Println(stack)
			val := len(temp)
			op := pop()
			left_val := pop()

			if op == mul_sign {
				push(left_val * val)
				push(plus_sign)
			} else if op == plus_sign {
				push(left_val)
				push(op)
			}

			temp = ""
		} else {
			temp += string(text[i])
		}
	}

	push(0)

	sol := 0

	//stack을 다 비울때까지 반복한다.
	for len(stack) != 1 {
		//fmt.Println(stack)
		left_arg := pop()
		op_arg := pop()
		right_arg := pop()

		if op_arg == -1 {
			sol = left_arg + right_arg
		} else {
			sol = left_arg * right_arg
		}

		push(sol)
	}

	fmt.Println(sol)
}