#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd, fc;
	char buf;

    fd = open("test.txt", O_RDWR);
    fc = open("test1.txt", O_RDWR | O_CREAT, 0600);
	if (fd <= 0) {
		exit(1);
	}
	while (read(fd, &buf, 1) > 0) {
		write(fc, &buf, 1);
    }
    close(fd);
    close(fc);
    return 0;
}
