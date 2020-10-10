//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: ghost_integrator.cpp
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
#include "ghost_integrator.h"
#include "ghost_integrator_private.h"

// Named constants for Chart: '<S3>/Chart'
const uint8_T ghost_integrator_IN_catch_up = 1U;
const uint8_T ghost_integrator_IN_idle = 2U;
const uint8_T ghost_integrator_IN_slow_down = 3U;
const uint8_T ghost_integrator_IN_startup = 4U;

// Block signals (default storage)
B_ghost_integrator_T ghost_integrator_B;

// Block states (default storage)
DW_ghost_integrator_T ghost_integrator_DW;

// Previous zero-crossings (trigger) states
PrevZCX_ghost_integrator_T ghost_integrator_PrevZCX;

// Real-time model
RT_MODEL_ghost_integrator_T ghost_integrator_M_ = RT_MODEL_ghost_integrator_T();
RT_MODEL_ghost_integrator_T *const ghost_integrator_M = &ghost_integrator_M_;

// Model step function
void ghost_integrator_step(void)
{
  real_T tmp;
  uint32_T elapsedTicks;
  boolean_T b_varargout_1;
  boolean_T b_varargout_1_0;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S1>/SourceBlock' incorporates:
  //   Inport: '<S10>/In1'
  //   Inport: '<S11>/In1'
  //   Inport: '<S4>/In1'
  //   MATLABSystem: '<S8>/SourceBlock'
  //   MATLABSystem: '<S9>/SourceBlock'

  b_varargout_1 = Sub_ghost_integrator_3.getLatestMessage
    (&ghost_integrator_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S4>/Enable'

  if (b_varargout_1) {
    ghost_integrator_B.In1 = ghost_integrator_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S1>/Enabled Subsystem'

  // Outputs for Triggered SubSystem: '<Root>/Subsystem2' incorporates:
  //   TriggerPort: '<S3>/Trigger'

  if (b_varargout_1 && (ghost_integrator_PrevZCX.Subsystem2_Trig_ZCE !=
                        POS_ZCSIG)) {
    // Outputs for Atomic SubSystem: '<S3>/ego'
    // MATLABSystem: '<S8>/SourceBlock'
    b_varargout_1_0 = Sub_ghost_integrator_36.getLatestMessage
      (&ghost_integrator_B.BusAssignment);

    // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S10>/Enable'

    if (b_varargout_1_0) {
      ghost_integrator_B.In1_b = ghost_integrator_B.BusAssignment;
    }

    // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S3>/ego'

    // Outputs for Atomic SubSystem: '<S3>/ghost'
    // MATLABSystem: '<S9>/SourceBlock' incorporates:
    //   Inport: '<S10>/In1'
    //   MATLABSystem: '<S8>/SourceBlock'

    b_varargout_1_0 = Sub_ghost_integrator_37.getLatestMessage
      (&ghost_integrator_B.BusAssignment);

    // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S11>/Enable'

    if (b_varargout_1_0) {
      ghost_integrator_B.In1_f = ghost_integrator_B.BusAssignment;
    }

    // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<S3>/ghost'

    // Chart: '<S3>/Chart' incorporates:
    //   Inport: '<S11>/In1'
    //   MATLABSystem: '<S9>/SourceBlock'
    //   SignalConversion generated from: '<S3>/Bus Selector1'
    //   SignalConversion generated from: '<S3>/Bus Selector'

    elapsedTicks = ghost_integrator_M->Timing.clockTick0 -
      ghost_integrator_DW.previousTicks;
    ghost_integrator_DW.previousTicks = ghost_integrator_M->Timing.clockTick0;
    if (ghost_integrator_DW.temporalCounter_i1 + elapsedTicks <= 2047U) {
      ghost_integrator_DW.temporalCounter_i1 = static_cast<uint16_T>
        (ghost_integrator_DW.temporalCounter_i1 + elapsedTicks);
    } else {
      ghost_integrator_DW.temporalCounter_i1 = 2047U;
    }

    if (ghost_integrator_DW.is_active_c3_ghost_integrator == 0U) {
      ghost_integrator_DW.is_active_c3_ghost_integrator = 1U;
      ghost_integrator_DW.is_c3_ghost_integrator = ghost_integrator_IN_startup;
      ghost_integrator_B.Adjustment = 0.0;
    } else {
      switch (ghost_integrator_DW.is_c3_ghost_integrator) {
       case ghost_integrator_IN_catch_up:
        ghost_integrator_B.reset = 0U;
        ghost_integrator_DW.is_c3_ghost_integrator = ghost_integrator_IN_idle;
        ghost_integrator_DW.temporalCounter_i1 = 0U;
        break;

       case ghost_integrator_IN_idle:
        tmp = ghost_integrator_B.In1_f.Point.X -
          ghost_integrator_B.In1_b.Point.X;
        if ((ghost_integrator_DW.temporalCounter_i1 >= 1500U) && (tmp > 100.0))
        {
          ghost_integrator_DW.is_c3_ghost_integrator =
            ghost_integrator_IN_catch_up;
          ghost_integrator_B.Adjustment = ghost_integrator_B.In1_b.Point.X;
          ghost_integrator_B.reset = 1U;
        } else {
          if ((ghost_integrator_DW.temporalCounter_i1 >= 1500U) && (tmp < -30.0))
          {
            ghost_integrator_DW.is_c3_ghost_integrator =
              ghost_integrator_IN_slow_down;
            ghost_integrator_B.Adjustment = ghost_integrator_B.In1_b.Point.X;
            ghost_integrator_B.reset = 1U;
          }
        }
        break;

       case ghost_integrator_IN_slow_down:
        ghost_integrator_B.reset = 0U;
        ghost_integrator_DW.is_c3_ghost_integrator = ghost_integrator_IN_idle;
        ghost_integrator_DW.temporalCounter_i1 = 0U;
        break;

       default:
        // case IN_startup:
        ghost_integrator_DW.is_c3_ghost_integrator = ghost_integrator_IN_idle;
        ghost_integrator_DW.temporalCounter_i1 = 0U;
        break;
      }
    }

    // End of Chart: '<S3>/Chart'
  }

  ghost_integrator_PrevZCX.Subsystem2_Trig_ZCE = b_varargout_1;

  // End of Outputs for SubSystem: '<Root>/Subsystem2'

  // Outputs for Triggered SubSystem: '<Root>/Subsystem' incorporates:
  //   TriggerPort: '<S2>/Trigger'

  if (b_varargout_1 && (ghost_integrator_PrevZCX.Subsystem_Trig_ZCE != POS_ZCSIG))
  {
    if (ghost_integrator_DW.Subsystem_RESET_ELAPS_T) {
      elapsedTicks = 0U;
    } else {
      elapsedTicks = ghost_integrator_M->Timing.clockTick0 -
        ghost_integrator_DW.Subsystem_PREV_T;
    }

    ghost_integrator_DW.Subsystem_PREV_T = ghost_integrator_M->Timing.clockTick0;
    ghost_integrator_DW.Subsystem_RESET_ELAPS_T = false;

    // DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
    if (ghost_integrator_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
      ghost_integrator_DW.DiscreteTimeIntegrator_DSTATE =
        ghost_integrator_B.Adjustment;
    } else if ((ghost_integrator_B.reset > 0) &&
               (ghost_integrator_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
      ghost_integrator_DW.DiscreteTimeIntegrator_DSTATE =
        ghost_integrator_B.Adjustment;
    } else {
      // DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
      ghost_integrator_DW.DiscreteTimeIntegrator_DSTATE +=
        ghost_integrator_P.DiscreteTimeIntegrator_gainval * static_cast<real_T>
        (elapsedTicks) * (ghost_integrator_DW.DiscreteTimeIntegrator_PREV_U +
                          ghost_integrator_B.In1.Twist.Linear.X);
    }

    // End of DiscreteIntegrator: '<S2>/Discrete-Time Integrator'

    // BusAssignment: '<S2>/Bus Assignment' incorporates:
    //   Constant: '<S5>/Constant'

    ghost_integrator_B.BusAssignment = ghost_integrator_P.Constant_Value_m;
    ghost_integrator_B.BusAssignment.Point.X =
      ghost_integrator_DW.DiscreteTimeIntegrator_DSTATE;
    ghost_integrator_B.BusAssignment.Header = ghost_integrator_B.In1.Header;

    // Outputs for Atomic SubSystem: '<S2>/Publish'
    // MATLABSystem: '<S6>/SinkBlock'
    Pub_ghost_integrator_26.publish(&ghost_integrator_B.BusAssignment);

    // End of Outputs for SubSystem: '<S2>/Publish'

    // Update for DiscreteIntegrator: '<S2>/Discrete-Time Integrator'
    ghost_integrator_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
    ghost_integrator_DW.DiscreteTimeIntegrator_PrevRese = static_cast<int8_T>
      (ghost_integrator_B.reset > 0);
    ghost_integrator_DW.DiscreteTimeIntegrator_PREV_U =
      ghost_integrator_B.In1.Twist.Linear.X;
  }

  ghost_integrator_PrevZCX.Subsystem_Trig_ZCE = b_varargout_1;

  // End of MATLABSystem: '<S1>/SourceBlock'
  // End of Outputs for SubSystem: '<Root>/Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The resolution of this integer timer is 0.02, which is the step size
  //  of the task. Size of "clockTick0" ensures timer will not overflow during the
  //  application lifespan selected.

  ghost_integrator_M->Timing.clockTick0++;
}

// Model initialize function
void ghost_integrator_initialize(void)
{
  {
    static const char_T tmp_1[20] = { '/', 'g', 'h', 'o', 's', 't', '_', 'd',
      'i', 's', 't', '_', 't', 'r', 'a', 'v', 'e', 'l', 'e', 'd' };

    static const char_T tmp[18] = { '/', 'g', 'h', 'o', 's', 't', '_', 'v', 'e',
      'h', 'i', 'c', 'l', 'e', '/', 'v', 'e', 'l' };

    static const char_T tmp_0[18] = { '/', 'e', 'g', 'o', '_', 'd', 'i', 's',
      't', '_', 't', 'r', 'a', 'v', 'e', 'l', 'e', 'd' };

    int32_T i;
    char_T b_zeroDelimTopic_tmp[21];
    char_T b_zeroDelimTopic[19];
    ghost_integrator_PrevZCX.Subsystem_Trig_ZCE = POS_ZCSIG;
    ghost_integrator_PrevZCX.Subsystem2_Trig_ZCE = POS_ZCSIG;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S1>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S4>/Out1' incorporates:
    //   Inport: '<S4>/In1'

    ghost_integrator_B.In1 = ghost_integrator_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S1>/Enabled Subsystem'

    // Start for MATLABSystem: '<S1>/SourceBlock'
    ghost_integrator_DW.obj_d.matlabCodegenIsDeleted = false;
    ghost_integrator_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[18] = '\x00';
    Sub_ghost_integrator_3.createSubscriber(&b_zeroDelimTopic[0], 1);
    ghost_integrator_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S1>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Triggered SubSystem: '<Root>/Subsystem2'
    // SystemInitialize for Atomic SubSystem: '<S3>/ego'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S10>/Out1' incorporates:
    //   Inport: '<S10>/In1'

    ghost_integrator_B.In1_b = ghost_integrator_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    ghost_integrator_DW.obj_g.matlabCodegenIsDeleted = false;
    ghost_integrator_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      b_zeroDelimTopic[i] = tmp_0[i];
    }

    b_zeroDelimTopic[18] = '\x00';
    Sub_ghost_integrator_36.createSubscriber(&b_zeroDelimTopic[0], 1);
    ghost_integrator_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S3>/ego'

    // SystemInitialize for Atomic SubSystem: '<S3>/ghost'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S11>/Out1' incorporates:
    //   Inport: '<S11>/In1'

    ghost_integrator_B.In1_f = ghost_integrator_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // Start for MATLABSystem: '<S9>/SourceBlock' incorporates:
    //   MATLABSystem: '<S6>/SinkBlock'

    ghost_integrator_DW.obj.matlabCodegenIsDeleted = false;
    ghost_integrator_DW.obj.isInitialized = 1;
    for (i = 0; i < 20; i++) {
      // SystemInitialize for Triggered SubSystem: '<Root>/Subsystem'
      // SystemInitialize for Atomic SubSystem: '<S2>/Publish'
      b_zeroDelimTopic_tmp[i] = tmp_1[i];

      // End of SystemInitialize for SubSystem: '<S2>/Publish'
      // End of SystemInitialize for SubSystem: '<Root>/Subsystem'
    }

    // SystemInitialize for Triggered SubSystem: '<Root>/Subsystem'
    // SystemInitialize for Atomic SubSystem: '<S2>/Publish'
    b_zeroDelimTopic_tmp[20] = '\x00';

    // End of SystemInitialize for SubSystem: '<S2>/Publish'
    // End of SystemInitialize for SubSystem: '<Root>/Subsystem'
    for (i = 0; i < 21; i++) {
      ghost_integrator_B.b_zeroDelimTopic[i] = b_zeroDelimTopic_tmp[i];
    }

    Sub_ghost_integrator_37.createSubscriber
      (&ghost_integrator_B.b_zeroDelimTopic[0], 1);
    ghost_integrator_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<S3>/ghost'
    // End of SystemInitialize for SubSystem: '<Root>/Subsystem2'

    // SystemInitialize for Triggered SubSystem: '<Root>/Subsystem'
    // InitializeConditions for DiscreteIntegrator: '<S2>/Discrete-Time Integrator' 
    ghost_integrator_DW.DiscreteTimeIntegrator_PrevRese = 2;
    ghost_integrator_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

    // SystemInitialize for Atomic SubSystem: '<S2>/Publish'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    ghost_integrator_DW.obj_ge.matlabCodegenIsDeleted = false;
    ghost_integrator_DW.obj_ge.isInitialized = 1;
    Pub_ghost_integrator_26.createPublisher(&b_zeroDelimTopic_tmp[0], 1);
    ghost_integrator_DW.obj_ge.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S2>/Publish'
    // End of SystemInitialize for SubSystem: '<Root>/Subsystem'

    // Enable for Triggered SubSystem: '<Root>/Subsystem2'
    // Enable for Chart: '<S3>/Chart'
    ghost_integrator_DW.previousTicks = ghost_integrator_M->Timing.clockTick0;

    // End of Enable for SubSystem: '<Root>/Subsystem2'

    // Enable for Triggered SubSystem: '<Root>/Subsystem'
    ghost_integrator_DW.Subsystem_RESET_ELAPS_T = true;

    // End of Enable for SubSystem: '<Root>/Subsystem'
  }
}

// Model terminate function
void ghost_integrator_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S1>/SourceBlock'
  if (!ghost_integrator_DW.obj_d.matlabCodegenIsDeleted) {
    ghost_integrator_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Triggered SubSystem: '<Root>/Subsystem2'
  // Terminate for Atomic SubSystem: '<S3>/ego'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!ghost_integrator_DW.obj_g.matlabCodegenIsDeleted) {
    ghost_integrator_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<S3>/ego'

  // Terminate for Atomic SubSystem: '<S3>/ghost'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!ghost_integrator_DW.obj.matlabCodegenIsDeleted) {
    ghost_integrator_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<S3>/ghost'
  // End of Terminate for SubSystem: '<Root>/Subsystem2'

  // Terminate for Triggered SubSystem: '<Root>/Subsystem'
  // Terminate for Atomic SubSystem: '<S2>/Publish'
  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  if (!ghost_integrator_DW.obj_ge.matlabCodegenIsDeleted) {
    ghost_integrator_DW.obj_ge.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<S2>/Publish'
  // End of Terminate for SubSystem: '<Root>/Subsystem'
}

//
// File trailer for generated code.
//
// [EOF]
//
