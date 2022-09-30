/*
 * player.c
 *
 *  Created on: 30-Sep-2022
 *      Author: fnln
 */

#include "player.h"

void load_Player_is_idle(player_res* res){

	res->player_idle = LoadImage("res/playerbasic.png");

	ImageCrop(&res->player_idle, (Rectangle){0,0,(16*12),(16*2)});

	ImageResizeNN(&res->player_idle,(16*12*4),(16*2*4));

}

void load_Player_is_idle_flipped(player_res* res){

	res->player_idle_flipped = LoadImage("res/playerbasic.png");

	ImageCrop(&res->player_idle_flipped, (Rectangle){0,0,(16*12),(16*2)});

	ImageFlipHorizontal(&res->player_idle_flipped);

	ImageResizeNN(&res->player_idle_flipped,(16*12*4),(16*2*4));
}

void load_Player_is_running(player_res* res){

	res->player_running = LoadImage("res/playerbasic.png");

	ImageCrop(&res->player_running,(Rectangle){0,32,(16*15),(16*2)});

	ImageResizeNN(&res->player_running,(16*15*4),(16*2*4));
}

void load_Player_is_running_flipped(player_res* res){

	res->player_running_flipped = LoadImage("res/playerbasic.png");

	ImageCrop(&res->player_running_flipped,(Rectangle){0,32,(16*15),(16*2)});

	ImageFlipHorizontal(&res->player_running_flipped);

	ImageResizeNN(&res->player_running_flipped,(16*15*4),(16*2*4));
}

void load_Player_is_jumping(player_res* res){

	res->player_jumping = LoadImage("res/playerbasic.png");

	ImageCrop(&res->player_jumping,(Rectangle){0,64,(16*3*4),(16*2)});

	ImageResizeNN(&res->player_jumping,(16*3*4*4),(16*2*4));
}

void load_Player_is_jumping_flipped(player_res* res){

	res->player_jumping_flipped = LoadImage("res/playerbasic.png");

	ImageCrop(&res->player_jumping_flipped,(Rectangle){0,64,(16*3*4),(16*2)});


	ImageFlipHorizontal(&res->player_jumping_flipped);

	ImageResizeNN(&res->player_jumping_flipped,(16*3*4*4),(16*2*4));
}

void load_Player_falling(player_res* res){

	res->player_falling = LoadImage("res/playerbasic.png");

	ImageCrop(&res->player_falling,(Rectangle){16*8*3,64,(16*3),(16*2)});

	ImageResizeNN(&res->player_falling,(16*3*4),(16*2*4));
}
void load_Player_falling_flipped(player_res* res){

	res->player_falling_flipped = LoadImage("res/playerbasic.png");

	ImageCrop(&res->player_falling_flipped,(Rectangle){16*8*3,64,(16*3),(16*2)});


	ImageFlipHorizontal(&res->player_falling_flipped);

	ImageResizeNN(&res->player_falling_flipped,(16*3*4),(16*2*4));
}

player_state player_state_init(){

	player_state * state = (player_state*) malloc(sizeof(player_state));

	state->player_gravity = 0;
	state->player_health = 3;
	state->player_is_flipped = 0;
	state->player_is_idle = 1;
	state->player_speed = 5;
	state->player_is_jumping = 0;
	state->player_is_running = 0;
	state->player_is_on_ground = false;
	return *state;
}
player_res load_player_res(){

	player_res * res = (player_res*) malloc(sizeof(player_res));

	load_Player_is_idle(res);

	load_Player_is_idle_flipped(res);

	load_Player_is_running( res);

	load_Player_is_running_flipped(res);

	load_Player_is_jumping(res);

	load_Player_is_jumping_flipped(res);

	load_Player_falling(res);

	load_Player_falling_flipped(res);



	return *res;


}

player_tex load_player_tex(player_res *res){

	player_tex * tex = (player_tex*) malloc(sizeof(player_tex));

	tex->player_animation_rect = (Rectangle){0,0,(16*3*4),(32*4)};

	tex->player_idle_tx = LoadTextureFromImage(res->player_idle);
	tex->player_idle_flipped_tx = LoadTextureFromImage(res->player_idle_flipped);
	tex->player_running_tx = LoadTextureFromImage(res->player_running);
	tex->player_running_flipped_tx = LoadTextureFromImage(res->player_running_flipped);
	tex->player_jumping_tx = LoadTextureFromImage(res->player_jumping);
	tex->player_jumping_flipped_tx = LoadTextureFromImage(res->player_jumping_flipped);
	tex->player_falling_tx = LoadTextureFromImage(res->player_falling);
	tex->Player_falling_flipped_tx = LoadTextureFromImage(res->player_falling_flipped);

	return *tex;

}




