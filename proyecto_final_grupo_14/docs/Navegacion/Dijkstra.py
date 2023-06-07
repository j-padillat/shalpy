import numpy as np
import cv2
import yaml
import heapq
import matplotlib.pyplot as plt
import os

def create_thicker_walls(yaml_file, pgm_file, wall_thickness):
    script_dir = os.path.dirname(os.path.abspath(__file__))
    yaml_file_path = os.path.join(script_dir, yaml_file)
    pgm_file_path = os.path.join(script_dir, pgm_file)
    with open(yaml_file_path, 'r') as f:
        yaml_data = yaml.load(f, Loader=yaml.FullLoader)
    image_file = yaml_data['image']
    resolution = yaml_data['resolution']
    origin = yaml_data['origin']
    negate = yaml_data['negate']
    occupied_thresh = yaml_data['occupied_thresh']
    free_thresh = yaml_data['free_thresh']
    if occupied_thresh is None:
        occupied_thresh = 0.5  
    if not os.path.exists(image_file):
        raise FileNotFoundError("No se puede encontrar el archivo de imagen:", image_file)

    img = cv2.imread(image_file, cv2.IMREAD_GRAYSCALE)

    if img is None:
        raise ValueError("No se puede abrir o leer el archivo de imagen:", image_file)

    occupied_pixels = np.where(img < occupied_thresh * 255)

    # Crear una copia del mapa original
    img_copy = img.copy()

    # Expandir las áreas ocupadas
    for x, y in zip(occupied_pixels[1], occupied_pixels[0]):
        # Verificar si es un borde
        is_border = False
        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < img.shape[1] and 0 <= ny < img.shape[0] and img[ny, nx] > 0:
                is_border = True
                break
        if is_border:
            img_copy[y-wall_thickness:y+wall_thickness+1, x-wall_thickness:x+wall_thickness+1] = 0

    # Guardar el mapa modificado
    modified_pgm_file = pgm_file_path.split('.pgm')[0] + '_thicker.pgm'
    cv2.imwrite(modified_pgm_file, img_copy)

    # Actualizar el YAML con el nombre del archivo de imagen modificado
    yaml_data['image'] = modified_pgm_file

    # Guardar el YAML modificado
    modified_yaml_file = yaml_file_path.split('.yaml')[0] + '_modified.yaml'
    with open(modified_yaml_file, 'w') as f:
        yaml.dump(yaml_data, f)

    print("Mapa y YAML modificados guardados exitosamente.")

def create_matrix_from_map(yaml_file, pgm_file):
    # Obtener la ruta absoluta de los archivos
    script_dir = os.path.dirname(os.path.abspath(__file__))
    yaml_file_path = os.path.join(script_dir, yaml_file)
    pgm_file_path = os.path.join(script_dir, pgm_file)

    # Cargar el archivo YAML
    with open(yaml_file_path, 'r') as f:
        yaml_data = yaml.load(f, Loader=yaml.FullLoader)

    # Extraer los valores del YAML
    image_file = yaml_data['image']
    resolution = yaml_data['resolution']
    origin = yaml_data['origin']

    # Comprobar si la imagen existe
    if not os.path.exists(image_file):
        raise FileNotFoundError("No se puede encontrar el archivo de imagen:", image_file)

    # Cargar el archivo PGM
    img = cv2.imread(image_file, cv2.IMREAD_GRAYSCALE)

    if img is None:
        raise ValueError("No se puede abrir o leer el archivo de imagen:", image_file)

    # Identificar las áreas libres (fondo) y los obstáculos (paredes)
    free_pixels = np.where(img > 0)  # Se asume que los valores distintos de cero representan áreas libres
    wall_pixels = np.where(img == 0)  # Se asume que los valores cero representan paredes

    # Crear una matriz vacía con la misma forma que la imagen
    matrix = np.ones_like(img)

    # Establecer el valor de las celdas obstáculo en 0 en la matriz
    matrix[wall_pixels] = 0

    return matrix

def heuristic(node, goal):
    x1, y1 = node
    x2, y2 = goal
    return np.sqrt((x2 - x1)**2 + (y2 - y1)**2)

def dijkstra(matrix, start, goal):
    frontier = [(0, start)]
    came_from = {}
    cost_so_far = {}
    came_from[start] = None
    cost_so_far[start] = 0

    while frontier:
        _, current = heapq.heappop(frontier)

        if current == goal:
            break

        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            x, y = current[0] + dx, current[1] + dy
            if 0 <= x < matrix.shape[0] and 0 <= y < matrix.shape[1] and matrix[x, y] == 1:
                new_cost = cost_so_far[current] + 1

                if (x, y) not in cost_so_far or new_cost < cost_so_far[(x, y)]:
                    cost_so_far[(x, y)] = new_cost
                    priority = new_cost
                    heapq.heappush(frontier, (priority, (x, y)))
                    came_from[(x, y)] = current

    # Reconstruir el camino desde el inicio hasta la meta
    path = []
    current = goal
    while current != start:
        path.append(current)
        current = came_from[current]
    path.append(start)
    path.reverse()

    return path

