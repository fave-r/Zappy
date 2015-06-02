#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
from commands import *
import ia

def survivor(socket, foodNeeded, inv):
 if inv[0][1] > foodNeeded:
  print ("Mode survie terminée")
  ia.begin_ia(socket)
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
    return survivor(socket, foodNeeded, inv)
   else:
    inventaire(socket, inv)
    print (inv)
    return survivor(socket, foodNeeded, inv)
  i += 1

 avance(socket)
 return survivor(socket, foodNeeded, inv)
