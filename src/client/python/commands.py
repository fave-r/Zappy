#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket

def avance(socket):
 msg = "avance\n"
 return sendCommand(socket, msg)

def gauche(socket):
 msg = "gauche\n"
 return sendCommand(socket, msg)

def droite(socket):
 msg = "droite\n"
 return sendCommand(socket, msg)

def voir(socket):
 msg = "voir\n"
 rep = sendCommand(socket, msg)
 return voir_to_list(rep)

def voir_to_list(msg):
 msg = msg.replace("{ ", "").replace('}', '').split(',');
 i = 0
 j = len(msg)
 while i < j:
  msg[i] = creatObject(msg[i])
  i += 1
 return msg

def inventaire(socket, inv):
 msg = "inventaire\n"
 rep = sendCommand(socket, msg)
 update_inventory(rep, inv)

def update_inventory(msg, inv):
 msg = msg.replace("{", "").replace('}', '').split(',');
 inv[0][1] = numberOf(msg, "nourriture")
 inv[1][1] = numberOf(msg, "linemate")
 inv[2][1] = numberOf(msg, "deraumere")
 inv[3][1] = numberOf(msg, "sibur")
 inv[4][1] = numberOf(msg, "mendiane")
 inv[5][1] = numberOf(msg, "phiras")
 inv[6][1] = numberOf(msg, "thystame")

def prend(socket, objet):
 msg = "prend " + objet + "\n"
 return sendCommand(socket, msg)

def pose(socket, objet):
 msg = "pose " + objet + "\n"
 return sendCommand(socket, msg)

def expulse(socket):
 msg = "expulse\n"
 return sendCommand(socket, msg)

def broadcast(socket, texte):
 msg = "broadcast " + texte + "\n"
 return sendCommand(socket, msg)

def incantation(socket):
 msg = "incantation\n"
 return sendCommand(socket, msg)

def fork(socket):
 msg = "fork\n"
 return sendCommand(socket, msg)

def connect_nbr(socket):
 msg = "connect_nbr\n"
 return sendCommand(socket, msg)


def sendCommand(socket, msg):
 print (msg)
 msg = msg.encode()
 socket.send(msg)
 rep = socket.recv(1024).decode()
 print (rep)
 if (rep == "mort\n"):
  socket.close()
  sys.exit(0)
 return rep


def numberOf(cmd, to_find):
 ret = 0
 try:
  cmd.index(to_find)
  ret = 1
  return ret
#  while cmd.index(to_find):
#   begin = cmd[0:cmd.index(to_find)]
#   end = cmd[cmd.index(to_find) + len(to_find):]
#   cmd = begin + end
#   ++ret
 except SyntaxError: 
  return ret
 except ValueError: 
  return ret

def creatObject(cmd):
 ret = [
        ("player", numberOf(cmd, "player")),
        ("nourriture", numberOf(cmd, "nourriture")),
        ("linemate", numberOf(cmd, "linemate")),
        ("deraumere", numberOf(cmd, "deraumere")),
        ("sibur", numberOf(cmd, "sibur")),
        ("mendiane", numberOf(cmd, "mendiane")),
        ("phirus", numberOf(cmd, "phiras")),
        ("thystame", numberOf(cmd, "thystame")),
       ]
 return ret


def move(case, socket):
 if case == 0:
  case += 1
  #return
 avance(socket)
 pos_actu = 2
 coef = 4
 while (pos_actu != case):
  if (case / pos_actu) > 1.5:
   avance(socket)
   pos_actu += coef
   coef += 2
  elif (case / pos_actu) < 1:
   gauche(socket)
   while (pos_actu != case):
    avance(socket)
    pos_actu -= 1
  else:
   droite(socket)
   while (pos_actu != case):
    avance(socket)
    pos_actu += 1
