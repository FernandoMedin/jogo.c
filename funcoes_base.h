#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int randompais(){
	time_t t;
		srand((unsigned) time(&t));
		return rand()%13+1;
}

int randompoint(){
	
		time_t t;
		srand((unsigned) time(&t));
		return rand()%26+1;
}

int randombairro(){
	time_t t;
		srand((unsigned) time(&t));
		return rand()%31+1;
}
	
float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}
	
bool ddt(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)//dentro do triângulo?
{   
	//Área ABC
	float A = area (x1, y1, x2, y2, x3, y3);

	//Área PBC
	float A1 = area (x, y, x2, y2, x3, y3);

	//Área PAC  
	float A2 = area (x1, y1, x, y, x3, y3);

	//Área PAB 
	float A3 = area (x1, y1, x2, y2, x, y);

	return  ( A>A1+A2+A3 && A<=(A1+A2+A3+10) || A<A1+A2+A3 && A>=A1+A2+A3-10 || A==A1+A2+A3);
}

int op(ALLEGRO_AUDIO_STREAM *musica, ALLEGRO_EVENT_QUEUE *fila_eventos, ALLEGRO_EVENT evento, int *musicaof){
	int x, y;
		ALLEGRO_BITMAP *fundo_jogo = NULL, *botaoon=NULL, *botaoof=NULL;
		botaoon = al_load_bitmap("imagens/musicaon.png");
		botaoof = al_load_bitmap("imagens/musicaoff.png");
		fundo_jogo = al_load_bitmap("imagens/fundo_jogo.png");
		al_draw_bitmap(fundo_jogo, 0, 0, 0);
		if(*musicaof==1)
			al_draw_bitmap(botaoon, 250 ,225 ,0);
				
				if(*musicaof==0)
					al_draw_bitmap(botaoof, 250, 225, 0);
						al_flip_display();
						
						printf("foi\n");
						while(*musicaof == 1 || *musicaof == 0){
							al_wait_for_event(fila_eventos, &evento);
								if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
									x=evento.mouse.x;
										y=evento.mouse.y;
										printf("%d %d\n", x, y);
										
										if(x>=250 && x<=550){
											if(y>=225 && y<=375){
												printf("clicou\n");
													printf("%d %d\n", evento.mouse.x, evento.mouse.y);
													
													printf("%d %d\n", x, y);
													if(*musicaof==1){
														*musicaof=0;
															al_set_audio_stream_playing(musica, false);
															al_draw_bitmap(botaoof, 250, 225, 0);
															al_flip_display();
															al_rest(0.5);
															break;
													}
												if(*musicaof==0){
													*musicaof=1;
														al_set_audio_stream_playing(musica, true);
														al_draw_bitmap(botaoon, 250 ,225 ,0);
														al_flip_display();
														al_rest(0.5);
														break;
												}
											}
										}
									
								}
						}
	al_destroy_bitmap(botaoon);
		al_destroy_bitmap(botaoof);
		return 0;
}


int brasil(int x,int y,int estado){
	switch (estado){
		case 1:
			if(ddt(19,178,158,237,27,319,x,y))
			{
				printf("Acre\n");
				return 1;
			}

		case 2:
			if(ddt(470,235,535,275,555,205,x,y))
			{
				printf("Alagoas\n");
				return 2;
			}
		case 3:
			if(ddt(11,14,11,344,378,194,x,y))
			{
				printf("Amazonas\n");
				return 3;
			}
		case 4:
			if(ddt(254,37,383,47,305,154,x,y))
			{
				printf("Amapa\n");
				return 4;
			}
		case 5:
			if(ddt(334,245,536,176,499,410,x,y))
			{
				printf("Bahia\n");
				return 5;
			}
		case 6:
			if(ddt(429,121,553,141,459,258,x,y))
			{
				printf("Ceara\n");
				return 6;
			}
		case 7:
			if(ddt(343,315,392,302,370,357,x,y))
			{
				printf("Distrito Federal\n");
				return 7;
			}
		case 8:
			if(ddt(418,393,481,422,475,326,x,y))
			{
				printf("Espirito Santo\n");
				return 8;
			}
		case 9:
			if(ddt(254,329,376,430,406,249,x,y))
			{
				printf("Goias\n");
				return 9;
			}
		case 10:
			if(ddt(363,94,484,129,367,296,x,y))
			{
				printf("Maranhao\n");
				return 10;
			}
		case 11:
			if(ddt(280,308,359,480,527,302,x,y))
			{
				printf("Minas Gerais\n");
				return 11;
			}
		case 12:
			if(ddt(187,316,387,309,264,496,x,y))
			{
				printf("Mato Grosso do Sul\n");
				return 12;
			}
		case 13:
			if(ddt(87,351,414,368,256,143,x,y))
			{
				printf("Mato Grosso \n");
				return 13;
			}
		case 14:
			if(ddt(290,398,257,498,392,468,x,y))
			{
				printf("Parana\n");
				return 14;
			}
		case 15:
			if(ddt(482,181,482,237,574,208,x,y))
			{
				printf("Paraiba\n");
				return 15;
			}
		case 16:
			if(ddt(443,184,443,268,583,226,x,y))
			{
				printf("Pernambuco\n");
				return 16;
			}
		case 17:
			if(ddt(367,263,477,261,455,125,x,y))
			{
				printf("Piaui\n");
				return 17;
			}
		case 18:
			if(ddt(164,43,463,73,278,315,x,y))
			{
				printf("Para\n");
				return 18;
			}
		case 19:
			if(ddt(387,395,419,446,478,389,x,y))
			{
				printf("Rio de Janeiro\n");
				return 19;
			}
		case 20:
			if(ddt(480,149,484,222,583,202,x,y))
			{
				printf("Rio Grande do Norte\n");
				return 20;
			}
		case 21:
			if(ddt(81,219,205,357,251,187,x,y))
			{
				printf("Rondonia\n");
				return 21;
			}
		case 22:
			if(ddt(105,19,187,173,323,29,x,y))
			{
				printf("Roraima\n");
				return 22;
			}
		case 23:
			if(ddt(208,493,295,597,389,470,x,y))
			{
				printf("Rio Grande do sul\n");
				return 23;
			}
		case 24:
			if(ddt(335,532,376,454,249,457,x,y))
			{
				printf("Santa Catarina\n");
				return 24;
			}
		case 25:
			if(ddt(470,253,512,227,518,288,x,y))
			{
				printf("Sergipe\n");
				return 25;
			}
		case 26:
			if(ddt(294,358,291,483,456,428,x,y))
			{
				printf("Sao Paulo\n");
				return 26;
			}
		case 27:
			if(ddt(294,298,430,295,368,150,x,y))
			{
				printf("Tocantins\n");
				return 27;
			}
	}
}


