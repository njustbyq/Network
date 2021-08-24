#!/usr/bin/python 
from scapy.all import *

packet = Ether(src = 'dc:99:14:01:a3:5e', dst = 'ff:ff:ff:ff:ff:ff') / Dot1Q(vlan = 1) / \
         IP() / TCP()

hexdump(packet)