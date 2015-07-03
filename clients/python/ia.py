#!/usr/bin/env python
# __author__ = 'denche_t'

import sys
import signal
import socket
from socket import error as socket_error
import os
import errno
from optparse import OptionParser
from random import *
import copy
import time
import ctypes

BUFFER_SIZE = 4096

class Utilitaires:
    def __init__(self):
        self._stnb = 6
        self._sttab = {}
        self._elevtab = {}
        self._leadtab = []
        self.MFLL = 35
        self.MFFL = 35
        self.initsttab()
        self.initelevtab()
        self.initleadtab()

    def initleadtab(self):
        self._leadtab = [[0 for x in range(8)] for x in range(8)]
        self._leadtab[1] = [0, 1, 2, 3, 4, 5, 6, 7]
        self._leadtab[2] = [0, 0, 2, 2, 4, 4, 6, 6]
        self._leadtab[3] = [0, 0, 2, 2, 4, 4, 6, 6]
        self._leadtab[4] = [0, 0, 0, 0, 4, 4, 4, 4]
        self._leadtab[5] = [0, 0, 0, 0, 4, 4, 4, 4]
        self._leadtab[6] = [0, 0, 0, 0, 0, 0, -1, -1]
        self._leadtab[7] = [0, 0, 0, 0, 0, 0, -1, -1]

    def initelevtab(self):
        level = 1
        x = Case(1, 0, 1, 0, 0, 0, 0, 0)
        self._elevtab[1] = copy.copy(x)
        x = Case(2, 0, 1, 1, 1, 0, 0, 0)
        self._elevtab[2] = copy.copy(x)
        x = Case(2, 0, 2, 0, 1, 0, 2, 0)
        self._elevtab[3] = copy.copy(x)
        x = Case(4, 0, 1, 1, 2, 0, 1, 0)
        self._elevtab[4] = copy.copy(x)
        x = Case(4, 0, 1, 2, 1, 3, 0, 0)
        self._elevtab[5] = copy.copy(x)
        x = Case(6, 0, 1, 2, 3, 0, 1, 0)
        self._elevtab[6] = copy.copy(x)
        x = Case(6, 0, 2, 2, 2, 2, 2, 1)
        self._elevtab[7] = copy.copy(x)

    def initsttab(self):
        self._sttab[0] = "linemate"
        self._sttab[1] = "deraumere"
        self._sttab[2] = "sibur"
        self._sttab[3] = "mendiane"
        self._sttab[4] = "phiras"
        self._sttab[5] = "thystame"

class Stones:
    def __init__(self, li, de, si, me, ph, th):
        self._dic = {}
        self.setstones(li, de, si, me, ph, th)

    def printstones(self):
        print ("\t** Stones **")
        print(self._dic)
    
    def setstones(self, li, de, si, me, ph, th):
        self._dic["linemate"] = li
        self._dic["deraumere"] = de
        self._dic["sibur"] = si
        self._dic["mendiane"] = me
        self._dic["phiras"] = ph
        self._dic["thystame"] = th            

class Inventory:
    def __init__(self, fo, li, de, si, me, ph, th):
        self._fo = fo
        self._stones = Stones(li, de, si, me, ph, th)

    def setinventaire(self, fo, li, de, si, me, ph, th):
        self._fo = fo
        self._stones.setstones(li, de, si, me, ph, th)

    def printinventaire(self):
        print ("\t** Inventaire **")
        print ("Nourriture\t\t" + str(self._fo))
        self._stones.printstones()
       
    def tostring(self):
        i = 0
        ret = ""
        while i < self._ut._stnb:
            ret = ret + str(self._stones._dic[self._ut._sttab[i]]) + " "
        return ret

class Case:
    def __init__(self, players, fo, li, de, si, me, ph, th):
        self._players = players
        self._inv = Inventory(fo, li, de, si, me, ph, th)

    def printcase(self):
        print ("\t** Case **")
        print ("Players\t\t" + str(self._players))
        self.printinventaire()

