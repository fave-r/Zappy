#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
from commands import *
import ia
import client
from survive import *

def elevation(cli):
 print ("elevation")
 
 if client.pblevels[cli.lvl] != ia.evol[cli.lvl]["player"]:
  print ("Pas assez de joueurs de mon niveau pour évoluer, je retourne manger.")
  return survivor(cli, int(ia.inv["nourriture"]) + 10, ia.inv)

 v = voir(cli)

 if (canIncant(cli, v[0]) == False):
  print ("Je ne peux pas évoluer")
  return survivor(cli, int(ia.inv["nourriture"]) + 10, ia.inv)

 print ("Je peux évoluer")
 incantation(cli)


def canIncant(cli, case):
 print (case)
 for elem in case:
  if (elem[0] != "player" and elem[0] != "nourriture" and count_ressource(cli, elem[0]) + int(ia.inv[elem[0]]) < ia.evol[cli.lvl][elem[0]]):
   return (False)
 return (True)
