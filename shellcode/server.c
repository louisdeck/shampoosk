/*
gcc -fno-stack-protector -z execstack -no-pie -m32 server.c -o server

sudo chown root:root flag.txt
sudo chmod 600 flag.txt
sudo chown root:root server
sudo chmod 4655 server
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int secret_function() {
    asm("jmp %esp");
}

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
