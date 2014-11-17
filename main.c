#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include "funcoes_base.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

const int LARGURA_TELA = 800;
const int ALTURA_TELA = 600;

void fadeout(int vel);
void fadein(ALLEGRO_BITMAP *imagem, int vel);

ALLEGRO_BITMAP *fundo_jogo = NULL, *mapa_br = NULL;	
ALLEGRO_DISPLAY *janela = NULL;

int main(void){

	ALLEGRO_BITMAP *imagem = NULL, *botao_sair = NULL, *botao_jogar = NULL, *botao_opcoes = NULL, *abertura = NULL, *logo = NULL;
	ALLEGRO_BITMAP *botao_sair_press = NULL, *botao_jogar_press = NULL, *botao_opcoes_press = NULL;
	ALLEGRO_BITMAP *fundo_jogo = NULL, *mapa_br = NULL;
	ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
	ALLEGRO_BITMAP *tax_1 = NULL, *folha = NULL, *sombra = NULL, *sombra_folha = NULL;
	ALLEGRO_AUDIO_STREAM *musica = NULL;
	ALLEGRO_SAMPLE *sample = NULL;
	int sair = 0, teste = 0, jogar = 0, opcoes = 0;

	// Inicializa a Allegro
	al_init();

	// Iniciando os Addons
	al_init_image_addon();
	al_install_mouse();
	al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
	al_install_audio();
	al_init_acodec_addon();
	al_reserve_samples(1);

	// Configura a janela / Eventos
	janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
	fila_eventos = al_create_event_queue();

	// Carrega a imagem
	imagem = al_load_bitmap("imagens/fundo_jogo.png");
	botao_sair = al_load_bitmap("imagens/botao_sair.png");
	botao_jogar = al_load_bitmap("imagens/botao_jogar.png");
	botao_opcoes = al_load_bitmap("imagens/botao_opcoes.png");
	abertura = al_load_bitmap("imagens/abertura2.png");
	logo = al_load_bitmap("imagens/logo_certo.png");
	botao_sair_press = al_load_bitmap("imagens/botao_sair2.png");
	botao_jogar_press = al_load_bitmap("imagens/botao_jogar2.png");
	botao_opcoes_press = al_load_bitmap("imagens/botao_opcoes2.png");
	fundo_jogo = al_load_bitmap("imagens/fundo_jogo");
	mapa_br = al_load_bitmap("imagens/mapa_br");
	tax_1 = al_load_bitmap("imagens/tachinha2.png");
	sombra = al_load_bitmap("imagens/sombra.png");
	sombra_folha = al_load_bitmap("imagens/sombra_papel.png");
	folha = al_load_bitmap("imagens/folha_lindinha.png");

	//Carrega Sons
	musica = al_load_audio_stream("som/The_Builder.ogg", 4, 1024);

	// Desenhar abertura do Jogo
    al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());
    al_set_audio_stream_playing(musica, true);
	fadein(abertura, 1);
	al_draw_bitmap(abertura, 0, 0, 0);
	al_flip_display();
	fadeout(2);

	//Falar que os eventos vão vir do Mouse e janela
	al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

	while(sair == 0){

		ALLEGRO_EVENT evento;

		al_draw_bitmap(imagem, 0, 0, 0);
		al_draw_bitmap(sombra, 20, 430, 0);
		al_draw_bitmap(botao_sair, 30, 420, 0);
		al_draw_bitmap(sombra, 20, 230, 0);
		al_draw_bitmap(botao_opcoes, 30, 220, 0);
		al_draw_bitmap(sombra, 20, 30, 0);
		al_draw_bitmap(botao_jogar, 30, 20, 0);
		al_draw_bitmap(logo, -20, 25, 0);
		al_draw_bitmap(sombra_folha, 365, 425, 0);
		al_draw_bitmap(folha, 370, 420, 0);
		al_draw_bitmap(tax_1, 380, 400, 0);
		al_draw_bitmap(tax_1, 730, 400, 0);

		al_flip_display();
		al_wait_for_event(fila_eventos, &evento);

		if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){

			if(evento.mouse.x >= 30 &&
					evento.mouse.x <= 330 && 
					evento.mouse.y <= ALTURA_TELA - 10 &&
					evento.mouse.y >= ALTURA_TELA - al_get_bitmap_height(botao_sair) - 10){

				al_draw_bitmap(botao_sair_press, 30, 420, 0);
				al_flip_display();
				al_rest(0.15);
				sair = 1;
			}

			else if(evento.mouse.x >= 30 &&
					evento.mouse.x <= 330 &&
					evento.mouse.y <= ALTURA_TELA - 210 &&
					evento.mouse.y >= ALTURA_TELA - al_get_bitmap_height(botao_opcoes) - 210){

				al_draw_bitmap(botao_opcoes_press, 30, 220, 0);
				al_flip_display();
				al_rest(0.15);
			}

			else if(evento.mouse.x >= 30 &&
					evento.mouse.x <= 330 &&
					evento.mouse.y <= ALTURA_TELA - 410 &&
					evento.mouse.y >= ALTURA_TELA - al_get_bitmap_height(botao_jogar) - 410){

				al_draw_bitmap(botao_jogar_press, 30, 20, 0);
				al_flip_display();
				al_rest(0.15);
				jogar = 1;
				if(jogar == 1)
					jogaar(); 	
			}
		}
	}
	// Finaliza a janela
	al_destroy_bitmap(imagem);	
	al_destroy_bitmap(botao_jogar);	
	al_destroy_bitmap(botao_opcoes);	
	al_destroy_bitmap(botao_sair);	
	al_destroy_bitmap(abertura);
	al_destroy_bitmap(folha);
	al_destroy_bitmap(tax_1);
	al_destroy_display(janela);
	al_destroy_event_queue(fila_eventos);
	return 0;
}

void fadein(ALLEGRO_BITMAP *imagem, int vel){

	if(vel < 0){
		vel = 1;
	}
	else if(vel > 15){
		vel = 15;
	}

	int alfa;
	for (alfa = 0; alfa <= 255; alfa += vel){
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_tinted_bitmap(imagem, al_map_rgba(alfa, alfa, alfa, alfa), 0, 0, 0);
		al_flip_display();
		al_rest(0.005);
	}
}
void fadeout(int vel){
	ALLEGRO_BITMAP *buffer = NULL;
	buffer = al_create_bitmap(LARGURA_TELA, ALTURA_TELA);
	al_set_target_bitmap(buffer);
	al_draw_bitmap(al_get_backbuffer(janela), 0, 0, 0);
	al_set_target_bitmap(al_get_backbuffer(janela));

	if (vel <= 0){
		vel = 1;
	}
	else if (vel > 15){
		vel = 15;
	}

	int alfa;
	for (alfa = 0; alfa <= 255; alfa += vel){
		al_clear_to_color(al_map_rgba(0, 0, 0, 0));
		al_draw_tinted_bitmap(buffer, al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa), 0, 0, 0);
		al_flip_display();
		al_rest(0.005);
	}

	al_destroy_bitmap(buffer);
}
