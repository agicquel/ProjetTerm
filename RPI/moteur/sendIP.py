#!/usr/bin/env python

from subprocess import *
from time import sleep, strftime
from datetime import datetime
import serial

ser = serial.Serial('/dev/ttyACM0', 9600)
cmd = "ip addr show eth0 | grep inet | awk '{print $2}' | cut -d/ -f1 | sed -n 1p"

def run_cmd(cmd):
    p = Popen(cmd, shell=True, stdout=PIPE)
    output = p.communicate()[0]
    return output

while 1:
    ipaddr = run_cmd(cmd)
    ser.write(str(ipaddr))
    sleep(10)
