#ifndef MOX_DBG_H
#define MOX_DBG_H

#include "MoX_TYPE.H"
#include "MoX_BASE.H"





#ifdef __cplusplus
extern "C" {
#endif

/*
    WZD  seg024
*/

// WZD s24p01
// DBG_Quit();

// WZD s24p02
// DBG_ScreenDump();

// WZD s24p03
// VGA_GetDACBlock();

// WZD s24p04
// VGA_ReadScreenLine();

// WZD s24p05
void Release_Version(void);

// WZD s24p06
int Check_Release_Version(void);

// WZD s24p07
// Screen_Picture_Capture();

// WZD s24p08
// Capture_Screen_Block();



#ifdef __cplusplus
}
#endif

#endif /* MOX_DBG_H */