int bairros_ddt(int x,int y,int bai){

	switch (bai){

		

		case 1://paralheiros

			

				if(ddt(9,590,274,592,121,270,x,y))

				{

					return 1;

				}

			

		case 2://socorro

				

					if(ddt(123,477,271,407,108,246,x,y))

					{

						return 2;

					}

				

		case 3://M Boi Miri

					

						if(ddt(27,293,81,404,152,247,x,y))

						{

							return 3;

						}

					

		case 4://Campo Limpo

						

							if(ddt(24,268,84,363,172,225,x,y))

							{

								return 4;

							}

						

		case 5://Cidade Ademar

							

								if(ddt(99,280,188,239,228,379,x,y))

								{

									return 5;

								}

							

		case 6://Santo Amaro

								

									if(ddt(89,252,195,206,173,350,x,y))

									{

										return 6;

									}

								

		case 7://Jabaquara

									

										if(ddt(141,255,210,222,201,311,x,y))

										{

											return 7;

										}

									

		case 8://Butanta

										

											if(ddt(39,170,38,293,171,216,x,y))

											{

												return 8;

											}

										

		case 9://Ipiranga

											

												if(ddt(177,188,280,180,204,325,x,y))

												{

													return 9;

												}

											

		case 10://Vila Mariana

												

													if(ddt(136,197,225,165,204,297,x,y))

													{

														return 10;

													}

												

		case 11://Pinheiros

													

														if(ddt(91,162,143,292,212,188,x,y))

														{

															return 11;

														}

													

		case 12://Lapa

														

															if(ddt(82,115,77,225,188,161,x,y))

															{

																return 12;

															}

														

		case 13://Se

															

																if(ddt(139,203,182,130,225,210,x,y))

																{

																	return 13;

																}

															

		case 14://Pirituba

																

																	if(ddt(56,98,143,186,153,57,x,y))

																	{

																		return 14;

																	}

																

		case 15://Anhanguera

																	

																		if(ddt(45,146,157,57,25,31,x,y))

																		{

																			return 15;

																		}

																	

		case 16://Freguesia do O

																		

if(ddt(109,151,176,155,156,47,x,y))

																			{

																				return 16;

																			}

																		

		case 17://Casa Verde

																			

																				if(ddt(136,144,196,158,177,53,x,y))

																				{

																					return 17;

																				}

																			

		case 18://Santana

																				

																					if(ddt(155,151,236,169,224,41,x,y))

																					{

																						return 18;

																					}

																				

		case 19://Tremembe

																					

																						if(ddt(162,57,257,152,293,9,x,y))

																						{

																							return 19;

																						}

																					

		case 20://Vila Maria

																						

																							if(ddt(186,158,279,177,251,108,x,y))

																							{

																								return 20;

																							}

																						

		case 21://Penha

																							

																								if(ddt(218,161,305,87,328,209,x,y))

																								{

																									return 21;

																								}

																							

		case 22://Ermelino Matarazzo

																								

																									if(ddt(285,98,361,93,306,183,x,y))

																									{

																										return 22; 

																									}

																								

		case 23://Sao Miguel

																									

																										if(ddt(311,111,335,193,440,99,x,y))

																										{

																											return 23;

																										}

																									

		case 24://Itaquera

																										

																											if(ddt(256,195,360,118,389,244,x,y))

																											{

																												return 24;

																											}

																										

		case 25://Itaim

																											

																												if(ddt(399,101,433,157,333,169,x,y))

																												{

																													return 25;

																												}

																											

		case 26://Guaianases

																												

																													

																													if(ddt(404,140,398,201,342,182,x,y))

																													{

																														return 26;

																													}

																												

		case 27://Cidade Tiradentes

																													

																														if(ddt(414,206,378,266,356,186,x,y))

																														{

																															return 27;

																														}

																													

		case 28://Sao Matheus

																														

																															if(ddt(401,199,385,306,286,219,x,y))

																															{

																																return 28;

																															}

																														

		case 29://Vila Prudente

																															

																																if(ddt(228,178,204,249,330,250,x,y))

																																{

																																	return 29;

																																}

																															

		case 30://Aricanduva

																																

																																	if(ddt(251,148,234,212,312,218,x,y))

																																	{

																																		return 30;

																																	}

																																

		case 31://Mooca

																																	

																																		if(ddt(179,143,273,153,239,231,x,y))

																																		{

																																			return 31;

																																		}

	}

}

