#include <iostream>
#include <fstream>
#include <string>
#include "DBCParser.hpp"

void DBCParser::load()
{
    //Load the file
    std::ifstream dbcFile(this->filePath);

    //Read the file
    if(!dbcFile.is_open())
    {
        //Handle error
        std::cout << "Problem encountered in opening dbc file" << std::endl;
    }
    else
    {
        std::string line;
        while(std::getline(dbcFile,line))
        {
            std::string firstThree = line.substr(0,3);
            if(!std::strcmp(firstThree.c_str(),"BO_"))
            {
                this->setMessages(line);
            }
            else if(!std::strcmp(firstThree.c_str()," SG"))
            {
                this->setSignals(line);
            }
        }
        dbcFile.close();
    }
}

void DBCParser::setMessages(const std::string& line)
{
    int8_t firstDelimiter = line.find(" ");
    int8_t secondDelimiter = line.find(" ",firstDelimiter+1);
    int8_t thirdDelimiter = line.find(" ",secondDelimiter+1);
    int8_t fourthDelimiter = line.find(" ",thirdDelimiter+1);
    int8_t fifthDelimiter = line.find(" ",fourthDelimiter+1);
    struct Message_S message;
    message.messageID = line.substr(firstDelimiter+1,secondDelimiter-firstDelimiter-1);
    message.messageName = line.substr(secondDelimiter+1,thirdDelimiter-secondDelimiter-2);
    message.dataLength = line.substr(thirdDelimiter+1,fourthDelimiter-thirdDelimiter-1);
    message.TXNode = line.substr(fourthDelimiter+1,fifthDelimiter-fourthDelimiter-1);
    this->messageList.push_back(message);   
}

void DBCParser::setSignals(const std::string& line)
{
    int16_t firstDelimiter = line.find(" ",1);
    int16_t secondDelimiter = line.find(":",firstDelimiter+1);
    int16_t thirdDelimiter = line.find(" ",secondDelimiter+1);
    int16_t fourthDelimiter = line.find("|",thirdDelimiter+1);
    int16_t fifthDelimiter = line.find("@",fourthDelimiter+1);
    int16_t sixthDelimiter = line.find("(",fifthDelimiter+1);
    int16_t seventhDelimiter = line.find(",",sixthDelimiter+1);
    int16_t eighthDelimiter = line.find(")",seventhDelimiter+1);
    int16_t ninthDelimiter = line.find("|",eighthDelimiter+1);
    int16_t tenthDelimiter = line.find("]",ninthDelimiter+1);
    int16_t eleventhDelimiter = line.find('"',tenthDelimiter+3);

    struct Signal_S signal;
    signal.signalName = line.substr(firstDelimiter+1,secondDelimiter-firstDelimiter-2);
    this->checkMultiplex(signal);
    signal.startBit = std::stoi(line.substr(thirdDelimiter+1,fourthDelimiter-thirdDelimiter-1));
    signal.signalLength = std::stoi(line.substr(fourthDelimiter+1,fifthDelimiter-fourthDelimiter-1));
    if (!std::stoi(line.substr(fifthDelimiter+1,1)))
    { 
        signal.isLittleEndian = true;
    }
    else
    {
        signal.isLittleEndian = false;
    }
    if ((line.substr(fifthDelimiter+2,1)).c_str()=="+")
    {
        signal.isUnsigned = true;
    }
    else
    {
        signal.isUnsigned = false;
    }
    signal.factor = std::stof(line.substr(sixthDelimiter+1,seventhDelimiter-sixthDelimiter-1));
    signal.offset = std::stof(line.substr(seventhDelimiter+1,eighthDelimiter-seventhDelimiter-1));
    signal.min = line.substr(eighthDelimiter+3,ninthDelimiter-eighthDelimiter-3);
    signal.max = line.substr(ninthDelimiter+1,tenthDelimiter-ninthDelimiter-1);
    signal.unit = line.substr(tenthDelimiter+3,eleventhDelimiter-tenthDelimiter-3);
    signal.RXNode = line.substr(eleventhDelimiter+2,line.length()-eleventhDelimiter-2);
    (this->messageList.back()).signals.push_back(signal);
}

void DBCParser::checkMultiplex(struct Signal_S& signal)
{
    int16_t spaceDelimiter = 0;
    std::string signalNameSubStr = "";
    std::string multiplexID = "";
    spaceDelimiter = signal.signalName.find(" ");
    if(spaceDelimiter!=-1)
    {
        signalNameSubStr = signal.signalName.substr(0,spaceDelimiter);
        multiplexID = signal.signalName.substr(spaceDelimiter+1,signal.signalName.length()-spaceDelimiter-1);
        signal.signalName = signalNameSubStr;
        (this->messageList.back()).isMultiplexed = true;
            
        if(!std::strcmp(multiplexID.c_str(),"M"))
        {
            (this->messageList.back()).multiplexorName = std::move(signalNameSubStr);
        }
        else
        {
            signal.multiplexorID = std::stoi(multiplexID.substr(1,multiplexID.length()-1));
        }
    }
    else
    {
    }
}