#if defined(_WIN32)
#  define FILE_SEPARATOR '\\'
#  define FILE_SEPARATOR_STR "\\"
#else
#  define FILE_SEPARATOR '/'
#  define FILE_SEPARATOR_STR "/"
#endif

/* Ruby source defines this macro.  This is how it is defined on the
   Mac as well. */
#if !defined(S_ISDIR)
#  define S_ISDIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#endif

#if !defined(S_ISREG)
#  define S_ISREG(mode) (((mode) & S_IFMT) == S_IFREG)
#endif

int file_is_directory(const char* fname);
int file_is_file(const char* fname);

char* file_basename(const char* fname);
char* file_dirname(const char* fname);
char* file_extname(const char* fname);
char* file_join(const char** strings, int num_strings);
