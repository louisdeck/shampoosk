//gcc -fno-stack-protector -z execstack -no-pie -m32 ret2win.c -o ret2win

#include <stdio.h>

void get_flag()
{
    printf("\ndaddy, I just pwned eip :)\n");
}

void register_name()
{
    char buffer[21];

    printf("Name:\n");
    scanf("%s", buffer);
    printf("Hi there, %s\n", buffer);    
}

int main(void)
{
    register_name();
    return 0;
}