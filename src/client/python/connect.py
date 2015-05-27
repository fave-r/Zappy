#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket

#print (sys.argv[1])
#print (sys.argv[2])
#print (sys.argv[3])
#print (sys.argv[4])
#if len(sys.argv) > 5:
# print (sys.argv[5])
#if len(sys.argv) > 6:
# print (sys.argv[6])

team = sys.argv[2] + "\n"
host = "localhost"
if len(sys.argv) > 6:
 host = sys.argv[6]
port = int(sys.argv[4])

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host, port))

msg = s.recv(1024).decode()
print (msg)
s.send(team.encode())
num_client = s.recv(1024).decode()
print (num_client)
position = s.recv(1024).decode()
print (position)

msg_send = ""
while 1:
        msg_send = input("> ")
        if msg_send == "fin":
         break
        msg_send += "\n"
        msg_send = msg_send.encode()
        s.send(msg_send)
        msg_recv = s.recv(1024).decode()
        print (msg_recv)

s.close()
