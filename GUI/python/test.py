

import matplotlib
matplotlib.use('TkAgg')

from numpy import arange, sin, pi
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg, NavigationToolbar2TkAgg
# implement the default mpl key bindings
from matplotlib.backend_bases import key_press_handler


from matplotlib.figure import Figure

import sys
if sys.version_info[0] < 3:
    import Tkinter as Tk
else:
    import tkinter as Tk

root = Tk.Tk()
root.wm_title("Purificateur d'eau")


f = Figure(figsize=(5, 4), dpi=100)
a = f.add_subplot(111)
t = arange(0.0, 3.0, 0.01)
s = sin(2*pi*t)

a.plot(t, s)


# a tk.DrawingArea
canvas = FigureCanvasTkAgg(f, master=root)
canvas.show()
canvas.get_tk_widget().pack(side=Tk.TOP, fill=Tk.BOTH, expand=1)

#toolbar = NavigationToolbar2TkAgg(canvas, root)
#toolbar.update()
canvas._tkcanvas.pack(side=Tk.BOTTOM, fill=Tk.BOTH, expand=1)


def _quit():
    root.quit()     # stops mainloop
    root.destroy()  # this is necessary on Windows to prevent
                    # Fatal Python Error: PyEval_RestoreThread: NULL tstate

FrameL = Tk.Frame(root, borderwidth=2, relief=Tk.GROOVE)
FrameL.pack(side=Tk.LEFT, padx=30, pady=5)

FrameR = Tk.Frame(root, borderwidth=2, relief=Tk.GROOVE)
FrameR.pack(side=Tk.RIGHT, padx=30, pady=5)

button1 = Tk.Button(master=FrameR, text='Quitter', command=_quit)
button1.pack(side=Tk.RIGHT)

button2 = Tk.Button(master=FrameR, text='Parametre', command=_quit)
button2.pack(side=Tk.RIGHT)

button3 = Tk.Button(master=FrameR, text='Actualiser', command=_quit)
button3.pack(side=Tk.RIGHT)

button4 = Tk.Button(master=FrameR, text='Analyser', command=_quit)
button4.pack(side=Tk.RIGHT)

button5 = Tk.Button(master=FrameL, text='Connexion', command=_quit)
button5.pack(side=Tk.RIGHT)

ip = Tk.StringVar()
ip.set("IP")
ip = Tk.Entry(FrameL, textvariable=ip, width=30)
ip.pack(side=Tk.LEFT)

port = Tk.StringVar()
port.set("port")
port = Tk.Entry(FrameL, textvariable=port, width=15)
port.pack(side=Tk.LEFT)


Tk.mainloop()
# If you put root.destroy() here, it will cause an error if
# the window is closed with the window manager.
