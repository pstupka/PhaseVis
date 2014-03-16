/* 
 * File:   Defines.h
 * Author: stup
 *
 * Created on August 17, 2013, 2:29 PM
 */

#ifndef DEFINES_H
#define	DEFINES_H


template <typename T>
inline void SAFE_DELETE(T *x)
{
    if(x){
        delete x;
        x = 0;
    }
}




#endif	/* DEFINES_H */

