/*
 * gameloop.c
 *
 *  Created on: 30-Sep-2022
 *      Author: fnln
 */

#include "gameloop.h"
#include "stdio.h"
#include "stdlib.h"

bool xor(bool arr[],int n){

	int val = 0;
	for(int i = 0 ; i < n;i++){

		if(arr[i] == true){
			val++;
		}
	}

	if(val > 1 || val == 0){
		return false;
	}

	return true;

}


void gameinstance(){

	player_res res = load_player_res();
	player_state state = player_state_init();

	gameloop(res,state);

	end();

}

void input(player_state *s,Vector2 * playerpos,player_tex *t,Vector2 *worldpos){

	if(IsKeyPressed(KEY_SPACE)){

			if(s->player_is_on_ground){


				if(s->player_is_flipped == 0){t->player_animation_rect.x = 0;}
				else{t->player_animation_rect.x = (7 * 9 * 16 * 4);}

				s->player_is_jumping = 30;

				s->player_is_on_ground = false;

			}else{

				printf("on air");


			}

	}

	if(IsKeyDown(KEY_D)){


		if(playerpos->x < ((screenwidth/2))){
			playerpos->x += s->player_speed;
					s->player_is_idle = 0;
					s->player_is_running = 1;
					s->player_is_flipped = 0;


		}else{

			worldpos->x -= s->player_speed;
			s->player_is_idle = 0;
			s->player_is_running = 1;
			s->player_is_flipped = 0;

		}

	}
	if(IsKeyDown(KEY_A)){

		if(playerpos->x > (screenwidth/3)){
					playerpos->x -= s->player_speed;
							s->player_is_idle = 0;
							s->player_is_running = 1;
							s->player_is_flipped = 1;


		}else{

					worldpos->x += s->player_speed;
					s->player_is_idle = 0;
					s->player_is_running = 1;
					s->player_is_flipped = 1;

		}

	}


}

void playerdraw(player_state *s,player_tex *t,Vector2 *playerpos){

	if(s->player_is_idle && s->player_is_flipped && !s->player_is_jumping && s->player_is_on_ground){
		DrawTextureRec(t->player_idle_flipped_tx, t->player_animation_rect, *playerpos, WHITE);
	}
	else if(s->player_is_running && !s->player_is_flipped && !s->player_is_idle && !s->player_is_jumping && s->player_is_on_ground){
			DrawTextureRec(t->player_running_tx, t->player_animation_rect, *playerpos, WHITE);
	}
	else if(s->player_is_running && s->player_is_flipped && !s->player_is_idle && !s->player_is_jumping && s->player_is_on_ground){
			DrawTextureRec(t->player_running_flipped_tx, t->player_animation_rect, *playerpos, WHITE);



	}else if(/*!s->player_is_running && */!s->player_is_flipped && /*!s->player_is_idle &&*/ s->player_is_jumping > 0 ){
			DrawTextureRec(t->player_jumping_tx, t->player_animation_rect, *playerpos, WHITE);
	}
	else if(/*!s->player_is_running && */s->player_is_flipped && /*!s->player_is_idle && */s->player_is_jumping > 0){
			DrawTextureRec(t->player_jumping_flipped_tx, t->player_animation_rect, *playerpos, WHITE);
	}else if(s->player_is_idle && !s->player_is_flipped && !s->player_is_jumping && s->player_is_on_ground){

			DrawTextureRec(t->player_idle_tx, t->player_animation_rect, *playerpos, WHITE);
	}else if(!s->player_is_on_ground && !s->player_is_flipped && !s->player_is_jumping){

			DrawTextureRec(t->player_falling_tx,t->player_animation_rect, *playerpos, WHITE);
	}else if(!s->player_is_on_ground && s->player_is_flipped && !s->player_is_jumping){

		DrawTextureRec(t->Player_falling_flipped_tx,t->player_animation_rect, *playerpos, WHITE);
	}





}


