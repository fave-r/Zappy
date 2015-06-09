#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
from client import *

if len(sys.argv) < 5:
 print("Usage: -n team_name -p port (-h host)")
 sys.exit(0)

team = sys.argv[2] + "\n"
host = "localhost"
if len(sys.argv) > 6:
 host = sys.argv[6]
port = int(sys.argv[4])

t_connect = (team, port, host)

Client(t_connect)
