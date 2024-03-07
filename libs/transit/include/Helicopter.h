#ifndef CSCI_3081W_F22_AHME0313_LAB10_TEAM_010_31_LAB10_LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
#define CSCI_3081W_F22_AHME0313_LAB10_TEAM_010_31_LAB10_LIBS_TRANSIT_INCLUDE_HELICOPTER_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief A class built to  represents a helicopter in a physical  system.
 * Helicopter move using euler integration based on a specified velocity and
 *direction.
 **/
class Helicopter : public IEntity {
 public:
  /**
   * @brief constructor.
   **/
  Helicopter(JsonObject& obj);
  /**
   * @brief destructor.
   **/
  ~Helicopter();

  /**
   * @brief Get the speed
   *
   * @return returns current speed
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the helicopter position
   *
   * @return returns the helicopter current position
   **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the helicopter's direction
   *
   * @return returns the helicopter's direction
   **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the helicopter's destination
   *
   * @return returns the helicopter's destination
   **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the helicopter's details
   *
   * @return returns the details of the helicopter
   **/
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Updates the helicopter's position
   *
   * @param dt delta time
   * @param scheduler scheduler
   * @return returns nothing
   **/
  void Update(double dt,
              std::vector<IEntity*> scheduler);  // not sure about this one

  /**
   * @brief sets the the helicopter's position
   *
   * @param pos_ the position of the helicopter
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the helicopter's direction
   *
   * @param dir_ set direction
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the helicopter's destination
   *
   * @param des_ set destination
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Removing the copy constructor and assignment operator
   * so that helicopter cannot be coppied.
   * @param helicopter helicopter
   * @param helicopter helicopter
   **/
  Helicopter(const Helicopter& helicopter) =
      delete;  // idk if these two are necessary
  Helicopter& operator=(const Helicopter& helicopter) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  IStrategy* toDestStrategy = NULL;
  bool done = false;
};

#endif  // CSCI_3081W_F22_AHME0313_LAB10_TEAM_010_31_LAB10_LIBS_TRANSIT_INCLUDE_HELICOPTER_H_