void gameloop(player_res r,player_state s){

	InitWindow(screenwidth,screenheight,"game");

	SetTargetFPS(60);

	Image world = LoadImage("res/example.png");


	ImageResizeNN(&world, world.width*4,world.height*4);

	Texture2D world_tex = LoadTextureFromImage(world);

	Vector2 worldpos = (Vector2){0,0};




	Image world1 = LoadImage("res/background_0.png");



	ImageResizeNN(&world1, world1.width*8,world1.height*8);

	Texture2D world_tex1 = LoadTextureFromImage(world1);


	Image world2 = LoadImage("res/background_1.png");


	ImageResizeNN(&world2, world2.width*8,world2.height*8);

	Texture2D world_tex2 = LoadTextureFromImage(world2);



	Image world3 = LoadImage("res/background_2.png");


	ImageResizeNN(&world3, world3.width*8,world3.height*8);

	Texture2D world_tex3 = LoadTextureFromImage(world3);




	player_tex t = load_player_tex(&r);

	int everyseven = 0;

	int everythree = 0;

	Vector2 playerpos = (Vector2){(1280/2),(720/2)};


	while(!WindowShouldClose()){


		Rectangle floor_rec1 = (Rectangle){worldpos.x,worldpos.y+(14*4*16),(23*4*16),(2*4*16)};
		Rectangle floor_rec2 = (Rectangle){worldpos.x + (24*4*16),worldpos.y +(13*4*16),(5*4*16),(4*16)};
		Rectangle floor_rec3 = (Rectangle){worldpos.x +(29*4*16),worldpos.y+(11*4*16),(5*4*16),(4*16)};
		Rectangle floor_rec4 = (Rectangle){worldpos.x + (30*4*16),worldpos.y +(14*4*16),(11*4*16),(4*2*16)};

		bool arr[4];
		/*
		 *
		 * Updates every 7 frames
		 *
		 *
		 */

		if(everyseven == 7){

			everyseven = 0;






		}


		Rectangle player_rec = (Rectangle){playerpos.x+(16*4),playerpos.y,(16*4),(32*4)};
		//Rectangle player_right_rec = (Rectangle){playerpos.x,playerpos.y,(16*4),(32*2)};
		//Rectangle player_left_rec = (Rectangle){playerpos.x+(16*8),playerpos.y,(16*4),(32*2)};

		/*
		 *
		 *
		 * updates every three frames
		 *
		 *
		 */

		if(everythree == 5){

			if(s.player_is_flipped == 1){

				t.player_animation_rect.x = t.player_animation_rect.x - (16*3*4);

			}else if(s.player_is_flipped == 0){

				t.player_animation_rect.x = t.player_animation_rect.x + (16*3*4);
			}

					s.player_is_idle = 1;
					s.player_is_running = 0;

			everythree = 0;


		}


		/*
		 *
		 * updaters end here
		 *
		 */

		if(s.player_is_jumping > 0){
			s.player_is_jumping--;

		}

		if(s.player_is_jumping > 0){

			playerpos.y -= 5;
		}

		bool bol1 = CheckCollisionRecs(player_rec, floor_rec1);
		bool bol2 = CheckCollisionRecs(player_rec, floor_rec2);

		bool bol3 = CheckCollisionRecs(player_rec, floor_rec3);
		bool bol4 = CheckCollisionRecs(player_rec, floor_rec4);

		arr[0] = bol1;
		arr[1] = bol2;
		arr[2] = bol3;
		arr[3] = bol4;

//		bool bol3 = CheckCollisionRecs(player_left_rec, floor_rec1);
//		bool bol4 = CheckCollisionRecs(player_right_rec, floor_rec1);

//		bool bol5 = CheckCollisionRecs(player_left_rec, floor_rec2);
//		bool bol6 = CheckCollisionRecs(player_right_rec, floor_rec2);
//
//		bool bol9 = CheckCollisionRecs(player_left_rec, floor_rec3);
//		bool bol10 = CheckCollisionRecs(player_right_rec, floor_rec3);

//		bool bol11 = CheckCollisionRecs(player_left_rec, floor_rec4);
//		bool bol12 = CheckCollisionRecs(player_right_rec, floor_rec4);

		if(xor(arr,4)){
			s.player_is_on_ground = true;
		}else{
			s.player_is_on_ground = false;
		}

//		if(s.player_is_flipped){
//			if(bol3 || bol5 || bol9 || bol10 ){
//				s.player_speed = 0;
//			}
//		}else if (!s.player_is_flipped){
//
//			if(bol4 ||bol6 || bol11 || bol12 ){
//				s.player_speed = 0;
//			}
//		}



		if(s.player_is_jumping == 0){

		if(s.player_is_on_ground == true){
			//printf("collided");
			s.player_gravity = 0;

		}else{
			s.player_gravity = 7;

		}

		}


		playerpos.y += s.player_gravity;

		input(&s, &playerpos,&t,&worldpos);


		BeginDrawing();

		ClearBackground(WHITE);

		DrawTexture(world_tex1, 0, 0, WHITE);
		DrawTexture(world_tex2, 0, 0, WHITE);
		DrawTexture(world_tex3, worldpos.x, worldpos.y, WHITE);
		DrawTexture(world_tex, worldpos.x, worldpos.y, WHITE);
		//DrawRectangleRec(floor_rec1, (Color){255,0,0,150});
		//DrawRectangleRec(floor_rec2, (Color){255,0,0,150});

//		if(playerpos.y > 720){
//
//			DrawText("GIT GUD SCRUB", 1280/3, 720/3,100, RED);
//
//			if(IsKeyPressed(KEY_ENTER)){
//				CloseWindow();
//
//
//			}
//		}

		playerdraw(&s, &t, &playerpos);


		printf("fps : %d \n ",GetFPS());

		EndDrawing();

		everyseven++;
		everythree++;

	}

}


void end(){

	CloseWindow();

}




