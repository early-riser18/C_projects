# Introduction
This repository contains a selection of projects implemented in C, based on the [curriculum](https://github.com/rphlr/42-Subjects) of 42 School. [*More about 42*](https://42.fr/en/homepage/). 

These projects were done as part of my initiative to acquire a solid technical foundation and subsequently join technical projects as an Engineer (done from Sept. to Dec. 2023).

These projects allowed me to deepen my understanding of how operating systems work, specifically virtualization, memory management and multi-threaded processes, while writing them in C allowed me to practice that newly-acquired knowledge.


# Projects
Below, you will find a break down of each project, including their functionalities, objectives and how to run them. The projects are ordered below from most to least advanced.
## 🧙‍♂️ philo 
A version of the Dining Philosopher problem formulated by Edsger Dijkstra in 1965. 


**The problem**<br>
There are N philosophers around a table, and N-1 fork. Each philosopher needs to eat to survive and needs two forks to eat. 
<br>**How to design a concurrent algorithm such that any philosopher will not starve?**

This project focuses on multi-threaded programming, and the use of mutex to avoid data race, via the `pthread.h` library. 


### Try it!
```bash
# Compile it to an executable file.
make all

# Run it
./philo <nbr_of_philosopher> <time_to_die> <time_to_eat> <time_to_sleep>

# Example
./philo 3 60 25 25
```

## 🗣️ minitalk
Let two processes send text data to each other only trought Signals.

**The problem**<br>
One clients process wants to send a string to a server process. How can it be done by only using `SIGUSR1` and `SIGUSR2`?

This project focuses on inter-process signals and the `signal.h` library 
### Try it!
```bash
# Compile it to an executable file.
make all

# Run it
## Start server
./server # -> Will print its PID

## Open another terminal and start client
./client <PID> <any_text>

# Example
./server # OUTPUT: 8110
./client 8110 "I am a message!"
```

## 🪈 pipex 
This project focuses on building our own implementation of the pipe (`|`) operator found in bash. 

It emphasizes on handling file descriptors, memory and creating new processes with `execve()`.

### Try it!
```bash
# Compile it to an executable file.
make all

# Run it
./pipex <in_file> <cmd1> <cmd2> <out_file> 

# Example - print the line count when runnin ls -l in the current folder.
./pipex "." "ls -l" "wc -l" "output.txt"

# It will behave exactly like
ls -l . | wc -l > output.txt
```

## 🖨️ ft_printf 
This project focuses on building our own implementation the built-in `libc.h` function `printf()`.

It emphasizes on working with variadic functions and using the `write` system calls on a variety of data types (eg: print a float or int as a string).
### Try it!
```c
include <ft_printf.h>

void main(void)
{
    ft_printf("Test message 123!")
    return 0
}
// Should print: Test message 123!
```

## 📚 ft_libc 
This project contains my own re-implementation of 43 built-in functions of the `libc.h` library. It emphasizes on properly understanding data types and memory management.

### Try it!
```c
include <libft.h>
// Use any of the functions declared
```
