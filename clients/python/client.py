#!/usr/bin/python3
# -*-coding:Utf-8 -*

import sys
import socket
import os
import signal
import re
import time
import asyncore
import ia
from ia import IA


if len(sys.argv) < 5:
  print("Usage: -n team_name -p port (-h host)")
  sys.exit(0)         

for i in range(1, len(sys.argv)):
  if sys.argv[i] == "-n":
   team = sys.argv[i + 1]
  elif sys.argv[i] == "-p":
   try:
    port = int(sys.argv[i + 1])
   except ValueError:
    print ("Port must be an integer")
  elif sys.argv[i] == "-h" and len(sys.argv) > 6:
   host = sys.argv[i + 1]

if 'host' not in locals():
  host = "localhost"
if 'team' not in locals() or 'port' not in locals():
  print("Usage: -n team_name -p port (-h host)")
  sys.exit(0)

params = [ team, port, host ]

nbClis = 0;
cliId = 0;
levels = [0, 0, 0, 0, 0 ,0, 0, 0]
mapX = 0;
mapY = 0;
maxPlayers = 0;


class Client(asyncore.dispatcher):

        infos = []
        cmds = []
        tmp = None
        id = 0
        lvl = 0
        inv = { "nourriture":0, "linemate":0, "deraumere":0, "sibur":0, "mendiane":0, "phiras":0, "thystame":0 }
        buffer = ""
        rep_list = []
        rep_ptr = "connection"
        obj = ""
        vision = []
        iaCallback = None
        lastCallback = None
        callbackParam = None
        isIncant = False

        def __init__(self, params):
         self.infos = params
         global cliId
         self.id = cliId
         global nbClis
         nbClis += 1
         cliId += 1
         global levels
         levels[self.lvl] += 1
         self.cmds = []
         self.tmp = None
         self.rep_list = []
         self.lvl = 0
         self.inv = { "nourriture":0, "linemate":0, "deraumere":0, "sibur":0, "mendiane":0, "phiras":0, "thystame":0 }
         self.buffer = ""
         self.rep_ptr = "connection"
         self.obj = ""
         self.vision = []
         self.iaCallback = None
         self.lastCallback = None
         self.callbackParam = None
         self.isIncant = False


         asyncore.dispatcher.__init__(self)
         self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
         self.connect( (params[2], params[1]) )


        def handle_connect(self):
          buffer = params[0] + "\n"
          self.send(buffer.encode())

        def handle_close(self):
         global nbClis
         nbClis -= 1
         global levels
         levels[self.lvl] -= 1
         self.close()


        def handle_send(self, msg, funcCallback, returnCallback, *params):
         if msg != "connect_nbr\n" and nbClis < maxPlayers:
          self.handle_send("connect_nbr\n", callbacks["connect_nbr"], None)
