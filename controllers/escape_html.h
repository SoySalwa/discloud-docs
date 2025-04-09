
#include <iostream>

class EscapeHTML {
public:
  static std::string toFormat(const std::string &input) {
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
};
