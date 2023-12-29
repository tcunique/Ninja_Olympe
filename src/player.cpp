#include "../header/player.hpp"
#include "../header/data.hpp"

Player::Player()
{
    // Gère les états
    idle = true;
    jump = false;
    walk_state = false;
    run_state = false;
    attack_1_state = false;
    jump_length = 0;
    isAlive = true;
    isHurt = false;

    // Gère les animations
    idle_count = 1;
    walk_count.x = 1;
    walk_count.y = Dir::Right;
    jump_count = 1;
    run_count = 1;
    attack_1_count = 1;
    hurt_count = 1;
    death_count = 1;

    view.setSize(CONST_VIEW_WIDTH, CONST_VIEW_HEIGHT);
    view.setCenter(x, y);
    view.zoom(2.0f);
}

Player::~Player()
{
}

void Player::move(float movex, float movey)
{
    // MOve les sprites
    spriteIdle.move(movex, movey);
    spriteWalk.move(movex, movey);
    spriteJump.move(movex, movey);
    spriteRun.move(movex, movey);
    spriteAttack_1.move(movex, movey);
    spriteHurt.move(movex, movey);
    spriteDeath.move(movex, movey);

    // Move les hitbox
    hitbox.move(movex, movey);
    arm.move(movex, movey);
    hitboxBody.move(movex, movey);

    // Move la view
    view.move(movex, movey);

    // Move les coordonnées
    setX(getX() + movex);
    setY(getY() + movey);
}

sf::Sprite Player::getSpriteWalk()
{
    return spriteWalk;
}

sf::View Player::getView()
{
    return view;
}

sf::Texture Player::getTextureWalk()
{
    return textureWalk;
}

sf::Sprite Player::getSpriteIdle()
{
    return spriteIdle;
}

sf::Texture Player::getTextureIdle()
{
    return textureIdle;
}

int Player::getJumpLength()
{
    return jump_length;
}

void Player::setJumpLength(int jump_length)
{
    this->jump_length = jump_length;
}

sf::Vector2<unsigned int> Player::getWalkCount()
{
    return walk_count;
}

bool Player::getIdle()
{
    return idle;
}

unsigned int Player::getJumpCount()
{
    return jump_count;
}

bool Player::getJump()
{
    return jump;
}

bool Player::getRun()
{
    return run_state;
}

bool Player::getAttack_1()
{
    return attack_1_state;
}

sf::RectangleShape Player::getHitbox()
{
    return hitbox;
}

void Player::setArmHitboxLength(sf::Vector2f size)
{
    arm.setSize(size);
}

void Player::setArmHitboxPosX(float x)
{
    arm.setPosition(x, arm.getPosition().y);
}

void Player::setArmHitboxPosY(float y)
{
    arm.setPosition(arm.getPosition().x, y);
}

sf::Vector2f Player::getArmHitBoxSize()
{
    return arm.getSize();
}

float Player::getArmHitBoxPosX()
{
    return arm.getPosition().x;
}

float Player::getArmHitBoxPosY()
{
    return arm.getPosition().y;
}

sf::RectangleShape Player::getArmHitBox()
{
    return arm;
}

sf::RectangleShape Player::getHitBoxBody()
{
    return hitboxBody;
}

void Player::setIdle(bool resp)
{
    idle = resp;
}

void Player::setJump(bool resp)
{
    jump = resp;
}

void Player::setJumpCount(unsigned int count)
{
    jump_count = count;
}

void Player::setRun(bool resp)
{
    run_state = resp;
}

void Player::setAttack_1(bool resp)
{
    attack_1_state = resp;
}

void Player::setDirection(Dir direction)
{
    walk_count.y = direction;
}

void Player::setLife(float life)
{
    this->hp = life;
}

void Player::setHurt(bool resp)
{
    isHurt = resp;
}

void Player::setAlive(bool resp)
{
    isAlive = resp;
}

float Player::getLife()
{
    return hp;
}

bool Player::getAlive()
{
    return isAlive;
}

healthBar& Player::getHealthBar()
{
    return healthbar;
}

sf::Sprite Player::animationJump()
{
    if (jump_count * 128 >= textureJump.getSize().x)
    {
        jump_count = 9;
    }
    if (walk_count.y == Dir::Right)
    {
        spriteJump.setTextureRect(sf::IntRect(jump_count * 128, 0, 128, 128));
    } else 
    {
        spriteJump.setTextureRect(sf::IntRect(jump_count * 128, 0, -128, 128));
    }
    jump_count++;
    fpsCount = 0;
    return spriteJump;
}

sf::Sprite Player::animationWalk()
{
    if (walk_count.x * 128 >= textureWalk.getSize().x)
    {
        walk_count.x = 1;
    }

    if (walk_count.y == Dir::Right)
    {
        spriteWalk.setTextureRect(sf::IntRect(walk_count.x * 128, 0, 128, 128));
        spriteIdle.setTextureRect(sf::IntRect(idle_count * 128, 0, 128, 128)); // Permet d'éviter d'avoir des conflits de sens
    } else 
    {
        spriteWalk.setTextureRect(sf::IntRect(walk_count.x * 128, 0, -128, 128));
        spriteIdle.setTextureRect(sf::IntRect(idle_count * 128, 0, -128, 128)); // Pareil, empêche les conflits de sens
    }
    fpsCount = 0;
    walk_count.x++;
    return spriteWalk;
}

