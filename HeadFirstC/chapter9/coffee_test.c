#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]){
	char *my_env[] = {"FOOD=coffee", NULL};
	if(execle("/Users/igor/Documents/workspace/c/HeadFirstC/chapter9/coffee", "/Users/igor/Documents/workspace/c/HeadFirstC/chapter9/coffee", "donuts", NULL, my_env) == -1){
		fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
		return 1;
	}
	fprintf(stderr,"Can't create order: %s\n", strerror(errno));
	return 1;
	return 0;
}
