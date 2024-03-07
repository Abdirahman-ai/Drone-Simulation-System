#ifndef CSCI_3081W_F22_AHME0313_LAB10_TEAM_010_31_LAB10_LIBS_TRANSIT_INCLUDE_HORSEFACTORY_H_
#define CSCI_3081W_F22_AHME0313_LAB10_TEAM_010_31_LAB10_LIBS_TRANSIT_INCLUDE_HORSEFACTORY_H_

#include <vector>

#include "Horse.h"
#include "IEntity.h"
#include "IEntityFactory.h"

/**
 * @brief A HelicopterFactory inherits  IEntityFactory that uses the Factory
 *design pattern
 **/
class HorseFactory : public IEntityFactory {
 public:
  /**
   * @brief A function that creates an entity of type Helicopter
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif  // CSCI_3081W_F22_AHME0313_LAB10_TEAM_010_31_LAB10_LIBS_TRANSIT_INCLUDE_HORSEFACTORY_H_
