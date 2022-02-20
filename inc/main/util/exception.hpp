#pragma once

#include "util/util.hpp"

#include <string>
#include <iostream>
#include <exception>

inline void logException(const std::exception & error)
{
    std::string logLine = "";
    #ifdef COLORS
    logLine += RED;
    logLine += BOLD;
    #endif
    logLine += "#### EXCEPTION: ";

    logLine += error.what();

    logLine += " ####";
    #ifdef COLORS
    logLine += NO_COLOR; 
    #endif
    std::cerr << logLine << std::endl;
}