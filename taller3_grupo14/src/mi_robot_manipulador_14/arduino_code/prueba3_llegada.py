from time import sleep
from pySerialTransfer import pySerialTransfer as txfer
import threading


class struct(object):
    z = 'w'
    y = 4.5

class struct2(object):
    x = 0.0
    y = 0.0
    arr2 = ''



def mi_funcion():
    print("Hilo ejecutando")
    estructura2 = struct2
    while True:
        if link.available():
            print("The link is receiving")
            recSize = 0
            
            estructura2.x = link.rx_obj(obj_type='f', start_pos=recSize)
            recSize += txfer.STRUCT_FORMAT_LENGTHS['f']
            
            estructura2.y = link.rx_obj(obj_type='f', start_pos=recSize)
            recSize += txfer.STRUCT_FORMAT_LENGTHS['f']
            
            arr2 = link.rx_obj(obj_type=str,
                                start_pos=recSize,
                                obj_byte_size=5)
            recSize += len(arr2)
            
            print('{}, {} | {}'.format(estructura2.x, estructura2.y, arr2))
            
        elif link.status < 0:
            if link.status == txfer.CRC_ERROR:
                print('ERROR: CRC_ERROR')
            elif link.status == txfer.PAYLOAD_ERROR:
                print('ERROR: PAYLOAD_ERROR')
            elif link.status == txfer.STOP_BYTE_ERROR:
                print('ERROR: STOP_BYTE_ERROR')
            else:
                print('ERROR: {}'.format(link.status))



arr = "stop"

if __name__ == '__main__':
    try:
        testStruct = struct
        link = txfer.SerialTransfer('/dev/ttyACM0')
        thread = threading.Thread(target=mi_funcion)
        thread.start()
        
        link.open()
        sleep(5)

        while True:
            sendSize = 0
            testStruct.y += 1
            sendSize = link.tx_obj(testStruct.z, start_pos=sendSize)
            sendSize = link.tx_obj(testStruct.y, start_pos=sendSize)
            sendSize = link.tx_obj(arr, start_pos=sendSize)
            
            link.send(sendSize)

        # sleep(5)
        # testStruct.z='h'
        # sendSize = 0
        # testStruct.y += 5
        # sendSize = link.tx_obj(testStruct.z, start_pos=sendSize)
        # sendSize = link.tx_obj(testStruct.y, start_pos=sendSize)
        # sendSize = link.tx_obj(arr, start_pos=sendSize)
        
        # link.send(sendSize)
            #link.close()
        
        
    except KeyboardInterrupt:
        link.close()