#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket
from survive import *
from elevation import *

evol = [
        {"player":1, "linemate":1, "deraumere":0, "sibur":0, "mendiane":0, "phiras":0, "thystame":0},
        {"player":2, "linemate":1, "deraumere":1, "sibur":1, "mendiane":0, "phiras":0, "thystame":0},
        {"player":2, "linemate":2, "deraumere":0, "sibur":1, "mendiane":0, "phiras":2, "thystame":0},
        {"player":4, "linemate":1, "deraumere":1, "sibur":2, "mendiane":0, "phiras":1, "thystame":0},
        {"player":4, "linemate":1, "deraumere":2, "sibur":1, "mendiane":3, "phiras":0, "thystame":0},
        {"player":6, "linemate":1, "deraumere":2, "sibur":3, "mendiane":0, "phiras":1, "thystame":0},
        {"player":6, "linemate":2, "deraumere":2, "sibur":2, "mendiane":2, "phiras":2, "thystame":1},
       ]


inv = { "nourriture":0, "linemate":0, "deraumere":0, "sibur":0, "mendiane":0, "phiras":0, "thystame":0 }

def begin_ia(client):
 inventaire(client, inv)
 if (int(inv["nourriture"]) < 10):
  survivor(client, int(inv["nourriture"]) + 20, inv)
 else:
  elevation(client)
