#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket
import os
import signal
from ia import *
from survive import *

glo_sock = 0

def get_params(argv):
        if len(argv) < 5:
         print("Usage: -n team_name -p port (-h host)")
         sys.exit(0)         

        for i in range(1, len(argv)):
         if argv[i] == "-n":
          team = argv[i + 1]
         elif argv[i] == "-p":
          port = int(argv[i + 1])
         elif argv[i] == "-h" and len(argv) > 6:
          host = argv[i + 1]

        if 'host' not in locals():
         host = "localhost"
        if 'team' not in locals() or 'port' not in locals():
         print("Usage: -n team_name -p port (-h host)")
         sys.exit(0)         

        return team, port, host

def connection(port, host):
        try:
         sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
         sock.connect((host, port))
        except socket.error:
         print ("CANNOT CONNECT TO SERVER.")
         sys.exit(0)

        my_recv(sock)
        msg = team + "\n"
        sendCommand(sock, team + "\n")
        rcv = my_recv(sock).split("\n")
        nb_client = int(rcv[0])
        rcv = my_recv(sock).split(" ")
        mapX = rcv[0]
        mapY = rcv[1][:-1]

        return sock, nb_client, mapX, mapY


def signal_handler(signum, frame):
        global glo_sock
        glo_sock.close()
        sys.exit()

signal.signal(signal.SIGINT, signal_handler)

if __name__ == '__main__':

        team, port, host = get_params(sys.argv)
        sock, nb_client, mapX, mapY = connection(port, host)
        global glo_sock
        glo_sock = sock
        print (nb_client, mapX, mapY)

        max_client = nb_client + 1
        for i in range(1, max_client):
         pid = os.fork()
         if pid == 0:
          sock.close()
          sock, nb_client, mapX, mapY = connection(port, host)
          begin_ia(sock, i)
          sys.exit(1)

        i += 1
        begin_ia(sock, i)
        sys.exit(1)