int americaddt(int x,int y, int pais){
	switch(pais){
		case 1:
			if(ddt(283,49,366,44,309,128,x,y))
			{
				printf("Guiana Francesa\n");  
				return 1;
			}


		case 2:
			if(ddt(258,51,329,43,290,128,x,y))
			{
				printf("Suriname\n");  
				return 2;
			}




		case 3:
			if(ddt(228,37,303,33,272,138,x,y))
			{
				printf("Guiana\n");  
				return 3;
			}



		case 4:
			if(ddt(123,9,331,7,216,157,x,y))
			{
				printf("Venezuela\n");  
				return 4;
			}


		case 5:           
			if(ddt(50,2,273,5,165,182,x,y))
			{
				printf("Colombia\n");  
				return 5;
			}


		case 6:
			if(ddt(67,91,162,90,116,190,x,y))
			{
				printf("Equador\n");  
				return 6;
			}


		case 7:
			if(ddt(44,132,192,60,184,312,x,y))
			{
				printf("Peru\n");  
				return 7;
			}


		case 8:
			if(ddt(170,159,173,341,334,246,x,y))
			{
				printf("Bolivia\n");  
				return 8;
			}




		case 9:
			if(ddt(156,243,246,260,131,532,x,y))
			{
				printf("Chile\n");  
				return 9;
			}


		case 10:
			if(ddt(210,297,283,235,322,362,x,y))
			{
				printf("Paraguai\n");  
				return 10;
			}



		case 11:
			if(ddt(260,331,261,419,359,389,x,y))
			{
				printf("Uruguai\n");  
				return 11;
			}



		case 12:
			if(ddt(178,250,369,347,137,582,x,y))
			{
				printf("Argentina\n");
				return 12;
			}
		case 13:
			if(ddt(86,34,563,48,293,455,x,y))
			{
				printf("Brasil\n"); 
				return 13;
			}
	}
}

