int randompoint()
{
	time_t t;
	srand((unsigned) time(&t));
	return rand()%26+1;
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

	return (A == A1 + A2 + A3);
}



int brasil(int x,int y,int estado)
{
	switch (estado){


		case 1:
			if(ddt(116,248,65,224,64,262,x,y) ||ddt(64,262,115,247,92,263,x,y) ||ddt(64,239,66,225,54,248,x,y) ||
					ddt(54,248,64,222,44,246,x,y) ||ddt(44,246,58,221,40,242,x,y) ||ddt(42,243,34,234,30,240,x,y) ||ddt(32,235,56,223,22,211,x,y) 
					||ddt(23,211,23,216,19,214,x,y) ||ddt(22,209,68,227,47,237,x,y))
			{
				printf("Acre\n");
				return 1;
			}
		case 2:
			if(ddt(490,240,499,234,513,251,x,y) ||ddt(506,241,514,253,529,235,x,y) ||ddt(507,240,525,233,521,245,x,y) ||ddt(512,242,520,238,513,250,x,y))
			{
				printf("Alagoas\n");  
				return 2;
			}

		case 3:
			if(ddt(71,173,66,223,23,209,x,y) ||ddt(23,209,71,171,42,173,x,y) ||
					ddt(31,185,56,171,61,203,x,y) ||ddt(66,224,114,246,71,172,x,y) ||ddt(71,172,156,221,116,245,x,y) ||
					ddt(149,234,177,176,115,232,x,y) ||ddt(227,212,222,205,181,231,x,y) ||ddt(181,231,223,232,222,204,x,y) ||
					ddt(222,204,158,217,177,231,x,y) ||ddt(250,143,157,221,223,205,x,y) ||ddt(250,144,219,121,155,219,x,y) ||ddt(217,108,152,153,213,183,x,y) ||
					ddt(200,122,205,109,222,127,x,y) ||ddt(217,110,205,109,214,136,x,y) ||ddt(194,124,189,119,180,138,x,y) ||ddt(186,122,180,134,193,138,x,y) ||
					ddt(182,132,168,222,82,188,x,y) ||ddt(171,123,128,101,167,87,x,y) ||ddt(168,89,158,82,130,100,x,y) ||ddt(121,103,79,126,147,192,x,y) ||
					ddt(78,122,83,103,71,105,x,y) ||ddt(71,105,77,125,71,115,x,y) ||ddt(82,96,75,90,73,96,x,y) ||ddt(75,90,104,110,107,88,x,y) ||ddt(107,88,94,88,105,82,x,y) ||
					ddt(111,97,167,126,94,193,x,y) ||ddt(88,120,84,208,221,157,x,y) ||ddt(212,133,203,208,95,145,x,y) ||ddt(161,111,222,179,85,216,x,y) ||ddt(233,157,211,218,106,187,x,y))
			{
				printf("Amazonia\n");
				return 3;
			}
		case 4:
			if(ddt(336,102,312,128,293,106,x,y) ||ddt(315,51,333,90,297,84,x,y) ||ddt(272,80,306,119,329,84,x,y) ||ddt(289,84,298,115,326,108,x,y) ||ddt(335,96,312,130,294,100,x,y) ||ddt(294,114,305,109,306,109,x,y) ||ddt(294,107,305,126,311,128,x,y) ||ddt(311,128,311,87,295,87,x,y) ||ddt(273,81,308,82,300,94,x,y) ||ddt(305,76,306,114,330,100,x,y))
			{
				printf("Amapa\n");
				return 4;
			}
		case 5:
			if(ddt(460,349,475,359,469,329,x,y) ||ddt(469,332,475,354,482,292,x,y) ||ddt(415,306,467,327,481,284,x,y) ||ddt(451,324,413,302,480,280,x,y) ||ddt(386,318,416,301,382,263,x,y) ||ddt(381,264,395,250,413,288,x,y) ||ddt(397,261,453,232,453,311,x,y) ||ddt(402,260,454,232,420,240,x,y) ||ddt(418,249,480,301,475,244,x,y) ||ddt(477,298,499,271,455,245,x,y) ||ddt(415,257,431,244,421,241,x,y) ||ddt(435,243,459,247,450,231,x,y) ||ddt(447,235,454,232,457,245,x,y) ||ddt(458,239,488,259,492,244,x,y) ||ddt(462,239,490,241,476,230,x,y) ||ddt(469,234,475,233,467,241,x,y) ||ddt(386,260,392,306,470,300,x,y))
			{
				printf("Bahia\n");  
				return 5;
			}

		case 6:
			if(ddt(450,151,457,201,485,196,x,y) ||ddt(485,196,460,213,484,211,x,y) ||ddt(484,211,474,211,483,216,x,y) ||ddt(483,216,475,215,479,217,x,y) ||ddt(502,178,487,198,451,154,x,y) ||ddt(451,154,503,178,469,148,x,y) ||ddt(454,153,465,147,476,179,x,y) ||ddt(484,162,502,178,475,190,x,y) ||ddt(451,158,462,191,484,175,x,y) ||ddt(484,165,479,202,460,181,x,y) ||ddt(459,158,484,167,471,202,x,y) ||ddt(466,208,481,207,464,176,x,y) ||ddt(458,200,470,206,487,177,x,y))
			{
				printf("Ceara\n");  
				return 6;
			}
		case 7:
			if(ddt(357,321,357,330,370,330,x,y) ||ddt(370,330,357,322,370,321,x,y))
			{
				printf("Distrito Federal\n");  
				return 7;
			}
		case 8: 
			if(ddt(442,396,460,398,472,361,x,y) ||ddt(444,388,462,357,463,388,x,y) ||ddt(452,360,464,356,463,376,x,y) ||ddt(454,360,445,388,465,383,x,y) ||ddt(458,359,470,361,464,374,x,y))
			{
				printf("Espirito Santo\n");  
				return 8;
			}
		case 9:
			if(ddt(371,332,373,344,334,347,x,y) ||ddt(371,353,364,364,336,335,x,y) ||ddt(373,343,357,363,330,358,x,y) ||ddt(371,332,340,334,350,352,x,y) ||ddt(357,302,355,334,321,332,x,y) ||ddt(377,320,340,322,363,302,x,y) ||ddt(372,320,370,328,378,327,x,y) ||ddt(378,327,371,321,377,316,x,y) ||ddt(330,285,362,303,321,333,x,y) ||ddt(330,283,315,336,348,322,x,y) ||ddt(388,314,356,306,369,295,x,y) ||ddt(369,295,386,306,382,291,x,y) ||ddt(345,289,365,294,341,322,x,y) ||ddt(343,293,324,347,347,348,x,y) ||ddt(356,332,355,360,332,364,x,y) ||ddt(332,364,323,377,298,365,x,y) ||ddt(298,365,304,330,344,336,x,y) ||ddt(300,339,299,363,293,351,x,y) ||ddt(293,351,297,342,325,343,x,y) ||ddt(303,333,294,357,327,359,x,y) ||ddt(314,321,308,370,354,342,x,y) ||ddt(327,297,319,361,358,334,x,y) ||ddt(355,300,349,350,318,350,x,y) ||ddt(330,297,332,327,359,305,x,y) ||ddt(381,315,354,316,369,301,x,y) ||ddt(348,290,364,296,343,325,x,y) ||ddt(333,295,361,301,338,332,x,y))
			{
				printf("Goias\n");  
				return 9;
			}
		case 10:
			if(ddt(410,145,427,172,446,149,x,y) ||ddt(386,128,439,151,387,183,x,y) ||ddt(388,129,373,165,414,177,x,y) ||ddt(374,166,370,189,356,182,x,y) ||ddt(372,168,367,208,404,202,x,y) ||ddt(375,222,396,216,380,174,x,y) ||ddt(369,209,378,216,422,171,x,y) ||ddt(396,215,382,220,390,235,x,y) ||ddt(390,235,382,224,375,235,x,y) ||ddt(375,235,381,244,388,232,x,y) ||ddt(389,233,390,249,384,248,x,y) ||ddt(383,248,379,246,385,236,x,y) ||ddt(430,201,430,153,397,201,x,y) ||ddt(421,203,392,199,413,152,x,y) ||ddt(412,205,403,214,384,183,x,y) ||ddt(414,203,397,216,383,174,x,y) ||ddt(369,178,380,207,414,184,x,y) ||ddt(387,127,394,175,415,155,x,y) ||ddt(386,155,381,193,429,169,x,y) ||ddt(382,221,370,215,395,184,x,y) ||ddt(369,188,367,207,426,180,x,y) ||ddt(390,150,390,203,423,168,x,y) ||ddt(422,152,417,196,386,167,x,y) ||ddt(390,140,421,153,394,196,x,y) ||ddt(395,213,414,199,379,171,x,y))
			{
				printf("Maranhao\n");  
				return 10;
			}

		case 11:
			if(ddt(367,384,385,423,436,408,x,y) ||ddt(436,407,463,353,373,385,x,y) ||ddt(374,388,369,362,321,387,x,y) ||ddt(321,384,343,365,357,382,x,y) ||ddt(336,367,373,355,361,385,x,y) ||ddt(372,330,375,400,451,379,x,y) ||ddt(451,379,372,332,386,316,x,y) ||ddt(388,319,416,307,440,383,x,y) ||ddt(416,312,449,324,413,384,x,y) ||ddt(446,320,453,367,393,364,x,y) ||ddt(449,325,468,331,429,360,x,y) ||ddt(452,360,460,349,466,357,x,y) ||ddt(409,322,452,329,427,379,x,y) ||ddt(369,350,381,311,405,363,x,y))
			{
				printf("Minas Gerais\n");  
				return 11;
			}
		case 12:
			if(ddt(229,377,231,412,248,415,x,y) ||ddt(248,415,235,354,285,377,x,y) ||ddt(241,356,248,414,287,411,x,y) ||ddt(323,382,279,437,249,383,x,y) ||ddt(282,356,323,377,288,406,x,y) ||ddt(324,377,322,385,316,387,x,y) ||ddt(322,378,315,388,282,363,x,y) ||ddt(284,355,295,359,285,394,x,y) ||ddt(286,348,283,354,279,351,x,y) ||ddt(278,351,267,352,277,370,x,y) ||ddt(267,353,256,347,246,370,x,y) ||ddt(242,355,250,349,265,379,x,y) ||ddt(240,363,242,404,307,383,x,y) ||ddt(278,361,274,407,243,411,x,y) ||ddt(245,372,253,402,296,397,x,y) ||ddt(265,364,267,422,304,401,x,y) ||ddt(287,359,321,379,285,422,x,y))
			{
				printf("Mato Grosso do Sul\n");  
				return 12;
			}
		case 13:
			if(ddt(331,246,286,348,209,241,x,y) ||ddt(184,233,224,233,204,264,x,y) ||ddt(204,264,183,235,184,259,x,y) ||ddt(204,265,204,275,268,264,x,y) ||ddt(202,271,206,282,255,253,x,y) ||ddt(207,280,195,299,200,315,x,y) ||ddt(200,317,198,320,201,333,x,y) ||ddt(202,332,197,299,224,334,x,y) ||ddt(224,334,199,294,289,255,x,y) ||ddt(217,246,227,337,307,279,x,y) ||ddt(330,286,321,317,274,303,x,y) ||ddt(316,318,300,335,275,292,x,y) ||ddt(293,355,284,298,285,355,x,y) ||ddt(301,334,268,353,235,334,x,y) ||ddt(236,354,272,341,226,288,x,y) ||ddt(232,268,246,337,306,285,x,y) ||ddt(315,253,299,326,237,266,x,y) ||ddt(241,244,302,254,228,316,x,y) ||ddt(218,241,227,317,297,265,x,y) ||ddt(197,237,198,261,253,251,x,y) ||ddt(322,252,311,309,201,264,x,y) ||ddt(244,318,280,344,323,280,x,y) ||ddt(214,251,218,316,320,265,x,y))
			{
				printf("Mato Grosso \n");  
				return 13;
			}
		case 14:
			if(ddt(274,457,296,416,319,472,x,y) ||ddt(293,422,313,473,359,455,x,y) ||ddt(308,453,290,424,359,456,x,y) ||ddt(289,421,319,423,298,450,x,y) ||ddt(311,420,335,426,302,452,x,y) ||ddt(325,424,340,426,324,444,x,y) ||ddt(337,427,359,452,317,463,x,y))
			{
				printf("Parana\n");  
				return 14;
			}

		case 15:
			if(ddt(505,209,517,214,509,224,x,y) ||ddt(508,224,510,212,505,213,x,y) ||ddt(487,199,483,215,502,209,x,y) ||ddt(486,201,508,213,511,207,x,y) ||ddt(493,199,503,204,504,194,x,y) ||ddt(505,205,513,220,526,215,x,y) ||ddt(514,198,515,217,527,200,x,y) ||ddt(520,200,528,211,534,202,x,y))
			{
				printf("Paraiba\n");  
				return 15;
			}

		case 16:
			if(ddt(461,211,451,231,462,239,x,y) ||ddt(461,239,460,214,476,217,x,y) ||ddt(476,217,466,227,492,239,x,y) ||ddt(469,218,502,220,491,238,x,y) ||ddt(492,219,505,210,502,220,x,y) ||ddt(508,222,537,214,530,233,x,y) ||ddt(511,221,531,228,510,239,x,y) ||ddt(496,233,506,223,514,236,x,y) ||ddt(476,229,497,221,492,239,x,y) ||ddt(454,230,470,228,461,236,x,y))
			{
				printf("Pernambuco\n");  
				return 16;
			}

		case 17:
			if(ddt(444,151,451,153,450,179,x,y) ||ddt(452,168,460,205,446,219,x,y) ||ddt(462,206,434,173,434,230,x,y) ||ddt(458,216,458,225,431,242,x,y) ||ddt(431,242,427,204,461,207,x,y) ||ddt(429,200,431,168,446,154,x,y) ||ddt(429,203,419,238,408,212,x,y) ||ddt(408,212,420,206,414,204,x,y) ||ddt(408,213,390,247,396,218,x,y) ||ddt(390,229,390,250,416,247,x,y) ||ddt(418,247,401,260,394,250,x,y) ||ddt(392,251,400,257,419,246,x,y) ||ddt(402,220,410,237,430,222,x,y) ||ddt(437,171,428,220,455,212,x,y) ||ddt(454,183,461,206,429,234,x,y))
			{
				printf("Piaui\n");
				return 17;
			}
		case 18:
			if(ddt(252,144,356,184,227,197,x,y) ||ddt(224,204,234,225,333,162,x,y) ||ddt(236,230,248,241,298,164,x,y) ||ddt(244,239,332,246,349,146,x,y) ||ddt(354,184,372,167,327,128,x,y) ||ddt(331,104,387,127,371,168,x,y) ||ddt(253,145,246,238,349,176,x,y) ||ddt(307,129,251,142,257,78,x,y) ||ddt(257,78,272,81,275,107,x,y) ||ddt(274,86,292,103,275,144,x,y) ||ddt(255,89,219,97,252,143,x,y) ||ddt(252,143,219,97,220,121,x,y) ||ddt(220,121,240,135,256,108,x,y) ||ddt(264,103,247,191,321,161,x,y) ||ddt(257,107,257,226,355,163,x,y) ||ddt(334,102,296,160,359,160,x,y) ||ddt(329,131,313,208,371,154,x,y) ||ddt(375,164,356,182,259,201,x,y) ||ddt(359,187,352,203,312,173,x,y) ||ddt(355,184,346,205,288,212,x,y) ||ddt(355,182,330,244,256,180,x,y) ||ddt(263,119,248,231,353,160,x,y) ||ddt(253,142,248,239,224,204,x,y) ||ddt(236,183,233,218,342,190,x,y))
			{
				printf("Para\n");  
				return 18; 
			}
		case 19:
			if(ddt(406,417,409,426,441,424,x,y) ||ddt(406,418,439,423,436,409,x,y) ||ddt(427,412,442,425,443,396,x,y) ||ddt(439,397,443,415,455,409,x,y) ||ddt(439,405,444,395,454,408,x,y) ||ddt(448,401,451,405,453,400,x,y) ||ddt(441,405,446,397,450,406,x,y) ||ddt(439,411,445,407,449,413,x,y) ||ddt(414,415,430,413,424,420,x,y))
			{
				printf("Rio de Janeiro\n");  
				return 19;
			}

		case 20:
			if(ddt(527,183,534,199,514,196,x,y) ||ddt(514,196,524,183,501,179,x,y) ||ddt(502,200,514,206,513,181,x,y) ||ddt(510,181,511,196,495,189,x,y) ||ddt(494,188,506,179,506,184,x,y) ||ddt(489,197,496,188,502,193,x,y) ||ddt(500,192,510,188,509,201,x,y) ||ddt(506,188,517,187,508,196,x,y))
			{
				printf("Rio Grande do Norte\n");  
				return 20;
			}
		case 21:
			if(ddt(182,262,202,264,178,297,x,y) ||ddt(178,297,201,273,206,281,x,y) ||ddt(205,279,178,296,195,298,x,y) ||ddt(184,232,183,296,157,282,x,y) ||ddt(184,232,140,235,144,280,x,y) ||ddt(144,280,183,263,167,227,x,y) ||ddt(167,222,148,232,155,220,x,y) ||ddt(156,221,177,232,149,277,x,y) ||ddt(135,239,134,268,174,256,x,y) ||ddt(140,234,139,274,193,286,x,y) ||ddt(134,239,133,244,115,246,x,y) ||ddt(115,246,127,242,121,240,x,y) ||ddt(183,232,141,235,166,275,x,y) ||ddt(138,235,181,237,162,282,x,y))
			{
				printf("Rondonia\n");  
				return 21;
			}
		case 22:
			if(ddt(218,96,218,110,203,107,x,y) ||ddt(203,107,206,89,214,96,x,y) ||ddt(206,87,199,121,189,118,x,y) ||ddt(189,118,199,121,194,124,x,y) ||ddt(188,118,177,128,171,123,x,y) ||ddt(176,130,183,121,180,132,x,y) ||ddt(174,120,165,87,203,96,x,y) ||ddt(175,58,203,74,209,59,x,y) ||ddt(209,59,201,42,182,54,x,y) ||ddt(183,54,167,87,159,84,x,y) ||ddt(159,84,180,56,161,57,x,y) ||ddt(160,59,158,79,144,58,x,y) ||ddt(141,57,153,77,194,65,x,y) ||ddt(168,67,175,112,209,102,x,y))
			{
				printf("Roraima\n");  
				return 22;
			}
		case 23:
			if(ddt(235,522,293,567,337,512,x,y) ||ddt(236,521,284,482,334,514,x,y) ||ddt(282,482,307,486,289,513,x,y) ||ddt(304,486,326,499,291,514,x,y) ||ddt(312,487,339,512,292,527,x,y) ||ddt(324,499,338,511,337,500,x,y) ||ddt(246,514,279,485,285,495,x,y))
			{
				printf("Rio Grande do sul\n");  
				return 23;
			}
		case 24:
			if(ddt(285,469,284,483,320,470,x,y) ||ddt(283,484,319,476,317,491,x,y) ||ddt(319,472,319,490,339,511,x,y) ||ddt(319,472,342,468,331,499,x,y) ||ddt(317,473,354,465,357,487,x,y) ||ddt(316,485,340,508,356,486,x,y) ||ddt(321,472,356,471,337,494,x,y))
			{
				printf("Santa Catarina\n");  
				return 24;
			}

		case 25:
			if(ddt(494,242,487,259,504,270,x,y) ||ddt(494,243,515,252,501,265,x,y) ||ddt(492,247,505,252,495,264,x,y))
			{
				printf("Sergipe\n");  
				return 25;
			}

		case 26:
			if(ddt(293,418,323,386,340,429,x,y) ||ddt(322,384,346,382,340,427,x,y) ||ddt(340,424,345,449,387,425,x,y) ||ddt(342,441,361,454,378,414,x,y) ||ddt(409,415,410,428,388,434,x,y) ||ddt(388,434,385,424,401,419,x,y) ||ddt(379,403,338,423,378,437,x,y) ||ddt(350,388,372,387,362,414,x,y) ||ddt(298,420,336,423,338,394,x,y) ||ddt(340,425,349,448,370,388,x,y))
			{
				printf("Sao Paulo\n");  
				return 26;
			}

		case 27:
			if(ddt(355,184,368,196,369,190,x,y) ||ddt(359,188,369,192,366,210,x,y) ||ddt(359,192,346,220,368,223,x,y) ||ddt(356,200,348,217,344,215,x,y) ||ddt(344,215,350,206,359,223,x,y) ||ddt(354,201,348,208,355,217,x,y) ||ddt(360,204,376,224,353,246,x,y) ||ddt(376,222,379,226,381,221,x,y) ||ddt(372,219,376,230,355,237,x,y) ||ddt(375,222,377,245,356,245,x,y) ||ddt(349,212,350,263,366,233,x,y) ||ddt(346,224,336,240,361,249,x,y) ||ddt(335,238,327,261,357,261,x,y) ||ddt(328,265,328,285,354,269,x,y) ||ddt(329,285,357,269,343,247,x,y) ||ddt(333,283,343,291,347,249,x,y) ||ddt(347,286,367,293,345,244,x,y) ||ddt(367,291,384,288,345,255,x,y) ||ddt(380,265,385,280,356,273,x,y) ||ddt(391,252,362,278,351,252,x,y) ||ddt(339,238,333,284,370,269,x,y) ||ddt(345,231,342,289,375,263,x,y) ||ddt(352,221,353,288,380,286,x,y) ||ddt(385,287,373,238,339,272,x,y) ||ddt(351,208,350,243,373,226,x,y) ||ddt(338,244,352,280,335,288,x,y))
			{
				printf("Tocantins\n");  
				return 27;
			}

	}
}


