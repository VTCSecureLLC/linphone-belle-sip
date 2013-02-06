/*
	belle-sip - SIP (RFC3261) library.
    Copyright (C) 2010  Belledonne Communications SARL

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef belle_sip_provider_h
#define belle_sip_provider_h

#define BELLE_SIP_BRANCH_MAGIC_COOKIE "z9hG4bK"

BELLE_SIP_BEGIN_DECLS

BELLESIP_EXPORT int belle_sip_provider_add_listening_point(belle_sip_provider_t *p, belle_sip_listening_point_t *lp);

void belle_sip_provider_remove_listening_point(belle_sip_provider_t *p, belle_sip_listening_point_t *lp);

BELLESIP_EXPORT belle_sip_listening_point_t *belle_sip_provider_get_listening_point(belle_sip_provider_t *p, const char *transport);

const belle_sip_list_t *belle_sip_provider_get_listening_points(belle_sip_provider_t *p);

BELLESIP_EXPORT void belle_sip_provider_add_sip_listener(belle_sip_provider_t *p, belle_sip_listener_t *l);

BELLESIP_EXPORT void belle_sip_provider_remove_sip_listener(belle_sip_provider_t *p, belle_sip_listener_t *l);

BELLESIP_EXPORT belle_sip_header_call_id_t * belle_sip_provider_create_call_id(const belle_sip_provider_t *prov);

BELLESIP_EXPORT belle_sip_dialog_t *belle_sip_provider_create_dialog(belle_sip_provider_t *prov, belle_sip_transaction_t *t);

BELLESIP_EXPORT belle_sip_client_transaction_t *belle_sip_provider_create_client_transaction(belle_sip_provider_t *p, belle_sip_request_t *req);

BELLESIP_EXPORT belle_sip_server_transaction_t *belle_sip_provider_create_server_transaction(belle_sip_provider_t *p, belle_sip_request_t *req);

belle_sip_stack_t *belle_sip_provider_get_sip_stack(belle_sip_provider_t *p);

BELLESIP_EXPORT void belle_sip_provider_send_request(belle_sip_provider_t *p, belle_sip_request_t *req);

void belle_sip_provider_send_response(belle_sip_provider_t *p, belle_sip_response_t *resp);

void belle_sip_provider_clean_channels(belle_sip_provider_t *p);

/**
 * Add auth info to the request if found
 * @param p object
 * @param request to be updated
 * @param resp response to take authentication values from, might be NULL
 * @param auth_infos  if auth infos cannot be added for an authenticate header, (I.E case where this method return TRUE),
 * a newly allocated belle_sip_auth_info_t object is added to this list. These object contains useful information like realm and username.
 * @returns 0 in case of success,
 *
 **/
BELLESIP_EXPORT int belle_sip_provider_add_authorization(belle_sip_provider_t *p, belle_sip_request_t* request,belle_sip_response_t *resp,belle_sip_list_t** auth_infos);

/**
 * Can be used to simulate network recv error, for tests.
 * @param stack
 * @param recv_error if <=0, will cause channel error to be reported
**/

void belle_sip_provider_set_recv_error(belle_sip_provider_t *prov, int recv_error);

BELLE_SIP_END_DECLS

#define BELLE_SIP_PROVIDER(obj) BELLE_SIP_CAST(obj,belle_sip_provider_t)

#endif
