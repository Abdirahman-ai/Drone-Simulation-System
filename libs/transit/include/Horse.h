#ifndef CSCI_3081W_F22_AHME0313_LAB10_TEAM_010_31_LAB10_LIBS_TRANSIT_INCLUDE_HORSE_H_
#define CSCI_3081W_F22_AHME0313_LAB10_TEAM_010_31_LAB10_LIBS_TRANSIT_INCLUDE_HORSE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief A class built to represents a horse in a physical system.
 * horse move using euler integration based on a specified velocity and
 *direction.
 **/
class Horse : public IEntity {
 public:
  /**
   * @brief constructor.
   **/
  Horse(JsonObject& obj);
  /**
   * @brief destructor.
   *
   **/
  ~Horse();
  /**
   * @brief Get the speed
   *
   * @return returns current speed
   *
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the horse position
   *
   * @return returns the horse current position
   **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the horse's direction
   * @return returns the horse's direction
   **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the horse's destination
   *
   * @return returns the horse's destination
   **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the horse's details
   *
   * @return returns the details of the horse
   **/
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Updates the horse's position
   *
   * @param dt delta time
   * @param scheduler scheduler
   * @return returns nothing
   **/
  void Update(double dt, std::vector<IEntity*> scheduler);

  /**
   * @brief sets the the horse's position
   *
   * @param pos_ the position of the horse
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the horse's direction
   *
   * @param dir_ set direction
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the horse's destination
   *
   * @param des_ set destination
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Removing the copy constructor and assignment operator
   * so that cars cannot be coppied.
   * @param horse horse
   * @param horse horse
   **/
  Horse(const Horse& horse) = delete;  // idk if these two are necessary
  Horse& operator=(const Horse& horse) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  IStrategy* toDestStrategy = NULL;
  bool done = false;
};

#endif  // CSCI_3081W_F22_AHME0313_LAB10_TEAM_010_31_LAB10_LIBS_TRANSIT_INCLUDE_HORSE_H_
