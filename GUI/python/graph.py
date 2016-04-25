# Python 3 + tkinter + matplotlib

import matplotlib
matplotlib.use('TkAgg')

from numpy import arange, sin, pi
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2TkAgg
# implement the default mpl key bindings
from matplotlib.backend_bases import key_press_handler
from matplotlib.figure import Figure
import sys
import socket
import linecache
import tkinter as Tk
from tkinter.ttk import *
from tkinter import messagebox


class Reseau:

    def __init__(self):
        self.port = 42
        self.ip = "localhost"
        self.buffer_size = 256
        self.socket_client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def connect(self):
        try:
            print("IP = ", self.ip, " port = ", self.port)
            connextion = self.socket_client.connect((self.ip, self.port))
        except:
            Tk.messagebox.showerror("Connexion", "Impossible de se connecter !", icon='warning')

    def disconnect(self):
        self.close()

    def close(self):
        self.socket_client.close()

    def sendString(self, string):
        self.socket_client.send(bytes(string, 'UTF-8'))

    def receiveString(self):
        recu = self.socket_client.recv(self.buffer_size)
        string = recu.decode('utf-8')
        return string

    def sendFile(self, file_to_send):
        size = sum(1 for line in open(file_to_send))
        i = 1
        print("La taille: ", size)
        print("On envoie sendFile")
        self.sendString("sendFile")
        recu = self.receiveString()
        if recu == "size ?":
            print("OK, on envoie la taille")
            self.sendString(str(size))
        else:
            print("Erreur, pas reçu demande de taille")
            print("On a recu:", recu)
        recu = self.receiveString()
        if recu == "OK sendFile":
            while i < (size+1):
                print("Envoie de la ligne no: ", i)
                data = linecache.getline(file_to_send, i).rstrip('\n')
                print("On lit:", data)
                self.sendString(data)
                print("On attend le OK")
                recu = self.receiveString()
                if recu != "OK":
                    print("Erreur lors de la reception du fichier")
                    break
                i += 1
                linecache.clearcache()
        else:
            print("Erreur, pas recu OK sendFile")
            print("On a recu:", recu)
        print("Le fichier a fini de s'envoyer")

    def receiveFile(self, file_to_receive):
        fichier = open(file_to_receive, "a")
        print("Le ficher est ouvert")
        recu = self.receiveString()
        if recu == "sendFile":
            print("On envoie size ?")
            self.sendString("size ?")
        else:
            print("Don't receive the signal for sendFile")
        recu = self.receiveString()
        size = int(recu)
        print("La taille: ", size)
        self.sendString("OK sendFile")
        i = 0

        while i < size:
            print("On recoit no: ", i)
            recu = self.receiveString()
            print("On a recu :", recu)
            print("On écrit dans le fichier")
            fichier.write(recu)
            print("On envoie OK")
            self.sendString("OK")
            i += 1
        fichier.close()
        print("On a recu le fichier")

class Application:
    def __init__(self):
        self.root = Tk.Tk()
        self.root.wm_title("Purificateur d'eau")
        self.root.style = Tk.ttk.Style()
        self.root.style.theme_use("clam")

        self.client = Reseau()

        self.f = Figure(figsize=(5, 4), dpi=100)
        self.a = self.f.add_subplot(111)
        self.t = arange(0.0, 3.0, 0.01)
        self.s = sin(2*pi*self.t)

        self.a.plot(self.t, self.s)

        # a tk.DrawingArea
        self.canvas = FigureCanvasTkAgg(self.f, master=self.root)
        self.canvas.show()
        self.canvas.get_tk_widget().pack(side=Tk.TOP, fill=Tk.BOTH, expand=1)

        #toolbar = NavigationToolbar2TkAgg(canvas, root)
        #toolbar.update()
        self.canvas._tkcanvas.pack(side=Tk.BOTTOM, fill=Tk.BOTH, expand=1)

        self.FrameL = Tk.ttk.Frame(self.root, relief=Tk.GROOVE)
        self.FrameL.pack(side=Tk.LEFT, padx=30, pady=5)

        self.FrameR = Tk.ttk.Frame(self.root, relief=Tk.GROOVE)
        self.FrameR.pack(side=Tk.RIGHT, padx=30, pady=5)

        self.button1 = Tk.ttk.Button(master=self.FrameR, text='Quitter', command=self.quitter)
        self.button1.pack(side=Tk.RIGHT)

        self.button2 = Tk.ttk.Button(master=self.FrameR, text='Parametre')
        self.button2.pack(side=Tk.RIGHT)

        self.button3 = Tk.ttk.Button(master=self.FrameR, text='Analyser', command=self.analyse)
        self.button3.pack(side=Tk.RIGHT)

        self.button4 = Tk.ttk.Button(master=self.FrameL, text='Résultats', command=self.resultat)
        self.button4.pack(side=Tk.RIGHT)

        self.ip = Tk.StringVar()
        self.ip.set("IP")
        self.ip = Tk.Entry(self.FrameL, textvariable=self.ip, width=30)
        self.ip.pack(side=Tk.LEFT)

        self.port = Tk.StringVar()
        self.port.set("port")
        self.port = Tk.Entry(self.FrameL, textvariable=self.port, width=15)
        self.port.pack(side=Tk.LEFT)

        Tk.mainloop()

    def quitter(self):
        self.root.quit()     # stops mainloop
        self.root.destroy()  # this is necessary on Windows to prevent errors

    def resultat(self):
        try:
            self.client.ip = self.ip.get()
            self.client.port = int(self.port.get())
            self.client.connect()
            self.client.sendString("nitrite\n")
            self.client.receiveFile("nitrite.txt")
            self.client.receiveFile("nitrite.date.txt")
            self.client.disconnect()
            # LES AFFICHER DANS LE GRAPHIQUE http://matplotlib.org/users/pyplot_tutorial.html
        except :
            Tk.messagebox.showerror("Connexion", "IP ou port impossible !", icon='warning')

    def analyse(self):
        confirmation = Tk.messagebox.askyesno("Analyse", "Lançer une analyse ?", icon='warning')
        if confirmation == 'yes':
            try:
                self.client.ip = self.ip.get()
                self.client.port = int(self.port.get())
                self.client.connect()
                print("On lance l'analyse")
                self.client.sendString("analyse\n")
                self.client.disconnect()
            except :
                Tk.messagebox.showerror("Connexion", "IP ou port impossible !", icon='warning')
        else:
            print("On ne lance PAS l'analyse")


projet = Application()
