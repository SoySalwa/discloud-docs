
#pragma once

#include <cstdio>
#include <drogon/HttpAppFramework.h>
#include <drogon/HttpController.h>
#include <drogon/HttpRequest.h>
#include <drogon/HttpSimpleController.h>
#include <drogon/HttpTypes.h>
#include <functional>

class Routes : public drogon::HttpSimpleController<Routes> {
public:
    // Método estático para manejar la ruta
     void asyncHandleHttpRequest(const drogon::HttpRequestPtr &req, std::function<void (const drogon::HttpResponsePtr &)> &&callback);
     void pagesDocs(const drogon::HttpRequestPtr &req, std::function<void(const drogon::HttpResponsePtr &)> &&callback);
    // Definición de las rutas
    PATH_LIST_BEGIN
    PATH_ADD("/", drogon::Get);
    PATH_ADD("/home", drogon::Get);
    PATH_ADD("/index", drogon::Get);
    PATH_LIST_END
};
