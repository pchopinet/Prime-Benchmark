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

#include "TCPclient.h"

int TCPconnectServer(const char *IP, int port) {
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = (in_addr_t) inet_addr(IP);

    int socketClient = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(socketClient, (struct sockaddr *) &sa, sizeof(sa)) != 0) {
        perror("connect : ");
        exit(-1);
    } else {
        printf("Client Socket : %d\n", socketClient);
    }
    return socketClient;
}