class User:
    def __init__(self, port, host, team):
        self._team = team
        self._port = port
        self._host = host
        self._num = 42
        self._posx = 0
        self._posy = 0
        self._level = 1
        self._socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.tryconnect(host, port)
        self._socket.setblocking(False)
        self._broadcast = []
        self._leadlist = []
        self._buffer = ""
        self._inv = Inventory(0, 1, 1, 1, 3, 0, 0)
        self._ut = Utilitaires()
        self._lead = -1
        self._print = True

    def tryconnect(self, host, port):
        try:
            self._socket.connect((host, port))
        except socket_error as serr:
            if serr.errno != errno.ECONNREFUSED:
                raise serr
            print "Impossible de se connecter au serveur"
            sys.exit(0)

    def delete(self):
        self.printf("A bientot")
        if self._num <= 0:
            self._socket.close()
        if self._num == 0:
            string = self._team + ".conf"
            os.remove(string)

    def printuser(self):
        print("** User **")
        print("User = " + str(self._num))
        print("Team = " + self._team)
        print("Pos = " + str(self._posx) + " " + str(self._posy))
        print("Level = " + str(self._level))

    def setnum(self, num):
        self._num = int(num)

    def setx(self, x):
        self._posx = x

    def sety(self, y):
        self._posy = y

    def isanint(self, string):
        try:
            int(string)
            return True
        except ValueError:
            return False

    def setinventaire(self, inventaire):
        inventaire = inventaire.replace(',', ' ')
        inventaire = inventaire.replace('{', '')
        inventaire = inventaire.replace('}', '')
        tab = inventaire.split()
        i = 0
        while i < len(tab):
            j = 0
            while j < self._ut._stnb:
                if tab[i] == self._ut._sttab[j] and i + 1 < len(tab):
                    self._inv._stones._dic[self._ut._sttab[j]] = int(tab[i + 1])
                j = j + 1
            if tab[i] == "nourriture" and i + 1 < len(tab):
                tmp = self.isanint(tab[i + 1])
                if tmp == True:
                    self._inv._fo = int(tab[i + 1])
            i = i + 1

    def stonesneeded(self):
        i = 0
        ret = ""
        while (i < self._ut._stnb):
            ret = ret + str((self._ut._elevtab[self._level])._inv._stones._dic[self._ut._sttab[i]] - self._inv._stones._dic[self._ut._sttab[i]]) + " "
            i = i + 1
        return ret

    def matchstring(self, s1, s2):
        t1 = s1.split()
        t2 = s2.split()
        ret = ""
        i = 0
        while i < len(t1):
            if (int(t1[i]) > int(t2[i])):
                ret = ret + str(t2[i]) + " "
            else:
                ret = ret + str(t1[i]) + " "                
            i = i + 1
        return ret

    def substring(self, s1, s2):
        t1 = s1.split()
        t2 = s2.split()
        ret = ""
        i = 0
        tmp = 0
        while i < len(t1):
            tmp = int(t1[i]) - int(t2[i])
            ret = ret + tmp + " "
            i = i + 1
        return ret

    def putallnoneeded(self):
        needed = self.stonesneeded()
        inv = self._inv.tostring()
        diff = self.substring(inv, needed)
        self.putstones(diff)

    def trytakeallneeded(self):
        self.printf("Try Take All Needed")
        needed = self.stonesneeded()
        onthefloor = self.voir0()
        diff = self.matchstring(needed, onthefloor)
        self.trytakeall(diff)

    def trytakeall(self, string):
        tab = string.split()
        i = 0
        while i < len(tab):
            x = int(tab[i])
            while x > 0:
                result = self.prend(self._ut._sttab[i])
                if result == "ko\n":
                    break
                x = x - 1
            i = i + 1
        
    def putstones(self, string):
        tab = string.split()
        i = 0
        while i < len(tab):
            x = int(tab[i])
            while x > 0:
                result = self.pose(self._ut._sttab[i])
                if result == "ko\n":
                    break
                x = x - 1
            i = i + 1

    def inventaire(self):
        MESSAGE = "inventaire\n"
        self._socket.send(MESSAGE)
        data = self.get_answer()
        tmp = self.check_error(self.check_inv, data)
        while tmp == False:
            data = self.get_answer()
            tmp = self.check_error(self.check_inv, data)
        self.setinventaire(data)
        return data

    def firstneeded(self):
        i = 0
        needed = self.stonesneeded()
        tokens = needed.split()
        while i < len(tokens):
            if int(tokens[i]) > 0:
                self.printf("first needed " + self._ut._sttab[i])
                return self._ut._sttab[i]
            i = i + 1
        return ""

    def substring(self, s1, s2):
        t1 = s1.split()
        t2 = s2.split()
        ret = ""
        i = 0
        while i < len(t1):
            ret = ret + str(int(t1[i]) - int(t2[i])) + " "
            i = i + 1
        return ret

    def convertonb(self, string):
        i = 0
        cpt = 0
        ret = ""
        parse = string.split()
        while i < self._ut._stnb:
            j = 0
            while j < len(parse):
                if parse[j] == self._ut._sttab[i]:
                    cpt = cpt + 1
                j = j + 1
            ret = ret + str(cpt) + ' '
            cpt = 0
            i = i + 1
        return ret

    def voir0(self):
        string = self.voir()
        tab = string.split(',')
        ret = self.convertonb(tab[0])
        return ret

    def find_food(self, nb):
        self.printf("Find Food : " + str(self._inv._fo) + " -> " + str(nb))
        call = self.callofduty()
        if call == True and self._inv._fo > self._ut.MFFL - 2:
            self.printf("Call of Duty pendant qu'on cherche de la food")
            return
        dest = self.search(self.find,"nourriture")
        self.goto(dest)
        i = self.count("nourriture")
        while i > 0:
            self.prend("nourriture")
            i = i - 1
        food = int(self._inv._fo)
        self.inventaire()
        if food < nb:
            self.find_food(nb)
        return

    def printf(self, string):
        if self._print == False:
            return
        i = self._num
        s = str(self._num) + " : " + str(self._level) + " :\t" + string
        print s
        return

    def fork(self):
        MESSAGE = "fork" + '\n'
        self._socket.sendall(MESSAGE)
        return self.get_answer()

    def init_lead(self):
        self.printf("INIT LEAD")
        self._lead = self._ut._leadtab[self._level][self._num]
        self._leadlist = []
        if self._lead == self._num:
            if self._level % 2 != 0:
                leng = self._level - 2
            else:
                leng = self._level - 1
            if leng != -1:
                self._leadlist = [False] * (leng)

    def lead_broadcast(self):
        self.printf("Lead Broadcast")
        nb = self.count_joueurs()
        nb_max = self._ut._elevtab[self._level]._players
        while nb < nb_max:
            self.inventaire()
            if self._inv._fo < 5:
                self.say("EXIT")
                self.trytakeallneeded()
                return
            self.say("VIENS")
            self.listen()
            nb = self.count_joueurs()

        if nb > nb_max:
            self.trytakeallneeded()
            self.say("EXIT")
            return
        self.tryupgrade()

    def loop(self):
        while (self._level < 9):
            self.init_lead()
            if self._lead == self._num:
                self.lead_loop()
            else:
                self.follow_loop()
        data = self.get_answer()
        print data

    def isrdy(self):
        i = 0
        while i < len(self._leadlist):
            if self._leadlist[i] == False:
                return False
            i = i + 1
        return True

    def is_a_mate(self, num):
        if num > self._num and num <= self._num + len(self._leadlist):
            return True
        return False

    def gere_broadcast(self):
        i = 0
        j = 0
        while i < len(self._broadcast):
            data = self._broadcast[i]
            data = data.replace('\n', '')
            level = int(((((data.split(','))[1]).split())[1]))
            tmp = (data.split(','))[1].split()[0]
            num = int(data.split(',')[2])
            if level == self._level:
                if self.is_a_mate(num) == True:
                    x = num - self._num
                    if x > 0:
                        x = x - 1
                    self._leadlist[x] = True
            del self._broadcast[0]
        return None

    def lead_loop(self):
        while "Buddha Swag" == "Buddha Swag":
            self.inventaire()
            self.listen()
            self.gere_broadcast()
            target = self.firstneeded()
            if self._inv._fo < self._ut.MFLL:
                self.find_food(self._ut.MFLL + 5)
            elif target != None and target != "":
                dest = self.search(self.find, target)
                if dest != -1:
                    self.goto(dest)
                    self.trytakeallneeded()
                    dest = -1
            elif self.isrdy() == True and self._inv._fo >= self._ut.MFLL:
                self.printf("PRET A UPGRADE")
                dest = self.search(self.findempty, target)
                if dest != -1:
                    self.goto(dest)
                self.clearfloor()
                self.putstones(self.upgradestones())
                self.lead_broadcast()
                return

    def follow_loop(self):
        while "Buddha Swag" == "Buddha Swag":
            self.inventaire()
            if self.callofduty() == True and self._inv._fo > self._ut.MFFL - 2:
                self.printf("ON FOLLOW LE BROADCAST")
                self.follow_broadcast()
                return
            elif self._inv._fo < self._ut.MFFL:
                self.find_food(self._ut.MFFL + 5)
            else:
                self.roam()
                self.say("READY")

    def callofduty(self):
        self.listen()
        i = 0
        j = 0
        data = self.findbroadcast_spe_last_targ(["VIENS", "EXIT"])
        if data != None:
            data = data.replace('\n', '')
            level = int(((((data.split(','))[1]).split())[1]))
            tmp = (data.split(','))[1].split()[0]
            num = int(data.split(',')[2])
            if level == self._level and num == self._lead and tmp == "VIENS":
                self._broadcast = []
                self._broadcast.append(data)
                return True
        return False

    def follow_broadcast(self):
        tmp = True
        self.printf("Follow broadcast")
        tmp = self.travelto_broadcast()
        if tmp:
            tmp = self.bepatient()

    def travelto_broadcast(self):
        dest = 42
        tab = ["VIENS", "EXIT"]
        data = self.findbroadcast_spe_last_targ(tab)
        while dest != 0:
            if data != None:
                tab = (((data.split(','))[1]).split())[0]
                dest = int((((data.split(','))[0].split()[1])))
                if tab == "VIENS":
                    self.printf("On nous a dit VIENS")
                    """
                    self._broadcast = []
                    """
                    self.printf("GoToBroadcast : " + str(dest))
                    tmp = self.goto_broadcast(dest)
                    if tmp == False:
                        return True
                elif tab == "EXIT":
                    return False
            self.inventaire()
            self.listen()
            dest = 42
            data = self.findbroadcast_spe_last_targ(["VIENS", "EXIT"])
            if self._inv._fo < 6:
                return False
        return True

    def bepatient(self):
        self.printf("Be Patient")
        self.listen()
        tab = ["SUCESS", "EXIT"]
        data = self.findbroadcast_spe_last_targ(tab)
        while 42:
            self.inventaire()
            if self._inv._fo < 5:
                return False
            if data != None:
                tmp = (((data.split(','))[1]).split())[0]
                if tmp == "EXIT":
                    self._broadcast = []
                    if self._level < 4:
                        self.roam()
                    return False
                elif tmp == "SUCESS":
                    self._level = self._level + 1
                    return True
            self.listen()
            data = self.findbroadcast_spe_last_targ(tab)
        return False

    def goto_broadcast(self, dest):
        self.printf("goto broadcast" + str(dest))
        i = 2
        if dest == 0:
            self.printf("On est arrive")
            return False
        if dest >= 7:
            self.droite()
            self.avance()
            if dest == 8:
                self.gauche()
                self.avance()
        else:
            while dest > i:
                self.gauche()
                i = i + 2
            self.avance()
            if dest == i:
                self.gauche()
                self.avance()
        tab = ["EXIT"]
        tmp = self.findbroadcast_spe_targ(tab, self._lead)
        self._broadcast = []
        if tmp != None:
            self._broadcast.append(tmp)
        return

    def upgradestones(self):
        i = 0
        ret = ""
        while (i < self._ut._stnb):
            ret = ret + str((self._ut._elevtab[self._level])._inv._stones._dic[self._ut._sttab[i]]) + " "
            i = i + 1
        self.printf("UPGRADESTONES : " + ret)
        return ret

    def clearfloor(self):
        self.printf("Clear Floor")
        onthefloor = self.voir0()
        self.trytakeall(onthefloor)
        onthefloor = self.voir0()

    def find(self, string):
        data = self.voir()
        data = data.replace('{', '')
        data = data.replace('}', '')
        data = data.replace('\n', '')
        tab = data.split(',')
        del tab[-1]
        i = 0
        x = 0
        tmp = 0
        while tmp < len(tab):
            ret = self.check_find(tab, string, tmp)
            if ret != -1:
                return ret
            tmp2 = tmp - 1
            while tmp2 >= tmp - x + 1:
                ret = self.check_find(tab, string, tmp2)
                if ret != -1:
                    return ret
                tmp2 = tmp2 - 1
            tmp2 = tmp + 1
            while tmp2 <= tmp + x - 1:
                ret = self.check_find(tab, string, tmp2)
                if ret != -1:
                    return ret
                tmp2 = tmp2 + 1
            x = x + 1
            tmp = tmp + (2 * x)        
        return -1

    def check_find(self, tab, string, tmp):
        tab2 = tab[tmp].split()
        j = 0
        while (j < len(tab2) and (tab2[0] != "joueur" or j == 0)):
            if (tab2[j] == string):
                return tmp
            j = j + 1
        return -1

    def findempty(self, string):
        self.printf("Find Empty Place")
        data = self.voir()
        data = data.replace('{', '')
        data = data.replace('}', '')
        data = data.replace('\n', '')
        tab = data.split(',')
        i = 0
        while (i < len(tab)):
            if tab[i] == '':
                return i
            tab2 = tab[i].split()
            j = 0
            var = True
            while (j < len(tab2) and (tab2[0] != "joueur" and tab2[0] != "oeuf") and var == True):
                if (tab2[j] != "" and tab2[j] != "nourriture"):
                    var = False
                j = j + 1
            if var == True and tab2[0] != "joueur":
                return i
            i = i + 1        
        return -1

    def goto(self, i):
        k = 0
        last = 1
        while (k < i):
            last = last + 2
            k  = k + last
            self.avance()
        pos = 0
        pos = k - (last / 2)
        if (i < pos):
            self.gauche()
        elif (i > pos):
            self.droite()
            i = pos - (i - pos)
        while (i < pos):
            self.avance()
            pos = pos - 1

    def search(self, func, string):
        pos = -1
        i = 1
        pos = func(string)
        while (i < 4 and pos == -1):
            self.droite()
            i = i + 1
            pos = func(string)
        if pos == -1:
            self.roam()
        return pos

    def roam(self):
        self.printf("Roaming")
        rand = [0, 1, 2, 3]
        i = 0
        x = choice(rand)
        while (i < x):
            self.droite()
            i += 1
        i = 0
        while (i < (self._level + 1) * 2):
            self.avance()
            i = i + 1

    def sendall(self, data):
        while data:
            sent = sock.send(data)
            data = data[sent:]

    def check_error(self, func, string):
        ret = func(string)
        if ret == False:
            tmp = string.split()
            if tmp[0] == "niveau" or tmp[0] == "expulse":
                return False
            else:
                self.printf("J'ai grave fail : " + string)
                self.printerror()
                return False
        return True
            

    def check_okko(self, string):
        if string == "ok\n" or string == "ko\n":
            return True
        i = 0
        return False

    def printerror(self):
        i = 0
        while i < 5:
            self.printf("Si tu vois ce message c'est que ton serveur a fait planter mon IA. Si si je t'assure...")
            i = i + 1

    def avance(self):
        MESSAGE = "avance\n"
        self._socket.sendall(MESSAGE)
        data = self.get_answer()
        check = self.check_error(self.check_okko, data)
        while check == False:
            data = self.get_answer()            
            check = self.check_error(self.check_okko, data)
        return data

    def check_voir(self, data):
        if data[0] != "{":
            return False
        data = data.replace("{", "")
        data = data.replace("}", "")
        data = data.replace("\n", "")
        tmp = data.split()
        i = 0
        while i < len(tmp):
            if self.isanint(tmp[i]) == True:
                return False
            i = i + 1
        return True
        
    def check_inv(self, data):
        if data[0] != "{":
            return False
        data = data.replace("{", "")
        data = data.replace("}", "")
        data = data.replace("\n", "")
        tmp2 = data.split(',')
        j = 0
        while j < len(tmp2): 
            i = 1
            tmp = tmp2[j].split()
            while i < len(tmp):
                if self.isanint(tmp[i]) != True:
                    return False
                i = i + 2
            j = j + 1
        return True
        
    def voir(self):
        MESSAGE = "voir\n"
        self._socket.sendall(MESSAGE)
        data = self.get_answer()
        check = self.check_error(self.check_voir, data)
        while check == False:
            data = self.get_answer()
            check = self.check_error(self.check_voir, data)
        return data

    def droite(self):
        MESSAGE = "droite\n"
        self._socket.sendall(MESSAGE)
        data = self.get_answer()
        check = self.check_error(self.check_okko, data)
        while check == False:
            data = self.get_answer()
            check = self.check_error(self.check_okko, data)
        return data

    def gauche(self):
        MESSAGE = "gauche\n"
        self._socket.sendall(MESSAGE)
        data = self.get_answer()
        check = self.check_error(self.check_okko, data)
        while check == False:
            data = self.get_answer()
            check = self.check_error(self.check_okko, data)
        return data
 
    def prend(self, string):
        MESSAGE = "prend " + string + '\n'
        self._socket.sendall(MESSAGE)        
        data = self.get_answer()
        check = self.check_error(self.check_okko, data)
        while check == False:
            data = self.get_answer()
            check = self.check_error(self.check_okko, data)
        if data == "ko\n":
            self.droite()
        return data

    def pose(self, string):
        self.printf("Pose " + string)
        MESSAGE = "pose " + string + '\n'
        self._socket.sendall(MESSAGE)
        self.printf(MESSAGE)
        data = self.get_answer()
        check = self.check_error(self.check_okko, data)
        while check == False:
            data = self.get_answer()
            check = self.check_error(self.check_okko, data)
        return data

    def broadcast(self, string):
        MESSAGE = "broadcast " + string + '\n'
        self._socket.sendall(MESSAGE)
        data = self.get_answer()
        check = self.check_error(self.check_okko, data)
        while check == False:
            data = self.get_answer()
            check = self.check_error(self.check_okko, data)
        return data

    def connect_nbr(self):
        MESSAGE = "connect_nbr" + '\n'
        self._socket.sendall(MESSAGE)        
        ret = self.get_answer()
        self.printf("GET ANSWER = " + ret)
        check = self.check_error(self.isanint, ret)
        self.printf("coonect_nbr = " + ret )
        if check != True:
            self.printf("CONNECT_NBR")
            self.printerror()
            ret = self.get_answer()
        return ret

    def bisgood(self, data):
        tab = data.split(',')
        if len(tab) != 4 or len(tab[0].split()) != 2 or len(tab[1].split()) != 2 or len(tab[2].split()) != 1 or len(tab[3].split()) != 1:
            return False
        message = tab[1].split()[0]
        level = tab[1].split()[1]
        num = tab[2]
        team = tab[3]
        if self.isanint(level) == False or self.isanint(num) == False:
            return False
        if team == self._team:
            return True
        return False

    def listen(self):
        ret = ""
        i = 0
        error = False
        try:
            data = self._socket.recv(BUFFER_SIZE)
        except socket.error:
            data = self._buffer
            self._buffer = ""
        if self._buffer != "":
            data = self._buffer + data
            self._buffer = ""
        if data == "":
            return ""
        tokens = data.split('\n')
        if tokens != []:
            if tokens[-1] == "":
                del tokens[-1]
            else:
                error = True
        tmp = (tokens[i].split())[0]
        while (i < len(tokens) and tokens[i] != "") and  ((tokens[i].split())[0] == "message" or (tokens[i].split())[0] == "broadcast"):
            if i == (len(tokens) - 1) and error == True:
                break
            if self.bisgood(tokens[i]) == True:
                self._broadcast.append(tokens[i])
            if (len(self._broadcast) > 300):
                if self._lead == self._num:
                    self.gere_broadcast()
                else:
                    break
                    del self._broadcast[0]
            i = i + 1
        if i < len(tokens) and not (error == True and i + 1 == len(tokens)):
            ret = tokens[i]
            i = i + 1
        while (i < len(tokens)):
            if (tokens[i] != ""):
                if i == (len(tokens) - 1) and error == True:
                    self._buffer = self._buffer + tokens[i]
                else:
                    self._buffer = self._buffer + tokens[i] + '\n'
            i = i + 1
        if ret == "mort":
            if self._level == 7:
                self.printf("GG WP !!")
            self.delete()
            sys.exit(0)
        if ret != "":
            ret = ret + '\n'
        return ret

    def prend_max(self, string):
        data = ""
        i = 0
        while (data != "ko\n"):
            data = self.prend(string)
            i = i + 1
        return i

    def findbroadcast(self):
        i = 0
        while i < len(self._broadcast):
            data = ((((self._broadcast[i]).split(','))[1].split()))
            if int(data[1]) == self._level:
                tmp = self._broadcast[0]
                del self._broadcast[0]
                return tmp
            del self._broadcast[0]
        return None

    def findbroadcast_spe(self, tab):
        i = 0
        j = 0
        while i < len(self._broadcast):
            data = self._broadcast[i]
            data.replace('\n', '')
            level = int(((((data.split(','))[1]).split())[1]))
            tmp = (data.split(','))[1].split()[0]
            if level == self._level:
                while j < len(tab):
                    if tab[j] == tmp:
                        tmp = self._broadcast[0]
                        del self._broadcast[0]
                        return tmp
                    j = j + 1
                j = 0
            del self._broadcast[0]
        return None

    def findbroadcast_spe_targ(self, tab, interlocutor):
        i = 0
        j = 0
        while i < len(self._broadcast):
            data = self._broadcast[i]
            data = data.replace('\n', '')
            level = int(((((data.split(','))[1]).split())[1]))
            tmp = (data.split(','))[1].split()[0]
            num = int(data.split(',')[2])
            if level == self._level:
                while j < len(tab):
                    if tab[j] == tmp:
                        if num == self._lead:
                            tmp = self._broadcast[0]
                            del self._broadcast[0]
                            return tmp
                    j = j + 1
                j = 0
            del self._broadcast[0]
        return None

    def findbroadcast_spe_last(self, tab):
        data = "42"
        while data != None:
            last = data
            data = self.findbroadcast_spe(tab)
        if last == "42":
            return None
        return last

    def findbroadcast_spe_last_targ(self, tab):
        data = "42"
        while data != None:
            last = data
            data = self.findbroadcast_spe_targ(tab, self._lead)
        if last == "42":
            return None
        return last

    def say(self, data):
        string = data + " " + str(self._level) + "," + str(self._num) + "," + self._team
        self.printf("Say = " + string)
        self.broadcast(string)

    def setupgrade(self, data):
        nb = int((data.split())[-1])
        if nb > self._level:
            self._level = nb

    def answerupgrade(self):
        self.printf("Answer Upgrade")
        data = self.listen();
        while 42:
            if data != None and data != "":
                tmp = (data.split())[0]
                if data == "ko\n":
                    self.trytakeallneeded()
                    self.say("EXIT")
                    return False
                if tmp == "niveau":
                    nb = int((data.split())[-1])
                    if nb > self._level:
                        self.say("SUCESS")
                        self._level = self._level + 1
                        return True
                    else:
                        self.trytakeallneeded()
                        self.say("EXIT")
                        return False
            data = self.listen();

    def tryupgrade(self):
        self.printf("Try Upgrade")
        self.say("VIENS")
        if self._inv._fo < 5:
            self.trytakeallneeded()
            self.say("EXIT")
            return
        message = "incantation\n"
        self._socket.send(message)
        data = self.get_answer()
        if data == "ko\n":
            self.printf("ON A RECU KOOOOO")
        while 42:
            if data != None and data != "":
                if data == "ko\n":
                    self.trytakeallneeded()
                    self.say("EXIT")
                    return
                elif data == "elevation en cours\n":
                    self.answerupgrade()
                    return
            data = self.listen();

    def count(self, target):
        data = self.voir()
        data = data.replace('{', '')
        data = data.replace('}', '')
        data = data.replace('\n', '')
        tab = data.split(',')
        case = (tab[0]).split()
        i = 0;
        cpt = 0
        while i < len(case):
            if case[i] == target:
                cpt = cpt + 1
            i = i + 1
        return cpt        

    def count_joueurs(self):
        data = self.voir()
        data = data.replace('{', '')
        data = data.replace('}', '')
        data = data.replace('\n', '')
        tab = data.split(',')
        case = (tab[0]).split()
        i = 0;
        cpt = 0
        while i < len(case):
            if case[i] == 'joueur':
                cpt = cpt + 1
            i = i + 1
        return cpt

    def elevation_test(self):
        self.listen()
        self.listen()
        if (self.callofduty()) == True:
            self.follow_broadcast()
        else:
            self.lead_broadcast()

    def find_mate(self):
        i = 0
        while i < len(self._broadcast):
            i = i + 1

    def get_answer(self):
        data = ""
        while (data == "" or data == "\n"):
            data = champion.listen()
        return data

    def connect(self):
        string = "python ia.py " + "-n " + self._team + " -H " + self._host + " -p " + str(self._port)
        nbr = int(self.connect_nbr())
        if nbr > 0 and self._num < 7:
            newpid = os.fork()
            if newpid == 0:
                os.system(string)
                sys.exit(0)
            return True
        return False

    def loop_fork(self):
        self.fork()
        self.printf("Je viens de pondre un oeuf : j'ai mal...")
        self.avance()
        while (42):
            if self._inv._fo < self._ut.MFFL:
                while self._inv._fo < self._ut.MFFL + 10:
                    dest = self.search(self.find,"nourriture")
                    if dest != -1:
                        self.goto(dest)
                        j = self.count("nourriture")
                        while j > 0:
                            self.prend("nourriture")
                            j = j - 1
                    self.inventaire()
                    tmp = self.connect()
                    if tmp == True:
                        return
            else:
                tmp = self.connect()
                if tmp == True:
                    self.printf("On a INVOCATIONNNNNNNNNNNNNNN BREAK")
                    return
            self.inventaire()

    def find_food_spe(self, nb):
        self.printf("Find Food Spe")
        dest = self.search(self.find,"nourriture")
        self.goto(dest)
        i = self.count("nourriture")
        while i > 0:
            self.prend("nourriture")
            i = i - 1
        food = int(self._inv._fo)
        self.inventaire()
        tmp = self.connect()
        
        if food < nb:
            self.find_food(nb)
        return

    def invoque(self):
        if self._num < 7:
            tmp = self.connect()
            if tmp == False:
                self.loop_fork()

    def test_file(self, string):
        try:
            f = open(string, "a")
            f.close
        except:
            f.close


    def loop_open(self, string, option):
        i = 0
        while 42:
            try:
                data = open(string, option)
                return data
            except:
                print "On tourne en round putain !!"

    def gere_num(self, NAME):
        string = self._team + ".conf"
        self.test_file(string)
        with self.loop_open(string, "r+") as f:
            data = f.read()
            f.seek(0, 0)
            f.truncate()
            if data == "":
                f.write("0")
                self._num = 0
            else:
                num = int(data)
                num = num + 1
                self._num = num
                f.truncate()
                f.write(str(num))
            f.close()
parser = OptionParser()
parser.add_option("-n", "--name", dest="name", default=None, action="store", type="str")
parser.add_option("-p", "--port", dest="port", default = None, action="store", type="int")
parser.add_option("-H", "--hostname", dest="hostname", default = None, action="store", type="str")
(options, args) = parser.parse_args()

if options.port is None:
    print "An option is missing. try -h for help"
    sys.exit(0)
if options.name is None:
    print "An option is missing. try -h for help"
    sys.exit(0)
if options.hostname is None:
    TCP_IP = '127.0.0.1'
else:
    TCP_IP = options.hostname
TCP_PORT = options.port
NAME = options.name


champion = User(TCP_PORT, TCP_IP, NAME)

data = champion.get_answer()
champion._socket.send(NAME + '\n')
data = champion.get_answer()

def signal_handler(signal, frame):
        champion.delete()
        sys.exit(0)
signal.signal(signal.SIGINT, signal_handler)

if data != "ko\n":
    champion.gere_num(NAME)
    data = champion.get_answer()
    champion.setx(int(data.split()[0]))
    champion.sety(int(data.split()[1]))
    champion.invoque()
    champion.loop()
else:
    print "EXIT"
champion.delete()
