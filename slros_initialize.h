#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ghost_integrator/Subscribe
extern SimulinkSubscriber<geometry_msgs::TwistStamped, SL_Bus_ghost_integrator_geometry_msgs_TwistStamped> Sub_ghost_integrator_3;

// For Block ghost_integrator/Subsystem2/ego
extern SimulinkSubscriber<geometry_msgs::PointStamped, SL_Bus_ghost_integrator_geometry_msgs_PointStamped> Sub_ghost_integrator_36;

// For Block ghost_integrator/Subsystem2/ghost
extern SimulinkSubscriber<geometry_msgs::PointStamped, SL_Bus_ghost_integrator_geometry_msgs_PointStamped> Sub_ghost_integrator_37;

// For Block ghost_integrator/Subsystem/Publish
extern SimulinkPublisher<geometry_msgs::PointStamped, SL_Bus_ghost_integrator_geometry_msgs_PointStamped> Pub_ghost_integrator_26;

void slros_node_init(int argc, char** argv);

#endif
