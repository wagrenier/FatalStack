//
// Created by wagrenier on 4/10/2021.
//

#ifndef FATALSTACK_INITSYSTEM_H
#define FATALSTACK_INITSYSTEM_H

#include "SoundSystem/SndSys.h"
#include "PadSystem/PadSys.h"

/// Defining structs related to the system's behaviour
struct OPTION_WRK {
    int Brightness;           // Max value is 144
    int Volume;               // The max non 0 value is 254
    bool IsVibrationOn;
    CONTROL_TYPE ControlType;
    bool IsLookInverted;
    bool IsAnalogStickInverse;
    bool IsSubtitleOne;
    bool IsMonoSound;
    bool Is3dMovement;
} game_options_wrk;

/// Defining functions
void init_super();
void InitOptionSetup(OPTION_WRK *option_wrk);
void OptSoundSetupRef(OPTION_WRK *option_wrk);


#endif //FATALSTACK_INITSYSTEM_H
