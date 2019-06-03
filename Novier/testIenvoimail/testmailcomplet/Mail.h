#ifndef MAIL_H
#define MAIL_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <Poco/Net/SMTPClientSession.h>
#include <Poco/Net/MailMessage.h>
#include <Poco/Net/FilePartSource.h>
#include <Poco/Net/NetException.h>
#include <Poco/Net/AcceptCertificateHandler.h>
#include <Poco/Net/FilePartSource.h>
#include <Poco/Net/InvalidCertificateHandler.h>
#include <Poco/Net/SecureSMTPClientSession.h>
#include <Poco/Net/SSLManager.h>
#include "Config.h"


using namespace std;

class Mail {
public:
    Mail();
    Mail(const Mail& orig);
    virtual ~Mail();
    void corpmail();
    int envoimail();
private:
    Config*ptrconfig;
    Poco::Net::MailMessage mailMessage;
};

#endif /* MAIL_H */

