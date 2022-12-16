#ifndef LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_
#define LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_

#include "IEntity.h"
#include "util/json.h"

//--------------------  Controller Interface ----------------------------

/// Abstract controller class used in the Transit Service.  Uses the Model View
/// Controller Pattern
/**
 * @brief This class serves as the controller class used in the Transit Service
 */
class IController {
 public:
    /**
    * @brief virtual destructor
    */
  virtual ~IController() {}
    /**
    * @brief Adds an entity to the program
    * @param entity that needs to be added
    */
  virtual void AddEntity(const IEntity& entity) = 0;
    /**
    * @brief Adds an entity to the program
    * @param entity that needs to be updated
    */
  virtual void UpdateEntity(const IEntity& entity) = 0;
    /**
    * @brief Removes an entity from the program
    * @param id pos of index
    */
  virtual void RemoveEntity(int id) = 0;
    /**
    * @brief Adds a path to the program
    * @param id pos of index path of vector containing float values
    */
  virtual void AddPath(int id,
                       const std::vector<std::vector<float> >& path) = 0;
    /**
    * @brief Removes a path from the program
    * @param id pos of index
    */           
  virtual void RemovePath(int id) = 0;
    /**
    * @brief Allows messages to be passed back to the view
    * @param event that needs to be sent to the view
    * @param details for the object
    */    
  virtual void SendEventToView(const std::string& event,
                               const JsonObject& details) = 0;
};

#endif  // LIBS_TRANSIT_INCLUDE_ICONTROLLER_H_