#         if len(self.cmds) >= 10:
 #         print ("exit")
  #        sys.exit()
         print (self.id, "envoie", msg)
         if len(params) == 0:
          self.cmds.append( {"msg":msg, "funcCallback":funcCallback, "returnCallback":returnCallback, "params":None })
         else:
          self.cmds.append( {"msg":msg, "funcCallback":funcCallback, "returnCallback":returnCallback, "params":params[0] })
         self.send(msg.encode())


        def handle_read(self):
         rep = self.recv(5).decode()
         self.buffer += rep;
         try:
          rep = self.buffer[0:self.buffer.index("\n")];
          self.buffer = self.buffer[self.buffer.index("\n") + 1:];
          if (len(rep) > 0):
           funcdic[self.rep_ptr](self, rep);
         except ValueError:
          pass


        def connection(self, msg):
         global maxPlayers
         print ("msg :", msg)
         self.rep_list.append(msg)
         if len(self.rep_list) % 3 == 0:
          self.id = nbClis
          if nbClis == 1:
           maxPlayers = int(self.rep_list[1]) + 1
          map = self.rep_list[2].split(" ")
          mapX = int(map[0])
          mapY = int(map[1])
          self.rep_ptr = "handle response"
          IA(self, mapX, mapY)

        def handle_response(self, msg):
         print (self.id, "reçoit", msg)

         if msg == "mort\n":
          sys.exit()

         if msg[:13] == "niveau actuel":
          msg = msg.replace(" ", "")
          levels[self.lvl] -= 1
          self.lvl = int(msg.split(":")[1]) + 1
          levels[self.lvl] += 1
          self.isIncant = False
          return self.iaCallback((self.lvl + 1) * 10)

         if msg == "ko\n" and self.isIncant == True:
          self.isIncant = False
          return self.iaCallback((self.lvl + 1) * 10)

         if msg[:7] == "message":
          msg = msg.split(",")
          sound = msg[0].split(" ")[1]
          if int(msg.split(":")[0]) == self.lvl:
           if (int(self.inv["nourriture"]) < ((self.lvl + 1) * 10) / 2 or self.iaCallback is None or self.isIncant is True):
            return
           self.cmds = []
           self.tmp = { "sound":int(sound), "message":msg[1].split(":")[1] }
           if self.tmp["message"] == "help\n":
            return self.goTo(self.tmp["sound"])
           elif self.tmp["message"] == "ko\n":
            return self.iaCallback((self.lvl + 1) * 10)
           elif self.tmp["message"] == "ok\n":
            if self.tmp["sound"] is not 0:
             return self.iaCallback((self.lvl + 1) * 10)
          return

         if len(self.cmds) > 0:
          cmd = self.cmds.pop(0)
          if cmd["funcCallback"] is not None:
           if cmd["params"] is None:
            cmd["funcCallback"](self, msg, cmd["returnCallback"])
           else:
            cmd["funcCallback"](self, msg, cmd["returnCallback"], cmd["params"])




        def avance(self, cb, *params):
         if len(params) > 0:
          self.handle_send("avance\n", callbacks["avance"], cb, params)
         else:
          self.handle_send("avance\n", callbacks["avance"], cb)

        def avance_callback(self, rep, cb, *params):
         if cb is not None:
          if len(params) > 0:
           cb(rep, params[0])
          else:
           cb(rep)



        def droite(self, cb, *params):
         if len(params) > 0:
          self.handle_send("droite\n", callbacks["droite"], cb, params)
         else:
          self.handle_send("droite\n", callbacks["droite"], cb)

        def droite_callback(self, rep, cb, *params):
         if cb is not None:
          if len(params) > 0:
           cb(rep, params[0])
          else:
           cb(rep)




        def gauche(self, cb, *params):
         if len(params) > 0:
          self.handle_send("gauche\n", callbacks["gauche"], cb, params)
         else:
          self.handle_send("gauche\n", callbacks["gauche"], cb)

        def gauche_callback(self, rep, cb, *params):
         if cb is not None:
          if len(params) > 0:
           cb(rep, params[0])
          else:
           cb(rep)




        def expulse(self, cb, *params):
         if len(params) > 0:
          self.handle_send("expulse\n", callbacks["expulse"], cb, params)
         else:
          self.handle_send("expulse\n", callbacks["expulse"], cb)

        def expulse_callback(self, rep, cb, *params):
         if cb is not None:
          if len(params) > 0:
           cb(rep, params[0])
          else:
           cb(rep)





        def broadcast(self, msg, cb, *params):
         if len(params) > 0:
          self.handle_send("broadcast " + msg + "\n", callbacks["broadcast"], cb, params)
         else:
          self.handle_send("broadcast " + msg + "\n", callbacks["broadcast"], cb)

        def broadcast_callback(self, rep, cb, *params):
         if cb is not None:
          if len(params) > 0:
           cb(rep, params[0])
          else:
           cb(rep)





        def fork(self, cb, *params):
         if len(params) > 0:
          self.handle_send("fork\n", callbacks["fork"], cb, params)
         else:
          self.handle_send("fork\n", callbacks["fork"], cb)

        def fork_callback(self, rep, cb, *params):
         if cb is not None:
          if len(params) > 0:
           cb(rep, params[0])
          else:
           cb(rep)


        def connect_nbr(self, cb):
         self.handle_send("connect_nbr\n", callbacks["connect_nbr"], cb)

        def connect_nbr_callback(self, rep, cb):
         if (int(rep) > 0):
          Client(params)


        def prend(self, obj, cb, *params):
         self.obj = obj
         if len(params) > 0:
          self.handle_send("prend " + obj + "\n", callbacks["prend"], cb, params)
         else:
          self.handle_send("prend " + obj + "\n", callbacks["prend"], cb)

        def prend_callback(self, rep, cb, *params):
         if rep == "ok\n":
          self.inv[self.obj] += 1
         if cb is not None:
          if len(params) > 0:
           cb(rep, params[0])
          else:
           cb(rep)



        def pose(self, obj, cb, *params):
         self.obj = obj
         if len(params) > 0:
          self.handle_send("pose " + obj + "\n", callbacks["pose"], cb, params)
         else:
          self.handle_send("pose " + obj + "\n", callbacks["pose"], cb)

        def pose_callback(self, rep, cb, *params):
         if rep == "ok\n":
          self.inv[self.obj] -= 1
         if cb is not None:
          if len(params > 0):
           cb(rep, params[0])
          else:
           cb(rep)



        def inventaire(self, cb, *params):
         if len(params) > 0:
          self.handle_send("inventaire\n", callbacks["inventaire"], cb, params)
         else:
          self.handle_send("inventaire\n", callbacks["inventaire"], cb)


        def inventaire_callback(self, rep, cb, *params):
         tab = re.findall(r'\d+', rep)
         if tab is not None:
          self.inv["nourriture"] = tab[0]
          self.inv["linemate"] = tab[1]
          self.inv["deraumere"] = tab[2]
          self.inv["sibur"] = tab[3]
          self.inv["mendiane"] = tab[4]
          self.inv["phiras"] = tab[5]
          self.inv["thystame"] = tab[6]
         if cb is not None:
          if len(params) > 0:
           cb(rep, params)
          else:
           cb(rep)



        def voir(self, cb, *params):
         if len(params) > 0:
          self.handle_send("voir\n", callbacks["voir"], cb, params)
         else:
          self.handle_send("voir\n", callbacks["voir"], cb)


        def voir_callback(self, rep, cb, *params):
         vue = rep.replace("{ ", "").replace("}", "").split(",")
         i = 0
         j = len(vue)
         while i < j:
          vue[i] = self.creatObject(vue[i])
          i += 1
         self.vision = vue
         if cb is not None:
          if len(params) > 0:
           cb(rep, params)
          else:
           cb(rep)



        def incantation(self, cb, *params): 
         if len(params) > 0:
          self.handle_send("incantation\n", callbacks["incantation"], cb, params)
         else:
          self.handle_send("incantation\n", callbacks["incantation"], cb)

        def incantation_callback(self, rep, cb, *params):
         if rep == "ko\n":
          self.isIncant = False
         if cb is not None:
          if len(params) > 0:
           cb(rep, params)
          else:
           cb(rep)



        def numberOf(self, cmd, to_find):
         ret = 0
         try:
          cmd.index(to_find)
          ret = 1
          return ret
         except SyntaxError: 
          return ret
         except ValueError: 
          return ret

        def creatObject(self, cmd):
         ret = {
                "player":self.numberOf(cmd, "joueur"),
                "nourriture":self.numberOf(cmd, "nourriture"),
                "linemate":self.numberOf(cmd, "linemate"),
                "deraumere":self.numberOf(cmd, "deraumere"),
                "sibur":self.numberOf(cmd, "sibur"),
                "mendiane":self.numberOf(cmd, "mendiane"),
                "phiras":self.numberOf(cmd, "phiras"),
                "thystame":self.numberOf(cmd, "thystame"),
               }
         return ret


        def move(self, case):
         if case == 0:
          return
         self.avance(None)
         pos_actu = 2
         coef = 4
         while (pos_actu != case):
          if (case / pos_actu) > 1.5:
           self.avance(None)
           pos_actu += coef
           coef += 2
          elif (case / pos_actu) < 1:
           self.gauche(None)
           while (pos_actu != case):
            self.avance(None)
            pos_actu -= 1
          else:
           self.droite
           while (pos_actu != case):
            self.avance(None)
            pos_actu += 1


        def goTo(self, sound):

         if (sound == 1):
          self.avance(None)

         if (sound == 2):
          self.avance(None)
          self.gauche(None)
          self.avance(None)

         if (sound == 3):
          self.gauche(None)
          self.avance(None)

         if (sound == 4):
          self.gauche(None)
          self.avance(None)
          self.gauche(None)
          self.avance(None)

         if (sound == 5):
          self.gauche(None)
          self.gauche(None)
          self.avance(None)

         if (sound == 6):
          self.droite(None)
          self.avance(None)
          self.droite(None)
          self.avance(None)

         if (sound == 7):
          self.droite(None)
          self.avance(None)

         if (sound == 8):
          self.avance(None)
          self.droite(None)
          self.avance(None)



def signal_handler(signum, frame):
        sys.exit()

signal.signal(signal.SIGINT, signal_handler)

funcdic = {
         "connection":Client.connection,
         "handle response":Client.handle_response
        }

callbacks = {
         "avance":Client.avance_callback,
         "droite":Client.droite_callback,
         "gauche":Client.gauche_callback,
         "expulse":Client.expulse_callback,
         "broadcast":Client.broadcast_callback,
         "fork":Client.fork_callback,
         "connect_nbr":Client.connect_nbr_callback,
         "inventaire":Client.inventaire_callback,
         "voir":Client.voir_callback,
         "prend":Client.prend_callback,
         "pose":Client.pose_callback,
         "incantation":Client.incantation_callback,
        }


Client(params)
asyncore.loop()

