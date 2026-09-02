#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(var,bitno) (var)|=(1<<(bitno))
#define CLS_BIT(var,bitno) (var)&=~(1<<(bitno))

#define GET_BIT(var,bitno)   ((var>>bitno)&1)
#define TOG_BIT(var,bitno) (var)^=(1<<(bitno))
#endif