void bairro(ALLEGRO_EVENT_QUEUE *fila_eventos, ALLEGRO_EVENT evento, int p){
	printf("abriu\n");
		
		int flag = 0,x,y,bairros=0, resposta=-1,i=0,lixo=NULL, score=p, j=0;
		ALLEGRO_BITMAP *fundo_jogo = NULL, *mapa_sp = NULL, *an = NULL;
		ALLEGRO_BITMAP *ar=NULL, *bu=NULL, *ca=NULL, *cv=NULL, *cp=NULL,*cij=NULL, *cit=NULL, *er=NULL, *fr=NULL, *gu=NULL, *ip= NULL, *it=NULL, *ita=NULL, *ja=NULL, *la=NULL, *mb=NULL, *mo=NULL, *pa=NULL;
		ALLEGRO_BITMAP *pe=NULL, *pi=NULL, *pir=NULL, *sa=NULL, *saa=NULL, *sm=NULL, *smi=NULL, *se=NULL, *so=NULL, *tr=NULL, *vi=NULL, *vim=NULL, *vip=NULL; 
		ALLEGRO_FONT *font = NULL, *font_fase = NULL;
		ALLEGRO_BITMAP *tax_1 = NULL, *sombra_folha = NULL, *folha = NULL, *fase3=NULL;
		
		fundo_jogo = al_load_bitmap("imagens/fundo_jogo.png");
		mapa_sp = al_load_bitmap("imagens/mapasp.png");
		fase3 = al_load_bitmap("imagens/fase3.png");
		
		font = al_load_font("fonts/SchoolNotes.ttf", 70, 0);
		font_fase = al_load_font("fonts/varsity_regular.ttf", 100, 0);
		tax_1 = al_load_bitmap("imagens/tachinha2.png");
		sombra_folha = al_load_bitmap("imagens/sombra_papel.png");
		folha = al_load_bitmap("imagens/folha_lindinha.png");
		
		an = al_load_bitmap("imagens/mapasp_anhanguera.png");
		ar = al_load_bitmap("imagens/mapasp_aricanduva.png");
		bu = al_load_bitmap("imagens/mapasp_butanta.png");
		ca = al_load_bitmap("imagens/mapasp_cidadeademar.png");
		cp = al_load_bitmap("imagens/mapasp_campolimpo.png");
		cv = al_load_bitmap("imagens/mapasp_casaverde.png");
		cij = al_load_bitmap("imagens/mapasp_cidadejardim.png");
		cit = al_load_bitmap("imagens/mapasp_cidadetiradentes.png");
		er = al_load_bitmap("imagens/mapasp_ermelindomatarazzo.png");
		fr = al_load_bitmap("imagens/mapasp_freguesiadoo.png");
		gu = al_load_bitmap("imagens/mapasp_guaianazes.png");
		ip = al_load_bitmap("imagens/mapasp_ipiranga.png");
		it = al_load_bitmap("imagens/mapasp_itaim.png");
		ita = al_load_bitmap("imagens/mapasp_itaquera.png");
		ja = al_load_bitmap("imagens/mapasp_jabaquara.png");
		la = al_load_bitmap("imagens/mapasp_lapa.png");
		mb = al_load_bitmap("imagens/mapasp_mboymirim.png");
		mo = al_load_bitmap("imagens/mapasp_mooca.png");
		pa = al_load_bitmap("imagens/mapasp_parelheiros.png");
		pe = al_load_bitmap("imagens/mapasp_penha.png");
		pi = al_load_bitmap("imagens/mapasp_pinheiros.png");
		pir = al_load_bitmap("imagens/mapasp_pirituba.png");
		sa = al_load_bitmap("imagens/mapasp_santana.png");
		saa = al_load_bitmap("imagens/mapasp_santoamaro.png");
		sm = al_load_bitmap("imagens/mapasp_saomateus.png");
		smi = al_load_bitmap("imagens/mapasp_saomiguel.png");
		se = al_load_bitmap("imagens/mapasp_se.png");
		so = al_load_bitmap("imagens/mapasp_socorro.png");
		tr = al_load_bitmap("imagens/mapasp_tremebe.png");
		vi = al_load_bitmap("imagens/mapasp_vilamaria.png");
		vim = al_load_bitmap("imagens/mapasp_vilamariana.png");
		vip = al_load_bitmap("imagens/mapasp_vilaprudente.png");
		
		//ALLEGRO_EVENT evento;
		//ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
		//fila_eventos = al_create_event_queue();
		//al_register_event_source(fila_eventos, al_get_mouse_event_source());
		
		
		while(flag == 0){
			if(i==0){
				if(j==0){
					al_draw_bitmap(fundo_jogo, 0, 0, 0);
						al_draw_text(font_fase, al_map_rgb(0, 0, 0), 50, 120, 0, "Terceiro Nível!");
					al_draw_text(font_fase, al_map_rgb(0, 0, 0), 40, 220, 0, "Você Está Com");
					al_draw_textf(font_fase, al_map_rgb(0, 0, 0), 180, 320, 0, "%d Pontos!", score);
					al_flip_display();
						al_rest(1.5);
						j=1;
				}
				
					if(i==0){
						bairros = randombairro();
							i=1;
					}
				
					al_draw_bitmap(fundo_jogo, 0, 0, 0);
					al_draw_bitmap(mapa_sp, 0, 0, 0);
					al_draw_bitmap(sombra_folha, 395, 445, 0);
					al_draw_bitmap(folha, 400, 450, 0);
					al_draw_bitmap(tax_1, 410, 420, 0);
					al_draw_bitmap(tax_1, 760, 420, 0);
					
					if(score < 2){
						al_draw_textf(font, al_map_rgb(0, 0, 0), 490, 450, 0, "%d Ponto", score);
					}
					else{
						al_draw_textf(font, al_map_rgb(0, 0, 0), 490, 450, 0, "%d Pontos", score);
					}
				switch(bairros){
					case 1:
						   printf("Parelheiros\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Parelheiros");
							   break;
					case 2:
						   printf("Socorro\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Socorro");
							   break;
					case 3:
						   printf("M Boi Mirim\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "M Boi Mirim");
							   break;
					case 4:
						   printf("Campo Limpo\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Campo Limpo");
							   break;
					case 5:
						   printf("Cidade Ademar\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Cidade Ademar");
							   break;
					case 6:
						   printf("Santo Amaro\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Santo Amaro");
							   break;
					case 7:
						   printf("Jabaquara\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Jabaquara");
							   break;
					case 8:
						   printf("Butanta\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Butanta");
							   break;
					case 9:
						   printf("Ipiranga\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Ipiranga");
							   break;
					case 10:
							printf("Vila Mariana\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Vila Mariana");
								break;
					case 11:
							printf("Pinheiros\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Pinheiros");
								break;
					case 12:
							printf("Lapa\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Lapa");
								break;
					case 13:
							printf("Se\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Se");
								break;
					case 14:
							printf("Pirituba\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Pirituba");
								break;
					case 15:
							printf("Anhanguera\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Anhanguera");
								break;
					case 16:
							printf("Freguesia do O\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Freguesia do O");
								break;
					case 17:
							printf("Casa Verde\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Casa Verde");
								break;
					case 18:
							printf("Santana\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Santana");
								break;
					case 19:
							printf("Tremembe\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Tremembe");
								break;
					case 20:
							printf("Vila Maria\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Vila Maria");
								break;
					case 21:
							printf("Penha\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Penha");
								break;
					case 22:
							printf("Ermelino Matarazzo\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Ermelino Matarazzo");
								break;
					case 23:
							printf("Sao Miguel\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Sao Miguel");
								break;
					case 24:
							printf("Itaquera\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Itaquera");
								break;
					case 25:
							printf("Itaim\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Itaim");
								break;
					case 26:
							printf("Guaianases\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Guaianases");
								break;
					case 27:
							printf("Cidade Tiradentes\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Cidade Tiradentes");
								break;
					case 28:
							printf("Sao Matheus\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Sao Matheus");
								break;
					case 29:
							printf("Vila Prudente\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Vila Prudente");
								break;
					case 30:
							printf("Aricanduva\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Aricanduva");
								break;
					case 31:
							printf("Mooca\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Mooca");
								break;
				}
				al_flip_display();
			}
			
				
				al_wait_for_event(fila_eventos, &evento);
				
				printf("%d\n", bairros);
				
				if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
					printf("clicou\n");
						printf("%d %d\n", evento.mouse.x, evento.mouse.y);
						resposta = bairros_ddt(evento.mouse.x, evento.mouse.y, bairros);
						printf("%d\n", resposta);
				}
			if(resposta == bairros){
				printf("acertou\n");
					score++;
					if(score==15){
						break;
					}
			}
			if(resposta != bairros && resposta != -1){
				printf("perdeu\n");
					resposta = 100;
				flag=1;
				al_draw_bitmap(fundo_jogo, 0, 0, 0);
				al_draw_text(font_fase, al_map_rgb(0, 0, 0), 195, 220, 0, "Errou =(");
				al_flip_display();
				al_rest(1.0);
				al_draw_bitmap(fundo_jogo, 0, 0, 0);
				al_draw_text(font_fase, al_map_rgb(0, 0, 0), 140, 120, 0, "Parabéns!!");
				al_draw_text(font_fase, al_map_rgb(0, 0, 0), 40, 220, 0, "Você conseguiu:");
				if(score == 1)
					al_draw_textf(font_fase, al_map_rgb(0, 0, 0), 180, 320, 0, "%d Ponto!", score);
				else
					al_draw_textf(font_fase, al_map_rgb(0, 0, 0), 180, 320, 0, "%d Pontos!", score);
				al_flip_display();
				al_rest(2.0);
				al_destroy_bitmap(mapa_sp);
					al_destroy_bitmap(fundo_jogo);
					return;
			}
			while(resposta==1){
				al_draw_bitmap(pa, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(pa);
			}
			while(resposta==2){
				al_draw_bitmap(so, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(so);
			}
			while(resposta==3){
				al_draw_bitmap(mb, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(mb);
			}
			while(resposta==4){
				al_draw_bitmap(cp, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(cp);
			}
			
				while(resposta==5){
					al_draw_bitmap(ca, 0, 0, 0);
						al_flip_display();  
						al_rest(1.5);
						resposta=-1;
						i=0;
						al_destroy_bitmap(ca);
				}
			while(resposta==6){
				al_draw_bitmap(saa, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(saa);
			}
			while(resposta==7){
				al_draw_bitmap(ja, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ja);
			}
			while(resposta==8){
				al_draw_bitmap(bu, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(bu);
			}
			while(resposta==9){
				al_draw_bitmap(ip, 0 , 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ip);
			}
			while(resposta==10){
				al_draw_bitmap(vim, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(vim);
			}
			
				while(resposta==11){ 
					al_draw_bitmap(pi, 0, 0, 0);
						al_flip_display();  
						al_rest(1.5);
						resposta=-1;
						i=0;
						al_destroy_bitmap(pi);
				}
			while(resposta==12){
				al_draw_bitmap(la, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(la);
			}
			while(resposta==13){
				al_draw_bitmap(se, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(se);
			}
			while(resposta==14){
				al_draw_bitmap(pir, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(pir);
			}
			while(resposta==15){
				al_draw_bitmap(an, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(an);
			}
			
				while(resposta==16){
					al_draw_bitmap(fr, 0, 0, 0);
						al_flip_display();  
						al_rest(1.5);
						resposta=-1;
						i=0;
						al_destroy_bitmap(fr);
				}
			
				
				while(resposta==17){
					al_draw_bitmap(cv, 0, 0, 0);
						al_flip_display();  
						al_rest(1.5);
						resposta=-1;
						i=0;
						al_destroy_bitmap(cv);
				}
			while(resposta==18){
				al_draw_bitmap(sa, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(sa);
			}
			while(resposta==19){
				al_draw_bitmap(tr, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(tr);
			}
			
				while(resposta==20){
					al_draw_bitmap(vi , 0, 0, 0);
						al_flip_display();  
						al_rest(1.5);
						resposta=-1;
						i=0;
						al_destroy_bitmap(vi);
				}
			while(resposta==21){
				al_draw_bitmap(pe, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(pe);
			}
			while(resposta==22){
				al_draw_bitmap(er, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(er);
			}
			while(resposta==23){
				al_draw_bitmap(smi, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(smi);
			}
			while(resposta==24){
				al_draw_bitmap(ita, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ita);
			}
			while(resposta==25){
				al_draw_bitmap(it, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					i=0;
					resposta=-1;
					al_destroy_bitmap(it);
			}
			while(resposta==26){
				al_draw_bitmap(gu, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(gu);
			}
			while(resposta==27){
				al_draw_bitmap(cit, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(cit);
			}
			while(resposta==28){
				al_draw_bitmap(sm, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(sm);
			}
			while(resposta==29){
				al_draw_bitmap(vip, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(vip);
			}
			while(resposta==30){
				al_draw_bitmap(ar, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ar);
			}
			while(resposta==31){
				al_draw_bitmap(mo, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(mo);
			}
			
				
		}
	printf("finalizou função\n");
		al_destroy_bitmap(mapa_sp);
		al_destroy_bitmap(fundo_jogo);
		return;
		
}


void jogaar(ALLEGRO_EVENT_QUEUE *fila_eventos, ALLEGRO_EVENT evento, int p){
	printf("abriu\n");
		int flag = 0,x,y,estado=0, resposta=-1,i=0,lixo=NULL, score=p,j=0;
		ALLEGRO_BITMAP *fundo_jogo = NULL, *mapa_br = NULL, *rs = NULL, *fase2=NULL;
		ALLEGRO_BITMAP *ac=NULL, *al=NULL, *am=NULL, *ap=NULL, *ba=NULL, *ce=NULL, *df=NULL, *es=NULL, *go= NULL, *ma=NULL, *mg=NULL, *ms=NULL, *mt=NULL, *pa=NULL, *pb=NULL, *pe=NULL;
		ALLEGRO_BITMAP *pi=NULL, *pr=NULL, *rj=NULL, *rn=NULL, *ro=NULL, *rr=NULL, *sc=NULL, *se=NULL, *sp=NULL, *to=NULL; 
		ALLEGRO_BITMAP *tax_1 = NULL, *folha = NULL, *sombra_folha = NULL;
		ALLEGRO_FONT *font = NULL, *font_fase = NULL;
	
		fundo_jogo = al_load_bitmap("imagens/fundo_jogo.png");
		mapa_br = al_load_bitmap("imagens/mapa_br.png");
		fase2 = al_load_bitmap("imagens/fase2.png");
		
		
		tax_1 = al_load_bitmap("imagens/tachinha2.png");
		sombra_folha = al_load_bitmap("imagens/sombra_papel.png");
		folha = al_load_bitmap("imagens/folha_lindinha.png");
		font = al_load_font("fonts/SchoolNotes.ttf", 70, 0);
	font_fase = al_load_font("fonts/varsity_regular.ttf", 100, 0);
	
		ac = al_load_bitmap("imagens/mapa_br_ac.png");
		al = al_load_bitmap("imagens/mapa_br_al.png");
		am = al_load_bitmap("imagens/mapa_br_am.png");
		ap = al_load_bitmap("imagens/mapa_br_ap.png");
		ba = al_load_bitmap("imagens/mapa_br_ba.png");
		ce = al_load_bitmap("imagens/mapa_br_ce.png");
		df = al_load_bitmap("imagens/mapa_br_df.png");
		es = al_load_bitmap("imagens/mapa_br_es.png");
		go = al_load_bitmap("imagens/mapa_br_go.png");
		ma = al_load_bitmap("imagens/mapa_br_ma.png");
		mg = al_load_bitmap("imagens/mapa_br_mg.png");
		ms = al_load_bitmap("imagens/mapa_br_ms.png");
		mt = al_load_bitmap("imagens/mapa_br_mt.png");
		pa = al_load_bitmap("imagens/mapa_br_pa.png");
		pb = al_load_bitmap("imagens/mapa_br_pb.png");
		pe = al_load_bitmap("imagens/mapa_br_pe.png");
		pi = al_load_bitmap("imagens/mapa_br_pi.png");
		pr = al_load_bitmap("imagens/mapa_br_pr.png");
		rj = al_load_bitmap("imagens/mapa_br_rj.png");
		rn = al_load_bitmap("imagens/mapa_br_rn.png");
		ro = al_load_bitmap("imagens/mapa_br_ro.png");
		rr = al_load_bitmap("imagens/mapa_br_rr.png");
		rs = al_load_bitmap("imagens/mapa_br_rs.png");
		sc = al_load_bitmap("imagens/mapa_br_sc.png");
		se = al_load_bitmap("imagens/mapa_br_se.png");
		sp = al_load_bitmap("imagens/mapa_br_sp.png");
		to = al_load_bitmap("imagens/mapa_br_to.png");
		
		//ALLEGRO_EVENT evento;
		//ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
		//fila_eventos = al_create_event_queue();
		//al_register_event_source(fila_eventos, al_get_mouse_event_source());
		
		
		while(flag == 0){
			if(i==0){
				if(j==0){
					al_draw_bitmap(fundo_jogo, 0, 0, 0);
						al_draw_text(font_fase, al_map_rgb(0, 0, 0), 50, 120, 0, "Segundo Nível!");
					al_draw_text(font_fase, al_map_rgb(0, 0, 0), 40, 220, 0, "Você Está Com");
					al_draw_textf(font_fase, al_map_rgb(0, 0, 0), 180, 320, 0, "%d Pontos!", score);
					al_flip_display();
						al_rest(1.5);
						j=1;
				}
				if(i==0){
					estado = randompoint();
						i=1;
				}
				
					al_draw_bitmap(fundo_jogo, 0, 0, 0);
					al_draw_bitmap(mapa_br, 0, 0, 0);
					al_draw_bitmap(sombra_folha, 395, 445, 0);
					al_draw_bitmap(folha, 400, 450, 0);
					al_draw_bitmap(tax_1, 410, 420, 0);
					al_draw_bitmap(tax_1, 760, 420, 0);
					if(score < 2){
						al_draw_textf(font, al_map_rgb(0, 0, 0), 490, 450, 0, "%d Ponto", score);
					}else{
						al_draw_textf(font, al_map_rgb(0, 0, 0), 490, 450, 0, "%d Pontos", score);
					}
				switch(estado){
					case 1:
						   printf("Acre\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Acre");
							   break;
					case 2:
						   printf("Alagoas\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Alagoas");
							   break;
					case 3:
						   printf("Amazonas\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Amazonas");
							   break;
					case 4:
						   printf("Amapa\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Amapa");
							   break;
					case 5:
						   printf("Bahia\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Bahia");
							   break;
					case 6:
						   printf("Ceara\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Ceara");
							   break;
					case 7:
						   printf("Distrito Federal\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Distrito Federal");
							   break;
					case 8:
						   printf("Espirito Santo\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Espirito Santo");
							   break;
					case 9:
						   printf("Goias\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Goias");
							   break;
					case 10:
							printf("Maranhao\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Maranhao");
								break;
					case 11:
							printf("Minas Gerais\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Minas Gerais");
								break;
					case 12:
							printf("Mato Grosso do Sul\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Mato Grosso do Sul");
								break;
					case 13:
							printf("Mato Grosso\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Mato Grosso");
								break;
					case 14:
							printf("Parana\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Parana");
								break;
					case 15:
							printf("Paraiba\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Paraiba");
								break;
					case 16:
							printf("Pernambuco\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Pernambuco");
								break;
					case 17:
							printf("Piaui\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Piaui");
								break;
					case 18:
							printf("Para\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Para");
								break;
					case 19:
							printf("Rio de Janeiro\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Rio de Janeiro");
								break;
					case 20:
							printf("Rio Grande do Norte\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Rio Grande do Norte");
								break;
					case 21:
							printf("Rondonia\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Rondonia");
								break;
					case 22:
							printf("Roraima\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Roraima");
								break;
					case 23:
							printf("Rio Grande do Sul\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Rio Grande do Sul");
								break;
					case 24:
							printf("Santa Catarina\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Santa Catarina");
								break;
					case 25:
							printf("Sergipe\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Sergipe");
								break;
					case 26:
							printf("Sao Paulo\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Sao Paulo");
								break;
					case 27:
							printf("Tocantins\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Tocantins");
								break;
				}
				al_flip_display();
					printf("%d\n", estado);
			}
			al_wait_for_event(fila_eventos, &evento);
				
				
				if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
					printf("clicou\n");
						printf("%d %d\n", evento.mouse.x, evento.mouse.y);
						resposta = brasil(evento.mouse.x, evento.mouse.y, estado);
						printf("%d\n", resposta);
				}
			
				if(resposta == estado){
					printf("acertou\n");
						score++;
						printf("%d\n", score);
				}
			while(resposta != estado && resposta != -1){
				printf("perdeu\n");
				resposta = 100;
				al_draw_bitmap(fundo_jogo, 0, 0, 0);
				al_draw_text(font_fase, al_map_rgb(0, 0, 0), 195, 220, 0, "Errou =(");
				al_flip_display();
				al_rest(1.0);
				al_draw_bitmap(fundo_jogo, 0 ,0 ,0);
				al_draw_text(font_fase, al_map_rgb(0, 0, 0), 140, 120, 0, "Parabéns!!");
				al_draw_text(font_fase, al_map_rgb(0, 0, 0), 40, 220, 0, "Você conseguiu:");
				if(score == 1)
					al_draw_textf(font_fase, al_map_rgb(0, 0, 0), 180, 320, 0, "%d Ponto!", score);
				else
					al_draw_textf(font_fase, al_map_rgb(0, 0, 0), 180, 320, 0, "%d Pontos!", score);
				al_flip_display();
				al_rest(2.0);
				flag=1;
					return;
					
			}
			if(resposta==1){
				ac = al_load_bitmap("imagens/mapa_br_ac.png");
					al_draw_bitmap(ac, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ac);
			}
			if(resposta==2){
				al = al_load_bitmap("imagens/mapa_br_al.png");
					al_draw_bitmap(al, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(al);
			}
			if(resposta==3){
				am = al_load_bitmap("imagens/mapa_br_am.png");
					al_draw_bitmap(am, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(am);
			}
			if(resposta==4){
				ap = al_load_bitmap("imagens/mapa_br_ap.png");
					al_draw_bitmap(ap, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ap);
			}
			if(resposta==5){
				ba = al_load_bitmap("imagens/mapa_br_ba.png");
					al_draw_bitmap(ba, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ba);
			}
			if(resposta==6){
				ce = al_load_bitmap("imagens/mapa_br_ce.png");
					al_draw_bitmap(ce, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ce);
			}
			if(resposta==7){
				df = al_load_bitmap("imagens/mapa_br_df.png");
					al_draw_bitmap(df, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(df);
			}
			if(resposta==8){
				es = al_load_bitmap("imagens/mapa_br_es.png");
					al_draw_bitmap(es, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(es);
			}
			if(resposta==9){
				go = al_load_bitmap("imagens/mapa_br_go.png");
					al_draw_bitmap(go, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(go);
			}
			if(resposta==10){
				ma = al_load_bitmap("imagens/mapa_br_ma.png");
					al_draw_bitmap(ma, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ma);
			}
			if(resposta==11){
				mg = al_load_bitmap("imagens/mapa_br_mg.png");
					al_draw_bitmap(mg, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(mg);
			}
			if(resposta==12){
				ms = al_load_bitmap("imagens/mapa_br_ms.png");
					al_draw_bitmap(ms, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ms);
			}
			if(resposta==13){
				mt = al_load_bitmap("imagens/mapa_br_mt.png");
					al_draw_bitmap(mt, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(mt);
			}
			if(resposta==14){
				pr = al_load_bitmap("imagens/mapa_br_pr.png");
					al_draw_bitmap(pr, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(pr);
			}
			
				if(resposta==15){
					pb = al_load_bitmap("imagens/mapa_br_pb.png");
						al_draw_bitmap(pb, 0, 0, 0);
						al_flip_display();  
						al_rest(1.5);
						resposta=-1;
						i=0;
						al_destroy_bitmap(pb);
				}
			
				
				if(resposta==16){
					pe = al_load_bitmap("imagens/mapa_br_pe.png");
						al_draw_bitmap(pe, 0, 0, 0);
						al_flip_display();  
						al_rest(1.5);
						resposta=-1;
						i=0;
						al_destroy_bitmap(pe);
				}
			if(resposta==17){
				pi = al_load_bitmap("imagens/mapa_br_pi.png");
					al_draw_bitmap(pi, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(pi);
			}
			if(resposta==18){
				pa = al_load_bitmap("imagens/mapa_br_pa.png");
					al_draw_bitmap(pa, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(pa);
			}
			
				if(resposta==19){
					rj = al_load_bitmap("imagens/mapa_br_rj.png");
						al_draw_bitmap(rj, 0, 0, 0);
						al_flip_display();  
						al_rest(1.5);
						resposta=-1;
						i=0;
						al_destroy_bitmap(rj);
				}
			if(resposta==20){
				rn = al_load_bitmap("imagens/mapa_br_rn.png");
					al_draw_bitmap(rn, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(rn);
			}
			if(resposta==21){
				ro = al_load_bitmap("imagens/mapa_br_ro.png");
					al_draw_bitmap(ro, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ro);
			}
			if(resposta==22){
				rr = al_load_bitmap("imagens/mapa_br_rr.png");
					al_draw_bitmap(rr, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(rr);
			}
			if(resposta==23){
				rs = al_load_bitmap("imagens/mapa_br_rs.png");
					al_draw_bitmap(rs, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(rs);
			}
			if(resposta==24){
				sc = al_load_bitmap("imagens/mapa_br_sc.png");
					al_draw_bitmap(sc, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					i=0;
					resposta=-1;
					al_destroy_bitmap(sc);
			}
			if(resposta==25){
				se = al_load_bitmap("imagens/mapa_br_se.png");
					al_draw_bitmap(se, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(se);
			}
			if(resposta==26){
				sp = al_load_bitmap("imagens/mapa_br_sp.png");
					al_draw_bitmap(sp, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(sp);
			}
			if(resposta==27){
				to = al_load_bitmap("imagens/mapa_br_to.png");
					al_draw_bitmap(to, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(to);
			}
			if(score==10){
				break;
			}
			
				
		}
	printf("finalizou função\n");
		al_destroy_bitmap(mapa_br);
		al_destroy_bitmap(fundo_jogo);
		bairro(fila_eventos, evento, score);
		return;
		
}


void americas(ALLEGRO_EVENT_QUEUE *fila_eventos, ALLEGRO_EVENT evento){
	printf("abriu\n");
		
		int flag = 0,x,y,pais=0, resposta=-1,i=0,lixo=NULL, score=0, j=0;
		ALLEGRO_BITMAP *fundo_jogo = NULL, *americam = NULL, *an = NULL;
		ALLEGRO_BITMAP *guif=NULL, *su=NULL, *gui=NULL, *ve=NULL, *co=NULL, *eq=NULL, *pe=NULL, *bo=NULL, *ch=NULL, *pa=NULL, *ur=NULL, *ar=NULL, *br=NULL;
		ALLEGRO_FONT *font=NULL, *font_fase=NULL;
		ALLEGRO_BITMAP *tax_1 = NULL, *sombra_folha = NULL, *folha = NULL, *fase1=NULL;
		
		fundo_jogo = al_load_bitmap("imagens/fundo_jogo.png");
		americam = al_load_bitmap("imagens/america.png");
		
		font = al_load_font("fonts/SchoolNotes.ttf", 70, 0);
	font_fase = al_load_font("fonts/varsity_regular.ttf", 100, 0);
	tax_1 = al_load_bitmap("imagens/tachinha2.png");
		sombra_folha = al_load_bitmap("imagens/sombra_papel.png");
		folha = al_load_bitmap("imagens/folha_lindinha.png");
		fase1 = al_load_bitmap("imagens/fase1.png");
		
		
		
		while(flag == 0){
			if(i==0){
				if(j==0){
					al_draw_bitmap(fundo_jogo, 0 ,0 ,0);
					al_draw_text(font_fase, al_map_rgb(0, 0, 0), 50, 120, 0, "Primeiro Nível!");
					al_draw_text(font_fase, al_map_rgb(0, 0, 0), 40, 220, 0, "Você Está Com");
					al_draw_textf(font_fase, al_map_rgb(0, 0, 0), 180, 320, 0, "%d Pontos!", score);
					al_flip_display();
					al_rest(1.5);
					j=1;
				}
				al_draw_bitmap(fundo_jogo, 0, 0, 0);
					al_draw_bitmap(americam, 0, 0, 0);
					al_draw_bitmap(sombra_folha, 395, 445, 0);
					al_draw_bitmap(folha, 400, 450, 0);
					al_draw_bitmap(tax_1, 410, 420, 0);
					al_draw_bitmap(tax_1, 760, 420, 0);
					al_flip_display();
					
					
					if(i==0){
						pais = randompais();
							i=1;
					}
				
					
					printf("%d\n", pais);
					
					if(score < 2){
						al_draw_textf(font, al_map_rgb(0, 0, 0), 490, 450, 0, "%d Ponto", score);
					}
					else{
						al_draw_textf(font, al_map_rgb(0, 0, 0), 490, 450, 0, "%d Pontos", score);
					}
				switch(pais){
					case 1:
						   printf("Guiana Francesa\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Guiana Francesa");
							   break;
					case 2:
						   printf("Suriname\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Suriname");
							   break;
					case 3:
						   printf("Guiana\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Guiana");
							   break;
					case 4:
						   printf("Venezuela\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Venezuela");
							   break;
					case 5:
						   printf("Colombia\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Colombia");
							   break;
					case 6:
						   printf("Equador\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Equador");
							   break;
					case 7:
						   printf("Peru\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Peru");
							   break;
					case 8:
						   printf("Bolivia\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Bolivia");
							   break;
					case 9:
						   printf("Chile\n");
							   al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Chile");
							   break;
					case 10:
							printf("Paraguai\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Paraguai");
								break;
					case 11:
							printf("Uruguai\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Uruguai");
								break;
					case 12:
							printf("Argentina\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Argentina");
								break;
					case 13:
							printf("Brasil\n");
								al_draw_text(font, al_map_rgb(0, 0, 0), 490, 500, 0, "Brasil");
								break;
								
				}
				al_flip_display();
			}
			
				al_wait_for_event(fila_eventos, &evento);
				
				if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
					printf("clicou\n");
						printf("%d %d\n", evento.mouse.x, evento.mouse.y);
						resposta = americaddt(evento.mouse.x, evento.mouse.y, pais);
						printf("%d\n", resposta);
				}
			if(resposta == pais){
				printf("acertou\n");
					score++;
					if(score==5){
						break;
					}
			}
			if(resposta != pais && resposta != -1){
				printf("perdeu\n");
				resposta = 100;
				flag=1;
				al_draw_bitmap(fundo_jogo, 0, 0, 0);
				al_draw_text(font_fase, al_map_rgb(0, 0, 0), 195, 220, 0, "Errou =(");
				al_flip_display();
				al_rest(1.0);
				al_draw_bitmap(fundo_jogo, 0 ,0 ,0);
				al_draw_text(font_fase, al_map_rgb(0, 0, 0), 140, 120, 0, "Parabéns!!");
				al_draw_text(font_fase, al_map_rgb(0, 0, 0), 40, 220, 0, "Você conseguiu:");
				if(score == 1)
					al_draw_textf(font_fase, al_map_rgb(0, 0, 0), 180, 320, 0, "%d Ponto!", score);
				else
					al_draw_textf(font_fase, al_map_rgb(0, 0, 0), 180, 320, 0, "%d Pontos!", score);
				al_flip_display();
				al_rest(2.0);
				al_destroy_bitmap(americam);
					al_destroy_bitmap(fundo_jogo);
					return;
					
			}
			while(resposta==1){
				guif = al_load_bitmap("imagens/america_guif.png");
					al_draw_bitmap(guif, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(guif);
			}
			while(resposta==2){
				su = al_load_bitmap("imagens/america_suriname.png");
					al_draw_bitmap(su, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(su);
			}
			while(resposta==3){
				gui = al_load_bitmap("imagens/america_gui.png");
					
					al_draw_bitmap(gui, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(gui);
			}
			while(resposta==4){
				ve = al_load_bitmap("imagens/america_venezuela.png");
					al_draw_bitmap(ve, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ve);
			}
			
				while(resposta==5){
					co = al_load_bitmap("imagens/america_colombia.png");
						al_draw_bitmap(co, 0, 0, 0);
						al_flip_display();  
						al_rest(1.5);
						resposta=-1;
						i=0;
						al_destroy_bitmap(co);
				}
			while(resposta==6){
				eq = al_load_bitmap("imagens/america_equador.png");
					al_draw_bitmap(eq, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(eq);
			}
			while(resposta==7){
				pe = al_load_bitmap("imagens/america_peru.png");
					al_draw_bitmap(pe, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(pe);
			}
			while(resposta==8){
				bo = al_load_bitmap("imagens/america_bolivia.png");
					al_draw_bitmap(bo, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(bo);
			}
			while(resposta==9){
				ch = al_load_bitmap("imagens/america_chile.png");
					al_draw_bitmap(ch, 0 , 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ch);
			}
			while(resposta==10){
				pa = al_load_bitmap("imagens/america_paraguai.png");
					al_draw_bitmap(pa, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(pa);
			}
			
				while(resposta==11){ 
					ur = al_load_bitmap("imagens/america_uruguai.png");
						al_draw_bitmap(ur, 0, 0, 0);
						al_flip_display();  
						al_rest(1.5);
						resposta=-1;
						i=0;
						al_destroy_bitmap(ur);
				}
			while(resposta==12){
				ar = al_load_bitmap("imagens/america_argentina.png");
					al_draw_bitmap(ar, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(ar);
			}
			while(resposta==13){
				br = al_load_bitmap("imagens/america_brasil.png");
					al_draw_bitmap(br, 0, 0, 0);
					al_flip_display();  
					al_rest(1.5);
					resposta=-1;
					i=0;
					al_destroy_bitmap(br);
			}
			if(i==0){
				j==0;
			}
			
		}
	printf("finalizou função\n");
	al_destroy_bitmap(americam);
	al_destroy_bitmap(fundo_jogo);
	jogaar(fila_eventos, evento, score);
	return;
	
}
