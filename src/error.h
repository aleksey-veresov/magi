#ifndef MAGI_INCLUDED_ERROR
#define MAGI_INCLUDED_ERROR


enum magi_error {
    magi_error_none = 0,
    magi_error_nobound,
    magi_error_unknown,
    magi_error_notype,
    magi_error_length,
    magi_error_memmory,
    magi_error_cookies,
    magi_error_urlenc,
    magi_error_multipart
};

const char * magi_error_message(enum magi_error error);


#endif
