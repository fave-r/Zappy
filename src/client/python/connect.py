#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket
import time

print (sys.argv[1])
print (sys.argv[2])
print (sys.argv[3])
print (sys.argv[4])
if len(sys.argv) > 5:
 print (sys.argv[5])
if len(sys.argv) > 6:
 print (sys.argv[6])

host = "localhost"
if len(sys.argv) > 6:
 host = sys.argv[6]
port = int(sys.argv[4])

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host, port))


s.close()
