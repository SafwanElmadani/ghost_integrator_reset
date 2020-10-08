//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_integrator_types.h
//
// Code generated for Simulink model 'ghost_integrator'.
//
// Model version                  : 2.45
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Wed Oct  7 22:04:39 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ghost_integrator_types_h_
#define RTW_HEADER_ghost_integrator_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_ros_time_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_ros_time_Time_

// MsgType=ros_time/Time
typedef struct {
  real_T Sec;
  real_T Nsec;
} SL_Bus_ghost_integrator_ros_time_Time;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

typedef struct {
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
} SL_Bus_ROSVariableLengthArrayInfo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_std_msgs_Header_

// MsgType=std_msgs/Header
typedef struct {
  uint32_T Seq;

  // MsgType=ros_time/Time
  SL_Bus_ghost_integrator_ros_time_Time Stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=FrameId_SL_Info:TruncateAction=warn 
  uint8_T FrameId[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=FrameId
  SL_Bus_ROSVariableLengthArrayInfo FrameId_SL_Info;
} SL_Bus_ghost_integrator_std_msgs_Header;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_ghost_integrator_geometry_msgs_Vector3;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
typedef struct {
  // MsgType=geometry_msgs/Vector3
  SL_Bus_ghost_integrator_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_ghost_integrator_geometry_msgs_Vector3 Angular;
} SL_Bus_ghost_integrator_geometry_msgs_Twist;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_geometry_msgs_TwistStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_geometry_msgs_TwistStamped_

// MsgType=geometry_msgs/TwistStamped
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_ghost_integrator_std_msgs_Header Header;

  // MsgType=geometry_msgs/Twist
  SL_Bus_ghost_integrator_geometry_msgs_Twist Twist;
} SL_Bus_ghost_integrator_geometry_msgs_TwistStamped;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
typedef struct {
  real_T X;
  real_T Y;
  real_T Z;
} SL_Bus_ghost_integrator_geometry_msgs_Point;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_geometry_msgs_PointStamped_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ghost_integrator_geometry_msgs_PointStamped_

// MsgType=geometry_msgs/PointStamped
typedef struct {
  // MsgType=std_msgs/Header
  SL_Bus_ghost_integrator_std_msgs_Header Header;

  // MsgType=geometry_msgs/Point
  SL_Bus_ghost_integrator_geometry_msgs_Point Point;
} SL_Bus_ghost_integrator_geometry_msgs_PointStamped;

#endif

#ifndef struct_tag_eFCXAaC7vLdwjksE0MwgOD
#define struct_tag_eFCXAaC7vLdwjksE0MwgOD

struct tag_eFCXAaC7vLdwjksE0MwgOD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_eFCXAaC7vLdwjksE0MwgOD

#ifndef typedef_ros_slroscpp_internal_block_S_T
#define typedef_ros_slroscpp_internal_block_S_T

typedef tag_eFCXAaC7vLdwjksE0MwgOD ros_slroscpp_internal_block_S_T;

#endif                                 //typedef_ros_slroscpp_internal_block_S_T

#ifndef struct_tag_D6QYIVJDjoKN0blLVEpT8F
#define struct_tag_D6QYIVJDjoKN0blLVEpT8F

struct tag_D6QYIVJDjoKN0blLVEpT8F
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 //struct_tag_D6QYIVJDjoKN0blLVEpT8F

#ifndef typedef_ros_slroscpp_internal_block_P_T
#define typedef_ros_slroscpp_internal_block_P_T

typedef tag_D6QYIVJDjoKN0blLVEpT8F ros_slroscpp_internal_block_P_T;

#endif                                 //typedef_ros_slroscpp_internal_block_P_T

// Parameters (default storage)
typedef struct P_ghost_integrator_T_ P_ghost_integrator_T;

// Forward declaration for rtModel
typedef struct tag_RTM_ghost_integrator_T RT_MODEL_ghost_integrator_T;

#endif                                 // RTW_HEADER_ghost_integrator_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
