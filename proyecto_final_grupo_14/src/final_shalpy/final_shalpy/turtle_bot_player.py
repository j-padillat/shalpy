from player_interfaces.srv import PlayerHardware
from geometry_msgs.msg import Twist
from proyecto_interfaces.srv import StartPerceptionTest
from proyecto_interfaces.srv import StartManipulationTest
from example_interfaces.srv import Juanpaser
import rclpy
from rclpy.node import Node
import time
import serial
import numpy as np
from pySerialTransfer import pySerialTransfer as txfer
import os

### Turtle Bot Player Node
# This node receives the request of custom type Player that includes the name of the circuit to play and an Array of the Twist messages to publish.

moveTeleopBindings = {
    'w': (1, 0, 0, 0),  # Hacia adelante en x
    'a': (0, 0, 0, 1),  # Gira sobre su eje sentido antihorario
    'd': (0, 0, 0, -1), # Gira sobre su eje sentido horario
    's': (-1, 0, 0, 0), # Hacia atras en x
}

moveManipulatorBindings = {
    'y': (1,0),   # Sentido horario servo 0
    'h': (-1,0),  # Sentido antihorario servo 0
    'u': (1,1),   # Sentido horario servo 1
    'j': (-1,1),  # Sentido antihorario servo 1
    'i': (1,2),   # Sentido horario servo 2
    'k': (-1,2),  # Sentido antihorario servo 2
    'o': (1,3),   # Sentido horario servo 3
    'l': (-1,3),  # Sentido antihorario servo 3
}

link = txfer.SerialTransfer('/dev/ttyACM0')     # Uno/Mega
#link = txfer.SerialTransfer('/dev/ttyUSB0')    # Nano
link.open() 
time.sleep(2) # allow some time for the Arduino to completely reset


class structForTransmition(object):
    tecla = '_'
    th0_vel = 0.0
    th1 = 0.0
    th2 = 0.0

punto = 'punto1'


