import numpy as np
import matplotlib.pyplot as plt
from PIL import Image

def convolution2D(image, filter):
    image_shape = image.shape

    image_pad = np.pad(image, 1, mode='edge')
    new_image = np.zeros(image_shape)

    for i in range(image_shape[0]):
        for j in range(image_shape[1]):
            mask = np.array([
                [image_pad[i][j], image_pad[i][j+1], image_pad[i][j+2]],
                [image_pad[i+1][j], image_pad[i+1][j+1], image_pad[i+1][j+2]],
                [image_pad[i+2][j], image_pad[i+2][j+1], image_pad[i+2][j+2]]
            ])

            pixel_value = np.dot(filter[0], mask[0]) + np.dot(filter[1], mask[1]) + np.dot(filter[2], mask[2])
            new_image[i][j] = pixel_value

    return new_image

# Filters

gaussian = (1.0/16.0) * np.array([
    [1.0, 2.0, 1.0],
    [2.0, 4.0, 2.0],
    [1.0, 2.0, 1.0]
])

sobel_x = np.array([
    [-1, 0, 1],
    [-2, 0, 2],
    [-1, 0, 1]
])

laplacian = np.array([
    [-1, -1, -1],
    [-1, 8, -1],
    [-1, -1, -1]
])

sobel_y = sobel_x.T

# Loading image

img = np.array(Image.open('penguins.jpg').convert('RGB'))
img_bw = np.mean(img, axis=2) / 255  # Setting the image to have one channel, and values ranging from 0 to 1

blurred_img = convolution2D(img_bw, gaussian)

# Alg 1

A = convolution2D(blurred_img, sobel_x)
B = convolution2D(blurred_img, sobel_y)

C = np.sqrt(np.power(A, 2) + np.power(B, 2))
thr = 0.4

D = np.where(C < thr, 0, 1)

# Alg 2

E = convolution2D(blurred_img, laplacian)
F = np.where(np.abs(E) > 2e-1, 1, 0)

# Plotting

fig, axs = plt.subplots(1, 3, figsize=(24, 10))

axs[0].imshow(img)
axs[0].set_xlabel('Original image')

axs[1].imshow(D, cmap='gray')
axs[1].set_xlabel('Gaussian Filter')

axs[2].imshow(F, cmap='gray')
axs[2].set_xlabel('Laplacian Filter')

plt.savefig('result.jpg')
