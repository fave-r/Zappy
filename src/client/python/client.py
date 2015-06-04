#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket
import signal
from ia import *

class Client:

   s = 0
   id_client = 0;
   def __init__(self, id_cli, team, host, port):

        Client.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        Client.s.connect((host, port))

        msg = Client.s.recv(1024).decode()
        print (msg)
        Client.s.send(team.encode())
        remain = Client.s.recv(1024).decode()
        print (remain)
        position = Client.s.recv(1024).decode()
        print (position)

        id_client = id_cli

        begin_ia(Client.s, id_client)

        Client.s.close()


   def signal_handler(signal, frame):
        Client.s.close()
        sys.exit(0)
   signal.signal(signal.SIGINT, signal_handler)
