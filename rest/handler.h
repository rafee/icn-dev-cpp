#ifndef HANDLER_H
#define HANDLER_H
#include <iostream>
// #include <cstring>

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/http_listener.h>

// #include <curl/curl.h>

namespace http = web::http;
namespace listener = http::experimental::listener;

class handler
{
public:
    handler();
    handler(utility::string_t url);
    virtual ~handler();

    pplx::task<void> open() { return m_listener.open(); }
    pplx::task<void> close() { return m_listener.close(); }

protected:
private:
    void handle_get(http::http_request message);
    void handle_put(http::http_request message);
    void handle_post(http::http_request message);
    void handle_delete(http::http_request message);
    void handle_error(pplx::task<void> &t);
    listener::http_listener m_listener;
};

#endif // HANDLER_H
