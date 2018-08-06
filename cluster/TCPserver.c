/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
*/

/**
 * @author Pierre Chopinet
 * @Date 2018-08-04
 */

#include <pthread.h>
#include "TCPserver.h"

int TCPcreateServer(int port) {
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = INADDR_ANY;

    int sd = socket(AF_INET, SOCK_STREAM, 0);

    bind(sd, (struct sockaddr *) &sa, sizeof(sa));
    listen(sd, SOMAXCONN);

    return sd;

}

int TCPacceptConnection(int socketServer) {
    struct sockaddr_in c_sa;
    int taille = sizeof(c_sa);
    int clientSocket = accept(socketServer, (struct sockaddr *) &c_sa, (socklen_t *) &taille);

    return clientSocket;
}


void *TCPthreadConnection(void *socket) {
    int *socketClient = (int *) socket;
    char *c = TCPrecv(*socketClient);

    printf("Recv : %s\n", c);

    TCPsend(*socketClient, c);

    close(*socketClient);
    free(socketClient);
    return NULL;
}

void TCPserver(int port, void *(*thread)(void *)) {
    int serverSocket = TCPcreateServer(port);
    printf("#######################\nServer Socket : %d\n", serverSocket);
    while (1) {
        int *clientSocket = (int *) malloc(sizeof(int));
        *clientSocket = TCPacceptConnection(serverSocket);
        pthread_t p;
        if (*clientSocket == -1) exit(-1);
        printf("#######################\nClient Socket : %d\n", *clientSocket);

        pthread_create(&p, NULL, thread, (void *) clientSocket);
    }
    close(serverSocket);
}
