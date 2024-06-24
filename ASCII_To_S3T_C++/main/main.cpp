#include "DBCParser/DBCParser.hpp"
#include "ASCIIParser/ASCIIParser.hpp"

int main()
{
    //DBCParser dbcParserObject("C:\\Users\\B841SNC\\Documents\\nCodeAutomation\\ASCII_To_S3T_C++\\trial.dbc");
    //dbcParserObject.load();

    ASCIIParser asciiParserObject("C:\\Users\\B841SNC\\Documents\\nCodeAutomation\\ASCII_To_S3T_C++\\ASCII_TriggerF002.asc");
    asciiParserObject.run();

    return 0;
}