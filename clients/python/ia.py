#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket
import time


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



        def survivor(self, *param):
         if int(self.cli.inv["nourriture"]) > self.foodNeeded:
          print ("Mode survie terminée")
          return self.begin_ia(self.foodNeeded)

         print ("Mode survie commencée")
         print (self.foodNeeded)
         print (self.cli.inv)
         print (self.cli.vision)

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




        def begin_ia(self, rep, foodNeeded):
         print ("begin_ia")
         self.foodNeeded = foodNeeded
         self.cli.inventaire(None)
         self.cli.voir(self.eat_or_evolve)

        def eat_or_evolve(self, rep):
         print ("eat or evolve")

         if (int(self.cli.inv["nourriture"]) < int(self.foodNeeded)):
          self.survivor()
         else:
          print ("sup")


         self.cli.fork(self.begin_ia, (self.cli.lvl + 1) * 10)
