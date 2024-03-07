#define _USE_MATH_DEFINES
#include "Helicopter.h"
#include "BeelineStrategy.h"

#include <cmath>
#include <limits>
#include <cstdlib>

Helicopter::Helicopter(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};

  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];

  //set new destination 
  int x = -1399 + rand() % 2899;
  int z = -799 + rand() % 1599;
  int y = position.y;
  destination = {x, y, z};
}

Helicopter::~Helicopter() {
  // Delete dynamically allocated variables
}

void Helicopter::Update(double dt, std::vector<IEntity*> scheduler) {
  if (toDestStrategy) {
    if (toDestStrategy->IsCompleted()) {
      int x = -1399 + rand() % 2899;
      int z = -799 + rand() % 1599;
      destination = {x, position.y, z};
      done = true; //kind of a hack solution
      //std::cout << "Car reached destination" << std::endl;
      delete toDestStrategy;
      toDestStrategy = new BeelineStrategy(position, destination);
    } else {
      toDestStrategy->Move(this, dt);
    }
  } else {
      toDestStrategy = new BeelineStrategy(position, destination);
    }
}
