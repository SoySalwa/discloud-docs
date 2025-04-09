#pragma once

#include <nlohmann/json.hpp>

class DatePagination {
private:
  nlohmann::json data;

public:
  DatePagination();
  void pagesIndex();
  void setNextPage(const std::string &url, const std::string title);
  void setPrevPage(const std::string &url, const std::string title);
  std::string render();
};
