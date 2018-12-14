
import socket
import os

ip = '10.67.142.2'

class LEDController:

    TCP_IP = ip
    TCP_PORT = 1337
    BUFFER_SIZE = 1024
    
    def __init__(self):
        self.TCP_IP = ip
        self.TCP_PORT = 1337
        self.BUFFER_SIZE = 1024

        print('connecting to ESP Module at ip: ' + self.TCP_IP)
        try:
            self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.s.connect((self.TCP_IP, self.TCP_PORT))
            print('connected')
        except TimeoutError:
            print('Unable to connect. Try "reset()"')
            
    def on(self):
        self.s.send(b'H')
        
    def off(self):
        self.s.send(b'L')
        
    def reset(self):
        # s.connnect((TCP_IP, TCP_PORT))
        print('resetting connection...')

        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.s.connect((self.TCP_IP, self.TCP_PORT))
        print('connection reset.');

L = LEDController()

def on():
    try:
        L.on()
    except OSError:
        print('Connection lost. Try "reset()"')


def off():
    try:
        L.off()
    except OSError:
        print('Connection lost. Try "reset()"')

def reset():
    try:
        L.reset()
    except TimeoutError:
        print('Timeout error. Unable to connect to ESP.')

response = ''
clear = lambda: os.system('cls')

while response.upper() not in ['Q', 'QUIT']:
    clear()
    print("commands: 'on', 'off', 'reset', 'q' to quit.")
    response = input()
    if response.upper() == 'ON':
        on()
    elif response.upper() == 'OFF':
        off()
    elif response.upper() == 'RESET':
        reset()















