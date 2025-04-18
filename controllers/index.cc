#include "index.h"
#include <drogon/HttpRequest.h>
#include <drogon/HttpResponse.h>

#include <inja/environment.hpp>
#include <inja/inja.hpp>
#include <string>

std::string escapeHtml(const std::string &input) {
  std::string output;
  for (char c : input) {
    switch (c) {
    case '&':
      output += "&amp;";
      break;
    case '<':
      output += "&lt;";
      break;
    case '>':
      output += "&gt;";
      break;
    case '"':
      output += "&quot;";
      break;
    case '\'':
      output += "&#39;";
      break;
    default:
      output += c;
      break;
    }
  }
  return output;
}

void Routes::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
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

  std::string codeFormatted = escapeHtml(code);
  inja::Environment env;

  std::map<std::string, std::string> data;
  data["titleName"] = "Discloud Library C++";
  data["version"] = "0.0.1";
  data["description"] =
      "This library has been created to facilitate the access of the Discloud "
      "API. "
      "The intention of the library is to be able to extract the API without "
      "the need of using the code spaghetti.";
  data["installation"] = "not available";
  data["prerequisites"] = "Curl, C++20";
  data["code"] = codeFormatted;
  std::string result = env.render_file("../views/index.html", data);

  // write your application logic here
  auto resp = drogon::HttpResponse::newHttpResponse();
  resp->setStatusCode(drogon::k200OK);
  resp->setContentTypeCode(drogon::CT_TEXT_HTML);
  resp->setBody(result);
  callback(resp);
};
