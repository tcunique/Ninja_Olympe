#pragma once
#include <string>
#include <SFML/Graphics.hpp>


// DImension de la fenêtre
const int CONST_WIDTH = 1600;
const int CONST_HEIGHT = 1000;
const std::string CONST_TITLE = "Name Game";

// Dimension de view
const int CONST_VIEW_WIDTH = 1000;
const int CONST_VIEW_HEIGHT = 700;

// Information sur le joueur
const int CONST_PLAYER_SPEED = 4;
const int CONST_PLAYER_RUN = 2;
const float CONST_PLAYER_SIZE = 2.0;
const float CONST_PLAYER_HEALTH = 100;
const int CONST_PLAYER_JUMP = 20;
const int CONST_PLAYER_JUMP_SPEED = 10;
const int CONST_POSITION_X = 100;
const int CONST_POSITION_Y = 100;
const std::string CONST_PLAYER_NAME = "Ninja";
const float CONST_PLAYER_HP = 100;
const float CONST_PLAYER_DAMAGE_ATTACK_1 = 10;
const int CONST_START_PIECE = 0;

// Hitbox Arm Player
const int CONST_PLAYER_ARM_WIDTH = 20;
const int CONST_PLAYER_ARM_HEIGHT = 30;

// const int CONST_JUMP = 100;
// Hitbox
const int CONST_HITBOX_WIDTH = 40;
const int CONST_HITBOX_HEIGHT = 63;

// GRAVITY
const int CONST_GRAVITY = 2;

// Saut 
extern int JUMP_COUNT;

// Block
const int CONST_BLOCK_WIDTH = 1000;
const int CONST_BLOCK_HEIGHT = 100;

// Hit box du sol
const int CONST_GROUND_WIDTH = 4000;
const int CONST_GROUND_HEIGHT = 100;
const int CONST_GROUND_POS_X = 0;
const int CONST_GROUND_POS_Y = 905;

// Information sur l'ennemi
const int CONST_ENNEMY_SPEED = 2;
const int CONST_ENNEMY_RUN = 4;
const float CONST_ENNEMY_SIZE = 2.0;
const float CONST_ENNEMY_HEALTH = 100;
const int CONST_ENNEMY_JUMP = 4;
const int CONST_ENNEMY_POSITION_X = 900;
const int CONST_ENNEMY_POSITION_Y = 100;
const std::string CONST_ENNEMY_NAME = "Ennemy";
const float CONST_ENNEMY_HP = 100;
const float CONST_ENNEMY_DAMAGE_ATTACK_1 = 30;

// attack interval for ennemy
const sf::Time CONST_ATTACK_INTERVAL = sf::seconds(1.0f);

