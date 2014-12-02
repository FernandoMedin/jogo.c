#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <allegro5/allegro_primitives.h>

const int largura = 800;
const int altura = 600;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila= NULL;
ALLEGRO_BITMAP *map=NULL;
ALLEGRO_MOUSE_STATE click;
ALLEGRO_EVENT evento;
FILE* file;
FILE* file2;
char *imagem;
int pass=0;
int next=0;
int first=0;


void start()
{
    al_init();    
    al_init_image_addon();
    al_init_primitives_addon();
    janela = al_create_display(largura, altura);  
    fila=al_create_event_queue();
    map=al_load_bitmap("map.png");     
    al_set_window_title(janela, "Mapeador de triângulos");
    al_install_mouse();
    al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);  
    al_register_event_source(fila,al_get_mouse_event_source());
    al_register_event_source(fila, al_get_display_event_source(janela));
    file=fopen("ddt.txt","a+");
    file2=fopen("drartriangle.txt","a+");

}

void destroy()
{
    al_destroy_display(janela);
    al_destroy_event_queue(fila);           
}


int main(void)
{
    int a,b,c,d,e,f;
    start();
    // al_clear_to_color(al_map_rgb(0,255,0));
    al_draw_bitmap(map,0,0,0);
    al_flip_display();
    
while (1)
{
        while (al_is_event_queue_empty(fila)==false)
        {
            
            al_wait_for_event(fila, &evento);

            if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){                                             
                  if(evento.mouse.button & 1){
                        al_get_mouse_state(&click);                 
                        if(pass==0){
                              printf("%d %d\n",click.x,click.y);
                              a=click.x;
                              b=click.y;
                              if(first==0)    
                                  fprintf(file, "if(ddt(%d,%d,",click.x,click.y); 
                              else if(first==1)
                                  fprintf(file, "ddt(%d,%d,",click.x,click.y); 
                              pass++;
                        }
                        else if(pass==1){
                              printf("%d %d\n",click.x,click.y);
                              c=click.x;
                              d=click.y;
                              fprintf(file,"%d,%d,",click.x,click.y);  
                              pass++;
                        }
                        else if(pass==2){
                              printf("%d %d\n",click.x,click.y);
                              e=click.x;
                              f=click.y;                            
                              al_flip_display();
                               if(next==0){
                               fprintf(file, "%d,%d,x,y) ||",click.x,click.y);                            
                               pass=0; 
                               first=1; 
                               }
                               else if(next==1){                           
                               fprintf(file, "%d,%d,x,y))\n\n",click.x,click.y); 
                               pass=0;
                               next=0;
                               pass=0;
                               }
                               //fprintf(file2, "al_draw_triangle(%d,%d,%d,%d,%d,%d,al_map_rgb(255,255,255),2)\n",a,b,c,d,e,f);
                               al_draw_triangle(a,b,c,d,e,f,al_map_rgb(255,0,0),2);
                               al_flip_display();
                        }                        
                  }



                  if(evento.mouse.button & 2)
                  {
                  next=1;
                  }
            }


        }
         




         if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }

            
             
}
fclose(file);
fclose(file2);
destroy();
return 0;
}