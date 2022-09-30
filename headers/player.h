/*
 * player.h
 *
 *  Created on: 30-Sep-2022
 *      Author: fnln
 */

#pragma once
#include <raylib.h>
#include <stdlib.h>

typedef struct{

	int player_is_idle;
	int player_is_running;
	int player_is_jumping;
	int player_is_flipped;
	int player_health;
	int player_gravity;
	int player_speed;
	bool player_is_on_ground;

} player_state;

typedef struct{

	Image player_idle;
	Image player_idle_flipped;
	Image player_running;
	Image player_running_flipped;
	Image player_jumping;
	Image player_jumping_flipped;
	Image player_falling;
	Image player_falling_flipped;


}player_res;

typedef struct{

	Texture2D player_idle_tx;
	Texture2D player_idle_flipped_tx;
	Texture2D player_running_tx;
	Texture2D player_running_flipped_tx;
	Texture2D player_jumping_tx;
	Texture2D player_jumping_flipped_tx;
	Texture2D player_falling_tx;
	Texture2D Player_falling_flipped_tx;
	Rectangle player_animation_rect;



}player_tex;

void load_Player_is_idle(player_res* res);

void load_Player_is_idle_flipped(player_res* res);

void load_Player_is_running(player_res* res);

void load_Player_is_running_flipped(player_res* res);

void load_Player_is_jumping(player_res* res);

void load_Player_is_jumping_flipped(player_res* res);




player_state player_state_init();
player_res load_player_res();
player_tex load_player_tex();

