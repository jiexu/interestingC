#ifndef _TEST_H_
#define _TEST_H_


inline int fInline(int x, int y)
{
    return x*x + y;
}


static inline int fStaticInline(int x, int y, int z)
{
    return z*z + x + y;
}

#endif //_TEST_H_
