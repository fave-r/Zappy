#!/usr/bin/python3.3
# -*-coding:Utf-8 -*

import sys
import socket
from survive import *

inv = [
        ("nourriture", 0),
        ("linemate", 0),
        ("deraumere", 0),
        ("sibur", 0),
        ("mendiane", 0),
        ("phiras", 0),
        ("thystame", 0),
      ]

def begin_ia(socket):
 inventaire(socket, inv)
 if (int(inv[0][1]) <= 10):
  survivor(socket, int(inv[0][1] + 20), inv)