void bairros(){
	printf("abriu\n");
  int flag = 0,x,y,bairros=0, resposta=-1,i=0,lixo=NULL, score=0;
  ALLEGRO_BITMAP *fundo_jogo = NULL, *mapa_sp = NULL, *an = NULL;
  ALLEGRO_BITMAP *ar=NULL, *bu=NULL, *ca=NULL, *cv=NULL, *cij=NULL, *cit=NULL, *er=NULL, *fr=NULL, *gu=NULL, *ip= NULL, *it=NULL, *ita=NULL, *ja=NULL, *la=NULL, *mb=NULL, *mo=NULL, *pa=NULL;
  ALLEGRO_BITMAP *pe=NULL, *pi=NULL, *pir=NULL, *sa=NULL, *saa=NULL, *sm=NULL, *smi=NULL, *se=NULL, *so=NULL, *tr=NULL, *vi=NULL, *vim=NULL, *vip=NULL; 
  fundo_jogo = al_load_bitmap("imagens/fundo_jogo.png");
  mapa_sp = al_load_bitmap("imagens/mapasp.png");
  an = al_load_bitmap("imagens/mapasp_anhanguera.png");
  ar = al_load_bitmap("imagens/mapasp_aricanduva.png");
  bu = al_load_bitmap("imagens/mapasp_butanta.png");
  ca = al_load_bitmap("imagens/mapasp_cidadejardim.png");
  cv = al_load_bitmap("imagens/mapasp_casaverde.png");
  cij = al_load_bitmap("imagens/mapasp_cidadejardim.png");
  cit = al_load_bitmap("imagens/mapasp_tiradentes.png");
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

  ALLEGRO_EVENT evento;
  ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
  fila_eventos = al_create_event_queue();
  al_register_event_source(fila_eventos, al_get_mouse_event_source());


  	while(flag == 0){
    if(ALLEGRO_EVENT_MOUSE_BUTTON_UP){
    al_draw_bitmap(fundo_jogo, 0, 0, 0);
    al_draw_bitmap(mapa_sp, 0, 0, 0);
    al_flip_display();
	}
	al_wait_for_event(fila_eventos, &evento);
    if(i==0){
      bairros = randompoint();
      i=1;
    }
    switch(bairros){
        case 1:
          printf("Acre\n");
          break;
        case 2:
          printf("Alagoas\n");
          break;
        case 3:
          printf("Amazonia\n");
          break;
        case 4:
          printf("Amapa\n");
          break;
        case 5:
          printf("Bahia\n");
          break;
        case 6:
          printf("Ceara\n");
          break;
        case 7:
          printf("Distrito Federal\n");
          break;
        case 8:
          printf("Espirito Santo\n");
          break;
        case 9:
          printf("Goias\n");
          break;
        case 10:
          printf("Maranhao\n");
          break;
        case 11:
          printf("Minas Gerais\n");
          break;
        case 12:
          printf("Mato Grosso do Sul\n");
          break;
        case 13:
          printf("Mato Grosso\n");
          break;
        case 14:
          printf("Parana\n");
          break;
        case 15:
          printf("Paraiba\n");
          break;
        case 16:
          printf("Pernambuco\n");
          break;
        case 17:
          printf("Piaui\n");
          break;
        case 18:
          printf("Para\n");
          break;
        case 19:
          printf("Rio de Janeiro\n");
          break;
        case 20:
          printf("Rio Grande do Norte\n");
          break;
        case 21:
          printf("Rondonia\n");
          break;
        case 22:
          printf("Roraima\n");
          break;
        case 23:
          printf("Rio Grande do Sul\n");
          break;
        case 24:
          printf("Santa Catarina\n");
          break;
        case 25:
          printf("Sergipe\n");
          break;
        case 26:
          printf("Sao Paulo\n");
          break;
        case 27:
          printf("Tocantins\n");
          break;
      }
    printf("%d\n", bairros);

    if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
      printf("clicou\n");
      printf("%d %d\n", evento.mouse.x, evento.mouse.y);
      resposta = brasil(evento.mouse.x, evento.mouse.y, bairros);
      printf("%d\n", resposta);
    }
    if(resposta == bairros){
      printf("acertou\n");
    	score++;
      	if(score==5){
      		break;
      	}
    }
    if(resposta != bairros && resposta != -1){
      printf("perdeu\n");
      resposta = 100;
      flag=1;

    }
    while(resposta==1){
      al_draw_bitmap(an, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(an);
    }
   	while(resposta==2){
      al_draw_bitmap(ar, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(ar);
    }
    while(resposta==3){
      al_draw_bitmap(bu, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(bu);
    }
    while(resposta==4){
      al_draw_bitmap(ca, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(ca);
    }

    while(resposta==5){
      al_draw_bitmap(cv, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(cv);
	}
    while(resposta==6){
      al_draw_bitmap(cij, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(cij);
    }
    while(resposta==7){
      al_draw_bitmap(cit, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(cit);
    }
    while(resposta==8){
      al_draw_bitmap(er, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(er);
    }
    while(resposta==9){
      al_draw_bitmap(fr, 0 , 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(fr);
    }
    while(resposta==10){
      al_draw_bitmap(gu, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(gu);
    }
    
    while(resposta==11){ 
      al_draw_bitmap(ip, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(ip);
    }
    while(resposta==12){
      al_draw_bitmap(it, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(ita);
    }
    while(resposta==13){
      al_draw_bitmap(ja, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(ja);
    }
    while(resposta==14){
      al_draw_bitmap(la, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(la);
    }
    while(resposta==15){
      al_draw_bitmap(mb, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(mb);
    }

     while(resposta==16){
      al_draw_bitmap(mo, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(mo);
    }


    while(resposta==17){
      al_draw_bitmap(pa, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(pa);
    }
    while(resposta==18){
      al_draw_bitmap(pe, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(pe);
    }
    while(resposta==19){
      al_draw_bitmap(pi, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(pi);
    }

    while(resposta==20){
      al_draw_bitmap(pir, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(pir);
    }
    while(resposta==21){
      al_draw_bitmap(sa, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(sa);
    }
    while(resposta==22){
      al_draw_bitmap(saa, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(saa);
    }
    while(resposta==23){
      al_draw_bitmap(sm, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(sm);
    }
    while(resposta==24){
      al_draw_bitmap(smi, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(smi);
    }
    while(resposta==25){
      al_draw_bitmap(se, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      i=0;
      resposta=-1;
      al_destroy_bitmap(se);
    }
    while(resposta==26){
      al_draw_bitmap(so, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(so);
    }
    while(resposta==27){
      al_draw_bitmap(tr, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(tr);
    }
    while(resposta==28){
      al_draw_bitmap(vi, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(vi);
    }
    while(resposta==29){
      al_draw_bitmap(vim, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(vim);
    }
    while(resposta==30){
      al_draw_bitmap(vip, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(vip);
    }
    
    
  }
  printf("finalizou função\n");
  al_destroy_bitmap(mapa_sp);
  al_destroy_bitmap(fundo_jogo);

}


void jogaar(){
	printf("abriu\n");
  int flag = 0,x,y,estado=0, resposta=-1,i=0,lixo=NULL, score=0;
  ALLEGRO_BITMAP *fundo_jogo = NULL, *mapa_br = NULL, *rs = NULL;
  ALLEGRO_BITMAP *ac=NULL, *al=NULL, *am=NULL, *ap=NULL, *ba=NULL, *ce=NULL, *df=NULL, *es=NULL, *go= NULL, *ma=NULL, *mg=NULL, *ms=NULL, *mt=NULL, *pa=NULL, *pb=NULL, *pe=NULL;
  ALLEGRO_BITMAP *pi=NULL, *pr=NULL, *rj=NULL, *rn=NULL, *ro=NULL, *rr=NULL, *sc=NULL, *se=NULL, *sp=NULL, *to=NULL; 
  fundo_jogo = al_load_bitmap("imagens/fundo_jogo.png");
  mapa_br = al_load_bitmap("imagens/mapa_br.png");
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


  ALLEGRO_EVENT evento;
  ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
  fila_eventos = al_create_event_queue();
  al_register_event_source(fila_eventos, al_get_mouse_event_source());


  while(flag == 0){
    if(ALLEGRO_EVENT_MOUSE_BUTTON_UP){
    al_draw_bitmap(fundo_jogo, 0, 0, 0);
    al_draw_bitmap(mapa_br, 0, 0, 0);
    al_flip_display();
	}
	al_wait_for_event(fila_eventos, &evento);
    if(i==0){
      estado = randompoint();
      i=1;
    }
    switch(estado){
        case 1:
          printf("Acre\n");
          break;
        case 2:
          printf("Alagoas\n");
          break;
        case 3:
          printf("Amazonia\n");
          break;
        case 4:
          printf("Amapa\n");
          break;
        case 5:
          printf("Bahia\n");
          break;
        case 6:
          printf("Ceara\n");
          break;
        case 7:
          printf("Distrito Federal\n");
          break;
        case 8:
          printf("Espirito Santo\n");
          break;
        case 9:
          printf("Goias\n");
          break;
        case 10:
          printf("Maranhao\n");
          break;
        case 11:
          printf("Minas Gerais\n");
          break;
        case 12:
          printf("Mato Grosso do Sul\n");
          break;
        case 13:
          printf("Mato Grosso\n");
          break;
        case 14:
          printf("Parana\n");
          break;
        case 15:
          printf("Paraiba\n");
          break;
        case 16:
          printf("Pernambuco\n");
          break;
        case 17:
          printf("Piaui\n");
          break;
        case 18:
          printf("Para\n");
          break;
        case 19:
          printf("Rio de Janeiro\n");
          break;
        case 20:
          printf("Rio Grande do Norte\n");
          break;
        case 21:
          printf("Rondonia\n");
          break;
        case 22:
          printf("Roraima\n");
          break;
        case 23:
          printf("Rio Grande do Sul\n");
          break;
        case 24:
          printf("Santa Catarina\n");
          break;
        case 25:
          printf("Sergipe\n");
          break;
        case 26:
          printf("Sao Paulo\n");
          break;
        case 27:
          printf("Tocantins\n");
          break;
      }
    printf("%d\n", estado);

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
      flag=1;
      break;

    }
     if(resposta==1){
      al_draw_bitmap(ac, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(ac);
    }
    if(resposta==2){
      al_draw_bitmap(al, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(al);
  }
    if(resposta==3){
      al_draw_bitmap(am, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(am);
    }
    if(resposta==4){
      al_draw_bitmap(ap, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(ap);
    }
    if(resposta==5){
      al_draw_bitmap(ba, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(ba);
    }
    if(resposta==6){
      al_draw_bitmap(ce, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(ce);
    }
    if(resposta==7){
      al_draw_bitmap(df, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(df);
    }
    if(resposta==8){
      al_draw_bitmap(es, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(es);
    }
    if(resposta==9){
      al_draw_bitmap(go, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(go);
    }
    if(resposta==10){
    al_draw_bitmap(ma, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(ma);
    }
    if(resposta==11){
      al_draw_bitmap(mg, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(mg);
    }
    if(resposta==12){
      al_draw_bitmap(ms, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(ms);
    }
    if(resposta==13){
      al_draw_bitmap(mt, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(mt);
    }
    if(resposta==14){
      al_draw_bitmap(pr, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(pr);
    }

     if(resposta==15){
      al_draw_bitmap(pb, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(pb);
    }


    if(resposta==16){
      al_draw_bitmap(pe, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(pe);
    }
    if(resposta==17){
      al_draw_bitmap(pi, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(pi);
    }
    if(resposta==18){
      al_draw_bitmap(pa, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(pa);
    }

    if(resposta==19){
      al_draw_bitmap(rj, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(rj);
    }
    if(resposta==20){
      al_draw_bitmap(rn, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(rn);
    }
    if(resposta==21){
      al_draw_bitmap(ro, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(ro);
    }
    if(resposta==22){
      al_draw_bitmap(rr, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(rr);
    }
    if(resposta==23){
      al_draw_bitmap(rs, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(rs);
    }
    if(resposta==24){
      al_draw_bitmap(sc, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      i=0;
      resposta=-1;
      al_destroy_bitmap(sc);
    }
    if(resposta==25){
      al_draw_bitmap(se, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(se);
    }
    if(resposta==26){
      al_draw_bitmap(sp, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(sp);
    }
    if(resposta==27){
      al_draw_bitmap(to, 0, 0, 0);
      al_flip_display();  
      al_rest(1.5);
      resposta=-1;
      i=0;
      al_destroy_bitmap(to);
    }
    if(score==5){
      	break;
     }
    
    
  }
  printf("finalizou função\n");
  al_destroy_bitmap(mapa_br);
  al_destroy_bitmap(fundo_jogo);
  fila_eventos=NULL;
  bairros();
  return;

}
