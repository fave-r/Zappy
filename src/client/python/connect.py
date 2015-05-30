#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket
import signal
from ia import *

def signal_handler(signal, frame):
        s.close()
        sys.exit(0)
signal.signal(signal.SIGINT, signal_handler)

if len(sys.argv) < 5:
 print("Usage: -n team_name -p port (-h host)")
 sys.exit(0)

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
id_client = s.recv(1024).decode()
print (id_client)
position = s.recv(1024).decode()
print (position)

begin_ia(s)

s.close()
