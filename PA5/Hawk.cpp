#include "Hawk.h"

Hawk::Hawk(Game* game, int player, int position): Animal(game,player,position){
  hp = MAX_HP;
  atk_damage = DEFAULT_ATK_DAMAGE;
  name = "Hawk";
  type = FLYING;

}

Hawk::~Hawk() {
	
}

void Hawk::attack()
{
  if(!enemies[pos]->isDead())
    enemies[pos]->takeDamage(atk_damage);
  else {
    for(int i = 1; i < 5; i++)
      {
	if(pos-i >= 0 && !enemies[pos-i]->isDead())
	  {
	    enemies[pos-i]->takeDamage(atk_damage);
	    break;
	  }
	else if(pos+i < 5 && !enemies[pos+i]->isDead())
	  {
	    enemies[pos+i]->takeDamage(atk_damage);
	    break;
	  }
      }
  }
}

void Hawk::defend(Animal* opponent, int damage) {
  //Hawks only take 70% damage.
  takeDamage(0.7*damage);
  // Deal 1 unblockable damage as revenge
  if (!isDead())
    opponent->takeDamage(1);
}

void Hawk::harass() {
  if(!isDead()) { // Ensure hawk is not dead.
    // Deal 1 unblockable damange to each enemy.
    for (int i = 0; i < 5; ++i)
      enemies[i]->takeDamage(1);
  }
}
