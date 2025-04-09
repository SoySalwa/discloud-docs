#pragma once

#include <drogon/HttpSimpleController.h>

class quick_start : public drogon::HttpSimpleController<quick_start> {
public:
  void asyncHandleHttpRequest(
      const drogon::HttpRequestPtr &req,
      std::function<void(const drogon::HttpResponsePtr &)> &&callback) override;
  PATH_LIST_BEGIN
  // list path definitions here;
  // PATH_ADD("/path", "filter1", "filter2", HttpMethod1, HttpMethod2...);
  PATH_ADD("/docs/your-first-program", drogon::Get);
  PATH_LIST_END
};
