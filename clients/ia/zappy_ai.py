#!/usr/bin/python3
# -*-coding:Utf-8 -*

import sys
import socket
import os
import signal
import re
import time
import random
import select
import asyncore


sys.setrecursionlimit(10000)
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
nbClis = 0
cliId = 0;
levels = [0, 0, 0, 0, 0 ,0, 0, 0]
maxPlayers = 8
evol = [
        {"player":1, "linemate":1, "deraumere":0, "sibur":0, "mendiane":0, "phiras":0, "thystame":0},
        {"player":2, "linemate":1, "deraumere":1, "sibur":1, "mendiane":0, "phiras":0, "thystame":0},
        {"player":2, "linemate":2, "deraumere":0, "sibur":1, "mendiane":0, "phiras":2, "thystame":0},
        {"player":4, "linemate":1, "deraumere":1, "sibur":2, "mendiane":0, "phiras":1, "thystame":0},
        {"player":4, "linemate":1, "deraumere":2, "sibur":1, "mendiane":3, "phiras":0, "thystame":0},
        {"player":6, "linemate":1, "deraumere":2, "sibur":3, "mendiane":0, "phiras":1, "thystame":0},
        {"player":6, "linemate":2, "deraumere":2, "sibur":2, "mendiane":2, "phiras":2, "thystame":1},
       ]
dirPos = [ 0, 2, 1, 8 ]



