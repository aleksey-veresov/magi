#ifndef MAGI_INCLUDED_REQUEST
#define MAGI_INCLUDED_REQUEST

#include "cookie.h"
#include "field.h"
#include "param.h"


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Request
 *
 * Can be generated via CGI handler (magi_cgi_request) or
 * as session in Fast CGI (magi_fast_cgi_request).
 *
 *     Example:     http://example.com/cgi-bin/script/foo/bar?var2=url%20enc
 * method:          get
 * uri:             /cgi-bin/script/foo/bar?var2=url%20enc
 * document_root:   { absolute path to root directory of domain }
 * document_uri:    /cgi-bin/script/foo/bar
 * script_name:     /cgi-bin/script
 * script_filename: { absolute path to script on server machine }
 * remote_addr:     { client IP }
 * remote_port:     { client port }
 * server_addr:     { server IP }
 * server_name:     example.com
 *  (^ Better to use http_params["HTTP_HOST"] -- server_name can be IP too.)
 * server_port:     80
 * server_protocol: http/1.1
 * server_software: { name of web server software }
 * path_info:       /foo/bar
 */
struct magi_request {
    struct magi_field_list *  fields;
    struct magi_cookie_list * cookies;
    char *                    method;
    char *                    uri;
    char *                    document_root;
    char *                    document_uri;
    char *                    script_name;
    char *                    script_filename;
    char *                    remote_addr;
    char *                    remote_port;
    char *                    server_addr;
    char *                    server_name;
    char *                    server_port;
    char *                    server_protocol;
    char *                    server_software;
    char *                    path_info;
    struct magi_param_list *  http_params;
    /* TODO: error. */
};


/*
 * Destroys request; request is not valid after destruction.
 */
void magi_request_destroy(struct magi_request * request);


#endif
