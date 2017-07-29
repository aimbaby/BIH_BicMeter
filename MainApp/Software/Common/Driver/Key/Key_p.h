/* 
 * File:   Key_p.h
 * Author: ??????
 *
 * Created on 14 ?????, 2017, 06:41 ?
 */

#ifndef KEY_P_H
#define	KEY_P_H

#define NUMBER_KEYS            (unsigned char)2

#define KEYS_CONFIG \
         {\
           {\
               (unsigned char)15,/* HWI*/\
               (unsigned char)0,/* Active value */\
               (unsigned short)6,/*Release ticks*/\
               (unsigned short)6,/* Short press ticks */\
               (unsigned short)100 /* long press ticks */\
           },\
           {\
               (unsigned char)16,\
               (unsigned char)0,\
               (unsigned short)6,\
               (unsigned short)6,\
               (unsigned short)100\
           }\
		 }


#endif	/* KEY_P_H */

