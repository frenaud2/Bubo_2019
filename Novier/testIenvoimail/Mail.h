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
#include "/home/snir2g2/Bureau/testuinternet/Internet.h"
#define PASINTERNET -2
#define PBSMTP -1
#define FILENOTFOUND -3
#define PBMCLIENTMSG -4

using namespace std;

class Mail {
public:
    Mail();
    Mail(const Mail& orig);
    virtual ~Mail();
    int envoimail();
private:
    Config*ptrconfig;
    Poco::Net::MailMessage mailMessage;
    Internet*ptrinternet;
    void corpmail();
};

#endif /* MAIL_H */

