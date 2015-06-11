import sys
import socket
import re
import ia


def sendCommand(sock, msg):
        print ("{} envoie {}".format(ia.cliId, msg))
        sock.send(msg.encode())

def my_recv(sock):
        msg = sock.recv(1024).decode()
        ret = "" + msg
        if len(msg) <= 0:
         sys.exit(0)
        else:
         while len(msg) == 1024:
          msg = sock.recv(1024).decode()
          ret += msg
        return ret


def reception(sock, cast):
        rep = ""
        while rep == "":
         str = my_recv(sock)
         if not str:
          sys.exit(0)
         split = str.split('\n')
         for cmd in split:
          if cmd != "":
           args = cmd.split()
           if args[0] == "message":
            cast.append(cmd)
           elif split[0] == "mort":
            sys.exit(0)
           else:
            rep = cmd
        
        print ("{} reçoit {}".format(ia.cliId, rep))
        return rep


def avance(sock, cast):
 msg = "avance\n"
 sendCommand(sock, msg)
 return reception(sock, cast)

def gauche(sock, cast):
 msg = "gauche\n"
 sendCommand(sock, msg)
 return reception(sock, cast)

def droite(sock, cast):
 msg = "droite\n"
 sendCommand(sock, msg)
 return reception(sock, cast)

def voir(sock, cast):
 msg = "voir\n"
 sendCommand(sock, msg)
 rep = reception(sock, cast)
 return voir_to_list(rep)

def voir_to_list(msg):
 msg = msg.replace("{ ", "").replace('}', '').split(',');
 i = 0
 j = len(msg)
 while i < j:
  msg[i] = creatObject(msg[i])
  i += 1
 return msg

def inventaire(sock, cast, inv):
 msg = "inventaire\n"
 sendCommand(sock, msg)
 rep = reception(sock, cast)
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

def prend(sock, cast, objet):
 msg = "prend " + objet + "\n"
 sendCommand(sock, msg)
 if reception(sock, cast) != "ko":
  ia.inv[objet] = int(ia.inv[objet]) + 1

def pose(sock, cast, objet):
 msg = "pose " + objet + "\n"
 sendCommand(sock, msg)
 if reception(sock, cast) != "ko":
  ia.inv[objet] = int(ia.inv[objet]) - 1

def expulse(sock, cast):
 msg = "expulse\n"
 sendCommand(sock, msg)
 return reception(sock, cast)

def broadcast(sock, cast, texte):
 msg = "broadcast " + texte + "\n"
 sendCommand(sock, msg)
 return reception(sock, cast)

def incantation(sock, cast):
 msg = "incantation\n"
 sendCommand(sock, msg)
 reception(sock, cast)
 return reception(sock, cast)

def fork(sock, cast):
 msg = "fork\n"
 sendCommand(sock, msg)
 return reception(sock, cast)

def connect_nbr(client):
 msg = "connect_nbr\n"
 sendCommand(sock, msg)
 return reception(sock, cast)

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


def move(case, sock, cast):
 if case == 0:
  return
 avance(sock, cast)
 pos_actu = 2
 coef = 4
 while (pos_actu != case):
  if (case / pos_actu) > 1.5:
   avance(sock, cast)
   pos_actu += coef
   coef += 2
  elif (case / pos_actu) < 1:
   gauche(sock, cast)
   while (pos_actu != case):
    avance(sock, cast)
    pos_actu -= 1
  else:
   droite(sock, cast)
   while (pos_actu != case):
    avance(sock, cast)
    pos_actu += 1


def take_ressource(sock, cast, ressource, need):
 i = 0
 while i < need:
  if prend(sock, cast, ressource) == "ko\n":
   break
  i += 1

def drop_ressource(sock, cast, lvl):
 for elem in ia.evol[lvl]:
  i = 0
  if elem != "player":
   if ia.evol[lvl][elem] > 0:
    while i < ia.evol[lvl][elem]:
     i += 1
     pose(sock, cast, elem)