class IA:

        cli = 0
        mapX = 0
        mapY = 0
        direction = 0
        foodNeeded = 0


        def __init__(self, cli, mapX, mapY):
         self.cli = cli
         self.mapX = mapX
         self.mapY = mapY
         self.direction = 0
         self.foodNeeded = 0
         self.cli.iaCallback = self.begin_ia
         self.cli.fork(None)
         self.begin_ia((self.cli.lvl + 1) * 20)


        def survivor(self, food, vue):

         if int(self.cli.inv["nourriture"]) > int(food):
          return self.begin_ia(10)

         i = 0

         while i < 4:
          if int(vue[i]["nourriture"]) > 0:
           if int(vue[2]["nourriture"]) > 0 and i != 0:
            self.cli.move(dirPos[2], None)
            return self.survivor2(food)
           else:
            self.cli.move(dirPos[i], None)
            return self.survivor2(food)
          i += 1

         self.cli.avance(None)
         new_vue = self.cli.voir(None)
         return self.survivor(food, new_vue)

        def survivor2(self, food):
          rep = self.cli.prend("nourriture", None)
          if rep == "ok":
           new_vue = self.cli.voir(None)
           return self.survivor(food, new_vue)
          else:
           self.cli.move(dirPos[int((random.uniform(0, 0.9) * 10) % 3 + 1)], None)
           new_vue = self.cli.voir(None)
           return self.survivor(food, new_vue)



        def evolve(self, vue):

         case = vue[0]

         if self.cli.id != self.cli.myLeader:
          return self.survivor(int(self.cli.inv["nourriture"]) + 10, vue)


         if self.canIncant(case) == False:
          self.searchStones(vue)

         for item in case:
          if (item != "player" and item != "nourriture"):
           if case[item] > evol[self.cli.lvl][item]:
            rep = self.cli.prend(item, None)
            return self.callbackStone(rep)

           if case[item] < evol[self.cli.lvl][item]:
            rep = self.cli.pose(item, None)
            return self.callbackStone(rep)


         return self.regroupTeam(vue)


        def canIncant(self, case):
         for item in case:
          if item != "player" and item != "nourriture" and int(case[item]) + int(self.cli.inv[item]) < int(evol[self.cli.lvl][item]):
           return False
         return True



        def launchIncant(self, vue):

         self.cli.broadcast(str(self.cli.lvl) + ":incant", None)
         rep = self.cli.incantation(None)
         if rep == "ko":
          self.cli.broadcast(str(self.cli.lvl) + ":ko", None)
          self.cli.avance(None)
          return self.begin_ia((self.cli.lvl + 1) * 10)
         else:
          return self.begin_ia((self.cli.lvl + 1) * 10)




        def regroupTeam(self, vue):

         case = vue[0]

         if case["player"] >= evol[self.cli.lvl]["player"]:
          return self.launchIncant(vue)
         elif case["player"] > evol[self.cli.lvl]["player"]:
          self.cli.avance(None)
          return self.begin_ia((self.cli.lvl + 1) * 10)
         else:
           self.cli.broadcast(str(self.cli.lvl) + ":help", None)
           self.cli.isIncant = True
           vue = self.cli.voir(None)
           return self.regroupTeam(vue)


        def callbackStone(self, rep):
         vue = self.cli.voir(None)
         if rep == "ok":
          return self.evolve(vue)
         else:
          self.cli.move(self.findCase(vue), None)
          new_vue = self.cli.voir(None)
          return self.evolve(new_vue)



        def searchStones(self, vue):

         case = vue[0]
         if self.cli.lvl + 1 == 7:
          nextlvl = self.cli.lvl + 1
         else:
          nextlvl = self.cli.lvl + 1

         for item in case:
          if item != "player" and item != "nourriture" and int(case[item]) > 0 and (int(evol[self.cli.lvl][item]) > 0 or int(evol[nextlvl][item]) > 0):
            rep = self.cli.prend(item, None)
            new_vue = self.cli.voir(None)
            return self.searchStones(new_vue)

         self.cli.move(self.findCase(vue), None)
         new_vue = self.cli.voir(None)
         return self.evolve(new_vue)




        def findCase(self, vue):
         needy = [ ]
         direction = 0
         i = 0

         while i < 4:
          score = 0
          for item in vue[i]:
           if item != "player" and item != "nourriture":
            if vue[i][item] > 0 and evol[self.cli.lvl][item] > 0:
             score += 11
           elif item == "player":
            if vue[i][item] > 0:
             score -= 10 * vue[i][item]

          needy.append({ "score":score, "index":i })
          i += 1

         i = 0
         l = len(needy)
         while i < l:
          if needy[0]["score"] > needy[i]["score"]:
           needy[0] = needy[0]
          else:
           needy[0] = needy[i]
          i += 1

         if needy[0]["score"] > 0:
          direction = needy[0]["index"]
         if needy[0]["score"] == 0:
          i = 0
          l = len(needy)
          while i < l:
           if needy[i]["score"] < 0:
            direction = needy[0]["index"]
            break
           else:
            direction = int((random.uniform(0, 0.9) * 10) % 3 + 1)
           i += 1
         if needy[0]["score"] < 0:
           direction = int((random.uniform(0, 0.9) * 10) % 3 + 1)
         return dirPos[direction];





        def begin_ia(self, food):

         inv = self.cli.inventaire(None)
         vue = self.cli.voir(None)
         if int(inv["nourriture"]) < int(food):
          return self.survivor(food + 20, vue)
         else:
          return self.evolve(vue)

 


