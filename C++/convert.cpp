#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "img_processing.h"


int main(int argc, char** argv) {

	unsigned char* rgb_image;
	unsigned char* gray_image;
	unsigned char* bw_image;
	int width, height, channels;
	char filename[100]; // Variável para armazenar a string

    // Pega a string a partir do comando
    printf("Insira uma imagem: ");
    scanf("%99s", filename); 
    
	rgb_image = stbi_load((const char*)filename, &width, &height, &channels, 3);
	if(!rgb_image)
		return 2;
		
	int length = width * height;
    gray_image = (unsigned char*) malloc(length * sizeof(char));
    bw_image = (unsigned char*) malloc(length * sizeof(char));
    rgb_to_grayscale(rgb_image, gray_image, length);
    to_blackwhite(rgb_image, bw_image, length, 90);
    
    int success1 = stbi_write_png("output_gray.png", width, height, 1, gray_image, width);
	int success2 = stbi_write_png("output_bw.png", width, height, 1, bw_image, width);
	
    if (success1 & success2) {
        printf("Imagens salvas com sucesso!\n");
    } else {
        printf("Erro ao salvar a imagem.\n");
        return -1;
    }
    
    printf("Abrindo imagens...");
    system("output_gray.png");
    system("output_bw.png");
    
    free(rgb_image);
    free(gray_image);
    free(bw_image);
    
	return 0;
}
