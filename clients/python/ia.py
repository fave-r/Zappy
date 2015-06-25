#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket
import time
import client


evol = [
        {"player":1, "linemate":2, "deraumere":0, "sibur":0, "mendiane":0, "phiras":0, "thystame":0},
        {"player":2, "linemate":1, "deraumere":1, "sibur":1, "mendiane":0, "phiras":0, "thystame":0},
        {"player":2, "linemate":2, "deraumere":0, "sibur":1, "mendiane":0, "phiras":2, "thystame":0},
        {"player":4, "linemate":1, "deraumere":1, "sibur":2, "mendiane":0, "phiras":1, "thystame":0},
        {"player":4, "linemate":1, "deraumere":2, "sibur":1, "mendiane":3, "phiras":0, "thystame":0},
        {"player":6, "linemate":1, "deraumere":2, "sibur":3, "mendiane":0, "phiras":1, "thystame":0},
        {"player":6, "linemate":2, "deraumere":2, "sibur":2, "mendiane":2, "phiras":2, "thystame":1},
       ]



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
         self.cli.fork(self.begin_ia, (self.cli.lvl + 1) * 10)



        def survivor(self, *params):
         if len(params) > 0:
          self.foodNeeded = params[0]

         if int(self.cli.inv["nourriture"]) > int(self.foodNeeded):
          print ("Mode survie terminée")
          return self.begin_ia("ok")

         print ("Mode survie commencée")

         i = 0
         j = len(self.cli.vision)

         while i < j:
          if self.cli.vision[i]["nourriture"] > 0:
           if i != 0 and self.cli.vision[2]["nourriture"] > 0:
            self.cli.move(2)
           else:
            self.cli.move(i)
           return self.cli.prend("nourriture", self.survivor_part_2)
          i += 1

         self.direction += 1
         if self.direction % 4 == 0:
          self.cli.gauche(None)
         self.cli.avance(None)
         return self.cli.voir(self.survivor)

        def survivor_part_2(self, rep):
           print ("part 2")
           if rep == "ko\n":
            self.cli.avance(None)
            return self.cli.voir(self.survivor)
           else:
            self.cli.inventaire(None)
            return self.cli.voir(self.survivor)





        def evolve(self, rep):
         case = self.cli.vision[0]
         if (evol[self.cli.lvl]["player"] > client.levels[self.cli.lvl]):
          return self.survivor(int(self.cli.inv["nourriture"]) + 10)

         if self.canIncant(case) == False:
          return self.searchCase()

         for item in case:
          if (item != "player"):
           if case[item] > evol[self.cli.lvl][item]:
            return self.cli.prend(item, self.callbackStone)

           if case[item] < evol[self.cli.lvl][item]:
            return self.cli.pose(item, self.callbackStone)

         return self.cli.voir(self.regroupTeam)


        def canIncant(self):
         case = self.cli.vision[0]

         for item in case:
          if item != "player" and item != "nourriture" and case[item] + self.cli.inv[item] < evol[self.cli.lvl][item]:
           return False
         return True


        def regroupTeam(self, case):
         if case["player"] == evol[self.cli.lvl]["player"]:
          return self.cli.broadcast(str(self.cli.lvl) + ":ok", self.launchIncant())
         elif case["player"] > evol[self.cli.lvl]["player"]:
          return self.cli.avance(self.begin_ia, (self.cli.lvl + 1) * 10)
         else:
          return self.cli.broadcast(str(self.cli.lvl) + ":help", self.regroupTeam2)

        def regroupTeam2(self, rep):
         self.cli.isIncant = True
         return self.cli.voir(self.regroupTeam)


        def callbackStone(self, rep):
         self.cli.voir(self.evolve)


        def searchCase(self):
         i = 0
         


        def launchIncant(self, rep):
         self.cli.incantation(self.launchIncant2)
        def launchIncant2(self, rep):
         if rep == "ko\n":
          self.cli.broadcast(str(self.cli.lvl) + ":ko", self.launchIncant3)
        def launchIncant3(self, rep):
         self.cli.avance(self.begin_ia, (self.cli.lvl + 1) * 10)





        def begin_ia(self, rep, *params):
         print ("begin_ia")
         if len(params) > 0:
          self.foodNeeded = params[0][0]
         self.cli.inventaire(None)
         self.cli.voir(self.eat_or_evolve)

        def eat_or_evolve(self, rep):
         print ("eat or evolve")

         if (int(self.cli.inv["nourriture"]) < int(self.foodNeeded)):
          self.survivor()
         else:
          self.evolve(None)


         self.cli.fork(self.begin_ia, (self.cli.lvl + 1) * 10)
