# include "../inc/utile.h"
# include "../Ct_lib/inc/Ct_lib.h"
# include "../inc/C_tool.h"
# include <ncurses.h>

static tracker_t* _trac_list(void) {
  static tracker_t d;
  return &d;
}

static short _edit_val(tracker_t* d, const size_t i, data_trac_t data, trac_type_t type) {
  if (i >= TRAC_BUFF)
    return 1;
  if (type == _len && data.len > 100)
    data.len = 100;
  if (type == _percent && data.percent > 101)
    data.percent = 101;
  d->_data[i] = data;
  d->_type[i] = type;
  return 0;
}

static short _add_end(tracker_t *d, const size_t i, const char* name, data_trac_t data, trac_type_t type) {
  d->_name[i] = NULL;
  d->_name[i] = strdup(name);
  if (d->_name[i] == NULL) {
    return 1;
  }
  const int test = strlen(name);
  if (d->_name_len < test)
    d->_name_len = test;
  return _edit_val(d, i, data, type);
}

short Ct_trac_rm(const char* name) {
  tracker_t* t = _trac_list();
  const size_t len = strlen(name);
  if (!len)
    return 1;
  for (size_t i = 0; i < TRAC_BUFF; i++) {
    if (t->_name[i] && strncmp(name, t->_name[i], len + 1) == 0) {
      free(t->_name[i]);
      t->_name[i] = NULL;
      break ;
    }
  }
  clear();
  size_t i = 1;
  while (i < TRAC_BUFF) {
    if (t->_name[i] && !t->_name[i - 1]) {
      t->_name[i - 1] = t->_name[i];
      t->_name[i] = NULL;
      t->_data[i - 1] = t->_data[i];
      t->_type[i - 1] = t->_type[i];
      i = 0;
    }
    i++;
  }
  return 0;
}

short Ct_trac_add(const char* name, data_trac_t data, trac_type_t type) {
  tracker_t* t = _trac_list();
  for (size_t i = 0; i < TRAC_BUFF; i++) {
    if (i > 0 && i < TRAC_BUFF && t->_name[i] && t->_name[i - 1] == NULL) {
      t->_name[i - 1] = t->_name[i];
      t->_name[i] = NULL;
      t->_data[i - 1] = t->_data[i];
      t->_type[i - 1] = t->_type[i];
      i = -1;
      continue ;
    }
  }
  size_t i = 0;
  while (t->_name[i] && i < TRAC_BUFF) {
    if (strncmp(t->_name[i], name , strlen(t->_name[i]) + 1) == 0) {
      return _edit_val(t, i, data, type);
    }
    i++;
  }
  if (i < TRAC_BUFF) {
    return _add_end(t, i , name, data, type);
  }
  return 1;
}

void Ct_trac_end(void) {
  tracker_t* t = _trac_list();
  for (size_t i = 0; i < TRAC_BUFF; i++) {
    if (t->_name[i])
      free(t->_name[i]);
  }
  printw("\n");
  endwin();
}

void Ct_trac_speed(const size_t speed) {
  tracker_t* t = _trac_list();
  t->_speed = speed;
}

void  Ct_trac(void) {
  static bool     b = false;
  static WINDOW*  w = NULL;
  tracker_t*      t = _trac_list();
  char            out[BUFSIZ];
  static size_t  _speed = 0;
  int x, y;
  if (b == false) {
    w = initscr();
    if (!w) {
      perror("initscr");
      return ;
    }
    b = true;
  }
  if (t->_speed != _speed) {
    _speed++;
    return;
  }
  _speed = 0;
  t->_total = 0;
  getmaxyx(w, y, x);
  (void)x; // unuse <--
  move(0,0);
  printw("%.*s v %s", t->_name_len, "name", "data");
  for (int i = 0; i < TRAC_BUFF && i < y - 2 && t->_name[i]; i++) {
    bzero(out, BUFSIZ);
    move(i + 1, 0);
    switch (t->_type[i]) {
    case _char:
      t->_total += snprintf(out, BUFSIZ, "%*.*s | %c", t->_name_len, t->_name_len, t->_name[i] , t->_data[i].c);
      break;
    case _int:
      t->_total += snprintf(out, BUFSIZ, "%*.*s | %i", t->_name_len, t->_name_len, t->_name[i] , t->_data[i].i);
      break;
    case _double:
      t->_total += snprintf(out, BUFSIZ, "%*.*s | %10.f", t->_name_len, t->_name_len, t->_name[i], t->_data[i].d);
      break;
    case _float:
      t->_total += snprintf(out, BUFSIZ, "%*.*s | %10.f", t->_name_len, t->_name_len, t->_name[i], t->_data[i].f);
      break;
    case _len:
      char tmp[BUFSIZ / 2];
      memset(tmp, '|', (BUFSIZ / 2) - 1);
      tmp[(BUFSIZ / 2)] = 0;
      if (t->_data[i].len < (BUFSIZ / 2))
        tmp[t->_data[i].len] = 0;
      t->_total += snprintf(out, BUFSIZ, "%*.*s | %s", t->_name_len, t->_name_len, t->_name[i], tmp);
      break;
    case _percent:
      t->_total += snprintf(out, BUFSIZ, "%*.*s | %%%d", t->_name_len, t->_name_len, t->_name[i], t->_data[i].percent);
      break;
    default:
      return ; //snprintf(out, BUFSIZ - 1, "what the %*.*s |", t->_name_len, t->_name_len, t->_name[i]);
      break;
    }
    printw("%s", out);
  }
  refresh();
}

/*
int main() {
  Ct_trac_speed(3);
  char    s[100];
  size_t j = 0;
  for (size_t i = 0; i < 100; i++) {
    bzero(s, 100);
    if (j > 5)
      j = 0;
    snprintf(s, 100, "test%zu", j);
    Ct_trac_add(s, TRACV(i), _int);
    if (i > 60)
      Ct_trac_rm("test3");
    usleep(100000);
    Ct_trac();
    j++;
  }
  for (size_t i = 0; i < 100; i++) {
    snprintf(s, 100, "test3");
    Ct_trac_add(s, TRACV(i), _int);
    usleep(1000);
    Ct_trac();
  }
  usleep(3000);
  Ct_trac_end();
}
*/

