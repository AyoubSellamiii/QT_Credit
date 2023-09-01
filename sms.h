#ifndef SMS_H
#define SMS_H

#include <string>
#include <curl/curl.h>

class SMS {
public:
    SMS(std::string apiKey, std::string apiSecret, std::string fromNumber);
    ~SMS();
    bool sendSMS(std::string toNumber, std::string message);
    static size_t writecallback(void* ptr, size_t size, size_t nmemb, void* userdata);

private:
    std::string m_apiKey;
    std::string m_apiSecret;
    std::string m_fromNumber;
};

#endif // SMS_H
