#include "main.h"

/****************************************************************
 * Main program for Homework XML.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 1 August 2017
 *
**/

static const string kTag = "Main: ";

int main(int argc, char *argv[]) {
  string in_filename = "";
  string out_filename = "";
  string log_filename = "";

  Scanner in_scanner;
  ofstream out_stream;

  ParseIntoXML parseintoxml;

  Utils::CheckArgs(2, argc, argv, "infilename logfilename");
  in_filename = static_cast<string>(argv[1]);
  log_filename = static_cast<string>(argv[2]);

  Utils::LogFileOpen(log_filename);
  in_scanner.OpenFile(in_filename);

  Utils::log_stream << kTag << "Beginning execution\n";
  Utils::log_stream.flush();

  Utils::log_stream << kTag << "logfile '" << log_filename << "'\n";

  parseintoxml.ParseTheFile(in_scanner, out_stream);

  Utils::log_stream << kTag << "Ending execution\n";
  Utils::log_stream.flush();

  Utils::FileClose(Utils::log_stream);

  return 0;
}

