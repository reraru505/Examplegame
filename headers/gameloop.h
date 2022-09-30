/*
 * gameloop.h
 *
 *  Created on: 30-Sep-2022
 *      Author: fnln
 */
#pragma once

#include <raylib.h>
#include "player.h"

#define screenwidth 1920
#define screenheight 1080

void gameinstance();

void gameloop(player_res r,player_state s);

void end();
