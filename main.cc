#include "controllers/docs.h"
#include "filters/favicon.h"
#include <drogon/HttpAppFramework.h>
#include <drogon/drogon.h>

int main() {
  drogon::app()
      .addListener("0.0.0.0", 5555)
      .setDocumentRoot("/home/salwa/Documents/MyProjects/discloud-docs/public")
      .registerHandler("/toggle_spoiler", &docs::toggle_spoiler,
                       {drogon::Post});
  LOG_DEBUG << "Server running on port 5555";
  drogon::app().run();
  return 0;
}
