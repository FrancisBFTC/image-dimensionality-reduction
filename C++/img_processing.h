// Inclui a biblioteca para leitura
#define STB_IMAGE_IMPLEMENTATION
#include "img/stb_image.h"

// Inclui a biblioteca para escrita
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "img/stb_image_write.h"

// Função para converter uma imagem RGB para escala de cinza
void rgb_to_grayscale(unsigned char* rgb_image, unsigned char* gray_image, int length) {
    for (int i = 0; i < length; i++) {
        int r = rgb_image[3 * i];
        int g = rgb_image[3 * i + 1];
        int b = rgb_image[3 * i + 2];
        // Fórmula para converter para escala de cinza
        gray_image[i] = (unsigned char)(0.299 * r + 0.587 * g + 0.114 * b);
    }
}

void to_blackwhite(unsigned char* rgb_image, unsigned char* bw_image, int length, int threshold){
	unsigned char* gray_image;
	gray_image = (unsigned char*) malloc(length * sizeof(char));
	rgb_to_grayscale(rgb_image, gray_image, length);
	for (int i = 0; i < length; i++) {
		bw_image[i] = (unsigned char*)(gray_image[i] >= threshold) ? 255 : 0;
    }
    free(gray_image);
}
