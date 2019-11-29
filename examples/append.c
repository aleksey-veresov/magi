#include <cgi.h>
#include <request.h>
#include <response.h>
#include <stdio.h>
#include <stdlib.h>


void response_request(struct magi_request * req, struct magi_response * res)
{
    char * data = magi_param_list_get(req->params, "addon");
    if (data) {
        FILE * file = fopen("file_to_append", "a");
        fputs(data, file);
        fclose(file);
    }

    magi_response_content_type(res, magi_xhtml);
    magi_response_add(
        res,
        "<!DOCTYPE html PUBLIC '-//W3C//DTD XHTML 1.0 Strict//EN' "
        "'http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd'>"
        "<html xmlns='http://www.w3.org/1999/xhtml'>"
        "<head><title>Append to File</title></head>"
        "<body>"
        "<form action='/cgi-bin/append' method='post'><fieldset>"
        "<input type='text' name='addon' value='Whatever you want to add.'/>"
        "<input type='submit' value='Append'/>"
        "</fieldset></form>"
        "</body>"
        "</html>");
}

int main(int argc, char const * argv[])
{
    struct magi_request request;
    magi_request_setup(&request);
    if (magi_request_cgi(&request) && magi_request_resume_cgi(&request)) {
        struct magi_response response;
        magi_response_setup(&response);
        response_request(&request, &response);
        magi_response_cgi(&response);
        magi_response_destroy(&response);
    } else {
        magi_error_cgi(request.error);
    }
    magi_request_destroy(&request);
    return 0;
}
