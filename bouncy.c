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


void effect(struct razer_chroma *chroma)
{

	struct razer_rgb col;
	col.g = 255;
	col.b = 0;
	col.r = 0;
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
	struct razer_pos logopos;
	int r,g,b,c;
	int ymod = 1;
	int xmod = 1;
	pos0.x = 10;
	pos0.y = 3;
	logopos.x = 20;
	logopos.y = 0;
	int cmod = 20;

	pos1 = pos0;
	pos2 = pos1;
	pos3 = pos2;
	pos4 = pos3;
	pos5 = pos4;
	pos6 = pos5;
	pos7 = pos6;
	pos8 = pos7;
	pos9 = pos8;


	while(1)
	{
		pos0.x += xmod;
		pos0.y += ymod;


		pos9 = pos8;
		pos8 = pos7;
		pos7 = pos6;
		pos6 = pos5;
		pos5 = pos4;
		pos4 = pos3;
		pos3 = pos2;
		pos2 = pos1;
		pos1 = pos0;
		
		if(pos0.x >= 28 || pos0.x < 1)
			pos0.x = 0;
		if(pos0.y >= 5 || pos0.y < 1)
			ymod *= -1;
	
		razer_clear_all(chroma->keys);


		

		razer_set_key_pos(chroma->keys,&pos0,&col);
		col.b += cmod;
		razer_set_key_pos(chroma->keys,&pos1,&col);
		col.b += cmod;
		razer_set_key_pos(chroma->keys,&pos2,&col);
		col.b += cmod;
		razer_set_key_pos(chroma->keys,&pos3,&col);
		col.b += cmod;
		razer_set_key_pos(chroma->keys,&pos4,&col);
		col.b += cmod;
		razer_set_key_pos(chroma->keys,&pos5,&col);
		col.b += cmod;
		razer_set_key_pos(chroma->keys,&pos6,&col);
		col.b += cmod;
		razer_set_key_pos(chroma->keys,&pos7,&col);
		col.b += cmod;
		razer_set_key_pos(chroma->keys,&pos8,&col);
		col.b += cmod;
		razer_set_key_pos(chroma->keys,&pos9,&col);
		col.b -= 9*cmod;
	

		razer_set_key_pos(chroma->keys,&logopos,&col);

		razer_update_keys(chroma,chroma->keys);

		wait_for(0.05);	
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
