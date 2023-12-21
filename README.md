# Minishell

Minishell is a simple command-line interpreter implemented in the C programming language. It supports executing external commands, managing environment variables, and other basic shell functionalities.

## Features

- **Command Execution:** Minishell can execute external commands entered by the user.
- **Environment Variables:** It manages environment variables, allowing users to set, unset, and display them.
- **Built-in Commands:** Supports built-in commands like `env`, and `exit`.
- **Path Analysis:** Analyzes the `PATH` variable to locate executable binaries.

## Compilation and Execution

To compile the project, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

To run Minishell, use the following command:

```bash
./hsh
```

## Usage

Minishell accepts standard shell commands. Here are some examples:

```bash
$ ls
```
Output:
```bash
file1.txt  file2.txt  folder
```
Display environment variables:

```bash
$ env
```
Output:
```bash
PATH=/usr/local/bin:/usr/bin:/bin
MY_VARIABLE=my_value
```
Exit Minishell:
```bash
$ exit 
```
## Error Handling

Minishell provides informative error messages:

If a command is not found:
```bash
$ invalid_command
```
Output:
```bash
./hsh: command not found: invalid_command
```



## Author

Hocine Bouabdallah

David Hache

