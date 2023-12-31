/*
 *  This file is automatically generated: do not modify
 *  ircd-ratbox: A slightly useful ircd
 *
 *  Copyright (C) 2003,2008 Aaron Sethman <androsyn@ratbox.org>
 *  Copyright (C) 2003-2005,2008 ircd-ratbox development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *  
 */
#include "stdinc.h"
#include "modules.h"
#include "hash.h"
#include "s_log.h"

extern struct mapi_header_av1 m_accept_mheader;
extern struct mapi_header_av1 m_admin_mheader;
extern struct mapi_header_av1 m_adminwall_mheader;
extern struct mapi_header_av1 m_away_mheader;
extern struct mapi_header_av1 m_capab_mheader;
extern struct mapi_header_av1 m_cap_mheader;
extern struct mapi_header_av1 m_close_mheader;
extern struct mapi_header_av1 m_cmessage_mheader;
extern struct mapi_header_av1 m_connect_mheader;
extern struct mapi_header_av1 m_dline_mheader;
extern struct mapi_header_av1 m_encap_mheader;
extern struct mapi_header_av1 m_gline_mheader;
extern struct mapi_header_av1 m_help_mheader;
extern struct mapi_header_av1 m_info_mheader;
extern struct mapi_header_av1 m_invite_mheader;
extern struct mapi_header_av1 m_ison_mheader;
extern struct mapi_header_av1 m_kline_mheader;
extern struct mapi_header_av1 m_knock_mheader;
extern struct mapi_header_av1 m_links_mheader;
extern struct mapi_header_av1 m_list_mheader;
extern struct mapi_header_av1 m_locops_mheader;
extern struct mapi_header_av1 m_lusers_mheader;
extern struct mapi_header_av1 m_map_mheader;
extern struct mapi_header_av1 m_motd_mheader;
extern struct mapi_header_av1 m_names_mheader;
extern struct mapi_header_av1 m_oper_mheader;
extern struct mapi_header_av1 m_operspy_mheader;
extern struct mapi_header_av1 m_pass_mheader;
extern struct mapi_header_av1 m_ping_mheader;
extern struct mapi_header_av1 m_pong_mheader;
extern struct mapi_header_av1 m_post_mheader;
extern struct mapi_header_av1 m_rehash_mheader;
extern struct mapi_header_av1 m_restart_mheader;
extern struct mapi_header_av1 m_resv_mheader;
extern struct mapi_header_av1 m_set_mheader;
extern struct mapi_header_av1 m_stats_mheader;
extern struct mapi_header_av1 m_svinfo_mheader;
extern struct mapi_header_av1 m_tb_mheader;
extern struct mapi_header_av1 m_testline_mheader;
extern struct mapi_header_av1 m_testmask_mheader;
extern struct mapi_header_av1 m_time_mheader;
extern struct mapi_header_av1 m_topic_mheader;
extern struct mapi_header_av1 m_trace_mheader;
extern struct mapi_header_av1 m_unreject_mheader;
extern struct mapi_header_av1 m_user_mheader;
extern struct mapi_header_av1 m_userhost_mheader;
extern struct mapi_header_av1 m_version_mheader;
extern struct mapi_header_av1 m_wallops_mheader;
extern struct mapi_header_av1 m_who_mheader;
extern struct mapi_header_av1 m_whois_mheader;
extern struct mapi_header_av1 m_whowas_mheader;
extern struct mapi_header_av1 m_xline_mheader;
extern struct mapi_header_av1 m_die_mheader;
extern struct mapi_header_av1 m_error_mheader;
extern struct mapi_header_av1 m_join_mheader;
extern struct mapi_header_av1 m_kick_mheader;
extern struct mapi_header_av1 m_kill_mheader;
extern struct mapi_header_av1 m_message_mheader;
extern struct mapi_header_av1 m_mode_mheader;
extern struct mapi_header_av1 m_nick_mheader;
extern struct mapi_header_av1 m_part_mheader;
extern struct mapi_header_av1 m_quit_mheader;
extern struct mapi_header_av1 m_server_mheader;
extern struct mapi_header_av1 m_squit_mheader;
const struct mapi_header_av1 *static_mapi_headers[] = {
	&m_accept_mheader,
	&m_admin_mheader,
	&m_adminwall_mheader,
	&m_away_mheader,
	&m_capab_mheader,
	&m_cap_mheader,
	&m_close_mheader,
	&m_cmessage_mheader,
	&m_connect_mheader,
	&m_dline_mheader,
	&m_encap_mheader,
	&m_gline_mheader,
	&m_help_mheader,
	&m_info_mheader,
	&m_invite_mheader,
	&m_ison_mheader,
	&m_kline_mheader,
	&m_knock_mheader,
	&m_links_mheader,
	&m_list_mheader,
	&m_locops_mheader,
	&m_lusers_mheader,
	&m_map_mheader,
	&m_motd_mheader,
	&m_names_mheader,
	&m_oper_mheader,
	&m_operspy_mheader,
	&m_pass_mheader,
	&m_ping_mheader,
	&m_pong_mheader,
	&m_post_mheader,
	&m_rehash_mheader,
	&m_restart_mheader,
	&m_resv_mheader,
	&m_set_mheader,
	&m_stats_mheader,
	&m_svinfo_mheader,
	&m_tb_mheader,
	&m_testline_mheader,
	&m_testmask_mheader,
	&m_time_mheader,
	&m_topic_mheader,
	&m_trace_mheader,
	&m_unreject_mheader,
	&m_user_mheader,
	&m_userhost_mheader,
	&m_version_mheader,
	&m_wallops_mheader,
	&m_who_mheader,
	&m_whois_mheader,
	&m_whowas_mheader,
	&m_xline_mheader,
	&m_die_mheader,
	&m_error_mheader,
	&m_join_mheader,
	&m_kick_mheader,
	&m_kill_mheader,
	&m_message_mheader,
	&m_mode_mheader,
	&m_nick_mheader,
	&m_part_mheader,
	&m_quit_mheader,
	&m_server_mheader,
	&m_squit_mheader,
	NULL
};
