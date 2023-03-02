# sysdebug

Sysdebug was written as a quick and dirty tool to execute syscalls on the run for testing purposes c.q. kernel development, userland development, and binary exploitation.

## Usage

You can use `sysdebug` to execute Linux system calls with up to 7 arguments at once.

`sys_open` (2) to open the /etc/passwd file, and it returns the new file descriptor:

```bash
$ ./sysdebug 2 "/etc/passwd" "" ""
0x3
```

`sys_open` (2) to open the /etc/shadow file, and it returns the error:

```bash
$ ./sysdebug 2 "/etc/shadow" "" ""
0xffffffffffffffff
```

`sys_execve` (59) to execute `whoami`:

```bash
$ ./sysdebug 59 "/bin/whoami" "" ""
dev
```

## Compiling

Sysdebug can be compiled using simply `gcc main.c -o sysdebug`. Alternatively you can build a static binary using `gcc main.c -o sysdebug -static`. We recommend `musl-gcc main.c -o sysdebug -static` for 95% size decrease. 