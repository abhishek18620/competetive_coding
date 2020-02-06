/*
 * compilation
 * g++ -O2 -std=c++14 -Wall -Wextra -Wfatal-errors -w -o stats thread_stats.cpp
 * -lcurl
 */

#include <chrono>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

// linux includes
#include <curl/curl.h>
#include <sys/resource.h>
#include <sys/time.h>

#define trace2(x, y) std::cerr << __func__ << " : " << #x << ": " << x << " | " << #y << ": " << y << std::endl;
#define trace3(x, y, z)                                                                                                \
  std::cerr << __func__ << " : " << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z            \
            << std::endl;
#define trace4(a, b, c, d)                                                                                             \
  std::cerr << __func__ << " : " << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | "   \
            << #d << ": " << d << std::endl;
#define trace5(a, b, c, d, e)                                                                                          \
  std::cerr << __func__ << " : " << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | "   \
            << #d << ": " << d << " | " << #e << ": " << e << std::endl;

void testConnection(std::vector<std::string>& url_list, int start, int end) {
  trace3(__func__, start, end);
  CURL* curl;
  int   res = 0;
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
  curl_easy_setopt(curl, CURLOPT_NOBODY, 1);
  std::string url;
  for (int i = start; i <= end; i++) {
    url = url_list[i];
    if (url.length() == 0)
      return;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    res = curl_easy_perform(curl);
    if (!res)
      std::cout << " URL : " << url << " is working" << std::endl;
    else
      std::cout << " URL : " << url << " is not working" << std::endl;
  }
  curl_easy_cleanup(curl);
  curl_global_cleanup();
}

int main() {
  freopen("websites.txt", "rt", stdin);
  std::thread t1;
  std::cout << "here" << std::endl;
  return 0;
}

