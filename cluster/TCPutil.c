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

#include "TCPutil.h"

int TCPsend(int socketClient, const char *query) {
    return (int) send(socketClient, query, strlen(query) + 1, 0);
}

char *TCPrecv(int socketClient) {

    int size = 0;
    char *msg = (char *) malloc(sizeof(char));
    do {
        recv(socketClient, msg + size, 1, 0);
        //printf("%c ", msg[size]);
        msg = (char *) realloc(msg, sizeof(char) * ++size);
        //printf("%d\n", size);

    } while (msg[size - 1] != '\0');
    msg[size - 1] = '\0';

    return msg;
}

int TCPclose(int socket) {
    return close(socket);
}


