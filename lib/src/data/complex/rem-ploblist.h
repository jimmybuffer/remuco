#ifndef REMPLOBLIST_H_
#define REMPLOBLIST_H_

///////////////////////////////////////////////////////////////////////////////
//
// includes
//
///////////////////////////////////////////////////////////////////////////////

#include <remuco.h>

#include "../../util/rem-util.h"

///////////////////////////////////////////////////////////////////////////////
//
// types and constants
//
///////////////////////////////////////////////////////////////////////////////

typedef struct {
	gchar			*plid;
	gchar			*name;
	RemStringList	*plobs; // pids and titles
} RemPloblist;

#define REM_PLOBLIST_PLID_PLAYLIST	"__PLAYLIST__"
#define REM_PLOBLIST_NAME_PLAYLIST	"Playlist"
#define REM_PLOBLIST_PLID_QUEUE		"__QUEUE__"
#define REM_PLOBLIST_NAME_QUEUE		"Queue"

//#define REM_PLOBLIST_PLID_VOTE		"__VOTE__"
//#define REM_PLOBLIST_NAME_VOTE		"Vote"

///////////////////////////////////////////////////////////////////////////////
//
// creating and destroying a ploblist
//
///////////////////////////////////////////////////////////////////////////////

RemPloblist*
rem_ploblist_new(const gchar *plid, const gchar *title);

void
rem_ploblist_destroy(RemPloblist *pl);

/**
 * Clears the ploblist. Removes all plobs and all sub ploblists, but keeps plid
 * and name!
 */
void
rem_ploblist_clear(RemPloblist *pl);

///////////////////////////////////////////////////////////////////////////////
//
// working with plobs in a ploblist
//
///////////////////////////////////////////////////////////////////////////////

void
rem_ploblist_append(RemPloblist *pl, gchar* pid, gchar* title);

void
rem_ploblist_append_const(RemPloblist *pl,
						  const gchar* pid,
						  const gchar* title);

RemStringList*
rem_ploblist_get_pids(const RemPloblist *pl);

#define rem_ploblist_get_title(_pl, _n) (_pl)->plobs->v[(_n) * 2 + 1]

///////////////////////////////////////////////////////////////////////////////
//
// serialization
//
///////////////////////////////////////////////////////////////////////////////

GByteArray*
rem_ploblist_serialize(const RemPloblist *pl,
					   const gchar *se,
					   const RemStringList *pte);

RemPloblist*
rem_ploblist_unserialize(const GByteArray *ba, const gchar *te);

///////////////////////////////////////////////////////////////////////////////
//
// debug
//
///////////////////////////////////////////////////////////////////////////////

void
rem_ploblist_dump(const RemPloblist *pl);

#endif /*REMPLOBLIST_H_*/
