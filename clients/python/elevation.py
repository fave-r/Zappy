import sys
import ia
from commands import *
from survive import *

def elevation(sock, cast, id, lvl):
 print ("elevation")
 
 if ia.pblevels[lvl] < ia.evol[lvl]["player"]:
  print ("Pas assez de joueurs de mon niveau pour évoluer, je retourne manger.")
  return survivor(sock, cast, id, int(ia.inv["nourriture"]) + 10, ia.inv)

 v = voir(sock, cast)

 if (canIncant(sock, cast, v[0], lvl) == False):
  print ("Je ne peux pas évoluer")
  return survivor(sock, cast, id, int(ia.inv["nourriture"]) + 10, ia.inv)

 print ("Je peux évoluer")
 print (ia.inv)
 drop_ressource(sock, cast, lvl)
 incantation(sock, cast)

 print (ia.inv)


def canIncant(sock, cast, case, lvl):
 print (case)
 for elem in case:
  if (elem[0] != "player" and elem[0] != "nourriture"):
   take_ressource(sock, cast, elem[0], ia.evol[lvl][elem[0]] - int(ia.inv[elem[0]]))
   if (int(ia.inv[elem[0]]) < ia.evol[lvl][elem[0]]):
    return (False)
 return (True)
