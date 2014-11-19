#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

const int LARGURA_TELA = 800;
const int ALTURA_TELA = 600;

int flag = 0,x,y,estado=1, resposta=10;
	ALLEGRO_DISPLAY *janela = NULL;

  ALLEGRO_BITMAP *mapa_br = NULL; 
  mapa_br = al_load_bitmap("map.png");
  ALLEGRO_EVENT evento;
  ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
  fila_eventos = al_create_event_queue();


	janela=al_create_display(LARGURA_TELA, ALTURA_TELA);
	al_register_event_source(fila_eventos, al_get_mouse_event_source());

  	while(1){
    	al_draw_bitmap(mapa_br, 0, 0, 0);
 		al_flip_display();
		al_wait_for_event(fila_eventos, &evento);
  	}