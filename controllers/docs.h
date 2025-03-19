#pragma once

#include <drogon/HttpSimpleController.h>
#include <drogon/HttpTypes.h>

class docs : public drogon::HttpSimpleController<docs>
{
  public:
    void asyncHandleHttpRequest(const drogon::HttpRequestPtr& req, std::function<void (const drogon::HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    // list path definitions here;
    // PATH_ADD("/path", "filter1", "filter2", HttpMethod1, HttpMethod2...);
    PATH_ADD("/docs", drogon::Get);
    PATH_ADD("/documentation", drogon::Get);
    PATH_LIST_END
};
