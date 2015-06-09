#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket
import signal
from ia import *

#t_connect = (team, port, host)

id_client = 0
nb_client = 0
max_client = 0
pblevels = [ 0, 0, 0, 0, 0, 0, 0, 0 ]

class Client:

   sock = 0
   lvl = 0
   cliId = 0
   t_connect = 0
   mapX = 0
   mapY = 0
   def __init__(self, t_connect):

      try:
        self.t_connect = t_connect

        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock.connect((t_connect[2], t_connect[1]))

        global max_client
        global nb_client
        nb_client += 1
        global id_client
        id_client += 1
        self.cliId = id_client
        global pblevels
        pblevels[0] += 1

        msg = self.sock.recv(1024).decode()
        print (msg)
        self.sock.send(t_connect[0].encode())
        remain = self.sock.recv(1024).decode()
        print (remain)
        map = self.sock.recv(1024).decode()
        print (map)

        if self.cliId == 1:
         max_client = int(remain) + 1

        map = map.split(' ')
        self.mapX = int(map[0])
        self.mapY = int(map[1])

        begin_ia(self)

        self.sock.close()
        nb_client -= 1
        pblevels[self.lvl] -= 1

      except KeyboardInterrupt:
        nb_client -= 1
        pblevels[self.lvl] -= 1
        self.sock.close()
        sys.exit(0)


   def sendCommand(self, msg):
     print ("{} : {}".format(self.cliId, msg))
#     if (msg != "connect_nbr" and nb_client < max_client):
#      rep = self.sendCommand("connect_nbr")
#      if int(rep) > 0:
#       Client(self.t_connect)
     msg = msg.encode()
     self.sock.send(msg)
     return self.recvCommand()

   def recvCommand(self):
     rep = ""
     while len(rep) < 2:
      rep = self.sock.recv(1024).decode()
     print ("rep = %s" % rep)
     if (rep == "mort\n"):
      self.sock.close()
      sys.exit(0)
     return rep
