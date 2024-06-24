#include "ASCIIParser.hpp"
#include <fstream>
#include <iostream>
#include <algorithm>

void ASCIIParser::run()
{

    //Load the file
    std::ifstream asciiFile(this->filePath);

    //Read the file
    if(!asciiFile.is_open())
    {
        //Handle error
        std::cout << "Problem encountered in opening ascii file" << std::endl;
    }
    else
    {
        std::string line;
        while(std::getline(asciiFile,line))
        {
          struct ASCIIMessage_S message;
          //std::pair<bool,int> messageInfo;
          //messageInfo = this->isMessageValid(line, message);
          this->loadMessage(line,message);
          if(message.timeStamp!=-1)
          {
          }
        }
        asciiFile.close();
    }
}

//std::pair<bool,int> ASCIIParser::loadMessagePreChecks(const std::string& line, struct ASCIIMessage_S& message)
//{
//    std::pair<bool,int> messageInfo = std::makepair(false,0);
//    int16_t firstDelimiter = line.find(" ",5);
//    std::string timeStamp = line.substr(0,firstDelimiter);
//    if(timeStamp.find(".")<timeStamp.length())
//    {
//        message.timeStamp = std::stof(timeStamp);
//    }
//    else
//    {
//    }
//    return messageInfo;
//
//}

void ASCIIParser::loadMessage(const std::string& line, struct ASCIIMessage_S& message)
{
    int16_t firstDelimiter = line.find(" ",5);
    std::string timeStamp = line.substr(0,firstDelimiter);
    if(timeStamp.find(".")<timeStamp.length())
    {
        message.timeStamp = std::stof(timeStamp);
        
        int16_t secondDelimiter = line.find(" ",firstDelimiter+1);
        message.CANBus = std::stoi(line.substr(firstDelimiter+1,secondDelimiter-firstDelimiter-1));
        
        int16_t thirdDelimiter = line.find(" ",secondDelimiter+2);
        std::string messageID = line.substr(secondDelimiter+2,thirdDelimiter-secondDelimiter-2);
        this->translateMessageID(message,messageID);

        int16_t fourthDelimiter = line.find(" ",thirdDelimiter+3);
        if(!std::strcmp((line.substr(fourthDelimiter-2,2)).c_str(),"Rx"))
        {
            message.receivedMessage = true;
        }
        else
        {
            message.receivedMessage = false;
        }
        
        int16_t fifthDelimiter = line.find("D",fourthDelimiter+1);
        int16_t sixthDelimiter = line.find(" ",fifthDelimiter+2);
        message.dataLength = std::stoi(line.substr(fifthDelimiter+2,sixthDelimiter-fifthDelimiter-2));
        
        std::string bytes = line.substr(sixthDelimiter+2,line.length()-sixthDelimiter-2);
        this->unpackBytes(message,bytes);

    }
    else
    {
    }
    //std::cout << message.timeStamp << std::endl;
}

void ASCIIParser::translateMessageID(struct ASCIIMessage_S& message,std::string messageID)
{
    //Remove x from end
    messageID.pop_back();
    message.messageID = std::stoi(messageID,0,16);
}

void ASCIIParser::unpackBytes(struct ASCIIMessage_S& message,std::string bytes)
{
    bytes.erase(std::remove(bytes.begin(),bytes.end(),' '), bytes.end());
    //std::cout << bytes.length() << std::endl;
    for(auto it=bytes.begin();it<bytes.end();it=it+2)
    {
        std::string indByte = std::string(1,(*it))+*(it+1);
        message.bytes.push_back(indByte);
    }
    std::cout << *message.bytes.begin() << std::endl;
}