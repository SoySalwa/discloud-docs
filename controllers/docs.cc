#include "docs.h"
#include <drogon/HttpResponse.h>
#include <drogon/HttpTypes.h>
#include <inja/environment.hpp>

void docs::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
  // write your application logic here

  inja::Environment env;
  std::map<std::string, std::string> data;
  data["titleName"] = "Discloud Library C++";
  data["version"] = "0.12.0";
  data["description"] =
      "This is a documentation for the library Discloud in C++.";

  std::string cookieValue = req->getCookie("show_spoiler");
  bool show = (cookieValue == "false");

  data["show"] = show;

  std::string result = env.render_file("../views/docs.html", data);
  auto resp = drogon::HttpResponse::newHttpResponse();
  resp->setStatusCode(drogon::k200OK);
  resp->setContentTypeCode(drogon::CT_TEXT_HTML);
  resp->setBody(result);

  callback(resp);
}

void docs::toggle_spoiler(
    const drogon::HttpRequestPtr &req,
    std::function<void(const drogon::HttpResponsePtr &)> &&callback) {
  std::string cookieValue = req->getCookie("show_spoiler");
  bool newShow = (cookieValue != "true"); // Invierte el estado
  // bool newShow = !currentShow;
  //  Debug crucial (verifica en logs)
  LOG_INFO << "Enviando JSON: {\"show\": " << newShow << "}";

  // Crea respuesta con formato EXACTO { "show": boolean }
  Json::Value json;
  json["show"] = newShow;

  auto resp = drogon::HttpResponse::newHttpJsonResponse(json);
  resp->addCookie("show_spoiler", newShow ? "true" : "false");
  callback(resp);
}
