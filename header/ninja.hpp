#pragma once
#include "player.hpp"

// Sprite 

class Ninja : public Player
{
    public:
        Ninja();
        ~Ninja();

        //Getter
        std::string getName();
        bool getIdle();
        sf::RectangleShape getHitbox();
        unsigned int getJumpCount();
        bool getJump();
        bool getRun();
        bool getAttack_1();

        //Setter
        void setIdle(bool resp);
        void setJump(bool resp);
        void setJumpCount(unsigned int count);
        void setRun(bool resp);
        void setAttack_1(bool resp);

        // Animation
        sf::Sprite animation();
        sf::Sprite animationWalk();
        sf::Sprite animationJump();
        sf::Sprite animationIdle();
        sf::Sprite animationRun();
        sf::Sprite animationAttack_1();

        // Init sprite
        void spriteLaunch();
        void spriteWalkL();
        void spriteIdleL();
        void spriteJumpL();
        void spriteRunL();
        void spriteAttack_1L();

        sf::Vector2<unsigned int> walk;
        enum Dir {Right, Left};

    private :
        std::string name;

        // Direction of animation
        int walk_count;

        // Idle animation
        unsigned int idle_count;

        // Jump animation
        unsigned int jump_count;

        // Run animation
        unsigned int run_count;

        // Attack animation
        unsigned int attack_1_count;

        // state
        bool idle;
        bool jump;
        bool walk_state;
        bool run_state;
        bool attack_1_state;
};