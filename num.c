#include "../example1.h"
#include <time.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"


void wait_for(double secs) {
	clock_t start_time = clock();
	double sec_diff = 0;

	while(sec_diff < secs) {
		clock_t now_time = clock();
		sec_diff = ((double) (now_time - start_time)) / CLOCKS_PER_SEC;
	}
}

void draw_bg(struct razer_chroma *chroma){
	struct	razer_pos pos;
	struct	razer_rgb colbg = {.r=0,.g=0,.b=0};

	for(int x = 18; x < 22; x++){
		for(int y = 1; y < 6; y++){
			pos.x = x;
			pos.y = y;
			razer_set_key_pos(chroma->keys,&pos,&colbg);
		}
	}
}

void draw_num(struct razer_chroma *chroma, int num){

	struct razer_rgb col = {.r=50,.g=50,.b=50};
	struct razer_pos pos0;
	struct razer_pos pos1;
	struct razer_pos pos2;
	struct razer_pos pos3;
	struct razer_pos pos4;
	struct razer_pos pos5;
	struct razer_pos pos6;
	struct razer_pos pos7;
	struct razer_pos pos8;
	struct razer_pos pos9;
	struct razer_pos pos10;
	struct razer_pos pos11;
	struct razer_pos pos12;
	struct razer_pos pos13;

	razer_convert_ascii_to_pos('1',&pos0);
	pos0.x += 16;
	pos1 = pos0;
	pos1.x += 1;
	pos2 = pos1;
	pos2.x += 1;
	pos3 = pos2;
	pos3.y += 1;
	pos4 = pos3;
	pos4.y += 1;
	pos5 = pos4;
	pos5.y += 1;
	pos6 = pos5;
	pos6.y += 1;
	pos7 = pos6;
	pos7.x -= 1;
	pos8 = pos7;
	pos8.x -= 1;
	pos9 = pos8;
	pos9.y -= 1;
	pos10 = pos9;
	pos10.y -= 1;
	pos11 = pos10;
	pos11.y -= 1;
	pos12 = pos11;
	pos12.y -= 1;
	pos13 = pos12;
	pos13.y += 2;
	pos13.x += 1;


	if(num == 0 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9)
		razer_set_key_pos(chroma->keys,&pos0,&col);
	if(num == 0 || num == 2 || num == 3 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9)		
		razer_set_key_pos(chroma->keys,&pos1,&col);
	if(num == 0 || num == 1 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9)
		razer_set_key_pos(chroma->keys,&pos2,&col);
	if(num == 0 || num == 1 || num == 2 || num == 3 || num == 4 || num == 7 || num == 8 || num == 9)
		razer_set_key_pos(chroma->keys,&pos3,&col);
	if(num == 0 || num == 1 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9)
		razer_set_key_pos(chroma->keys,&pos4,&col);
	if(num == 0 || num == 1 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9)
		razer_set_key_pos(chroma->keys,&pos5,&col);
	if(num == 0 || num == 1 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9)
		razer_set_key_pos(chroma->keys,&pos6,&col);
	if(num == 0 || num == 2 || num == 3 || num == 5 || num == 6 || num == 8 || num == 9)
		razer_set_key_pos(chroma->keys,&pos7,&col);
	if(num == 0 || num == 2 || num == 3  || num == 5 || num == 6 || num == 8 || num == 9)
		razer_set_key_pos(chroma->keys,&pos8,&col);
	if(num == 0 || num == 2 || num == 6 || num == 8)
		razer_set_key_pos(chroma->keys,&pos9,&col);
	if(num == 0 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 8 || num == 9)
		razer_set_key_pos(chroma->keys,&pos10,&col);
	if(num == 0 || num == 4 || num == 5 || num == 6 || num == 8 || num == 9)
		razer_set_key_pos(chroma->keys,&pos11,&col);
	if(num == 0 || num == 2 || num == 3 || num == 4 || num == 5 || num == 6 || num == 7 || num == 8 || num == 9)
		razer_set_key_pos(chroma->keys,&pos12,&col);
	if(num == 2 || num == 3 || num == 4 || num == 5 || num == 6 ||  num == 8 || num == 9)
		razer_set_key_pos(chroma->keys,&pos13,&col);

}



void effect(struct razer_chroma *chroma)
{


	int c = 0;

	while(1)
	{

		razer_clear_all(chroma->keys);

		if(c > 9)
			c = 0;

		draw_bg(chroma);
		draw_num(chroma, c);

		c++;

		razer_update_keys(chroma,chroma->keys);

		wait_for(1);
	}
}





#pragma GCC diagnostic pop

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

int main(int argc,char *argv[])
{
	struct razer_chroma *chroma = razer_open();
	if(!chroma)
		exit(1);
	razer_set_custom_mode(chroma);
	razer_clear_all(chroma->keys);
	razer_update_keys(chroma,chroma->keys);
	effect(chroma);
 	razer_close(chroma);
}

#pragma GCC diagnostic pop
