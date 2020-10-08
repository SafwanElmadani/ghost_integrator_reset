#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ghost_integrator";

// For Block ghost_integrator/Subscribe
SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_ghost_integrator_geometry_msgs_TwistStamped> Sub_ghost_integrator_3;

// For Block ghost_integrator/Subsystem2/ego
SimulinkSubscriber<geometry_msgs::PointStamped, SL_Bus_ghost_integrator_geometry_msgs_PointStamped> Sub_ghost_integrator_36;

// For Block ghost_integrator/Subsystem2/ghost
SimulinkSubscriber<geometry_msgs::PointStamped, SL_Bus_ghost_integrator_geometry_msgs_PointStamped> Sub_ghost_integrator_37;

// For Block ghost_integrator/Subsystem/Publish
SimulinkPublisher<geometry_msgs::PointStamped, SL_Bus_ghost_integrator_geometry_msgs_PointStamped> Pub_ghost_integrator_26;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

