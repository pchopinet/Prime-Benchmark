#!/bin/bash

gcc main.c TCPclient.c TCPutil.c -O3 -o master -g
gcc slave.c TCPserver.c TCPutil.c -O3 -o slave -lm -lpthread -g
