#include "sms.h"


size_t SMS::writecallback(void* ptr, size_t size, size_t nmemb, void* userdata)
{
    ((std::string*)userdata)->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

SMS::SMS(std::string apiKey, std::string apiSecret, std::string fromNumber)
    : m_apiKey(apiKey), m_apiSecret(apiSecret), m_fromNumber(fromNumber)
{}

SMS::~SMS() {}

bool SMS::sendSMS(std::string toNumber, std::string message) {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {

        std::string url = "https://rest.nexmo.com/sms/json?api_key=e6c2d473&api_secret=89XeibSGz2Td6whs";
        url += "&from=" + m_fromNumber;
        url += "&to=+216" + toNumber;
        url += "&text=" + message;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writecallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
        res = curl_easy_perform(curl);

        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return false;
        }
    }
    else {
        fprintf(stderr, "Failed to initialize curl\n");
        return false;
    }

    curl_global_cleanup();

    return true;
}