sf::Sprite Player::animationIdle()
{
//Respiration
    if (idle_count * 128 >= textureIdle.getSize().x)
    {
        idle_count = 1;
    }
    if (walk_count.y == Dir::Right)
    {
        spriteIdle.setTextureRect(sf::IntRect(idle_count * 128, 0, 128, 128));
    } else 
    {
        spriteIdle.setTextureRect(sf::IntRect(idle_count * 128, 0, -128, 128));
    }
    fpsCount = 0;
    idle_count++;
    return spriteIdle;
}

sf::Sprite Player::animationRun()
{
    if (run_count * 128 >= textureRun.getSize().x)
    {
        run_count = 1;
    }
    if (walk_count.y == Dir::Right)
    {
        spriteRun.setTextureRect(sf::IntRect(run_count * 128, 0, 128, 128));
    } else 
    {
        spriteRun.setTextureRect(sf::IntRect(run_count * 128, 0, -128, 128));
    }
    run_count++;
    fpsCount = 0;
    return spriteRun;
}

sf::Sprite Player::animationAttack_1()
{
    if (attack_1_count * 128 >= textureAttack_1.getSize().x)
    {
        attack_1_count = 1;
        attack_1_state = false;
        setArmHitboxLength(sf::Vector2f(CONST_PLAYER_ARM_WIDTH, CONST_PLAYER_ARM_HEIGHT));
        setArmHitboxPosX(x + 15);
    } else 
    {
        if (walk_count.y == Dir::Right)
        {
            spriteAttack_1.setTextureRect(sf::IntRect(attack_1_count * 128, 0, 128, 128));
        } else 
        {
            spriteAttack_1.setTextureRect(sf::IntRect(attack_1_count * 128, 0, -128, 128));
        }
        attack_1_count++;
        fpsCount = 0;
    }
    return spriteAttack_1;
}

sf::Sprite Player::animationHurt()
{
    if (hurt_count * 128 >= textureHurt.getSize().x)
    {
        hurt_count = 1;
        isHurt = false;
    } else 
    {
        if (walk_count.y == Dir::Right)
        {
            spriteHurt.setTextureRect(sf::IntRect(hurt_count * 128, 0, 128, 128));
        } else 
        {
            spriteHurt.setTextureRect(sf::IntRect(hurt_count * 128, 0, -128, 128));
        }
        hurt_count++;
        fpsCount = 0;
    }
    return spriteHurt;
}

sf::Sprite Player::animationDeath()
{
    if(fpsCount < switchFps)
    {
        fpsCount += 1;
    } 
    if (fpsCount >= switchFps)
    {
        if (death_count * 128 < textureDeath.getSize().x)
        {
            if (walk_count.y == Dir::Right)
            {
                spriteDeath.setTextureRect(sf::IntRect(death_count * 128, 0, 128, 128));
            } else 
            {
                spriteDeath.setTextureRect(sf::IntRect(death_count * 128, 0, -128, 128));
            }
            death_count++;
            fpsCount = 0;
        }
    }
    return spriteDeath;
}


sf::Sprite Player::animation()
{
    if(fpsCount < switchFps)
    {
        fpsCount += 1;
    } 

    // Permet de fixer un fps et que l'image de ne se charge pas tout le temps
    if (fpsCount >= switchFps)
    {
        if (isHurt)
        {
            return animationHurt();
        }
        if (attack_1_state == true)
        {
            return animationAttack_1();
        }
        // Vérifie s'il y a un input ou non, si non on fait l'anim de la respiration
        if (jump == true || (jump == false && onBlock == false))
        {
            return animationJump();
        } else if (idle == false && jump == false && run_state == true)
        {
            return animationRun();
        } else if (idle == false && jump == false && run_state == false)
        {
            return animationWalk();
        } else 
        {
            return animationIdle();
        }
    } else 
    {
        if (isHurt)
        {
            return spriteHurt;
        }
        if (attack_1_state == true)
        {
            return spriteAttack_1;
        }
        if (jump == true || (jump == false && onBlock == false))
        {
            return spriteJump;
        } else if (idle == false && jump == false && run_state == true)
        {
            return spriteRun;
        } else if (idle == false && jump == false && run_state == false)
        {
            return spriteWalk;
        } else 
        {
            return spriteIdle;
        }
    }
}

bool Player::checkAlive()
{
    if (hp <= 0)
    {
        isAlive = false;
        return false;
    } else 
    {
        return true;
    }
}

void Player::displayHealthBar(sf::RenderWindow &window)
{
    // Affichage de la barre de vie
    sf::Vector2f playerPosition = getPos();
    sf::Vector2f healthBarPosition = playerPosition + sf::Vector2f(-CONST_WIDTH/1.9, -CONST_HEIGHT/1.9);

    // Mettre la position de la barre de vie à la position du joueur
    healthbar.setHealthBarPos(healthBarPosition);

    // Affichage de la barre de vie
    window.draw(healthbar.getHealthBarShape());
    // interface.draw(health);
    window.draw(healthbar.getSpriteHealthBar());
}