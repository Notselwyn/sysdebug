# sysdebug

Sysdebug was written as a quick and dirty tool to execute syscalls on the run for testing purposes c.q. kernel development, userland development, and binary exploitation.

## Usage

You can use `sysdebug` to execute Linux system calls with up to 7 arguments at once.

```bash
$ ./sysdebug 59 "/bin/whoami" "" ""
user
```

## Compiling

Sysdebug can be compiled using simply `gcc main.c -o sysdebug`. Alternatively you can build a static binary using `gcc main.c -o sysdebug -static` - but we recommend `musl-gcc main.c -o sysdebug -static` for 95% size decrease. 