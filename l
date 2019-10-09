nasm -felf64 hello.asm -o hello.o
ld -s -o hello hello.o
for i in $(objdump -d hello |grep "^ " |cut -f2); do echo -n '\x'$i; done; echo

gcc -fno-stack-protector -z execstack -o asoc asoc2.c

su & echo 0 /proc/sys/kernel/randomize_va_space

