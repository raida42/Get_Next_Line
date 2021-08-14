# Get_Next_Line
This project is to make you code a function that returns a line ending with a newline, read from a file descriptor.

## Compilation
Your program must compile with the flag -D **BUFFER_SIZE=xx**. which will be used as the buffer size for the read calls in your get_next_line.

**GNL with files**
```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```
```
./a.out <filename>
```

**GNL with standard input (stdin)**
```
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```
```
./a.out
```

### Return Value

| Value | Description |
----|---- 
| 1 | A line has been read |
| 0 | EOF has been reached |
| -1| An error happened    |

## Test
Use this get_next_line tester
### Usage
**Author:** Tripouille
```
git clone https://github.com/Tripouille/gnlTester.git && cd gnlTester && make m
```
