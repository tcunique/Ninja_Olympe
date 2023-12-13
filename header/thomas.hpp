#pragma once
#include "player.hpp"

class Thomas : public Player
{
    public:
        Thomas();
        ~Thomas();

        //Getter
        std::string getName();
        bool getIdle();
        sf::RectangleShape getHitbox();

        //Setter
        void setIdle(bool resp);
        void setJump(bool resp);

        // Animation
        sf::Sprite animation();
        sf::Sprite animationWalk();
        sf::Sprite animationJump();
        sf::Sprite animationIdle();

        // Init sprite
        void spriteLaunch();
        void spriteWalkL();
        void spriteIdleL();
        void spriteJumpL();

        sf::Vector2<unsigned int> walk;
        enum Dir {Right, Left};

    private :
        std::string name;

        // Direction of animation
        int walk_count;

        // Idle animation
        unsigned int idle_count;

        // Jump
        unsigned int jump_count;

        // Speed of animation
        sf::Clock clock;
        float fpsCount;
        float switchFps;
        float fpsSpeed;

        // state
        bool idle;
        bool jump;
};