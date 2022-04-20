#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 4
#endif
char	*get_next_line(int fd);