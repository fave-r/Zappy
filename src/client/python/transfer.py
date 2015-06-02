#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket

def sendCommand(socket, msg):
 print (msg)
 msg = msg.encode()
 socket.send(msg)
 return recvCommand(socket)

def recvCommand(socket):
 rep = ""
 while len(rep) < 2:
  rep = socket.recv(1024).decode()
 print ("rep = %s" % rep)
 if (rep == "mort\n"):
  socket.close()
  sys.exit(0)
 return rep
