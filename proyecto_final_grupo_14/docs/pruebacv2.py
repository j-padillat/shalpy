import cv2
import numpy as np

cap = cv2.VideoCapture(0)
ret, frame = cap.read()
cv2.imwrite('Captura de video.jpg', frame)
cap.release()
cv2.destroyAllWindows()
