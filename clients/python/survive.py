#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
from commands import *
import ia

direction = 0

def survivor(client, foodNeeded, inv):
 if int(inv["nourriture"]) > foodNeeded:
  print ("Mode survie terminée")
  ia.begin_ia(client)
  return

 print ("Mode survie commencée")

 v = voir(client)

 i = 0
 j = len(v)

 while i < j:
  if v[i][1][1] > 0:
   if i != 0 and v[2][1][1] > 0:
    move(2, client)
   else:
    move(i, client)
   rep = prend(client, "nourriture")
   if rep == "ko\n":
    avance(client)
    return survivor(client, foodNeeded, inv)
   else:
    inventaire(client, inv)
    return survivor(client, foodNeeded, inv)
  i += 1

 global direction
 direction += 1
 if direction % 4 == 0:
  gauche(client)
 avance(client)
 return survivor(client, foodNeeded, inv)
