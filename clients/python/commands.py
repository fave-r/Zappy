#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket
import re
from transfer import *

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
 tab = re.findall(r'\d+', msg)
 i = 0
 while i < 7:
  tmp = list(inv[i])
  tmp[1] = int(tab[i])
  inv[i] = tuple(tmp)
  i += 1

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

def numberOf(cmd, to_find):
 ret = 0
 try:
  cmd.index(to_find)
  ret = 1
  return ret
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
  return
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
