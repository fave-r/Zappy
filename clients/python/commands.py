#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket
import re

def avance(client):
 msg = "avance\n"
 return client.sendCommand(msg)

def gauche(client):
 msg = "gauche\n"
 return client.sendCommand(msg)

def droite(client):
 msg = "droite\n"
 return client.sendCommand(msg)

def voir(client):
 msg = "voir\n"
 rep = client.sendCommand(msg)
 return voir_to_list(rep)

def voir_to_list(msg):
 msg = msg.replace("{ ", "").replace('}', '').split(',');
 i = 0
 j = len(msg)
 while i < j:
  msg[i] = creatObject(msg[i])
  i += 1
 return msg

def inventaire(client, inv):
 msg = "inventaire\n"
 rep = client.sendCommand(msg)
 update_inventory(rep, inv)

def update_inventory(msg, inv):
 tab = re.findall(r'\d+', msg)
 inv["nourriture"] = tab[0]
 inv["linemate"] = tab[1]
 inv["deraumere"] = tab[2]
 inv["sibur"] = tab[3]
 inv["mendiane"] = tab[4]
 inv["phiras"] = tab[5]
 inv["thystame"] = tab[6]

def prend(client, objet):
 msg = "prend " + objet + "\n"
 return client.sendCommand(msg)

def pose(client, objet):
 msg = "pose " + objet + "\n"
 return client.sendCommand(msg)

def expulse(client):
 msg = "expulse\n"
 return client.sendCommand(msg)

def broadcast(client, texte):
 msg = "broadcast " + texte + "\n"
 return client.sendCommand(msg)

def incantation(client):
 msg = "incantation\n"
 return client.sendCommand(msg)

def fork(client):
 msg = "fork\n"
 return client.sendCommand(msg)

def connect_nbr(client):
 msg = "connect_nbr\n"
 return client.sendCommand(msg)

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
        ("phiras", numberOf(cmd, "phiras")),
        ("thystame", numberOf(cmd, "thystame")),
       ]
 return ret


def move(case, client):
 if case == 0:
  return
 avance(client)
 pos_actu = 2
 coef = 4
 while (pos_actu != case):
  if (case / pos_actu) > 1.5:
   avance(client)
   pos_actu += coef
   coef += 2
  elif (case / pos_actu) < 1:
   gauche(client)
   while (pos_actu != case):
    avance(client)
    pos_actu -= 1
  else:
   droite(client)
   while (pos_actu != case):
    avance(client)
    pos_actu += 1


def count_ressource(client, ressource):
 i = 0
 while prend(client, ressource) == "ok\n":
  i += 1
 j = i
 while (j > 0):
  pose(client, ressource)
  j -= 1
 return i
