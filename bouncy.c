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
	struct razer_pos pos;
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
	pos.x = 10;
	pos.y = 3;
	logopos.x = 20;
	logopos.y = 0;
	int cmod = 20;

	pos1 = pos;
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
		pos.x += xmod;
		pos.y += ymod;


		pos9 = pos8;
		pos8 = pos7;
		pos7 = pos6;
		pos6 = pos5;
		pos5 = pos4;
		pos4 = pos3;
		pos3 = pos2;
		pos2 = pos1;
		pos1 = pos;
		
		if(pos.x >= 28 || pos.x < 1)
			pos.x = 0;
		if(pos.y >= 5 || pos.y < 1)
			ymod *= -1;
	
		razer_clear_all(chroma->keys);

			for(c = 0; c < 6; c++){
			
			//pos.y = c;

			razer_set_key_pos(chroma->keys,&pos,&col);
			

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
		}

		razer_set_key_pos(chroma->keys,&logopos,&col);

		razer_update_keys(chroma,chroma->keys);

		wait_for(0.05);	
	}
	/*
	while(1)
	{	

		chroma->keys->rows[3].column[4].r = (unsigned char)255;
		chroma->keys->rows[3].column[4].g = (unsigned char)0;
		chroma->keys->rows[3].column[4].b = (unsigned char)0;
		chroma->keys->update_mask |= 1<<y;			

		int x = 0;
		int y = 0;
		while(x > 0 && x < 22){
			while(y > 0 && y < 6){
				chroma->keys->rows[y].column[x].r = (unsigned char)255;
				chroma->keys->rows[y].column[x].g = (unsigned char)0;
				chroma->keys->rows[y].column[x].b = (unsigned char)0;
				chroma->keys->update_mask |= 1<<y;			
				y += ymod;
			}
			ymod *= -1;
		x += xmod;
		xmod *= -1;
		}
		razer_update_keys(chroma,chroma->keys);
		count+=count_dir;
		if(count<=0 || count>=44)
			count_dir=-count_dir;
		usleep(60000);
	}*/
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
