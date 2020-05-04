#include "handler.h"

handler::handler()
{
    //ctor
}
handler::handler(utility::string_t url) : m_listener(url)
{
    m_listener.support(http::methods::GET, std::bind(&handler::handle_get, this, std::placeholders::_1));
    m_listener.support(http::methods::PUT, std::bind(&handler::handle_put, this, std::placeholders::_1));
    m_listener.support(http::methods::POST, std::bind(&handler::handle_post, this, std::placeholders::_1));
    m_listener.support(http::methods::DEL, std::bind(&handler::handle_delete, this, std::placeholders::_1));
}
handler::~handler()
{
    //dtor
}

void handler::handle_error(pplx::task<void> &t)
{
    try
    {
        t.get();
    }
    catch (...)
    {
        // Ignore the error, Log it if a logger is available
    }
}

//
// Get Request
//
void handler::handle_get(http::http_request message)
{
    std::cout << message.to_string() << std::endl;
    auto resourceURI = message.request_uri();
    std::cout << resourceURI.to_string() << std::endl;
    auto queryString = resourceURI.query();
    std::cout << queryString << std::endl;

    auto filePath = "static/" + queryString;

    concurrency::streams::fstream::open_istream(U(filePath), std::ios::in).then([=](concurrency::streams::istream is) {
                                                                              message.reply(http::status_codes::OK, is, U("video/mp4")).then([](pplx::task<void> t) {
                                                                                  try
                                                                                  {
                                                                                      t.get();
                                                                                  }
                                                                                  catch (...)
                                                                                  {
                                                                                      //
                                                                                  }
                                                                              });
                                                                          })
        .then([=](pplx::task<void> t) {
            try
            {
                t.get();
            }
            catch (...)
            {
                message.reply(http::status_codes::InternalError, U("INTERNAL ERROR "));
            }
        });

    return;
};

//
// A POST request
//
void handler::handle_post(http::http_request message)
{
    ucout << message.to_string() << std::endl;

    message.reply(http::status_codes::OK, message.to_string());
    return;
};

//
// A DELETE request
//
void handler::handle_delete(http::http_request message)
{
    ucout << message.to_string() << std::endl;

    std::string rep = U("WRITE YOUR OWN DELETE OPERATION");
    message.reply(http::status_codes::OK, rep);
    return;
};

//
// A PUT request
//
void handler::handle_put(http::http_request message)
{
    ucout << message.to_string() << std::endl;
    std::string rep = U("WRITE YOUR OWN PUT OPERATION");
    message.reply(http::status_codes::OK, rep);
    return;
};
