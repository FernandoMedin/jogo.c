#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>

const int largura = 800;
const int altura = 600;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila= NULL;
ALLEGRO_BITMAP *map=NULL;
ALLEGRO_MOUSE_STATE click;
ALLEGRO_EVENT evento;
FILE *saida1;
int pass=0;
int sair=0;
int p[4];
int last=0;
char *imagem;


void start(){
    al_init();    
    al_init_image_addon();
    janela = al_create_display(largura, altura);  
    fila=al_create_event_queue();
    map=al_load_bitmap("map.png");     
    al_set_window_title(janela, "Mapeador de pontos");
    al_install_mouse();
    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);  
    al_register_event_source(fila,al_get_mouse_event_source());
    al_register_event_source(fila, al_get_display_event_source(janela));
    saida1=fopen("ifcreator.txt","a+");

}

void destroy(){
    al_destroy_display(janela);
    al_destroy_event_queue(fila);           
}

int main(void){
    
    start();


    al_clear_to_color(al_map_rgba(0,0,0,0));
    al_set_target_bitmap(al_get_backbuffer(janela));
    al_draw_bitmap(map,0,0,0);
    al_flip_display();

    fprintf(saida1, "Pontos\n");
    
while (1){ 
	al_wait_for_event(fila, &evento);
	if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){

	 	if(evento.mouse.button & 1){
		    al_get_mouse_state(&click);
    		fprintf(saida1, "x = %d y = %d\n", click.x, click.y);
    		printf("x = %d, y = %d\n",click.x,click.y);
    	}
    }
}


fclose(saida1); 
destroy();
return 0;
}