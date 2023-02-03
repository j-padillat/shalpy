import numpy as np
import matplotlib.pyplot as plt
import cv2


def hsv_to_cv(hsv):
    return np.array([int(hsv[0]/2.0), int(255.0*hsv[1]/100.0), int(255.0*hsv[2]/100.0)])

def plt_cv_image(img, title='Image'):
    global plt
    assert isinstance(img, np.ndarray), "img must a be numpy array"
    assert len(img.shape)==2 or len(img.shape)==3, "img.shape must be 2 or 3"
    if len(img.shape)==2:
        plt.imshow(img, cmap='gray')
        plt.title(title), plt.xticks([]), plt.yticks([])
        plt.show()
    else: # len(img.shape)==3
        assert img.shape[2]==3, "img.shape[2] must be 3 (RGB) if img has 3 dimensions"
        plt.imshow(img[...,::-1])
        plt.title(title), plt.xticks([]), plt.yticks([])
        plt.show()

def add_cols_left(img, num_cols, left=True):
    assert isinstance(img, np.ndarray), "img must a be numpy array"
    assert isinstance(num_cols, int), "num_cols must be integer"
    if len(img.shape)==2:
        zeros = np.zeros( (img.shape[0], num_cols), dtype=img.dtype )
        if left:
            img_add = np.hstack( (zeros, img) )
        else:
            img_add = np.hstack( (img, zeros) )
        return img_add
    elif len(img.shape)==3:
        if img.shape[2]==3:
            zeros = np.zeros( (img.shape[0], num_cols, 3), dtype=img.dtype )
            if left:
                img_add = np.hstack( (zeros, img) )
            else:
                img_add = np.hstack( (img, zeros) )
            return img_add
        else:
            print('Dimensions error.')
            return None
    else:
            print('Dimensions error.')
            return None

def add_cols_right(img, num_cols):
    assert isinstance(img, np.ndarray), "img must a be numpy array"
    assert isinstance(num_cols, int), "num_cols must be integer"
    return add_cols_left(img, num_cols, left=False)

def draw_points(img, points, title='Image', color=(0, 0, 255), radius=5):
    assert isinstance(img, np.ndarray), "img must a be numpy array"
    assert len(img.shape)==2 or len(img.shape)==3, "img.shape must be 2 or 3"
    if len(img.shape)==3:
        assert img.shape[2]==3, "img.shape[2] must be 3 (RGB) if img has 3 dimensions"
    assert isinstance(title, str), "title must be a string"
#     # dtpye!!!!
#     if len(img.shape)==2:
#         if color==None:
#             color = 255
# #     if color==None:
# #         if len(img.shape)==2:
# #             color = 255
# #         else: # len(img.shape)==3
# #             color = (0, 0, 255) # RED
#     assert isinstance(color, (np.ndarray, tuple, list)), "color must be"
    img_cpy = img.copy()
    for point in points:
        cv2.circle(img_cpy, tuple(point), radius, color, -1)
    plt_cv_image(img_cpy, title)