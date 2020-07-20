#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD 
#define TAPPING_TERM 100

#define ENCODERS_PAD_A { B12 }
#define ENCODERS_PAD_B { B13 }

#define ENCODER_RESOLUTION 1
#define MEDIA_KEY_DELAY 10
