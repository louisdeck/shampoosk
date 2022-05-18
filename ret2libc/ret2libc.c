/*
gcc -fno-stack-protector -no-pie -m32 ret2libc.c -o ret2libc
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void receive_feedback()
{
    char buffer[21];
    puts("hey dude, waiting for your input :-)\n");
    gets(buffer);
}

int main(void)
{
    setuid(0);
    setgid(0);

    receive_feedback();

    return 0;
}