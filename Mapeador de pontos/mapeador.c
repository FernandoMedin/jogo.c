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


void start()
{
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

void destroy()
{
    al_destroy_display(janela);
    al_destroy_event_queue(fila);           
}

 









int main(void)
{
    
    start();


    al_clear_to_color(al_map_rgba(0,0,0,0));
    al_set_target_bitmap(al_get_backbuffer(janela));
    al_draw_bitmap(map,0,0,0);
    al_flip_display();


    fprintf(saida1, "if( " );
    
while (1)
{
        while (al_is_event_queue_empty(fila)==false)
        {
            
            al_wait_for_event(fila, &evento);

            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            {                                               
				                 if(evento.mouse.button & 1)
				                 {
				                           
				                               if(pass==0)
				                               {
				                                al_get_mouse_state(&click);
				                                fprintf(saida1, "evento.mouse.x>=%d &&  evento.mouse.y>=%d && \n",click.x,click.y);
				                                printf("evento.mouse.x>=%d &&  evento.mouse.y>=%d && \n",click.x,click.y);
				                               }
				                               else if(pass==1)
				                               {
				                                al_get_mouse_state(&click);
				                                fprintf(saida1, " evento.mouse.x<=%d && \n",click.x);
				                                printf(" evento.mouse.x<=%d && \n",click.x);
				                               }

				                               else if(pass==2)
				                               {
							                               	if(last==0)
							                               	{
							                                al_get_mouse_state(&click);
							                                fprintf(saida1, " evento.mouse.y<=%d \n || ",click.y);
							                                printf(" evento.mouse.y<=%d \n || ",click.y);
							                                }
							                                else if (last==1)
							                                {
							                                al_get_mouse_state(&click);
							                                fprintf(saida1, " evento.mouse.y<=%d} \n\n\n",click.y);
							                                printf(" evento.mouse.y<=%d }",click.y);
							                                last=0;
							                                }
				                               }
				                                pass++;
				                                
				                                if(pass==3)
				                                {
				                                pass=0;
				                                }           
				                 }
				                 if(evento.mouse.button & 2)
				                 {
                                 last=1;
				                 }
	            
             
            }


        }
         if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }

            
             
}


fclose(saida1); 
destroy();
return 0;
}