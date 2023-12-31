/*   contrib/m_opme.c
 *   Copyright (C) 2002 Hybrid Development Team
 *   Copyright (C) 2004-2012 ircd-ratbox development team
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *   $Id: m_opme.c 27371 2012-03-16 05:33:15Z dubkat $
 */
#include "stdinc.h"
#include "ratbox_lib.h"
#include "struct.h"
#include "channel.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "s_log.h"
#include "s_serv.h"
#include "send.h"
#include "whowas.h"
#include "match.h"
#include "hash.h"
#include "parse.h"
#include "modules.h"
#include "s_newconf.h"

static int mo_opme(struct Client *client_p, struct Client *source_p, int parc, const char *parv[]);

struct Message opme_msgtab = {
	"OPME", 0, 0, 0, MFLG_SLOW,
	{mg_unreg, mg_not_oper, mg_ignore, mg_ignore, mg_ignore, {mo_opme, 2}}
};

mapi_clist_av1 opme_clist[] = { &opme_msgtab, NULL };

DECLARE_MODULE_AV1(opme, NULL, NULL, opme_clist, NULL, NULL, "$Revision: 27371 $");


/*
** mo_opme
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static int
mo_opme(struct Client *client_p, struct Client *source_p, int parc, const char *parv[])
{
	struct Channel *chptr;
	struct membership *msptr;
	rb_dlink_node *ptr;

	/* admins only */
	if(!IsOperAdmin(source_p))
	{
		sendto_one(source_p, form_str(ERR_NOPRIVS), me.name, source_p->name, "opme");
		return 0;
	}

	if((chptr = find_channel(parv[1])) == NULL)
	{
		sendto_one_numeric(source_p, ERR_NOSUCHCHANNEL,
				   form_str(ERR_NOSUCHCHANNEL), parv[1]);
		return 0;
	}

	RB_DLINK_FOREACH(ptr, chptr->members.head)
	{
		msptr = ptr->data;

		if(is_chanop(msptr))
		{
			sendto_one(source_p, ":%s NOTICE %s :%s Channel is not opless",
				   me.name, parv[0], parv[1]);
			return 0;
		}
	}

	msptr = find_channel_membership(chptr, source_p);

	if(msptr == NULL)
		return 0;

	msptr->flags |= CHFL_CHANOP;

	sendto_wallops_flags(UMODE_WALLOP, &me,
			     "OPME called for [%s] by %s!%s@%s",
			     parv[1], source_p->name, source_p->username, source_p->host);
	ilog(L_MAIN, "OPME called for [%s] by %s!%s@%s",
	     parv[1], source_p->name, source_p->username, source_p->host);

	/* dont send stuff for local channels remotely. */
	if(*chptr->chname != '&')
	{
		sendto_server(NULL, NULL, NOCAPS, NOCAPS,
			      ":%s WALLOPS :OPME called for [%s] by %s!%s@%s",
			      me.name, parv[1], source_p->name, source_p->username, source_p->host);
		sendto_server(NULL, chptr, NOCAPS, NOCAPS, ":%s PART %s", source_p->name, parv[1]);
		sendto_server(NULL, chptr, NOCAPS, NOCAPS,
			      ":%s SJOIN %ld %s + :@%s",
			      me.name, (long)chptr->channelts, parv[1], source_p->name);
	}

	sendto_channel_local(ALL_MEMBERS, chptr,
			     ":%s MODE %s +o %s", me.name, parv[1], source_p->name);

	return 0;
}
