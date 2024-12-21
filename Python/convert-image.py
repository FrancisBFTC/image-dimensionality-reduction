# Para baixar a biblioteca digite: pip install pillow
# Autor: Wenderson Francisco

from PIL import Image
import os

def to_grayscale(img):
    gray = Image.new("L", img.size)     # Criar uma nova imagem em modo "L" (tons de cinza)
    gray_pixels = gray.load()           # Carrega a imagem em um array
    matriz = img.load()                 # Obter os pixels da imagem original
    width, height = img.size            # Obter as dimensões da imagem

    for x in range(width):
        for y in range(height):
            r, g, b = matriz[x, y]                                      # Obter os valores RGB
            grayscale_value = int(0.299 * r + 0.587 * g + 0.114 * b)    # Calcular o valor do tom de cinza
            gray_pixels[x, y] = grayscale_value                         # Atribuir à nova imagem
    return gray

def to_black_and_white(img, threshold=90):
    gray_image = to_grayscale(img)          # Converter a imagem para tons de cinza usando a função to_grayscale
    gray_pixels = gray_image.load()         # Carrega a imagem cinza em um array
    bw = Image.new("1", img.size)           # Criar uma nova imagem em modo "1" (preto e branco)
    bw_pixels = bw.load()                   # Carrega a imagem neste modo em um array
    width, height = img.size                # Dimensões da imagem
    
    for x in range(width):
        for y in range(height):
            bw_pixels[x, y] = 1 if gray_pixels[x, y] >= threshold else 0       # Limiar de transformação
    return bw

# Solicita o caminho da imagem ao usuário
path = input("Por favor, insira o caminho da imagem: ")

# Verifica se o arquivo existe
if os.path.isfile(path):
    img = Image.open(path)
    gray_image = to_grayscale(img)
    bw_image = to_black_and_white(img)

    # Exibe a imagem em tons de cinza & preto e branco
    gray_image.show()
    bw_image.show()
else:
    print("Arquivo não encontrado. Por favor, tente novamente.")