class servicioPlayer(Node):
    def __init__(self):
        super().__init__('turtle_bot_player')
        self.srv = self.create_service(PlayerHardware, 'turtle_bot_player_srv', self.player_callback)   # Creates service
        self.pub = self.create_publisher(Twist, '/turtlebot_cmdVel', 10)    # Creates publisher
        print('---- Player Service succesfully initialized ----')
        self.srv1 = self.create_service(StartPerceptionTest, '/group_14/start_perception_test_srv', self.servicio_master_callback_perception)
        self.srv2 = self.create_service(StartManipulationTest, '/group_14/start_manipulation_test_srv', self.servicio_master_callback_manipulation)
        self.cli = self.create_client(Juanpaser, 'imagen_percepcion')
    
    def player_callback(self, request, response):
        
        for i in range(len(request.posiciones)-1):

            if (request.keys[i] in moveTeleopBindings.keys()):
            
                print("Tecla: "+ str(request.keys[i]))
                print("Lineal: "+ str(abs(request.posiciones[i].linear.x)))
                print("Angular: "+ str(abs(request.posiciones[i].angular.z)))

                punto = "punto5" # corresponde al motor() del arduino
                print(request.keys[i], request.posiciones[i].linear.x, request.posiciones[i].angular.z)
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = request.keys[i]
                testStruct.th0_vel = request.posiciones[i].linear.x
                testStruct.th1 = request.posiciones[i].angular.z
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                print("lol1")
                print(sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                print("lol2")
                print(sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                print("lol3")
                print(sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                print("lol4")
                print(sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                print("lol5")
                print(sendSize)
                link.send(sendSize)

                self.pub.publish(request.posiciones[i])
                print(request.posiciones[i])
                print("---")
                time.sleep(request.times[i])

                key="v"
                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = key
                testStruct.th0_vel = 0
                testStruct.th1 = 0
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)
                print("------")



            elif (request.keys[i] in moveManipulatorBindings.keys()):

                print("Tecla: "+ str(request.keys[i]))
                print("Lineal: "+ str(abs(request.posiciones[i].linear.x)))
                print("Angular: "+ str(abs(request.posiciones[i].angular.z)))

                punto = "punto1"
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = request.keys[i]
                testStruct.th0_vel = request.posiciones[i].linear.x
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)

                self.pub.publish(request.posiciones[i])
                print(request.posiciones[i])
                print("---")
                time.sleep(request.times[i])


                key="v"
                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = key
                testStruct.th0_vel = 0
                testStruct.th1 = 0
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)
        
            time.sleep(2)


    def servicio_master_callback_manipulation(self, request, response):

        print("VA callback servicio master")
        if request.platform == "platform_1" :
            
            home_dir = os.path.expanduser("~")
            file3 = os.path.join(home_dir, "platform_1.txt")

            recorridoCargado = np.loadtxt(file3, delimiter=',', dtype=np.str)
            print("Cargo el archivo 1")
            print(recorridoCargado)
            linealx = recorridoCargado[1].astype(np.float)
            linealy = recorridoCargado[2].astype(np.float)
            anguloth = recorridoCargado[3].astype(np.float)
            tiempillos = recorridoCargado[4].astype(np.float)
            print(linealx)
            keysVector=[]
            timesVector=[]

            print(len(linealx))
            for i in range(len(linealx)):
                keysVector.append(recorridoCargado[0][i])
                timesVector.append(tiempillos[i])

        elif request.platform == "platform_2" :
            home_dir = os.path.expanduser("~")
            file3 = os.path.join(home_dir, "platform_2.txt")
            recorridoCargado = np.loadtxt(file3, delimiter=',', dtype=np.str)
            print("Cargo el archivo 2")
            linealx = recorridoCargado[1].astype(np.float)
            linealy = recorridoCargado[2].astype(np.float)
            anguloth = recorridoCargado[3].astype(np.float)
            tiempillos = recorridoCargado[4].astype(np.float)
            print(linealx)
            keysVector=[]
            timesVector=[]

            print(len(linealx))
            for i in range(len(linealx)):
                keysVector.append(recorridoCargado[0][i])
                timesVector.append(tiempillos[i])

        for i in range(len(keysVector)-1):
            print("entro vez: {}".format(i))

            if (keysVector[i] in moveTeleopBindings.keys()):
            
                print("Tecla: "+ str(keysVector[i]))
                print("Lineal: "+ str(abs(linealx[i])))
                print("Angular: "+ str(abs(anguloth[i])))

                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                #print(keysVector, linealx, anguloth, )
                sendSize = 0
                testStruct.tecla = keysVector[i]
                testStruct.th0_vel = linealx[i]
                testStruct.th1 = anguloth[i]
                testStruct.th2 = linealy[i]
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)    # #sto está retornando un None ???
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                print("Antes de eviar")
                link.send(sendSize)

                time.sleep(timesVector[i])

                key="v"
                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = key
                testStruct.th0_vel = 0
                testStruct.th1 = 0
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)
            
            elif (keysVector[i] in moveManipulatorBindings.keys()):

                print("Tecla: "+ str(keysVector[i]))
                print("Velocidad: "+ str(abs(linealx[i])))

                punto = "punto1"
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = keysVector[i]
                testStruct.th0_vel = linealx[i]
                testStruct.th1 = anguloth[i]
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)

                time.sleep(timesVector[i])

                key="v"
                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = key
                testStruct.th0_vel = 0
                testStruct.th1 = 0
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)
        
            time.sleep(2)


        # self.a = request.banner_a
        # self.b = request.banner_b
        self.a = request.platform
        self.b = request.x


    ### JUANPAAA
        # self.peticion = Juanpaser.Request()
        # self.peticion.banner = self.a
        # self.peticion.empieza = "llamoJuanpaser"
        # self.future = self.cli.call_async(self.request)
        # rclpy.spin_until_future_complete(self, self.future)
        # self.termino1 = self.future.result()
        # print(self.termino1.termina)

        # # Moverse

        # file3 = './bannerb.txt'
        # recorridoCargado = np.loadtxt(file3, delimiter=',', dtype=np.str)
        # print(recorridoCargado)
        # print(recorridoCargado[1].astype(np.float))
        # linealx = recorridoCargado[1].astype(np.float)
        # linealy = recorridoCargado[2].astype(np.float)
        # anguloth = recorridoCargado[3].astype(np.float)
        # tiempillos = recorridoCargado[4].astype(np.float)
        # print(linealx)
        # keysVector=[]
        # timesVector=[]

        # print(len(linealx))
        # for i in range(len(linealx)):
        #     keysVector.append(recorridoCargado[0][i])
        #     timesVector.append(tiempillos[i])

        # for i in range(len(keysVector)-1):

        #     if (keysVector[i] in moveTeleopBindings.keys()):
            
        #         print("Tecla: "+ str(keysVector[i]))
        #         print("Lineal: "+ str(abs(linealx[i])))
        #         print("Angular: "+ str(abs(anguloth[i])))

        #         punto = "punto5" # corresponde al motor() del arduino
        #         testStruct = structForTransmition
        #         sendSize = 0
        #         testStruct.tecla = keysVector[i]
        #         testStruct.th0_vel = linealx[i]
        #         testStruct.th1 = anguloth[i]
        #         sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
        #         sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
        #         sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
        #         sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
        #         sendSize = link.tx_obj(punto, start_pos=sendSize)
        #         link.send(sendSize)

        #         time.sleep(timesVector[i])

        #         key="v"
        #         punto = "punto5" # corresponde al motor() del arduino
        #         testStruct = structForTransmition
        #         sendSize = 0
        #         testStruct.tecla = key
        #         testStruct.th0_vel = 0
        #         testStruct.th1 = 0
        #         sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
        #         sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
        #         sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
        #         sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
        #         sendSize = link.tx_obj(punto, start_pos=sendSize)
        #         link.send(sendSize)
        
        #     time.sleep(2)


        # self.peticion = Juanpaser.Request()
        # self.peticion.banner = self.b
        # self.peticion.empieza = "llamoJuanpaser"
        # self.future = self.cli.call_async(self.request)
        # rclpy.spin_until_future_complete(self, self.future)
        # self.termino2 = self.future.result()
        # print(self.termino2.termina)
        ### JUANPAAA

        response.answer = "La ficha de tipo {} se encuentra en la plataforma {} la llevaré a la otra plataforma".format(self.b, self.a)
        return response.answer
    
    def servicio_master_callback_perception(self, request, response):

        print("VA callback servicio master")
        if request.banner_a == 1 :
            
            home_dir = os.path.expanduser("~")
            file3 = os.path.join(home_dir, "bannera_1.txt")

            recorridoCargado = np.loadtxt(file3, delimiter=',', dtype=np.str)
            print("Cargo el archivo bannera_1")
            linealx = recorridoCargado[1].astype(np.float)
            linealy = recorridoCargado[2].astype(np.float)
            anguloth = recorridoCargado[3].astype(np.float)
            tiempillos = recorridoCargado[4].astype(np.float)
            print(linealx)
            keysVector=[]
            timesVector=[]

            print(len(linealx))
            for i in range(len(linealx)):
                keysVector.append(recorridoCargado[0][i])
                timesVector.append(tiempillos[i])

        if request.banner_a == 2 :
            home_dir = os.path.expanduser("~")
            file3 = os.path.join(home_dir, "bannera_2.txt")
            recorridoCargado = np.loadtxt(file3, delimiter=',', dtype=np.str)
            print("Cargo el archivo bannera_2")
            linealx = recorridoCargado[1].astype(np.float)
            linealy = recorridoCargado[2].astype(np.float)
            anguloth = recorridoCargado[3].astype(np.float)
            tiempillos = recorridoCargado[4].astype(np.float)
            print(linealx)
            keysVector=[]
            timesVector=[]

            print(len(linealx))
            for i in range(len(linealx)):
                keysVector.append(recorridoCargado[0][i])
                timesVector.append(tiempillos[i])
        
        if request.banner_a == 3 :
            home_dir = os.path.expanduser("~")
            file3 = os.path.join(home_dir, "bannera_3.txt")
            recorridoCargado = np.loadtxt(file3, delimiter=',', dtype=np.str)
            print("Cargo el archivo 3 bannera_3")
            linealx = recorridoCargado[1].astype(np.float)
            linealy = recorridoCargado[2].astype(np.float)
            anguloth = recorridoCargado[3].astype(np.float)
            tiempillos = recorridoCargado[4].astype(np.float)
            print(linealx)
            keysVector=[]
            timesVector=[]

            print(len(linealx))
            for i in range(len(linealx)):
                keysVector.append(recorridoCargado[0][i])
                timesVector.append(tiempillos[i])

        for i in range(len(keysVector)-1):

            if (keysVector[i] in moveTeleopBindings.keys()):
            
                print("Tecla: "+ str(keysVector[i]))
                print("Lineal: "+ str(abs(linealx[i])))
                print("Angular: "+ str(abs(anguloth[i])))

                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = keysVector[i]
                testStruct.th0_vel = linealx[i]
                testStruct.th1 = anguloth[i]
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)

                time.sleep(timesVector[i])

                key="v"
                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = key
                testStruct.th0_vel = 0
                testStruct.th1 = 0
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)
            
            elif (keysVector[i] in moveManipulatorBindings.keys()):

                print("Tecla: "+ str(keysVector[i]))
                print("Velocidad: "+ str(abs(linealx[i])))

                punto = "punto1"
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = keysVector[i]
                testStruct.th0_vel = linealx[i]
                testStruct.th1 = anguloth[i]
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)

                time.sleep(timesVector[i])

                key="v"
                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = key
                testStruct.th0_vel = 0
                testStruct.th1 = 0
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)
        
            time.sleep(2)


        self.a = request.banner_a
        self.b = request.banner_b


        self.peticion = Juanpaser.Request()
        self.peticion.banner = self.a
        self.peticion.empieza = "llamoJuanpaser"
        self.future = self.cli.call_async(self.request)
        rclpy.spin_until_future_complete(self, self.future)
        self.termino1 = self.future.result()
        print(self.termino1.termina)

        # Moverse
        if request.banner_b == 1 :
            
            home_dir = os.path.expanduser("~")
            file3 = os.path.join(home_dir, "bannerb_1.txt")

            recorridoCargado = np.loadtxt(file3, delimiter=',', dtype=np.str)
            print("Cargo el archivo bannerb_1")
            linealx = recorridoCargado[1].astype(np.float)
            linealy = recorridoCargado[2].astype(np.float)
            anguloth = recorridoCargado[3].astype(np.float)
            tiempillos = recorridoCargado[4].astype(np.float)
            print(linealx)
            keysVector=[]
            timesVector=[]

            print(len(linealx))
            for i in range(len(linealx)):
                keysVector.append(recorridoCargado[0][i])
                timesVector.append(tiempillos[i])

        if request.banner_b == 2 :
            home_dir = os.path.expanduser("~")
            file3 = os.path.join(home_dir, "bannerb_2.txt")
            recorridoCargado = np.loadtxt(file3, delimiter=',', dtype=np.str)
            print("Cargo el archivo bannerb_2")
            linealx = recorridoCargado[1].astype(np.float)
            linealy = recorridoCargado[2].astype(np.float)
            anguloth = recorridoCargado[3].astype(np.float)
            tiempillos = recorridoCargado[4].astype(np.float)
            print(linealx)
            keysVector=[]
            timesVector=[]

            print(len(linealx))
            for i in range(len(linealx)):
                keysVector.append(recorridoCargado[0][i])
                timesVector.append(tiempillos[i])
        
        if request.banner_b == 3 :
            home_dir = os.path.expanduser("~")
            file3 = os.path.join(home_dir, "bannerb_3.txt")
            recorridoCargado = np.loadtxt(file3, delimiter=',', dtype=np.str)
            print("Cargo el archivo 3 bannerb_3")
            linealx = recorridoCargado[1].astype(np.float)
            linealy = recorridoCargado[2].astype(np.float)
            anguloth = recorridoCargado[3].astype(np.float)
            tiempillos = recorridoCargado[4].astype(np.float)
            print(linealx)
            keysVector=[]
            timesVector=[]

            print(len(linealx))
            for i in range(len(linealx)):
                keysVector.append(recorridoCargado[0][i])
                timesVector.append(tiempillos[i])
        
        # ------

        for i in range(len(keysVector)-1):

            if (keysVector[i] in moveTeleopBindings.keys()):
            
                print("Tecla: "+ str(keysVector[i]))
                print("Lineal: "+ str(abs(linealx[i])))
                print("Angular: "+ str(abs(anguloth[i])))

                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = keysVector[i]
                testStruct.th0_vel = linealx[i]
                testStruct.th1 = anguloth[i]
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)

                time.sleep(timesVector[i])

                key="v"
                punto = "punto5" # corresponde al motor() del arduino
                testStruct = structForTransmition
                sendSize = 0
                testStruct.tecla = key
                testStruct.th0_vel = 0
                testStruct.th1 = 0
                sendSize = link.tx_obj(testStruct.tecla, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th0_vel, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th1, start_pos=sendSize)
                sendSize = link.tx_obj(testStruct.th2, start_pos=sendSize)
                sendSize = link.tx_obj(punto, start_pos=sendSize)
                link.send(sendSize)
        
            time.sleep(2)


        self.peticion = Juanpaser.Request()
        self.peticion.banner = self.b
        self.peticion.empieza = "llamoJuanpaser"
        self.future = self.cli.call_async(self.request)
        rclpy.spin_until_future_complete(self, self.future)
        self.termino2 = self.future.result()
        print(self.termino2.termina)


        response.answer = "Debo identificar el banner {} que se encuentra en las coordenadas tal y el banner {} que se encuentra en las coordenadas".format(self.a, self.b)
        
        return response.answer




def main(args=None):
    rclpy.init(args=args)
    nodoServicio = servicioPlayer()
    rclpy.spin(nodoServicio)
    rclpy.shutdown()

if __name__ == '__main__':
    main()