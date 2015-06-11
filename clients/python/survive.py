import sys
import ia
from commands import *

direction = 0

def survivor(sock, cast, id, foodNeeded, inv):
 if int(inv["nourriture"]) > foodNeeded:
  print ("Mode survie terminée")
  ia.begin_ia(sock, id)
  return

 print ("Mode survie commencée")

 v = voir(sock, cast)

 i = 0
 j = len(v)

 while i < j:
  if v[i][1][1] > 0:
   if i != 0 and v[2][1][1] > 0:
    move(2, sock, cast)
   else:
    move(i, sock, cast)
   rep = prend(sock, cast, "nourriture")
   if rep == "ko\n":
    avance(sock, cast)
    return survivor(sock, cast, id, foodNeeded, inv)
   else:
    inventaire(sock, cast, inv)
    return survivor(sock, cast, id, foodNeeded, inv)
  i += 1

 global direction
 direction += 1
 if direction % 4 == 0:
  gauche(sock, cast)
 avance(sock, cast)
 return survivor(sock, cast, id, foodNeeded, inv)
