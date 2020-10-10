//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_integrator.h
//
// Code generated for Simulink model 'ghost_integrator'.
//
// Model version                  : 2.46
// Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
// C/C++ source code generated on : Fri Oct  9 19:37:19 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_ghost_integrator_h_
#define RTW_HEADER_ghost_integrator_h_
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "slros_initialize.h"
#include "ghost_integrator_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_ghost_integrator_geometry_msgs_TwistStamped In1;// '<S4>/In1'
  SL_Bus_ghost_integrator_geometry_msgs_TwistStamped b_varargout_2;
  SL_Bus_ghost_integrator_geometry_msgs_PointStamped In1_f;// '<S11>/In1'
  SL_Bus_ghost_integrator_geometry_msgs_PointStamped In1_b;// '<S10>/In1'
  SL_Bus_ghost_integrator_geometry_msgs_PointStamped BusAssignment;// '<S2>/Bus Assignment' 
  char_T b_zeroDelimTopic[21];
  real_T Adjustment;                   // '<S3>/Chart'
  uint8_T reset;                       // '<S3>/Chart'
} B_ghost_integrator_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slroscpp_internal_block_S_T obj; // '<S9>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S8>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_d;// '<S1>/SourceBlock'
  ros_slroscpp_internal_block_P_T obj_ge;// '<S6>/SinkBlock'
  real_T DiscreteTimeIntegrator_DSTATE;// '<S2>/Discrete-Time Integrator'
  real_T DiscreteTimeIntegrator_PREV_U;// '<S2>/Discrete-Time Integrator'
  uint32_T previousTicks;              // '<S3>/Chart'
  uint32_T Subsystem_PREV_T;           // '<Root>/Subsystem'
  uint16_T temporalCounter_i1;         // '<S3>/Chart'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<S2>/Discrete-Time Integrator'
  uint8_T is_active_c3_ghost_integrator;// '<S3>/Chart'
  uint8_T is_c3_ghost_integrator;      // '<S3>/Chart'
  uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<S2>/Discrete-Time Integrator'
  boolean_T Subsystem_RESET_ELAPS_T;   // '<Root>/Subsystem'
} DW_ghost_integrator_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState Subsystem2_Trig_ZCE;      // '<Root>/Subsystem2'
  ZCSigState Subsystem_Trig_ZCE;       // '<Root>/Subsystem'
} PrevZCX_ghost_integrator_T;

// Parameters (default storage)
struct P_ghost_integrator_T_ {
  SL_Bus_ghost_integrator_geometry_msgs_TwistStamped Out1_Y0;// Computed Parameter: Out1_Y0
                                                                //  Referenced by: '<S4>/Out1'

  SL_Bus_ghost_integrator_geometry_msgs_TwistStamped Constant_Value;// Computed Parameter: Constant_Value
                                                                      //  Referenced by: '<S1>/Constant'

  SL_Bus_ghost_integrator_geometry_msgs_PointStamped Constant_Value_m;// Computed Parameter: Constant_Value_m
                                                                      //  Referenced by: '<S5>/Constant'

  SL_Bus_ghost_integrator_geometry_msgs_PointStamped Out1_Y0_i;// Computed Parameter: Out1_Y0_i
                                                                  //  Referenced by: '<S10>/Out1'

  SL_Bus_ghost_integrator_geometry_msgs_PointStamped Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                      //  Referenced by: '<S8>/Constant'

  SL_Bus_ghost_integrator_geometry_msgs_PointStamped Out1_Y0_n;// Computed Parameter: Out1_Y0_n
                                                                  //  Referenced by: '<S11>/Out1'

  SL_Bus_ghost_integrator_geometry_msgs_PointStamped Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                                      //  Referenced by: '<S9>/Constant'

  real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<S2>/Discrete-Time Integrator'

};

// Real-time Model Data Structure
struct tag_RTM_ghost_integrator_T {
  const char_T *errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_ghost_integrator_T ghost_integrator_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_ghost_integrator_T ghost_integrator_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_ghost_integrator_T ghost_integrator_DW;

// Zero-crossing (trigger) state
extern PrevZCX_ghost_integrator_T ghost_integrator_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void ghost_integrator_initialize(void);
  extern void ghost_integrator_step(void);
  extern void ghost_integrator_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_ghost_integrator_T *const ghost_integrator_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Scope' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'ghost_integrator'
//  '<S1>'   : 'ghost_integrator/Subscribe'
//  '<S2>'   : 'ghost_integrator/Subsystem'
//  '<S3>'   : 'ghost_integrator/Subsystem2'
//  '<S4>'   : 'ghost_integrator/Subscribe/Enabled Subsystem'
//  '<S5>'   : 'ghost_integrator/Subsystem/Blank Message'
//  '<S6>'   : 'ghost_integrator/Subsystem/Publish'
//  '<S7>'   : 'ghost_integrator/Subsystem2/Chart'
//  '<S8>'   : 'ghost_integrator/Subsystem2/ego'
//  '<S9>'   : 'ghost_integrator/Subsystem2/ghost'
//  '<S10>'  : 'ghost_integrator/Subsystem2/ego/Enabled Subsystem'
//  '<S11>'  : 'ghost_integrator/Subsystem2/ghost/Enabled Subsystem'

#endif                                 // RTW_HEADER_ghost_integrator_h_

//
// File trailer for generated code.
//
// [EOF]
//
