#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
from commands import *

def survivor(socket, foodNeeded, inv):
 if inv[0][1] > foodNeeded:
  print ("Mode survie terminée")
  return

 print ("Mode survie commencée")

 v = voir(socket)

 i = 0
 j = len(v)
 print (v[i][1][1])
 while i < j:
  if v[i][1][1] > 0:
   if i != 0 and v[2][1][1] > 0:
    move(2, socket)
   else:
    move(i, socket)
   rep = prend(socket, "nourriture")
   if rep == "ko\n":
    avance(socket)
    survivor(socker, foodNeeded, inv)
   else:
    inventaire(socket, inv)
    print (inv)
    survivor(socket, foodNeeded, inv)
  i += 1

 avance(socket)
 survivor(socket, foodNeeded, inv)
