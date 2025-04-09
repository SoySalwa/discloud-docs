#include "quick_start.h"
#include "escape_html.h"
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>
#include <inja/inja.hpp>

void quick_start::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) {

  inja::Environment env;
  std::string code = R"(
    #include <iostream>
    #include <discloud.h>

    int main() {
        dcl::discloud discloud("YOUR_API_TOKEN_HERE");
        
        dcl::application app_get = dcl::application();
        app_get.getApplication(discloud.getToken(), "/app/" + "YOUR_APP_ID");
        
        std::cout<<app_get.get_message();
    return 0;
})";
  std::string codeFormatted = EscapeHTML::toFormat(code);

  nlohmann::json data;
  data["titleName"] = "Discloud Library C++";
  data["code"] = codeFormatted;
  std::string quick_start = env.render_file("../views/quick_start.html", data);

  auto resp = drogon::HttpResponse::newHttpResponse();
  resp->setStatusCode(drogon::k200OK);
  resp->setContentTypeCode(drogon::CT_TEXT_HTML);
  resp->setBody(quick_start);
  callback(resp);
}