class Client:

        sock = None
        infos = []
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
        isIncant = False
        ia = None
        mapX = 0
        mapY = 0
        cmd_queue = []
        msg_queue = []
        rep_queue = []
        lvl_queue = []
        myLeader = 0
 

        def __init__(self, params):
         self.sock = None
         self.infos = params
         global cliId
         self.id = cliId
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
         self.ia = None
         self.mapX = 0
         self.mapY = 0
         self.cmd_queue = []
         self.msg_queue = []
         self.rep_queue = []
         self.lvl_queue = []
         self.myLeader = 0

         self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
         self.sock.connect((params[2], params[1]))
         self.handle_connect()


        def handle_connect(self):
         del self.cmd_queue[:]
         global nbClis
         global levels
         global cliId
         nbClis += 1
         cliId += 1
         levels[self.lvl] += 1
         rep = self.sock.recv(12).decode()
         self.rep_list.append(rep)
         buffer = params[0] + "\n"
         self.sock.send(buffer.encode())
         rep = self.sock.recv(3).decode()
         self.rep_list.append(rep)
         rep = self.sock.recv(6).decode()
         self.rep_list.append(rep)
         self.connection(None)


        def handle_close(self):
         global nbClis
         global levels
         nbClis -= 1
         levels[self.lvl] -= 1
         self.sock.close()
         os._exit(0)



        def handle_send(self, msg, funcCallback):
         if msg != "connect_nbr\n" and nbClis < maxPlayers and self.id == 1:
          self.connect_nbr(None)
         if len(self.cmd_queue) >= 10:
          print (self.id, "exit")
          print (self.cmd_queue)
          sys.exit()

         self.sock.send(msg.encode())

         self.cmd_queue.append(msg)

         return self.receive()


        def handle_read(self):
         if len(self.buffer) == 0:
          rep = self.sock.recv(16384).decode()
          self.buffer += rep;

         try:
           msg = self.buffer[0:self.buffer.index("\n")]
           self.buffer = self.buffer[self.buffer.index("\n") + 1:]

           if msg == "elevation en cours":
            print (self.id, msg)
           return msg

           if msg[:6] == "niveau":
            return msg

           if self.isIncant == True:
            return self.handle_read()
            
           if msg[:7] == "message" and int(self.inv["nourriture"]) < ((self.lvl + 1) * 10) / 2:
            cont = msg.split(",")
            sound = cont[0].split(" ")[1]
            cont = cont[1].split(";")
            infos1 = cont[0]
            infos2 = cont[1]
            team = infos1.split("/")[0]
            leader = int(infos1.split("/")[1])
            niv = int(infos2.split(":")[0])
            tmp = { "sound":int(sound), "message":infos2.split(":")[1] }

            if niv != self.lvl or team != params[0] or leader != self.myLeader:
             return self.handle_read()
            else:
             return msg

           self.cmd_queue.pop(0)
           return msg

         except ValueError:
          pass


        def receive(self):
         rep = self.handle_read()

         if rep == None or rep == "mort":
          print (self.id, "I'M DEAD")
          self.handle_close()

         elif rep[:6] == "niveau":
          while len(self.cmd_queue) > 0:
           tmp = self.handle_read()
           if tmp[:7] != "message":
            self.cmd_queue.pop(0)
          del self.rep_queue[:]
          del self.cmd_queue[:]
          return self.level_up(rep)

         elif rep == "ko" and self.isIncant == True:
          self.isIncant = False
          while len(self.cmd_queue) > 0:
           tmp = self.handle_read()
           if tmp[:7] != "message":
            self.cmd_queue.pop(0)
          del self.rep_queue[:]
          del self.cmd_queue[:]
          return self.iaCallback((self.lvl + 1) * 10)
          
         if rep[:7] == "message":
          cont = rep.split(",")
          sound = cont[0].split(" ")[1]
          cont = cont[1].split(";")
          infos1 = cont[0]
          infos2 = cont[1]
          team = infos1.split("/")[0]
          leader = int(infos1.split("/")[1])
          niv = int(infos2.split(":")[0])
          tmp = { "sound":int(sound), "message":infos2.split(":")[1] }


          if niv == self.lvl and leader == self.myLeader and team == params[0] and self.isIncant == False:
           while len(self.cmd_queue) > 0:
            truc = self.handle_read()
            if truc[:7] != "message":
             self.cmd_queue.pop(0)
           del self.rep_queue[:]
           del self.msg_queue[:]
           del self.cmd_queue[:]
           self.buffer = ""
           if tmp["message"] == "incant":
            self.isIncant = True
            return self.receive()
           if tmp["message"] == "help":
            self.goTo(tmp["sound"], None)
            return self.receive()
          else:
           return self.receive()

         else:
          self.cmd_queue.pop(0)
          return rep




        def level_up(self, msg):
          print (self.id, msg)
          self.isIncant = False

          msg = msg.replace(" ", "")
          self.lvl = int(msg.split(":")[1]) - 1
          levels[self.lvl] += 1
          levels[self.lvl - 1] -= 1
          if self.lvl == 7:
           print ("LEVEL 8")
           self.handle_close()
          while self.buffer != "":
           self.handle_read()
          self.buffer = ""
          self.myLeader = self.getNewLeader()
          return self.iaCallback((self.lvl + 1) * 10)


        def getNewLeader(self):
         i = self.id
         while i % int(evol[self.lvl]["player"]) != 0:
          i += 1
         return i

        
        def checkValid(self, cmd, rep):
         cmd = cmd.split("\n")[0];
         cmd = cmd.split(" ")[0]

         if cmd == "voir":
          vue = rep.replace("{ ", "").replace("}", "").split(",")
          i = 0
          j = len(vue)
          while i < j:
           vue[i] = self.creatObject(vue[i])
           i += 1
          if len(vue) < 3:
           return False
          else:
           return True

         if cmd == "inventaire":
          tab = re.findall(r'\d+', rep)
          try:
           self.inv["nourriture"] = tab[0]
           self.inv["linemate"] = tab[1]
           self.inv["deraumere"] = tab[2]
           self.inv["sibur"] = tab[3]
           self.inv["mendiane"] = tab[4]
           self.inv["phiras"] = tab[5]
           self.inv["thystame"] = tab[6]
           return True
          except:
           return False

         if rep == "ok" and (cmd == "avance" or cmd == "droite" or cmd == "gauche" or cmd == "prend" or cmd == "pose" or cmd == "expulse" or cmd == "broadcast" or cmd == "fork"):
          return True
         if rep == "ko" and (cmd == "prend" or cmd == "pose" or cmd == "expulse" or cmd == "incantation"):
          return True
         if rep == "elevation en cours" and cmd == "incantation":
          return True
         if rep.isdigit() == True and cmd == "connect_nbr":
          return True

         return False





        def connection(self, msg):
         global maxPlayers
         if len(self.rep_list) % 3 == 0:
          answer = self.rep_list[1].split("\n")
          self.id = nbClis
          if len(self.rep_list) > 2:
           map = self.rep_list[2].split(" ")
           self.mapX = int(map[0])
           self.mapY = int(map[1])
          self.myLeader = self.id
          self.rep_ptr = "handle response"
          print ("HERE COMES A NEW CHALLENGER, ID =", self.id)
          IA(self, self.mapX, self.mapY)





        def avance(self, cb):
         rep = self.handle_send("avance\n", None)
         if (len(self.rep_queue) > 0):
          rep = self.rep_queue.pop(0)
         return rep


        def droite(self, cb):
         rep = self.handle_send("droite\n", None)
         if (len(self.rep_queue) > 0):
          rep = self.rep_queue.pop(0)
         return rep


        def gauche(self, cb, *params):
         rep = self.handle_send("gauche\n", None)
         if (len(self.rep_queue) > 0):
          rep = self.rep_queue.pop(0)
         return rep


        def expulse(self, cb, *params):
         rep = self.handle_send("expulse\n", None)
         if (len(self.rep_queue) > 0):
          rep = self.rep_queue.pop(0)
         return rep


        def broadcast(self, msg, cb):
         rep = self.handle_send("broadcast " + str(params[0]) + "/" + str(self.id) + ";" + msg + "\n", None)
         if (len(self.rep_queue) > 0):
          rep = self.rep_queue.pop(0)
          return rep


        def fork(self, cb, *params):
         rep = self.handle_send("fork\n", None)
         if (len(self.rep_queue) > 0):
          rep = self.rep_queue.pop(0)
         return rep


        def connect_nbr(self, cb):
         rep = self.handle_send("connect_nbr\n", None)
         if (len(self.rep_queue) > 0):
          rep = self.rep_queue.pop(0)
         if int(rep) > 0:
          global levels
          self.newTh = False
          child_pid = os.fork()
          if child_pid == 0:
           Client(params)
          global nbClis
          nbClis += 1
          global cliId
          cliId += + 1

         return rep


        def prend(self, obj, cb, *params):
         rep = self.handle_send("prend " + str(obj) + "\n", None)
         if (len(self.rep_queue) > 0):
          rep = self.rep_queue.pop(0)
         if rep == "ok":
          self.inv[obj] = int(self.inv[obj]) + 1
         return rep


        def pose(self, obj, cb, *params):
         rep = self.handle_send("pose " + str(obj) + "\n", None)
         if (len(self.rep_queue) > 0):
          rep = self.rep_queue.pop(0)
         if rep == "ok":
          self.inv[obj] = int(self.inv[obj]) - 1
         return rep


        def inventaire(self, cb, *params):
         rep = self.handle_send("inventaire\n", None)
         if (len(self.rep_queue) > 0):
          rep = self.rep_queue.pop(0)
         tab = re.findall(r'\d+', rep)
         if len(tab) > 0:
          self.inv["nourriture"] = tab[0]
          self.inv["linemate"] = tab[1]
          self.inv["deraumere"] = tab[2]
          self.inv["sibur"] = tab[3]
          self.inv["mendiane"] = tab[4]
          self.inv["phiras"] = tab[5]
          self.inv["thystame"] = tab[6]
         return self.inv



        def voir(self, cb, *params):
         rep = self.handle_send("voir\n", None)
         if (len(self.rep_queue) > 0):
          rep = self.rep_queue.pop(0)
         vue = rep.replace("{ ", "").replace("}", "").split(",")
         i = 0
         j = len(vue)
         while i < j:
          vue[i] = self.creatObject(vue[i])
          i += 1
         self.vision = vue
         return vue


        def incantation(self, cb, *params):
         print (self.id, "INCANTATION")
         rep = self.handle_send("incantation\n", None)
         if (len(self.rep_queue) > 0):
          rep = self.rep_queue.pop(0)
         if rep != "elevation en cours":
          self.isIncant = False
         else:
          self.receive()
         return rep


        def getResponse(self, cmd):
         i = 0
         while (self.cmd_queue[i]["msg"] != cmd):
          i += 1
         return i


        def numberOf(self, cmd, to_find):
         ret = 0
         try:
          while True:
           begin = cmd[:cmd.index(to_find)];
           end = cmd[cmd.index(to_find) + len(to_find):];
           cmd = begin + end;
           ret += 1;
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


        def move(self, case, cb):

         if case == 0:
          return "ok"

         if case == 1:
          return self.avance(None)

         if case == 2:
          self.avance(None)
          self.gauche(None)
          return self.avance(None)

         if case == 8:
          self.avance(None)
          self.droite(None)
          return self.avance(None)



        def goTo(self, sound, cb):

         if (sound == 0):
          return

         if (sound == 1 or sound == 2 or sound == 8):
          tmp = "avance\n"
          self.sock.send(tmp.encode())
          msg = ""
          while msg != "ok":
           if len(self.buffer) == 0:
            rep = self.sock.recv(16384).decode()
            self.buffer += rep;
           try:
            msg = self.buffer[0:self.buffer.index("\n")]
            self.buffer = self.buffer[self.buffer.index("\n") + 1:]
           except ValueError:
            pass
         
         elif (sound == 3 or sound == 4 or sound == 5):
          tmp = "gauche\n"
          self.sock.send(tmp.encode())
          msg = ""
          while msg != "ok":
           if len(self.buffer) == 0:
            rep = self.sock.recv(16384).decode()
            self.buffer += rep;
           try:
            msg = self.buffer[0:self.buffer.index("\n")]
            self.buffer = self.buffer[self.buffer.index("\n") + 1:]
           except ValueError:
            pass

         else:
          tmp = "droite\n"
          self.sock.send(tmp.encode())
          msg = ""
          while msg != "ok":
           if len(self.buffer) == 0:
            rep = self.sock.recv(16384).decode()
            self.buffer += rep;
           try:
            msg = self.buffer[0:self.buffer.index("\n")]
            self.buffer = self.buffer[self.buffer.index("\n") + 1:]
           except ValueError:
            pass





def signal_handler(signum, frame):
         os._exit(0)

signal.signal(signal.SIGINT, signal_handler)


t = Client(params)