# Uso de ejemplo
create_thicker_walls('MapaRobotica.yaml', 'MapaRobotica.pgm', wall_thickness=25)

matrix = create_matrix_from_map('MapaRobotica_modified.yaml', 'MapaRobotica_thicker.pgm')
start = (600, 900)  # Posición de inicio
goals = [(650, 600)]  # Lista de posiciones de la meta

paths = []  # Lista para almacenar los caminos

# Calcular el camino para cada meta
current_position = start
for goal in goals:
    path = dijkstra(matrix, current_position, goal)
    paths.append(path)
    current_position = goal

#########################################################################################################################################
path_1 = paths[0]  # Obtener el primer camino de solución
x = [point[1] for point in path_1]  # Vectores de x
y = [point[0] for point in path_1]  # Vectores de y
#print("DatosX")
#print(x)
#print("DatosY")
#print(y)
##Orientacion
def obtener_orientacion(p1, p2, p3):
    producto_cruz = (p2[0] - p1[0]) * (p3[1] - p2[1]) - (p2[1] - p1[1]) * (p3[0] - p2[0])

    if producto_cruz > 0:
        return "derecha"
    elif producto_cruz < 0:
        return "izquierda"
    else:
        return "none"

# Datos de ejemplo y=x, x=y
#x = [900, 899, 898, 897, 896, 895, 894, 893, 892, 891, 890, 889, 888, 887, 886, 885, 884, 883, 882, 881, 880, 879, 878, 877, 876, 875, 874, 873, 872, 871, 870, 869, 868, 867, 866, 865, 864, 863, 862, 861, 860, 859, 858, 857, 856, 855, 854, 853, 852, 851, 850, 849, 848, 847, 846, 845, 844, 843, 842, 841, 840, 839, 838, 837, 836, 835, 834, 833, 832, 831, 830, 829, 828, 827, 826, 825, 824, 823, 822, 821, 820, 819, 818, 817, 816, 815, 814, 813, 812, 811, 810, 809, 808, 807, 806, 805, 804, 803, 802, 801, 800, 799, 798, 797, 796, 795, 794, 793, 792, 791, 790, 789, 788, 787, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 786, 785, 785, 784, 783, 782, 781, 780, 779, 778, 777, 776, 775, 774, 773, 772, 771, 770, 769, 768, 767, 766, 765, 764, 763, 762, 761, 760, 759, 758, 757, 756, 755, 754, 753, 752, 751, 750, 749, 748, 747, 746, 745, 744, 743, 742, 741, 740, 739, 738, 737, 736, 735, 734, 733, 732, 731, 730, 729, 728, 727, 726, 725, 724, 723, 722, 721, 720, 719, 718, 717, 716, 715, 714, 713, 712, 711, 710, 709, 708, 707, 706, 705, 704, 703, 702, 701, 700, 699, 698, 697, 696, 695, 694, 693, 692, 691, 690, 689, 688, 687, 686, 685, 684, 683, 682, 681, 680, 679, 678, 677, 676, 675, 674, 673, 672, 671, 670, 669, 668, 667, 666, 665, 664, 663, 662, 661, 660, 659, 658, 657, 656, 655, 654, 653, 652, 651, 650, 649, 648, 647, 646, 645, 644, 643, 642, 641, 640, 639, 638, 637, 636, 635, 634, 633, 632, 631, 630, 629, 628, 627, 626, 625, 624, 623, 622, 621, 620, 619, 618, 617, 616, 615, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 614, 613, 612, 611, 610, 609, 608, 607, 606, 605, 604, 603, 602, 601, 600]
#y = [600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 600, 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645, 646, 647, 648, 649, 650, 651, 652, 653, 654, 655, 656, 657, 658, 659, 660, 661, 662, 663, 664, 665, 666, 667, 668, 669, 670, 671, 672, 673, 674, 675, 676, 677, 678, 679, 680, 681, 682, 683, 684, 685, 685, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 686, 685, 684, 683, 682, 681, 680, 679, 678, 677, 676, 675, 674, 673, 672, 671, 670, 669, 668, 667, 666, 665, 664, 663, 662, 661, 660, 659, 658, 657, 656, 655, 654, 653, 652, 651, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650, 650]

contador_x = 0
contador_y = 0
contador_vector_x = []
contador_vector_y = []
contador_vector_unificado = []

