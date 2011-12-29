/*
 * Copyright (C) 2011 Dimitrios Georgiou <PLEASEdim.geo@DOgmailNOT.SPAMcom>
 *
 * This file is part of the ioniced, which is distributed under
 * the  terms  of the  GNU General Public Licence 2.  Please see the
 * COPYING file for details.
 */

#ifndef LOADCONFIG_H
#define LOADCONFIG_H


#define UID_ALL	-1
#define GID_ALL	-1
#define ID_NOT_FOUND -2

/* in-memory list of out config */
typedef struct config_entry
{
  char *name;			//processname
  char *options;		//ionice command line options
  int wildcard;			//flag set if config entry is a wildcard
  int absolute;			//flag is set if an absolute path to the executable is given
  uid_t uid;			//relevant user id
  gid_t gid;			//relevant group id
  void *next;			//next config entry
} config_entry_t;


/* 
 * reads configfile 
 */
int configLoadFile (char *filename);

/* 
 * search name in list 
 */
config_entry_t *configSearch (char *statusname, char *exename, uid_t uid,
			      gid_t gid);

/*
 * free config entries 
 */
void configFreeEntries (void);

#endif
