#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int randompais();
int randompoint();
int randombairro();
float area(int x1, int y1, int x2, int y2, int x3, int y3);
bool ddt(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y);//dentro do triângulo?
int op(ALLEGRO_AUDIO_STREAM *musica, ALLEGRO_EVENT_QUEUE *fila_eventos, ALLEGRO_EVENT evento, int *musicaof);
int brasil(int x,int y,int estado);
int bairros_ddt(int x,int y,int bai);
int americaddt(int x,int y, int pais);
void bairro(ALLEGRO_EVENT_QUEUE *fila_eventos, ALLEGRO_EVENT evento, int p);
void jogaar(ALLEGRO_EVENT_QUEUE *fila_eventos, ALLEGRO_EVENT evento, int p);
void americas(ALLEGRO_EVENT_QUEUE *fila_eventos, ALLEGRO_EVENT evento);
