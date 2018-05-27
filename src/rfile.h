#ifndef _RFILE_H
#define _RFILE_H

#include "rstring.h"

#if defined(_WIN32)
#  define RFILE_SEPARATOR '\\'
#  define RFILE_SEPARATOR_STR "\\"
#else
#  define RFILE_SEPARATOR '/'
#  define RFILE_SEPARATOR_STR "/"
#endif

/* Ruby source defines this macro.  This is how it is defined on the
   Mac as well. */
#if !defined(S_ISDIR)
#  define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#endif

#if !defined(S_ISREG)
#  define S_ISREG(mode) (((mode) & S_IFMT) == S_IFREG)
#endif

int rfile_is_directory(const rstring* fname);
int rfile_is_file(const rstring* fname);

rstring* rfile_basename(const rstring* fname);
rstring* rfile_dirname(const rstring* fname);
rstring* rfile_extname(const rstring* fname);
rstring* rfile_join(rstring** strings, int num_strings);

#endif // _RFILE_H