# Recorrer los datos de x e y en paralelo
for i in range(len(x) - 1):
    if x[i] == x[i + 1]:
        contador_x += 1
    else:
        if contador_x >= 2:
            contador_vector_x.append(contador_x + 1)
        contador_x = 0

    if y[i] == y[i + 1]:
        contador_y += 1
    else:
        if contador_y >= 2:
            contador_vector_y.append(contador_y + 1)
        contador_y = 0

# Añadir los últimos contadores a los vectores
if contador_x >= 2:
    contador_vector_x.append(contador_x + 1)

if contador_y >= 2:
    contador_vector_y.append(contador_y + 1)

# Combinar los vectores de contadores
i = 0
j = 0

while i < len(contador_vector_y) and j < len(contador_vector_x):
    if contador_vector_y[i] > 2:
        contador_vector_unificado.append(contador_vector_y[i])
    if contador_vector_x[j] > 2:
        contador_vector_unificado.append(contador_vector_x[j])
    i += 1
    j += 1

# Añadir los elementos restantes, si hay
while i < len(contador_vector_y):
    if contador_vector_y[i] > 2:
        contador_vector_unificado.append(contador_vector_y[i])
    i += 1

while j < len(contador_vector_x):
    if contador_vector_x[j] > 2:
        contador_vector_unificado.append(contador_vector_x[j])
    j += 1




###################################################################
# Obtener la longitud de la trayectoria
longitud_trayectoria = len(x)

# Lista para almacenar las direcciones de giro
direcciones_giro = []

# Calcular las direcciones de giro para cada punto en la trayectoria
for i in range(1, longitud_trayectoria - 1):
    # Obtener los puntos consecutivos en la trayectoria
    p1 = (x[i - 1], y[i - 1])
    p2 = (x[i], y[i])
    p3 = (x[i + 1], y[i + 1]) 

    # Obtener la orientación del vector de dirección entre los puntos
    orientacion = obtener_orientacion(p1, p2, p3)
    direcciones_giro.append(orientacion)


# Recorrer el vector
for i in range(len(direcciones_giro)):
    # Verificar si el elemento actual no es "none"
    if direcciones_giro[i] != "none":
        # Cambiar los siguientes 4 strings a "none"
        for j in range(i+1, min(i+5, len(direcciones_giro))):
            direcciones_giro[j] = "none"

# Imprimir el vector actualizado
#print(direcciones_giro)



direccionesFinales=[]
# Mostrar las direcciones de giro en cada punto
for i, direccion in enumerate(direcciones_giro):
    #print("Punto", i + 1, ": Giro hacia", direccion)
    if direccion == "izquierda" or direccion == "derecha":
      direccionesFinales.append(direccion)
#print(direccionesFinales)
# Imprimir el vector unificado de contadores
#print("Contador unificado:", contador_vector_unificado)

# Vector unificado
vector_unificado = []

# Determinar el tamaño máximo entre los dos vectores
max_tamano = max(len(contador_vector_unificado), len(direccionesFinales))

for i in range(max_tamano):
    # Agregar el elemento del vector1 si existe
    if i < len(contador_vector_unificado):
        vector_unificado.append(contador_vector_unificado[i])
    # Agregar el elemento del vector2 si existe
    if i < len(direccionesFinales):
        vector_unificado.append(direccionesFinales[i])

print(vector_unificado)

# Crear el archivo de texto
with open("archivoNavegacion.txt", "w") as archivo:
    # Escribir la primera línea con las letras separadas por coma
    letras = []
    for elemento in vector_unificado:
        if elemento == "izquierda":
            letras.append("a")
        elif elemento == "derecha":
            letras.append("d")
        else:
            letras.append("w")
    archivo.write(",".join(letras) + "\n")

    # Escribir la segunda línea con el número 4.0 repetido n veces
    archivo.write(",".join(["4.0"] * len(vector_unificado)) + "\n")

    # Escribir la tercera línea con el número 0.0 repetido n veces
    archivo.write(",".join(["0.0"] * len(vector_unificado)) + "\n")

    # Escribir la cuarta línea con el número 4.0 repetido n veces
    archivo.write(",".join(["4.0"] * len(vector_unificado)) + "\n")

    # Escribir la quinta línea con los valores específicos
    valores = []
    for elemento in vector_unificado:
        if elemento == "izquierda" or elemento == "derecha":
            valores.append("5.0")
        else:
            valores.append(str((elemento / 400.0)*5.0))
    archivo.write(",".join(valores))




###########################################################################################################################################





# Graficar el mapa con todos los caminos
plt.imshow(matrix, cmap='gray')

# Mostrar el punto de origen en verde
plt.plot(start[1], start[0], 'go', markersize=8)



# Mostrar los puntos de meta en azul
for goal in goals:
    plt.plot(goal[1], goal[0], 'bo', markersize=8)

for path in paths:
    plt.plot([p[1] for p in path], [p[0] for p in path], 'r-', linewidth=2)
plt.title('Dijkstra')
plt.show()


