clang -o TCPsocketClient TCPsocketClient.c DieWithError.c
clang -o TCPsocketServer TCPsocketServer.c HandleTCPClient.c DieWithError.c