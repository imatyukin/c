//
// Chapter 4 Exercise 2
//
#include "unp.h"

int main(int argc, char **argv)
{
    int	sockfd, n;
    char	recvline[MAXLINE + 1];
    struct	sockaddr_in servaddr;
    struct	sockaddr_storage ss;
    socklen_t	len;

    if (argc != 2)
        err_quit("usage: exercise4_02 <IPaddress>");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_sys("socket error");

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port   = htons(13); /* daytime server */
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
        err_quit("inet_pton error for %s", argv[1]);

    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) < 0)
        err_sys("connect error");

    /*
     * the requiment of exercise 4.2
     */
    len = sizeof(ss);
    if (getsockname(sockfd, (SA *)&ss, &len) < 0)
        err_sys("getsockname error");
    printf("local address and port: %s\n", sock_ntop((SA *)&ss, len));

    while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF)
            err_sys("fputs error");
    }
    if (n < 0)
        err_sys("read error");
    exit(0);
}
