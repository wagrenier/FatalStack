//
// Created by wagrenier on 4/10/2021.
//

/// 0x0000000000274f28      0x754 /home/zero_rom/zero2np/bin/cd_dbin/iopsys.a(snd.o)
/// 0x0000000000274f28                sndGetNeedSize
/// 0x0000000000275588                SndAllStop
/// 0x00000000002750d0                SndMain                   INCOMPLETE
/// 0x0000000000275258                SndIsMono                 DONE
/// 0x0000000000275248                SndSetMono                DONE
/// 0x0000000000275390                SndCalcValue
/// 0x0000000000274f80                SndInit                   INCOMPLETE
/// 0x0000000000275510                SndGetFrameAddVol
/// 0x0000000000275560                SndAddFadeVol
/// 0x0000000000275268                SndSetGroupVolume         DONE
/// 0x0000000000275110                SndFremaAfterMain
/// 0x00000000002755a8                GetFreeVoiceNum
/// 0x0000000000275668                IsExistFreeVoice
/// 0x00000000002750c8                SndInitAfter_ee_iopInit
/// 0x0000000000275118                SndSetEffect
/// 0x0000000000275238                SndSetStereo              DONE
/// 0x0000000000275310                SndGetGroupVolume         DONE

#ifndef FATALSTACK_SNDSYS_H
#define FATALSTACK_SNDSYS_H

/// Defining variable types
enum SOUND_TYPE {
    STEREO,
    MONO
};

/// Defining ctrl variables
SOUND_TYPE snd_sys = STEREO;

/// Contains the volume currently set in the game
float[2] sndGroup;

/// Defining functions

//***** Fully Implemented Functions ***** //
void SndSetMono();
void SndSetStereo();
void SndSetGroupVolume(int groupIndex, float volume);
float SndGetGroupVolume(int groupIndex);
bool SndIsMono();

//***** Unimplemented Functions ***** //
undefined8 SndInit(int param_1,undefined8 param_2);
void SndMain();
void SndAllStop();
void SndCalcValue(float param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                  undefined8 param_7,long param_8,short *param_9_00,short *param_9);

#endif //FATALSTACK_SNDSYS_H
