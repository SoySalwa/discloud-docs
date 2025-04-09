#include "pagination.h"
#include <inja/environment.hpp>
#include <inja/inja.hpp>

DatePagination::DatePagination() { data = nlohmann::json::object(); }

void DatePagination::pagesIndex() {};

void DatePagination::setNextPage(const std::string &url,
                                 const std::string title) {
  data["next_url"] = url;
  data["NextPageTitle"] = title;
};

void DatePagination::setPrevPage(const std::string &url,
                                 const std::string title) {
  data["prev_url"] = url;
  data["prevPageTitle"] = title;
};

std::string DatePagination::render() {
  inja::Environment env;
  auto templ = env.parse_template("../templates/pagination.inja");
  return env.render(templ, data);
}
