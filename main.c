#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
/* XA PODER USAR READ */
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int main()
 {
    int fd;
    int sz;
    char *c = (char *) calloc(100, sizeof(char));
    fd = open("text", O_RDONLY);
    if (fd < 0)
        return (0);
    sz = (int)read(fd, c, 10);                
    c[sz] = '\0';
    printf("%s\n", c);
    return(0);
}

