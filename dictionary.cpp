#include <algorithm>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "mongoose.h"
using namespace std;

struct StrNode
{
  string str;
  StrNode* next;
  StrNode(string in_str)
    : str(in_str), next(NULL) { }
  StrNode()
    : str(""), next(NULL) { }
};

struct StrIntNode
{
  string str;
  unsigned int count;
  StrIntNode(string in_str, unsigned int in_c)
    : str(in_str), count(in_c) {  }
  StrIntNode()
    : str(""), count(0) { }
  bool operator<(const StrIntNode& rhs) const
  {
    return count > rhs.count;
  }
};

class SuperDict
{
private:
  map<string, unsigned int> dict_search_count;
  map<string, StrNode> dict_definition;
  vector<StrIntNode> top10_search;
public:
  SuperDict() 
  {
    for (int i = 0; i < 10; i++) {
      StrIntNode temp;
      top10_search.push_back(temp);
    }
  }
  ~SuperDict()
  {
    for (std::map<string,StrNode>::iterator it=dict_definition.begin(); it!=dict_definition.end(); ++it) {
      if (it->second.next == NULL)
        continue;
      else {
        StrNode* curr = it->second.next;
        StrNode* temp;
        while (curr != NULL) {
          temp = curr->next;
          delete curr;
          curr = temp;
        }
      }
    }
  }
  void add_word(const string& in_word, const string& def) {
    // when the word has at least 1 definion in the dictionary
    if (dict_definition[in_word].str != "") {
      StrNode* curr_strnode= &dict_definition[in_word];
      while(curr_strnode->next != NULL)
        curr_strnode = curr_strnode->next;
      StrNode* newnode = new StrNode(def);
      curr_strnode->next = newnode;
    }// when the word has no definition in the dictionary
    else {
      dict_definition[in_word].str = def;
    }
  }

  vector<string> search_word(const string& in_word) {
    vector<string> found_definitions;
    if (dict_definition[in_word].str != "") {
      // take care of top 10 most searched words
      StrIntNode top10_node(in_word, ++dict_search_count[in_word]);
      bool update_count = false;
      for (int i = 0; i < 10; i++) {
        if (top10_search[i].str == top10_node.str) {
          top10_search[i].count++;
          update_count = true;
          break;
        }
      }
      if (!update_count) {
        top10_search.push_back(top10_node);
        std::sort(top10_search.begin(), top10_search.end());
        top10_search.pop_back();
      }
      else
        std::sort(top10_search.begin(), top10_search.end());

      // collect all definitoins of the word
      StrNode* curr_def_node= &dict_definition[in_word];
      found_definitions.push_back(curr_def_node->str);
      while(curr_def_node->next != NULL) {
        curr_def_node = curr_def_node->next;
        found_definitions.push_back(curr_def_node->str);
      }
    }
    return found_definitions;
  }

  vector<string> get_top10(bool if_print) {
    vector<string> result;
    for (int i = 0; i < 10; i++) {
      if (if_print)
        cout << top10_search[i].str << " ";
      result.push_back(top10_search[i].str);
    }
    if (if_print)
      cout << endl;
    return result;
  }
};

static const char *html_begin =
  "<html><head>"
  "<title>Super Dictionary</title>"
  "</head><body>"
    "<h3> Super Dictionary </h3>"
    "<form method=\"POST\" action=\"/handle_post_add_request\">"
      "Enter the word to add: <input type=\"text\" name=\"add_word\" />"
      "Enter the definition: <input type=\"text\" name=\"add_def\" />"
      "<input type=\"submit\" value=\"add\" />"
    "</form>"
    "<form method=\"POST\" action=\"/handle_post_search_request\">"
      "Enter the word to search: <input type=\"text\" name=\"search_word\" />"
      "<input type=\"submit\" value=\"search\" />"
    "</form>";
static const char *html_end = "</body></html>";

static SuperDict curr_dict;

static std::string search_definitons(const char* in_word) {
  vector<string> found_defs = curr_dict.search_word(in_word);
  string result = string("<h4>") + string(in_word) + string("</h4>");
  if (found_defs.size() == 0) {
    result += string("<p> No definition found </p>");
  }
  else {
    for (int i = 0; i < found_defs.size(); i++) {
      char c = '1' + i;
      result += string("<p> definition ") + c + string(": ")
        + found_defs[i] + string("</p>");
    }
  }
  return result;
}

static std::string display_top10_words() {
  string result("<h3> Top 10 searched words: </h3><p>");
  vector<string> words = curr_dict.get_top10(false);
  for (int i = 0; i < 10; i++) {
    result += words[i] + "    ";
  }
  result += "</p>";
  return result;
}

static int handler(struct mg_connection *conn) {
  char input_word[500], input_def[500];
  
  if (strcmp(conn->uri, "/handle_post_search_request") == 0) {
    mg_get_var(conn, "search_word", input_word, sizeof(input_word));
    string html_dictionary = std::string(html_begin);
    if (strlen(input_word) != 0)
      html_dictionary += search_definitons(input_word);
    html_dictionary += display_top10_words() + std::string(html_end);
    mg_send_data(conn, html_dictionary.c_str(), html_dictionary.length());
  }
  else if (strcmp(conn->uri, "/handle_post_add_request") == 0) {
    mg_get_var(conn, "add_word", input_word, sizeof(input_word));
    mg_get_var(conn, "add_def", input_def, sizeof(input_def));
    string html_dictionary = std::string(html_begin);
    if (strlen(input_word) != 0 && strlen(input_def) != 0) {
      curr_dict.add_word(input_word, input_def);
      html_dictionary += "<h4> Definition added </h4>";
    }
    html_dictionary += display_top10_words() + std::string(html_end);
    mg_send_data(conn, html_dictionary.c_str(), html_dictionary.length());
  }
  else {
    // Show HTML form.
    std::string html_dictionary = std::string(html_begin)
      + display_top10_words() + std::string(html_end);
    mg_send_data(conn, html_dictionary.c_str(), html_dictionary.length());
  }

  return 1;
}

int main(void) {
  struct mg_server *server = mg_create_server(NULL);
  mg_set_option(server, "listening_port", "8080");
  mg_add_uri_handler(server, "/", handler);
  printf("Starting on port %s\n", mg_get_option(server, "listening_port"));
  for (;;) {
    mg_poll_server(server, 1000);
  }
  mg_destroy_server(&server);
  return 0;
}
