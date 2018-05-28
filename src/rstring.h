#ifndef _RSTRING_H
#define _RSTRING_H

#include "rlib.h"

typedef struct tagbstring rstring;

typedef struct bstrList rstring_array;

/**
 * @brief Return the char at given position
 *
 * @param rstring* rstr
 * @param int index
 *
 * @returns The char at the position.  Or '\0' if the position doesn't exist ro the rstring is NULL.
 */
#define rstring_char_at bchar

/**
 * @brief These conditions must hold for the rstring to be valid.  See the btolower function for this.
 */
#define rstring_bad(rstr) (rstr == NULL || rstr->data == NULL || rstr->mlen < rstr->slen || rstr->slen < 0 || rstr->mlen <=0)

/* Constructing */

rstring* rstring_new(const char* cstr);

int rstring_free(rstring* rstr);


/* Other */

/* char rstring_char_at(const rstring* rstr, int index); */

rstring* rstring_copy(const rstring* rstr);

rstring* rstring_chomp(const rstring* rstr);

rstring* rstring_downcase(const rstring* rstr);

int rstring_eql(const rstring* rstr1, const rstring* rstr2);

int rstring_length(const rstring* rstr);

rstring* rstring_slice1(const rstring* rstr, int index);

rstring* rstring_slice(const rstring* rstr, int index, int length);

rstring* rstring_upcase(const rstring* rstr);



rstring_array* rstring_array_new();
int rstring_array_free(rstring_array* rary);

int rstring_array_push_cstr(rstring_array* rary, char* cstr);
int rstring_array_push_rstr(rstring_array* rary, rstring* rstr);

rstring* rstring_array_get(rstring_array* rary, int index);



rstring* rstring_array_join(rstring_array* rstrings, const rstring* sep);

rstring_array* rstring_split(rstring* rstr, const rstring* sep);

#endif // _RSTRING_H
