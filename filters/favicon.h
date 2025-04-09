#include <drogon/HttpFilter.h>
#include <drogon/drogon.h>
#include <regex>

class Favicon : public drogon::HttpFilter<Favicon> {
public:
  void doFilter(const drogon::HttpRequestPtr &req, drogon::FilterCallback &&fcb,
                drogon::FilterChainCallback &&fccb) override {
    if (req->path() == "/LogoDiscloud.png") {
      auto resp = drogon::HttpResponse::newHttpResponse();
      resp->setStatusCode(drogon::k404NotFound);
      fcb(resp);
    } else {
      fccb();
    }
  }
};
