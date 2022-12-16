#ifndef LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
#define LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_

#include "IController.h"
#include "CompositeFactory.h"
#include "IEntity.h"
#include "graph.h"
using namespace routing;

//--------------------  Model ----------------------------

/// Simulation Model handling the transit simulation.  The model can communicate
/// with the controller.
/**
 * @brief This class handles the transit simulation
 */
class SimulationModel {
 public:
  /**
   * @brief constructor
   * @param controller Controller
   */
  // controller cannot be constant--leads to errors if made constant
  SimulationModel(IController& controller);
  /**
   * @brief Initializes the graph
   * @param graph to be initialized
   */
  void SetGraph(const IGraph* graph) { this->graph = graph; }
  /**
   * @brief Creates an simulation entity
   * @param entity
   */
  void CreateEntity(const JsonObject& entity);
  /**
   * @brief Schedules a trip for an object in the scene
   * @param details
   */
  void ScheduleTrip(const JsonObject& details);
  /**
   * @brief Updates the simulation
   * @param dt
   */
  void Update(double dt);
  /**
   * @brief Adds a new entity type
   * @param factory
   */
  void AddFactory(IEntityFactory* factory);

 protected:
  IController& controller;
  std::vector<IEntity*> entities;
  std::vector<IEntity*> scheduler;
  std::vector<IEntity*> stations;
  const IGraph* graph;
  CompositeFactory* compFactory;
};

#endif  // LIBS_TRANSIT_INCLUDE_SIMULATIONMODEL_H_
