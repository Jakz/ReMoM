// _s14p01c.c Hardware_Init
// in MOM_DEF.H

#include "ST_VGA.H"

// int __cdecl __far Hardware_Init(int Input_Type, int Snd_Chnls, int FontFile@, int M_Drv, int M_IO, int M_IRQ, int M_DMA, int D_Drv, int D_IO, int D_IRQ, int D_DMA)

void Hardware_Init(int argInputType, int argSoundChannels, char *argFontFileName, int M_Drv, int M_IO, int M_IRQ, int M_DMA, int D_Drv, int D_IO, int D_IRQ, int D_DMA)
{
    int tmpInputType;

    // CRP_Empty_Exit_Fn2()

    EMM_Startup();

    // [x] VGA_SetModeY();

    if (argInputType == -1)
    {
        VGA_DAC_Init(DEFAULT_FONTS_FILE);
        //SND_Init(0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1);
        tmpInputType = 1;
    }
    else
    {
        VGA_DAC_Init(argFontFileName);
        //SND_Init(M_Drv, argSoundChannels, M_IO, M_IRQ, M_DMA, D_Drv, D_IO, D_IRQ, D_DMA);
        tmpInputType = argInputType;
    }

    // GUI_Init(tmpInputType);

    // RNG_TimerSeed();

    // VGA_SetDrawFrame();

}
