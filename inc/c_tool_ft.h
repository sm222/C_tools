#ifndef C_TOOL_FT_H
# define C_TOOL_FT_H

# include <stdio.h>
# include <unistd.h>

typedef struct timeval tt_time;

// flag

int         Ct_flag_init(void);
int         Ct_flag_make(char* name, short cat);
int         Ct_flag_print(short cat);
int         Ct_flag_end(short print);

// time

char*       Ct_time_return(void);
void        Ct_time_print(void);

//

void        Ct_err(char* msg);
int         Ct_strcmp(char* s1, char* s2);
void        Ct_mprintf(void* ptr, size_t size, int type, int name);
void        Ct_memcmp_print(void* ptr1, void* ptr2, size_t size, int type);

// log
ssize_t     Ct_debug_info(const char* s, ...);
int         Ct_debug_pro(int err, char* file, short clean, char* msg, ...);

//time 
short       Ct_start_time(tt_time* start);
const char* Ct_stop_time(tt_time* start, tt_time* stop, char* out, int size);

typedef struct data_trac {
  char          c;
  int           i;
  float         f;
  double        d;
  size_t        len; // make a line of '|'
  unsigned char percent;
} data_trac_t;


typedef enum trac_type {
  _char,
  _int,
  _float,
  _double,
  _len,
  _percent,
} trac_type_t;

#define TRAC_BUFF 101

typedef struct t_tracker {
  char*           _name[TRAC_BUFF];
  data_trac_t     _data[TRAC_BUFF];
  trac_type_t     _type[TRAC_BUFF];
  size_t          _total;
  int             _name_len;
  size_t          _speed;
} tracker_t;

// trac
void        Ct_trac(void);
void        Ct_trac_speed(const size_t speed);
short       Ct_trac_add(const char* name, data_trac_t data, trac_type_t type);
short       Ct_trac_rm(const char* name);
void        Ct_trac_end(void);
//
data_trac_t tracChar(char c);
data_trac_t tracInt(int i);
data_trac_t tracFloat(float f);
data_trac_t tracDouble(double d);
data_trac_t tracLen(size_t l);
data_trac_t tracPer(int l);

#endif
