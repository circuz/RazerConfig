#include "../input_example.h"
#include <time.h>
#include <stdlib.h>

#define keys_max 20
int keys_history_index = 0;
int keys_history[keys_max];//ring buffer
int running = 1;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"

int rand_span(int span)
{
	double rand_dbl = ((double) rand()) / RAND_MAX - 0.5; 
	int rand_int = (int) (rand_dbl * span);
	return rand_int;
}

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
	int r = 0, g = 0, b = 0;
	int count = 1;
	int count_dir =1;
	int x,y;
	int mod = 1;
	struct razer_rgb col;
	struct razer_pos pos;
	col.r = 0;
	col.g = 255;
	col.b = 0;
	while(running)
	{

	r += rand_span(20);
	if(r < 0)
		r = 0;
	else if(r > 255)
		r = 255;	

	g += rand_span(20);
	if(g < 0)
		g = 0;
	else if(g > 255)
		g = 255;	

	b += rand_span(20);
	if(b < 0)
		b = 0;
	else if(b > 255)
		b = 255;	

	for(x=0;x<22;x++)
		{
			for(y=0;y<6;y++)
			{	
				
				chroma->keys->rows[y].column[x].r = (unsigned char)r;
				chroma->keys->rows[y].column[x].g = (unsigned char)g;
				chroma->keys->rows[y].column[x].b = (unsigned char)b;
				chroma->keys->update_mask |= 1<<y;
			}
		}

		col.g -= mod;
		col.b += mod;
		if(g == 1)
			mod *= -1;


		for(int i=0;i<keys_max;i++)
			if(keys_history[i]!=-1)
			{
				
				razer_convert_keycode_to_pos(keys_history[i],&pos);							
				razer_set_key_pos(chroma->keys,&pos,&col);
			}
		razer_update_keys(chroma,chroma->keys);
		count+=count_dir;
		if(count<=0 || count>50)
		{
			count_dir=-count_dir;
		}
		razer_update(chroma);
		razer_frame_limiter(chroma,13);
	}
}

#pragma GCC diagnostic pop

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

void stop(int sig)
{
	#ifdef USE_DEBUGGING
		printf("Stopping input example\n");
	#endif
	running = 0;
}

int input_handler(struct razer_chroma *chroma, int keycode,int pressed)
{
	#ifdef USE_DEBUGGING
		printf("input_handler called\n");
	#endif
	if(!pressed)
		return(1);
	keys_history[keys_history_index++] = keycode;
	if(keys_history_index==keys_max)
		keys_history_index = 0;
	return(1);
}

int main(int argc,char *argv[])
{
	uid_t uid = getuid();
	if(uid != 0)
		printf("input example needs root to work correctly.\n");	
	struct razer_chroma *chroma = razer_open();
	if(!chroma)
		exit(1);
 	razer_set_input_handler(chroma,input_handler);
 	razer_set_custom_mode(chroma);
	razer_clear_all(chroma->keys);
	razer_update_keys(chroma,chroma->keys);
	for(int i=0;i<10;i++)
		keys_history[i] = -1;
 	signal(SIGINT,stop);
 	signal(SIGKILL,stop);
 	signal(SIGTERM,stop);	
	effect(chroma);
 	razer_close(chroma);
}

#pragma GCC diagnostic pop
