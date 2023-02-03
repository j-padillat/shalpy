import cv2
import numpy as np
import matplotlib.pyplot as plt
from img_util import draw_points

cap = cv2.VideoCapture('ssl1.mp4')

# TO DO 
# Defina la resolucion de los videos
WIDTH =
HEIGHT = 

# P1----P2
# ||    ||
# P4----P3

# P = (x,y)

#       P1       P2        P3       P4

pts1 = [[290,27],[1317,91],[1428,828],[34,699]]
pts2 = [[0,0],[WIDTH,0],[WIDTH,HEIGHT],[0,HEIGHT]]
radii = 15
font = cv2.FONT_HERSHEY_SIMPLEX

# Classe ROBOT para ayuda del desarrollo de la actividad en clase
class Robot:
    def __init__(self, center, team):
        self.team = team
        self.center = center
        self.points = []
        self.points_color = []
        self.id = -1
    def find_points(self,centers_green, centers_purple):
        for x,y in centers_green:
            d = np.sqrt((x-self.center[0])**2 + (y-self.center[1])**2)
            if d<radii:
                self.points.append((x,y))
                self.points_color.append('G')
        for x,y in centers_purple:
            d = np.sqrt((x-self.center[0])**2 + (y-self.center[1])**2)
            if d<radii:
                self.points.append((x,y))
                self.points_color.append('P')
    def sort_points(self):
        angles = [np.arctan2(-(y-self.center[1]), (x-self.center[0])) for x,y in self.points]
        self.points = [x for _,x in sorted(zip(angles, self.points))]
        self.points_color = [x for _,x in sorted(zip(angles, self.points_color))]

        d0 = euclidean_distance(self.points[0], self.points[1])
        d1 = euclidean_distance(self.points[1], self.points[2])
        d2 = euclidean_distance(self.points[2], self.points[3])
        d3 = euclidean_distance(self.points[3], self.points[0])
        if d1>d0 and d1>d2 and d1>d3:
            self.points = [self.points[1], self.points[2], self.points[3], self.points[0]]
            self.points_color = [self.points_color[1], self.points_color[2], self.points_color[3], self.points_color[0]]
        elif d2>d0 and d2>d1 and d2>d3:
            self.points = [self.points[2], self.points[3], self.points[0], self.points[1]]
            self.points_color = [self.points_color[2], self.points_color[3], self.points_color[0], self.points_color[1]]
        elif d3>d0 and d3>d1 and d3>d2:
            self.points = [self.points[3], self.points[0], self.points[1], self.points[2]]
            self.points_color = [self.points_color[3], self.points_color[0], self.points_color[1], self.points_color[2]]
    def get_id(self):
        if self.points_color == ['P','P','G','P']:
            self.id = 0
        elif self.points_color == ['P','G','G','P']:
            self.id = 1
        elif self.points_color == ['G','G','G','P']:
            self.id = 2
        elif self.points_color == ['G','P','G','P']:
            self.id = 3
        else:
            self.id = -1



def euclidean_distance(p1,p2):
    # TO DO 
    # Calcule distancia ecuclidianda entre dos puntos dados
    return 

def mask_color(lower, upper, img):
    # TO DO 
    # Realice la mascara de colores - lower limite inferior de rango - upper limite superior - img imagen a la que se va aplicar mascara
    hsv = 
    mask = 
    # Erocione y dilate la mascara
    return mask

def center_contours(mask):
    # TO DO 
    # calculo de centroides para la mascara 
    contours, _ = 
    # centro del enclosing circle de cada contorno
    centers = [cv2.minEnclosingCircle(c)[0] for c in contours]
    return centers

def plot_centers(centers_blue, centers_yellow, centers_green, centers_purple, img):
    for x,y in centers_blue:
        cv2.circle(img,(int(x),int(y)),2,(0,0,255),-1) 
    for x,y in centers_yellow:
        cv2.circle(img,(int(x),int(y)),2,(0,0,255),-1)
    for x,y in centers_green:
        cv2.circle(img,(int(x),int(y)),2,(0,0,255),-1) 
    for x,y in centers_purple:
        cv2.circle(img,(int(x),int(y)),2,(255,255,255),-1)
    # cv2.imshow('ssl',img)


while(cap.isOpened()):
    ret, frame = cap.read()
    if not ret:
        break
    # TO DO 
    # Aplique transformacion de perspectiva
    # transformacion proyectiva para ver de frente los frames del video en una imagen de 700x1050
    M = cv2.getPerspectiveTransform(np.float32(pts1),np.float32(pts2)) # matriz de transformacion
    new_size = (WIDTH,HEIGHT)
    new_frame = 
    # cv2.imshow('ssl',new_frame)

    # TO DO 
    # Defina rangos
    # mascara color azul
    lower = 
    upper = 
    mask_blue = mask_color(lower, upper, new_frame)
    cv2.imshow('blue mask',mask_blue)

    # TO DO 
    # Defina rangos
    # mascara color amarillo
    lower = 
    upper = 
    mask_yellow = mask_color(lower, upper, new_frame)
    # cv2.imshow('yellow mask',mask_yellow)

    # TO DO 
    # Defina rangos
    # mascara color verde
    lower = 
    upper = 
    mask_green = mask_color(lower, upper, new_frame)
    # cv2.imshow('green mask',mask_green)

    # TO DO 
    # Defina rangos
    # mascara color magenta
    lower = 
    upper = 
    mask_purple = mask_color(lower, upper, new_frame)
    # cv2.imshow('purple mask',mask_purple)

    
    # centros de para contorno de las mascaras
    centers_blue = center_contours(mask_blue)
    centers_yellow = center_contours(mask_yellow)
    centers_green = center_contours(mask_green)
    centers_purple = center_contours(mask_purple)
    #plot_centers(centers_blue, centers_yellow, centers_green, centers_purple, new_frame)
    
    # TO DO 
    # para cada equipo:
    # 1. encontrar puntos verdes y magentas que esten a menos de radii pix de distancia del centro.
    # Esto definira a los contornos que hacer parte de 1 robot
    # 2. Ordenar points de cada robot de acuerdo a angulo respecto al centro y ordenar los puntos 
    # en sentido antihorario de acuerdo a la distancia euclidiana entre puntos
    # 3. Obtener id de acuerdo a los codigos de colores dados

    cv2.imshow('ssl',new_frame)
    if cv2.waitKey(20) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()