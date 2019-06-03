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

using namespace Poco::Net;
int main()
{
	{
    if (key == ' ') // Press spacebar for a simple send.
    {
        // Send a simple short message.
        smtp.send(recipientEmail,             // Recipient email.
                  senderEmail,                // Sender email.
                  "I'm trying out ofxSMTP!",  // Subject line.
                  "It works!");               // Message body.
    }
    else if(key == 'a') // Press 'a' for an advanced send with attachment.
    {
        // You can construct complex messages using POCO's MailMessage object.
        // See http://pocoproject.org/docs/Poco.Net.MailMessage.html

        auto message = std::make_shared<Poco::Net::MailMessage>();

        // Encode the sender and set it.
        message->setSender(Poco::Net::MailMessage::encodeWord(senderEmail,
                                                              "UTF-8"));
        // Mark the primary recipient and add them.
        message->addRecipient(Poco::Net::MailRecipient(Poco::Net::MailRecipient::PRIMARY_RECIPIENT,
                                                       recipientEmail));
        
        // Encode the subject and set it.
        message->setSubject(Poco::Net::MailMessage::encodeWord("I'm sending you an image using ofxSMTP!",
                                                               "UTF-8"));

        // Poco::Net::MailMessage will take ownership of the *PartSource files,
        // so you don't have to worry about deleting the pointers.
        message->addContent(new Poco::Net::StringPartSource("Hello world! How about an image?"));
        
        // Poco::Net::MailMessage throws exceptions when a file is not found.
        // Thus, we need to add attachments in a try / catch block.

        try
        {
            message->addAttachment(Poco::Net::MailMessage::encodeWord("of.png","UTF-8"),
                                   new Poco::Net::FilePartSource(ofToDataPath("of.png", true)));
        }
        catch (const Poco::OpenFileException& exc)
        {
            ofLogError("ofApp::keyPressed") << exc.name() << " : " << exc.displayText();
        }

        // Add an additional header, just because we can.
        message->add("X-Mailer", "ofxSMTP (https://github.com/bakercp/ofxSMTP)");

        // Add the message to our outbox.
        smtp.send(message);
    }
}
