#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>  
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

char* get_next_line(int fd){

    int maxLine = 120;
    char* buf = (char*)malloc(sizeof(char)*maxLine);
    int x = read(fd,buf,maxLine);
    return buf;
}

int main(){
    int fd = open("text", O_RDONLY);
    char* line;
    //for(int i = 0 ; i < )
    line = get_next_line(fd);
    printf("%s",line);
    line = get_next_line(fd);
    printf("%s",line);
    return 0;
}