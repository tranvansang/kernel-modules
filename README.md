# OS Kernel modules

[class material](https://www.pf.is.s.u-tokyo.ac.jp/classes/)

## Usage

See usage in each directories

## Running environment

- `uname -r`: `4.15.0-38-generic #41-Ubuntu SMP Wed Oct 10 10:59:38 UTC 2018 x86_64 x86_64 x86_64 GNU/Linux`

- `gcc --version`: 

```
gcc (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
## How to check for kernel call

- The typical flow is user routine -> system call -> kernel routine
- `strace -f ./program >/dev/null` prints out program trace
- Manually check via system call table. For example, find out how `fork` is implemented
  + Look up in linux kernel source code at `arch/x86/entry/syscalls/syscall_64.tbl`. There is system call number and its counterpart kernel call.
    Looking for `fork`, there is `57 common fork sys_fork/ptregs`
  + Now, don't try looking for `sys_fork` keyword. Because it and other similar calls starting with `sys_` prefix are defined via `SYSCALL_DEINFE0` macro (in `include/linux/syscalls.h`)
  + Instead, try looking for `SYSCALL_DEFINE0(fork)` or `fork` keywords in the `kernel` directory
  + In `fork` case, there is `return _do_fork(SIGCHLD, 0, 0, NULL, NULL, 0);` in `kernel/fork.c`
