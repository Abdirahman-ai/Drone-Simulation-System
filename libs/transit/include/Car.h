#ifndef CSCI_3081W_F22_AHME0313_LAB10_TEAM_010_31_LAB10_LIBS_TRANSIT_INCLUDE_CAR_H_
#define CSCI_3081W_F22_AHME0313_LAB10_TEAM_010_31_LAB10_LIBS_TRANSIT_INCLUDE_CAR_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "math/vector3.h"

/**
 * @brief A class built to represents a car in a physical system.
 * car move using euler integration based on a specified velocity and direction.
 **/
class Car : public IEntity {
 public:
  /**
   * @brief constructor.
   **/
  Car(JsonObject& obj);
  /**
   * @brief destructor.
   * 
   **/
  ~Car();

  /**
   * @brief Get the speed
   *
   * @return returns current speed
   * 
   **/
  float GetSpeed() const { return speed; }

  /**
   * @brief Gets the cars position
   *
   * @return returns the cars current position
   **/
  Vector3 GetPosition() const { return position; }

  /**
   * @brief Gets the car's direction
   *
   * @return returns the car's direction
   **/
  Vector3 GetDirection() const { return direction; }

  /**
   * @brief Gets the car's destination
   *
   * @return returns the car's destination
   **/
  Vector3 GetDestination() const { return destination; }

  /**
   * @brief Gets the car's details
   *
   * @return returns the details of the car
   **/
  JsonObject GetDetails() const { return details; }

  /**
   * @brief Updates the cars's position
   *
   * @param dt delta time
   * @param scheduler scheduler
   * @return returns nothing
   **/
  void Update(double dt,
              std::vector<IEntity*> scheduler);  // not sure about this one

  /**
   * @brief sets the the car's position
   *
   * @param pos_ the position of the car
   **/
  void SetPosition(Vector3 pos_) { position = pos_; }

  /**
   * @brief Sets the car's direction
   *
   * @param dir_ set direction
   **/
  void SetDirection(Vector3 dir_) { direction = dir_; }

  /**
   * @brief Sets the car's destination
   *
   * @param des_ set destination
   **/
  void SetDestination(Vector3 des_) { destination = des_; }

  /**
   * @brief Removing the copy constructor and assignment operator
   * so that cars cannot be coppied.
   * @param car car
   * @param car car
   **/
  Car(const Car& car) = delete;  // idk if these two are necessary
  Car& operator=(const Car& car) = delete;

 private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  IStrategy* toDestStrategy = NULL;
  bool done = false;
};

#endif 
