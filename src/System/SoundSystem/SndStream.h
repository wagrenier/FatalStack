//
// Created by wagrenier on 4/10/2021.
//

/// 0x0000000000276d58     0x16cc /home/zero_rom/zero2np/bin/cd_dbin/iopsys.a(snd_stream.o)
/// 0x0000000000277ff0                SndStreamIsUse
/// 0x0000000000278290                SndStreamFadePitch
/// 0x0000000000277608                SndStreamPrintStatus
/// 0x0000000000276e80                SndStreamStart
/// 0x0000000000277f60                SndStreamSetPosition
/// 0x00000000002783b8                SetIRQCore
/// 0x0000000000276f38                SndStreamFade
/// 0x00000000002781b0                SndStreamChangePlaySpeed
/// 0x0000000000277d90                SndStreamFadeStop
/// 0x0000000000276dd8                SndStreamStartHeaderOnMemory
/// 0x0000000000277ea0                SndStreamAllStop
/// 0x0000000000278168                SndStreamGetNowOffset
/// 0x0000000000278010                SndStreamIsPreload
/// 0x0000000000277f18                SndStreamRestart
/// 0x00000000002782f8                SetStreamHeaderSub
/// 0x0000000000276d58                SndStreamInit
/// 0x0000000000278088                SndStreamGetInfo
/// 0x0000000000277ec8                SndStreamPause
/// 0x0000000000278148                SndStreamGetEndOffset
/// 0x0000000000278230                SndStreamSet3D
/// 0x0000000000277078                SndStreamPlay
/// 0x0000000000277020                SndStreamIsHeaderReady
/// 0x00000000002773e8                SndStreamMain

#ifndef FATALSTACK_SNDSTREAM_H
#define FATALSTACK_SNDSTREAM_H

/// Defining variable types
struct SND_STREAM_WRK {

    ///
    float[2] computedVolume;

    /// Struct inside a struct?
    /// Would be for a file header
    /// Header buffer for DXHd file, which are ~86 bytes long
    byte[255] header_buf_64;

    /// Padding inserted here by the compiler to reach the addr 0x0040cd4f

    /// Another byte buffer for I dont know what, size 1711, START : 0x0040cd50, END : 0x0040d3ff
    byte[1712] another_buffer;

    /// Struct inside a struct?

    /// byte buffer for the file, size 2048, START : 0x0040d400, END : 0x0040dbff
    byte[2048] file_buffer;
} snd_stream_wrk;

/// Defining functions

//***** Fully Implemented Functions ***** //

//***** Unimplemented Functions ***** //
void SndStreamStop(int param_1);
void SndStreamAllStop();

#endif //FATALSTACK_SNDSTREAM_H
