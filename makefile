all: 
		gcc main.c funcoes_base.c -Wall -pedantic -std=c99 -o teste -lallegro -lallegro_image -lallegro_acodec -lallegro_audio -lallegro_ttf -lallegro_font
